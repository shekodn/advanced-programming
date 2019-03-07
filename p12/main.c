#include <stdio.h>
#include <stdlib.h>
#include "P8.h"

int main()
{
    char cHexInt[8];
    char cAscDouble[8];

    printf("Give the binary number to convert it to an integer: ");
    printf("%d\n", asciiBinaryToInt());

    printf("Give the hexadecimal number to convert it to an integer: ");
    scanf("%s", &cHexInt);
    printf("%u\n", asciiHEXToInt(cHexInt));

    printf("Give the double string to convert it to an double: ");
    scanf("%s", &cAscDouble);
    printf("%lf\n", asciiToDouble(cAscDouble));

    return 0;
}
