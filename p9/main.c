#include <stdio.h>
#include <stdlib.h>

void extremlyLargeString()
{
    printf("Insert an extremely large string: \n");
    char cLetter = getchar();
    while(cLetter != '\n')
    {
        cLetter = getchar();
    }
}

int main()
{
    extremlyLargeString();
    return 0;
}
