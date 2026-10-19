static long minor_faults(void)          /* kernel's counter */
{
    struct rusage ru;
    getrusage(RUSAGE_SELF, &ru);
    return ru.ru_minflt;
}

int main(void)
{
    long page = sysconf(_SC_PAGESIZE);  /* 4096 bytes  */
    long size = 64 * MB;                /* 16384 pages */

    long f0 = minor_faults();
    char *a = malloc(size);             /* virtual only */
    long f1 = minor_faults();
    for (long i = 0; i < size; i += page)
        a[i] = 1;                       /* first touch  */
    long f2 = minor_faults();
    for (long i = 0; i < size; i += page)
        a[i] += 1;                      /* now resident */
    long f3 = minor_faults();
    /* print f1-f0, f2-f1, f3-f2 */
}
/* full program: code/page_faults.c */
