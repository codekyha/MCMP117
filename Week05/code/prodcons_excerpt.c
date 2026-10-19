sem_t empty, full, mutex;   /* SIZE, 0, 1 */

void *producer(void *arg) {
    for (int item = 1; item <= ITEMS; item++) {
        sem_wait(&empty);   /* free slot?  */
        sem_wait(&mutex);
        buffer[in] = item;  in = (in + 1) % SIZE;
        sem_post(&mutex);
        sem_post(&full);    /* one more item */
    }
    return NULL;
}
void *consumer(void *arg) {
    for (int k = 0; k < ITEMS; k++) {
        sem_wait(&full);    /* any item?   */
        sem_wait(&mutex);
        item = buffer[out]; out = (out + 1) % SIZE;
        sem_post(&mutex);
        sem_post(&empty);   /* one more slot */
        sum += item;   /* ... print every 5th */
    }
}
