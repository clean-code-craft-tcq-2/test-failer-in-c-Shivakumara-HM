#include <stdio.h>
#include <assert.h>

int printColorMap() 
{
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) 
    {
        for(j = 0; j < 5; j++) 
        {
           printOnConsole(i,j);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
