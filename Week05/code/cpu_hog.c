/* cpu_hog.c -- a program that only burns CPU time (a pure "CPU burst").
 * Used to watch the Linux scheduler share ONE CPU between two hogs
 * with different nice values.
 * Compile:  gcc -Wall -O2 cpu_hog.c -o cpu_hog
 * Run (two hogs on CPU 1, one of them "nicer"):
 *   taskset -c 1 ./cpu_hog &
 *   taskset -c 1 nice -n 10 ./cpu_hog &
 *   sleep 10; ps -o pid,ni,cls,pcpu,comm -C cpu_hog; pkill cpu_hog
 */
int main(void)
{
    volatile unsigned long x = 0;   /* volatile: keep the loop alive */
    for (;;)
        x++;                        /* never blocks, never ends */
}
