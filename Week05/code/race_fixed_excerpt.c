long counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *worker(void *arg)
{
    for (long i = 0; i < N; i++) {
        pthread_mutex_lock(&lock);    /* entry */
        counter++;                    /* critical
                                         section */
        pthread_mutex_unlock(&lock);  /* exit  */
    }
    return NULL;
}
/* main() unchanged; full program:
   code/race_fixed.c */
