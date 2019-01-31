#include <stdio.h>
#include <time.h>



int myRand ()
{
  //seed
  static int iN = 8392;
  iN = ((iN * iN) / 100 ) % 10000;
  return iN ;
}

int myRandInRange ( int iMin, int iMax )  // max-min must be <10000!!
{

  // time_t now;
  // struct tm *tm;
  //
  // now = time(0);
  //
  // int iMin = tm->tm_min;
  // printf ("%d\n", iMin);
  //
  // int iSec = tm->tm_sec;
  // printf ("%d\n", tm->tm_sec);

  // if ((tm = localtime (&now)) == NULL) {
  //   printf ("Error extracting time stuff\n");
  //   return 1;
  // }

  return myRand() % (iMax+1-iMin) + iMin ;
}

int main(int argc, char const *argv[]) {

  int iX;
  for (int iI = 0; iI < 10; iI++) {
    iX = myRandInRange(1,999);
    printf("%d\n", iX);
  }
  return 0;
}
