/* syscall_cost.c -- how expensive is a trip into the kernel?
 * We call a tiny ordinary function N times, then make a tiny
 * system call (getpid) N times, and compare the times.
 * Compile:  gcc -O2 syscall_cost.c -o syscall_cost
 * Run:      ./syscall_cost
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/syscall.h>

#define N 1000000L

/* noinline: stop the compiler from optimising the call away */
__attribute__((noinline)) long plain_function(long x)
{
    return x + 1;
}

static double seconds(void)
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec + t.tv_nsec / 1e9;
}

int main(void)
{
    volatile long sink = 0;   /* keeps results "used" */
    double t0, t1, t2;

    t0 = seconds();
    for (long i = 0; i < N; i++)
        sink += plain_function(i);          /* stays in user mode */
    t1 = seconds();
    for (long i = 0; i < N; i++)
        sink += syscall(SYS_getpid);        /* user -> kernel -> user */
    t2 = seconds();

    double f = (t1 - t0) / N * 1e9;         /* nanoseconds per call */
    double s = (t2 - t1) / N * 1e9;
    printf("ordinary function call : %6.1f ns\n", f);
    printf("system call (getpid)   : %6.1f ns\n", s);
    printf("system call is about %.0f times slower\n", s / f);
    return 0;
}
