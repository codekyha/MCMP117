/* fork_count.c -- how many processes do n calls to fork() create?
 * Every existing process executes each fork(), so the number of
 * processes doubles at every step: 1 -> 2 -> 4 -> ... -> 2^n.
 * Compile:  gcc -Wall -O2 fork_count.c -o fork_count
 * Run:      ./fork_count 3            (each process prints one line)
 *           ./fork_count 5 | wc -l    (count the lines: 32)
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int n = (argc > 1) ? atoi(argv[1]) : 3;
    if (n < 0 || n > 10) n = 3;   /* stay polite: at most 1024 */

    for (int i = 0; i < n; i++)
        fork();                   /* parent AND child continue */

    printf("PID %6d  parent %6d\n", getpid(), getppid());
    fflush(stdout);

    while (wait(NULL) > 0)        /* reap all my children,    */
        ;                         /* so none becomes a zombie */
    return 0;
}
