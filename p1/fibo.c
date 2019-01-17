#include <stdio.h>
#include <string.h>

// A program that shows the Fibonacci sequence without using recursion.
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34
void fibo(int x){

  int a = 0;
  int b = 1;
  int fibo = 0;

  printf("%d ", 0);
  printf("%d ", 1);

  for(int i = 0; i < (x - 2); i++) {
    fibo = a + b;
    printf("%d ", fibo);

    a = b;
    b = fibo;
  }
  printf("\n");
}

int main(void) {

  // The user will let you know how many numbers he/she wants from it.
  char cInput[100];
  int iOutput = 0;
  int iJ;
  int iLength;

  printf("Enter a number: ");
  gets(cInput);

  iLength = strlen(cInput);
  for(int iI =0; iI < iLength; iI++)
  {
    iOutput = iOutput * 10 + ( cInput[iI] - '0');
  }

  fibo(iOutput);

  return 0;
}
