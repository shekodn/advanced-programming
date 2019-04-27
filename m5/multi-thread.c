#include <stdio.h>

#include <time.h>

#include <pthread.h>

pthread_t tid[4];
long lMyLongInt = 1000000000;
double dInterBase = 0.0;
int iNumberOfThreads = 4;
double dSum[4];

void * PiOne() {
  double dFX = 0.0;
  double dAux = 0.0;
  long lA = 0;
  double dX = 0.0;
  for (; lA < 250000000; lA++) {
    dFX = 4 / (1 + (dX * dX));
    dAux = dAux + (dFX * dInterBase);
    dX = dX + dInterBase;
  }
  dSum[0] = dAux;
  pthread_exit(NULL);
}

void * PiTwo() {
  double dFX = 0.0;
  double dAux = 0.0;
  long lA = 250000000;
  double dX = 0.25;
  for (; lA < 500000000; lA++) {
    dFX = 4 / (1 + (dX * dX));
    dAux = dAux + (dFX * dInterBase);
    dX = dX + dInterBase;
  }
  dSum[1] = dAux;
  pthread_exit(NULL);
}

void * PiThree() {
  double dFX = 0.0;
  double dAux = 0.0;
  long lA = 500000000;
  double dX = 0.5;
  for (; lA < 750000000; lA++) {
    dFX = 4 / (1 + (dX * dX));
    dAux = dAux + (dFX * dInterBase);
    dX = dX + dInterBase;
  }
  dSum[2] = dAux;
  pthread_exit(NULL);
}

void * PiFour() {
  double dFX = 0.0;
  double dAux = 0.0;
  long lA = 750000000;
  double dX = 0.75;
  for (; lA < 1000000000; lA++) {
    dFX = 4 / (1 + (dX * dX));
    dAux = dAux + (dFX * dInterBase);
    dX = dX + dInterBase;
  }
  dSum[3] = dAux;
  pthread_exit(NULL);
}

void * Pi(long lA, double dX, long lLim, int iIndex) {
  double dFX = 0.0;
  double dAux = 0.0;
  for (; lA < lLim; lA++) {
    dFX = 4 / (1 + (dX * dX));
    dAux = dAux + (dFX * dInterBase);
    dX = dX + dInterBase;
  }
  dSum[iIndex] = dAux;
  pthread_exit(NULL);
}

int main() {
  dInterBase = 1.0 / lMyLongInt;
  double dAux = 0;
  struct timespec InitialTime, FinalTime;
  double dDeltaTime = 0.0;
  clock_gettime(CLOCK_MONOTONIC, & InitialTime);

  pthread_create( & tid[0], NULL, PiOne, NULL);
  pthread_create( & tid[1], NULL, PiTwo, NULL);
  pthread_create( & tid[2], NULL, PiThree, NULL);
  pthread_create( & tid[3], NULL, PiFour, NULL);

  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);
  pthread_join(tid[2], NULL);
  pthread_join(tid[3], NULL);

  int iA;
  for (iA = 0; iA < 4; iA++) {
    dAux = dAux + dSum[iA];
  }

  clock_gettime(CLOCK_MONOTONIC, & FinalTime);

  dDeltaTime = (FinalTime.tv_sec - InitialTime.tv_sec);
  dDeltaTime += (FinalTime.tv_nsec - InitialTime.tv_nsec) / 1000000000.0;

  printf("Number of Threads: %d\n", iNumberOfThreads);
  printf("Result: %2.8lf\n", dAux);
  printf("Time: %f\n", dDeltaTime);

}
