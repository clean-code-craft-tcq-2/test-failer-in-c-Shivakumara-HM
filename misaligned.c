#include <stdio.h>
#include <assert.h>
#include "misaligned.h"

int printColorMap() 
{
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) 
    {
        for(j = 0; j < 5; j++) 
        {
           printOnConsole(i * 5 + j , MajorColorNames[i] ,  MinorColorNames[i]);
        }
    }
    return i * j;
}

void printOnConsole(int Index, const char* MajorColor, const char* MinorColor)
{ 
        assert( MajorColorNames[Index / numberOfMajorColors] == MajorColor);
        assert( MinorColorNames[Index % numberOfMinorColors] == MinorColor);
     
        printf("%d | %s | %s\n", Index , MajorColor, MinorColor);  
}
    
int main() 
{
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
