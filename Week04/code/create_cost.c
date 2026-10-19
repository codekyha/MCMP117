/* create_cost.c -- is a thread really cheaper than a process?
 * Create (and wait for) 5000 processes with fork(), then
 * 5000 threads with pthread_create(); each one does nothing.
 * Compile:  gcc -Wall -O2 -pthread create_cost.c -o create_cost
 * Run:      ./create_cost
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 5000

static double now(void)
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec + t.tv_nsec / 1e9;
}

void *nothing(void *arg) { return arg; }   /* the thread's whole job */

int main(void)
{
    double t0 = now();
    for (int i = 0; i < N; i++) {
        pid_t pid = fork();                 /* copy the whole process */
        if (pid == 0) _exit(0);             /* child: exit at once    */
        waitpid(pid, NULL, 0);              /* parent: wait for it    */
    }
    double t1 = now();
    for (int i = 0; i < N; i++) {
        pthread_t t;
        pthread_create(&t, NULL, nothing, NULL); /* share everything */
        pthread_join(t, NULL);
    }
    double t2 = now();

    double p = (t1 - t0) / N * 1e6, th = (t2 - t1) / N * 1e6;
    printf("fork + wait          : %6.1f us per process\n", p);
    printf("pthread_create + join: %6.1f us per thread\n", th);
    printf("a thread is about %.0f times cheaper to create\n", p / th);
    return 0;
}
