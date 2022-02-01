#include <stdio.h>
#include <assert.h>
#include "misaligned.h"

ColorPair GetColorFromPairNumber(int pairNumber) 
{
    ColorPair colorPair;
    colorPair.majorColor = MajorColorNames[(pairNumber / numberOfMajorColors)];
    colorPair.minorColor = MinorColorNames[(pairNumber / numberOfMinorColors)];
    return colorPair;
}

void testNumberToPair(int pairNumber, const char* expectedMajor, const char* expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void formatColorPrinter(int pairNumber, const char* MajorColor, const char* MinorColor)
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
            formatColorPrinter(i * 5 + j, majorColor[i], minorColor[j]);
        }
    }
    return i * j;
}

    
int main() 
{
    int result = printColorMap(testNumberToPair(*colorPair));
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
