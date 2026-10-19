char *buf = malloc(SIZE);              /* 32 MB = 8192 pages */
memset(buf, 'A', SIZE);                /* parent owns them   */

pid_t pid = fork();
if (pid == 0) {                        /* ---- child ----    */
    long f0 = minor_faults();
    for (long i = 0; i < SIZE; i += page)
        sum += buf[i];                 /* READ: shared       */
    long f1 = minor_faults();
    for (long i = 0; i < SIZE; i += page)
        buf[i] = 'B';                  /* WRITE: copy page   */
    long f2 = minor_faults();
    /* print f1 - f0 and f2 - f1 */
    exit(0);
}
wait(NULL);
printf("parent still sees '%c'\n", buf[0]);
/* full program: code/cow_fork.c */
