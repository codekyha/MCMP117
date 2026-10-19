#define N 10000000L            /* per thread */
volatile long counter = 0;     /* SHARED     */

void *worker(void *arg)
{
    for (long i = 0; i < N; i++)
        counter++;             /* NOT atomic */
    return NULL;
}

int main(void)
{
    pthread_t a, b;
    pthread_create(&a, NULL, worker, NULL);
    pthread_create(&b, NULL, worker, NULL);
    pthread_join(a, NULL);
    pthread_join(b, NULL);
    printf("counter = %8ld of %ld ...\n",
           counter, 2 * N);
}
/* full program: code/race.c */
