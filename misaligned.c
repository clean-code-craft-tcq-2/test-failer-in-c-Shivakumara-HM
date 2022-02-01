#include <stdio.h>
#include <assert.h>
#include "misaligned.h"

ColorPair GetColorFromPairNumber(int pairNumber) 
{
    ColorPair colorPair;
    colorPair.majorColor = MajorColorNames[(pairNumber / numberOfMajorColors)];
    colorPair.minorColor = MinorColorNames[(pairNumber % numberOfMinorColors)];
    return colorPair;
}

void testNumberToPair(int pairNumber, const char* expectedMajor, const char* expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void printOnConsole(int pairNumber, const char* MajorColor, const char* MinorColor)
{
    printf("%d | %s | %s\n", pairNumber, MajorColor, MinorColor);
}

int printColorMap() 
{
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) 
    {
        for(j = 0; j < 5; j++) 
        {
            printOnConsole(i * 5 + j, MajorColorNames[i], MinorColorNames[j]);
        }
    }
    return i * j;
}

    
int main() 
{
    int result = printColorMap();
    assert(result == 25);
    for(int i = 0; i < 5; i++) 
    {
        for(int j = 0; j < 5; j++) 
        {
          testNumberToPair( i * 5 + j, MajorColorNames[i], MinorColorNames[j]);
        }
    }
    printf("All is well (maybe!)\n");
    return 0;
}
