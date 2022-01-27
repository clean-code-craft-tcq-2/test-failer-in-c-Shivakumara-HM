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

int printColorMap() 
{
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) 
    {
        for(j = 0; j < 5; j++) 
        {
            printf("%d | %s | %s\n", i * 5 + j, MajorColorNames[i], MinorColorNames[i]);
            testNumberToPair( i * 5 + j, MajorColorNames[i], MinorColorNames[i]);
        }
    }
    return i * j;
}

    
int main() 
{
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
