/* thread_hello.c -- one process, several threads.
 * Every thread prints the process ID (PID, shared by all threads)
 * and its own thread ID (TID, private to each thread).
 * Compile:  gcc -Wall -O2 -pthread thread_hello.c -o thread_hello
 * Run:      ./thread_hello
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>        /* getpid(), gettid(), sleep() */

#define NTHREADS 3

int shared_counter = 0;    /* global: ONE copy, seen by all threads */

/* Every thread starts its life in this function. */
void *worker(void *arg)
{
    int my_number = *(int *)arg;   /* local: on this thread's OWN stack */
    printf("thread %d: PID = %d, TID = %d\n",
           my_number, getpid(), gettid());
    shared_counter++;              /* (unsafe! see Week 5) */
    sleep(2);                      /* stay alive so we can watch it with ps */
    return NULL;
}

int main(void)
{
    pthread_t tid[NTHREADS];       /* thread "handles"            */
    int number[NTHREADS];

    printf("main    : PID = %d, TID = %d\n", getpid(), gettid());
    for (int i = 0; i < NTHREADS; i++) {
        number[i] = i + 1;
        /* create a thread that runs worker(&number[i]) */
        pthread_create(&tid[i], NULL, worker, &number[i]);
    }
    for (int i = 0; i < NTHREADS; i++)
        pthread_join(tid[i], NULL);  /* wait for thread i to finish */

    printf("main    : all threads done, shared_counter = %d\n",
           shared_counter);
    return 0;
}
