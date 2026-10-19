#define N 5000
void *nothing(void *arg) { return arg; }

/* 1) N processes */
for (int i = 0; i < N; i++) {
    pid_t pid = fork();            /* copy the process */
    if (pid == 0) _exit(0);        /* child exits      */
    waitpid(pid, NULL, 0);
}
/* 2) N threads */
for (int i = 0; i < N; i++) {
    pthread_t t;
    pthread_create(&t, NULL, nothing, NULL);
    pthread_join(t, NULL);
}
/* full program: code/create_cost.c */
