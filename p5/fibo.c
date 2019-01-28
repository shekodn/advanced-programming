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


int fibo(int iX) {

  if (iX <= 1) {
    return iX;
  }

  return (fibo(iX - 1) + fibo(iX - 2));

}

int factorial(int iX) {
  if(iX >= 1) {
    return iX*factorial(iX - 1);
  }

  return 1;
}

int main(int argc, char const *argv[]) {
  int iInput = iCout();
  int iI = 0;
  int iCounter = 1;

  for (iCounter = 1; iCounter <= iInput; iCounter++) {
    printf("%d\n", fibo(iI));
    iI++;
  }

  return 0;
}
