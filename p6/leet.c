#include <stdio.h>

int main()
{
    char sArr[100];
    char *sPtr;

    printf("Enter a string: ");
    gets(sArr);

    sPtr=sArr;

    printf("Entered string is: ");
    while(*sPtr!='\0'){
      char cAux = *sPtr++;

      if (cAux == 'a')
      {
        cAux = '4';
      }
      else if (cAux == 'e')
      {
        cAux = '3';
      }
      else if (cAux == 'i')
      {
        cAux = '1';
      }
      else if (cAux == 'o')
      {
        cAux = '0';
      }
      else if (cAux == 'u')
      {
        cAux = '2';
      }

      printf("%c",cAux);
    }

    return 0;
}
