/* race.c -- two threads increment ONE shared counter, with NO lock.
 * Each thread adds 1 to the counter 10 million times, so the correct
 * final value is 20,000,000. Run it a few times and compare.
 * Compile:  gcc -Wall -O2 -pthread race.c -o race
 * Run:      ./race
 */
#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define N 10000000L              /* increments per thread */

/* volatile: force a real load and store on every increment
 * (otherwise -O2 would add N in one step and hide the race). */
volatile long counter = 0;       /* shared by both threads */

void *worker(void *arg)
{
    for (long i = 0; i < N; i++)
        counter++;               /* load, add 1, store: NOT atomic */
    return NULL;
}

static double seconds(void)
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec + t.tv_nsec / 1e9;
}

int main(void)
{
    pthread_t a, b;
    double t0 = seconds();
    pthread_create(&a, NULL, worker, NULL);   /* start thread A */
    pthread_create(&b, NULL, worker, NULL);   /* start thread B */
    pthread_join(a, NULL);                    /* wait for both  */
    pthread_join(b, NULL);
    double t1 = seconds();

    printf("counter = %8ld of %ld  (lost %7ld)  %.3f s\n",
           counter, 2 * N, 2 * N - counter, t1 - t0);
    return 0;
}
