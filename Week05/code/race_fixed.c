/* race_fixed.c -- the same program, but the increment is a
 * CRITICAL SECTION protected by a mutex lock.
 * Compile:  gcc -Wall -O2 -pthread race_fixed.c -o race_fixed
 * Run:      ./race_fixed
 */
#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define N 10000000L

long counter = 0;                                  /* shared data   */
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;  /* protects it   */

void *worker(void *arg)
{
    for (long i = 0; i < N; i++) {
        pthread_mutex_lock(&lock);     /* acquire: entry section */
        counter++;                     /* critical section       */
        pthread_mutex_unlock(&lock);   /* release: exit section  */
    }
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
    pthread_create(&a, NULL, worker, NULL);
    pthread_create(&b, NULL, worker, NULL);
    pthread_join(a, NULL);
    pthread_join(b, NULL);
    double t1 = seconds();

    printf("counter = %8ld of %ld  (lost %7ld)  %.3f s\n",
           counter, 2 * N, 2 * N - counter, t1 - t0);
    return 0;
}
