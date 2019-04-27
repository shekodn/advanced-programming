#include <stdio.h>

#include <time.h>

long Inters = 1000000000;
double dInterBase = 0.0;
double dFX;
double dAux = 0;
int iNumberOfThreads = 1;

void main() {
  long lA;
  double dX = 0.0;

  dInterBase = 1.0 / Inters;
  struct timespec InitialTime, FinalTime;
  double dDeltaTime = 0.0;
  clock_gettime(CLOCK_MONOTONIC, & InitialTime);

  for (lA = 0, dX = 0.0; lA < Inters; lA++) {
    dFX = 4 / (1 + (dX * dX));
    dAux = dAux + (dFX * dInterBase);
    dX = dX + dInterBase;
  }

  clock_gettime(CLOCK_MONOTONIC, & FinalTime);

  dDeltaTime = (FinalTime.tv_sec - InitialTime.tv_sec);
  dDeltaTime += (FinalTime.tv_nsec - InitialTime.tv_nsec) / 1000000000.0;

  printf("Number of Threads: %d\n", iNumberOfThreads);
  printf("Result: %2.8lf\n", dAux);
  printf("Time: %f\n", dDeltaTime);
}
