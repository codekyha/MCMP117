/* burst.c -- a CPU-bound and an I/O-bound program in one file.
 *   ./burst cpu : one long CPU burst (pure arithmetic, no I/O)
 *   ./burst io  : 1000 short CPU bursts, each followed by an I/O wait
 *                 (write 4 KB to a file, then fsync = "wait until it
 *                 is really on the disk")
 * Compile:  gcc -Wall -O2 burst.c -o burst
 * Measure:  time ./burst cpu      time ./burst io
 */
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

static void cpu_bound(void)
{
    volatile double x = 0;                 /* volatile: keep the loop */
    for (long i = 1; i <= 400000000L; i++)
        x += 1.0 / i;                      /* only CPU work */
    printf("cpu: harmonic sum = %.6f\n", x);
}

static void io_bound(void)
{
    char buf[4096];
    memset(buf, 'x', sizeof buf);
    int fd = open("burst.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) { perror("open"); return; }
    for (int i = 0; i < 1000; i++) {
        buf[0] = 'A' + i % 26;             /* tiny CPU burst ...      */
        if (write(fd, buf, sizeof buf) < 0) /* ... then an I/O request */
            perror("write");
        fsync(fd);                         /* block until on the disk */
    }
    close(fd);
    unlink("burst.tmp");
    printf("io: wrote 1000 blocks of 4 KB, each followed by fsync\n");
}

int main(int argc, char *argv[])
{
    if (argc > 1 && strcmp(argv[1], "io") == 0)
        io_bound();
    else
        cpu_bound();
    return 0;
}
