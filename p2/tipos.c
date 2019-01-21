#include <stdio.h>
#include <string.h>

int iCout() {
  // The user will let you know how many numbers he/she wants from it.
  char cInput[100];
  int iOutput = 0;
  int iJ;
  int iLength;

  printf("Enter an Int: ");
  gets(cInput);

  iLength = strlen(cInput);
  for(int iI =0; iI < iLength; iI++)
  {
    iOutput = iOutput * 10 + ( cInput[iI] - '0');
  }

  return iOutput;
}

int dCout() {
  char cInput[100];
  double dOutput = 0.0;
  int iJ;
  int iLength;

  printf("Enter a Double: ");
  gets(cInput);

  iLength = strlen(cInput);
  for(int iI =0; iI < iLength; iI++)
  {
    dOutput = dOutput * 10 + ( cInput[iI] - '0');
  }

  return dOutput;
}

int main(void) {

  int iX = iCout();

  double dX = dCout();

  char cX;
  printf("Enter a Char: ");
  cX = getchar();

  printf("Your integer %x storage size is %hhx bytes\n", iX, sizeof(iX));
  printf("Your double %f storage size is %hhx bytes\n", dX, sizeof(dX));
  printf("Your char %c storage size is %hhx bytes\n", cX, sizeof(cX));

  return 0;
}
