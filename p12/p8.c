#include <stdio.h>
#include <stdlib.h>

// int asciiBinaryToInt(char *s): This routine returns an
// integer, corresponding to the input string, that codifies
// a binary number; consider that the string internal
// characters are just '0' and '1', with a maximum length of 32.
// Also, consider that the conversion should be finished
// reaching a null or any invalid characer.

int asciiBinaryToInt()
{
    char cBinary;
    int iData = 0;

    while(cBinary != '\n')
    {
        scanf("%c",&cBinary);
        if (cBinary == '1')
            iData = iData * 2 + 1;
        else if (cBinary == '0')
            iData *= 2;
    }
    return iData;
}

// int asciiHEXToInt(char *s): This routine returns an integer,
// corresponding to an equivalent decimal number converted
// from a hexadecimal, represented in sequence of characters
// in the input string; consider that the only alowed characters
// are from '0' to '9', from 'A' to 'F' and from 'a' to 'f',
// with a maximum string length of 8 characters .. any invalid
// character will finish the conversion process, so the
// acumulated result will be returned.

int asciiHEXToInt(char *cHex)
{
    int iHex;
    sscanf(cHex, "%x", &iHex);
    return iHex;
}

// double asciiToDouble(char *s): This routine returns a double
// precision float number, corresponding to an sequence of digit
// characters in the input string, with the optional single
// appearance of the sign ('+' or '-') and decimal point ('.')
// to commit with a valid representation for a real number, with
// integers and decimals; any invalid character will finish the
// conversion process, so the acumulated result will be returned.

double asciiToDouble(char *cDouble)
{
    double dData;
    sscanf(cDouble, "%lf", &dData);
    return dData;
}

int main()
{
    char cHex[8];
    char cDouble[8];

    printf("Integer converter: \n");

    printf("Insert a binary number: ");
    printf("%d\n", asciiBinaryToInt());

    printf("Insert an HEX number:: ");
    scanf("%s", &cHex);
    printf("%u\n", asciiHEXToInt(cHex));

    printf("Write the double string");
    scanf("%s", &cDouble);
    printf("%lf\n", asciiToDouble(cDouble));

    return 0;
}
