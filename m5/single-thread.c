#include <stdio.h>
#include <time.h>

long Inters = 1000000000;
double dInterBase = 0.0;
double dFX;
double dAux = 0;


void main()
{
	long lA;
	double dX = 0.0;



	dInterBase = 1.0/Inters;
	struct timespec start, finish;
	double dElapsed = 0.0;
	clock_gettime(CLOCK_MONOTONIC,&start);



	for (lA = 0, dX = 0.0; lA < Inters; lA++) {
		dFX = 4/(1 + (dX * dX));
		dAux = dAux + (dFX * dInterBase);
		dX = dX + dInterBase;
	}



	clock_gettime(CLOCK_MONOTONIC,&finish);

	dElapsed = (finish.tv_sec - start.tv_sec);
	dElapsed += (finish.tv_nsec - start.tv_nsec)/ 1000000000.0;



	printf("Resultado = %20.18lf (%f)\n", dAux, dElapsed);
}
