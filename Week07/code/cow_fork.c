/* cow_fork.c -- copy-on-write after fork() (links to Week 3).
 * The parent fills a 32 MB buffer, then forks. The child first only
 * READS the buffer (shared pages: almost no faults), then WRITES it
 * (each written page must be copied first: one fault per page).
 * Compile:  gcc -Wall -O2 cow_fork.c -o cow_fork
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/wait.h>

#define SIZE (32L * 1024 * 1024)

static long minor_faults(void)
{
    struct rusage ru;
    getrusage(RUSAGE_SELF, &ru);
    return ru.ru_minflt;
}

int main(void)
{
    long page = sysconf(_SC_PAGESIZE);
    char *buf = malloc(SIZE);
    if (buf == NULL) { perror("malloc"); return 1; }
    memset(buf, 'A', SIZE);             /* parent owns all pages now */
    printf("buffer: %ld pages of %ld bytes\n", SIZE / page, page);
    fflush(stdout);                     /* don't duplicate the buffer */

    pid_t pid = fork();
    if (pid == 0) {                     /* ---- child ---- */
        volatile long sum = 0;
        long f0 = minor_faults();
        for (long i = 0; i < SIZE; i += page)
            sum += buf[i];              /* read: pages still shared */
        long f1 = minor_faults();
        for (long i = 0; i < SIZE; i += page)
            buf[i] = 'B';               /* write: copy each page */
        long f2 = minor_faults();
        printf("child read  all pages: %6ld faults\n", f1 - f0);
        printf("child write all pages: %6ld faults (copy-on-write)\n",
               f2 - f1);
        exit(0);
    }
    wait(NULL);
    printf("parent still sees  '%c'  (its copy was never changed)\n",
           buf[0]);
    free(buf);
    return 0;
}
