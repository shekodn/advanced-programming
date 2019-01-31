#include <stdio.h>
#include <time.h>

int randomGenerator ()
{
  //seed
  static int iN = 8392;
  iN = ((iN * iN) / 100 ) % 10000;
  return iN ;
}

int range ( int iMin, int iMax )  // max-min must be <10000!!
{
  return randomGenerator() % (iMax+1-iMin) + iMin ;
}

int main(int argc, char const *argv[])
{

  int iX;
  for (int iI = 0; iI < 10; iI++)
  {
    iX = range(1,999);
    printf("%d\n", iX);
  }
  return 0;
}
