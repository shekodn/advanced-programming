#include <stdio.h>
#include <string.h>
#include <limits.h>

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

int dCout()
{
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

int main(void)
{

  int iX = iCout();

  double dX = dCout();

  char cX;
  printf("Enter a Char: ");
  cX = getchar();

  printf("Your integer %d storage size is %lx bytes\n", iX, sizeof(iX));
  printf("Your double %f storage size is %lu bytes I can read any number from %ld to %ld in this data type.\n", dX, sizeof(dX), LONG_MIN, LONG_MAX);
  printf("Your char '%c' storage size is %lx bytes. And I can read it as '%c' or as %d\n", cX, sizeof(cX), cX, cX - 0);

  return 0;
}
