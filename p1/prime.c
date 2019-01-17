#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A program that let us know if a given number is prime
_Bool isPrime(int iX)
{
  for(int iI = 2; iI <= iX / 2; ++iI)
  {
    if(iX % iI == 0)
    {
      return 0;
    }
  }
    return 1;
}

int main(void)
{
  char cInput[100];
  int iOutput = 0;
  int iJ;
  int iLength;

  // C String to Int: Simple Ways to Convert to Numeric Values
  // https://blog.udemy.com/c-string-to-int/
  printf("Enter a number: ");
  gets(cInput);

  iLength = strlen(cInput);
  for(int iI =0; iI < iLength; iI++)
  {
    iOutput = iOutput * 10 + ( cInput[iI] - '0');
  }

  if (isPrime(iOutput)) {
    printf("%d is prime. \n", iOutput);
  } else {
    printf("%d is NOT prime. \n", iOutput);
  }

  return 0;

  // printf("%d\n", isPrime(100)); // Not prime = 0 = false
  // printf("%d\n", isPrime(53)); //Prime = 1 = true

}
