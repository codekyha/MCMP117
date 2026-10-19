/* page_faults.c -- watch demand paging happen.
 * malloc() only reserves VIRTUAL memory. Physical frames are given
 * to us one page at a time, at the moment we first touch each page.
 * Every first touch is a (minor) page fault, counted by the kernel.
 * Compile:  gcc -Wall -O2 page_faults.c -o page_faults
 * Run:      ./page_faults        or   /usr/bin/time -v ./page_faults
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

#define MB (1024L * 1024L)

static long minor_faults(void)          /* faults so far, this process */
{
    struct rusage ru;
    getrusage(RUSAGE_SELF, &ru);
    return ru.ru_minflt;                /* minor = no disk I/O needed  */
}

int main(void)
{
    long page = sysconf(_SC_PAGESIZE);  /* usually 4096 bytes */
    long size = 64 * MB;
    long pages = size / page;
    printf("page size %ld bytes; array %ld MB = %ld pages\n",
           page, size / MB, pages);

    long f0 = minor_faults();
    char *a = malloc(size);             /* virtual space only */
    if (a == NULL) { perror("malloc"); return 1; }
    long f1 = minor_faults();
    printf("after malloc       : %6ld new faults\n", f1 - f0);

    for (long i = 0; i < size; i += page)
        a[i] = 1;                       /* first touch of each page */
    long f2 = minor_faults();
    printf("first touch (write): %6ld new faults\n", f2 - f1);

    for (long i = 0; i < size; i += page)
        a[i] += 1;                      /* pages are now resident */
    long f3 = minor_faults();
    printf("second touch       : %6ld new faults\n", f3 - f2);

    free(a);
    return 0;
}
