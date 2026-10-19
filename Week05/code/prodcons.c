/* prodcons.c -- bounded-buffer producer-consumer with POSIX semaphores.
 * One producer puts the numbers 1..ITEMS into a buffer of SIZE slots;
 * one consumer takes them out and adds them up.
 *   empty = number of free slots   (starts at SIZE)
 *   full  = number of filled slots (starts at 0)
 *   mutex = protects the buffer indices (binary semaphore, starts at 1)
 * Compile:  gcc -Wall -O2 -pthread prodcons.c -o prodcons
 * Run:      ./prodcons
 */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE  5                  /* buffer slots      */
#define ITEMS 20                 /* items to transfer */

int buffer[SIZE];
int in = 0, out = 0;             /* next slot to fill / to empty */
sem_t empty, full, mutex;

void *producer(void *arg)
{
    for (int item = 1; item <= ITEMS; item++) {
        sem_wait(&empty);                /* wait for a free slot   */
        sem_wait(&mutex);                /* enter critical section */
        buffer[in] = item;
        in = (in + 1) % SIZE;
        sem_post(&mutex);                /* leave critical section */
        sem_post(&full);                 /* one more filled slot   */
    }
    return NULL;
}

void *consumer(void *arg)
{
    long sum = 0;
    for (int k = 0; k < ITEMS; k++) {
        sem_wait(&full);                 /* wait for a filled slot */
        sem_wait(&mutex);
        int item = buffer[out];
        out = (out + 1) % SIZE;
        sem_post(&mutex);
        sem_post(&empty);                /* one more free slot     */
        sum += item;
        if (item % 5 == 0)
            printf("consumed %2d   running sum %3ld\n", item, sum);
    }
    printf("sum of 1..%d = %ld (expected %d)\n", ITEMS, sum, ITEMS * (ITEMS + 1) / 2);
    return NULL;
}

int main(void)
{
    pthread_t p, c;
    sem_init(&empty, 0, SIZE);   /* 0 = shared between threads, not processes */
    sem_init(&full,  0, 0);
    sem_init(&mutex, 0, 1);
    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);
    pthread_join(p, NULL);
    pthread_join(c, NULL);
    sem_destroy(&empty); sem_destroy(&full); sem_destroy(&mutex);
    return 0;
}
