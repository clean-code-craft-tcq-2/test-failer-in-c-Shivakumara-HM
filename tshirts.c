#include <stdio.h>
#include <assert.h>

char size(int cms) 
{
    char sizeName = '\0';
    if(cms < 38) 
    {
        sizeName = 'S';
    } 
    else if(cms >= 38 && cms <= 42) 
    {
        sizeName = 'M';
    } 
    else if(cms > 42)
    {
        sizeName = 'L';
    }
    return sizeName;
}


testShirtSize(int sizenumber, char sizename)
{
    assert(size(sizenumber) == sizename);
}
    
int main() {
    testShirtSize(37, 'S');
    testShirtSize(40, 'M');
    testShirtSize(43, 'L');
    testShirtSize(38, 'M');
    testShirtSize(42, 'M');
    printf("All is well (maybe!)\n");
    return 0;
}
