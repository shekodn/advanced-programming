#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//global variables
int N, T;
double *vsum;

//pie function
void* pie_runner(void* arg)
{
    long j = (long)arg;
    //double *limit_ptr = (double*) arg;
    //double j = *limit_ptr;

    //for(int i = (j-1)*N/T; i < N*(j) /T; i++)
    for(int i = (N/T)*(j-1); i < ((N/T)*(j)); i++)
    {

        if(i % 2 == 0){
            vsum[j] += 4.0/((2*j)*(2*j+1)*(2*j+2));
            //printf("vsum %lu = %f\n", j, vsum[j]);
                  }
        else{
            vsum[j] -= 4.0/((2*j)*(2*j+1)*(2*j+2));
            //printf("vsum %lu = %f\n", j, vsum[j]);
                  }


    }

    pthread_exit(0);
}

int main(int argc, char **argv)
{

    if(argc != 3) {
        printf("Error: Must send it 2 parameters, you sent %d\n", argc-1);
        exit(1);
    }
    N = atoi(argv[1]);
    T = atoi(argv[2]);

    vsum = malloc((T+1) * sizeof(*vsum));
    if(vsum == NULL) {
        fprintf(stderr, "Memory allocation problem\n");
        exit(1);
    }

    if(N <= T) {
        printf("Error: Number of terms must be greater then number of threads.\n");
        exit(1);
    }

    for(int p=1; p<=T; p++)        //initialize array to 0
    {
        vsum[p] = 0;
    }

    double pie = 3.0;
    //launch threads
    pthread_t tids[T+1];

    for(long i = 1; i<=T; i++)
    {
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_create(&tids[i], &attr, pie_runner, (void*)i);
    }

    //wait for threads...
    for(int k = 1; k<=T; k++)
    {
        pthread_join(tids[k], NULL);
    }

    for(int x=1; x<=T; x++)
    {
        pie += vsum[x];
    }

    printf("pi computed with %d terms in %d threads is %.20f\n", N, T, pie);

    //printf("pi computed with %d terms in %d threads is %20f\n", N, T, pie);

    free(vsum);
}
