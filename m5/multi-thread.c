#include <stdio.h>
#include <time.h>
#include <pthread.h>

pthread_t tid[4];
long lInter = 1000000000;
double dInterBase = 0.0;
double dSum[4];

void *PI_Calc1()
{
	double dFX = 0.0;
	double dAux = 0.0;
	long lA = 0;
	double dX = 0.0;
  for ( ; lA < 250000000; lA++)
  {
  	dFX = 4/(1 + (dX * dX));
		dAux = dAux + (dFX * dInterBase);
		dX = dX + dInterBase;
	}
	dSum[0] = dAux;
	pthread_exit(NULL);
}

void *PI_Calc2()
{
	double dFX = 0.0;
	double dAux = 0.0;
	long lA = 250000000;
	double dX = 0.25;
  for ( ; lA < 500000000; lA++)
  {
		dFX = 4/(1 + (dX * dX));
		dAux = dAux + (dFX * dInterBase);
		dX = dX + dInterBase;
	}
	dSum[1] = dAux;
	pthread_exit(NULL);
}

void *PI_Calc3()
{
	double dFX = 0.0;
	double dAux = 0.0;
	long lA = 500000000;
	double dX = 0.5;
  for ( ; lA < 750000000; lA++)
  {
		dFX = 4/(1 + (dX * dX));
		dAux = dAux + (dFX * dInterBase);
		dX = dX + dInterBase;
	}
	dSum[2] = dAux;
	pthread_exit(NULL);
}

void *PI_Calc4()
{
	double dFX = 0.0;
	double dAux = 0.0;
	long lA = 750000000;
	double dX = 0.75;
  for ( ; lA < 1000000000; lA++)
  {
		dFX = 4/(1 + (dX * dX));
		dAux = dAux + (dFX * dInterBase);
		dX = dX + dInterBase;
	}
	dSum[3] = dAux;
	pthread_exit(NULL);
}

int main()
{
	dInterBase = 1.0/lInter;
	double dAux = 0;
	struct timespec start, finish;
	double dDelay = 0.0;
	clock_gettime(CLOCK_MONOTONIC, &start);

  pthread_create(&tid[0], NULL, PI_Calc1, NULL);
  pthread_create(&tid[1], NULL, PI_Calc2, NULL);
  pthread_create(&tid[2], NULL, PI_Calc3, NULL);
  pthread_create(&tid[3], NULL, PI_Calc4, NULL);

  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);
  pthread_join(tid[2], NULL);
  pthread_join(tid[3], NULL);

	int iA;
  for (iA = 0 ; iA < 4; iA++)
  {
      dAux = dAux + dSum[iA];
  }

  clock_gettime(CLOCK_MONOTONIC,&finish);

	dDelay = (finish.tv_sec - start.tv_sec);
	dDelay += (finish.tv_nsec - start.tv_nsec)/ 1000000000.0;

	printf("Resultado = %20.18lf (%f)\n", dAux, dDelay);

}
