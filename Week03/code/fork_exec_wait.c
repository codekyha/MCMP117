/* fork_exec_wait.c -- the three system calls that create every
 * program you run from a shell: fork(), exec(), wait().
 * Compile:  gcc -Wall -O2 fork_exec_wait.c -o fork_exec_wait
 * Run:      ./fork_exec_wait
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>      /* fork, execlp, getpid, getppid */
#include <sys/wait.h>    /* waitpid, WEXITSTATUS          */

int main(void)
{
    printf("parent: my PID is %d\n", getpid());
    fflush(stdout);              /* empty the buffer BEFORE fork */

    pid_t pid = fork();          /* one process calls, two return */

    if (pid < 0) {               /* fork failed */
        perror("fork");
        return 1;
    }
    if (pid == 0) {              /* ---- child: fork returned 0 */
        printf("child : PID %d, my parent is %d\n",
               getpid(), getppid());
        fflush(stdout);
        /* replace this program by ps, listing just the
         * parent and the child (= itself!)                   */
        char list[32];
        snprintf(list, sizeof list, "%d,%d", getppid(), getpid());
        execlp("ps", "ps", "-o", "pid,ppid,stat,comm",
               "-p", list, NULL);
        perror("execlp");        /* reached only if exec failed */
        exit(127);
    }
    /* ---- parent: fork returned the child's PID */
    int status;
    waitpid(pid, &status, 0);    /* sleep until child ends */
    printf("parent: child %d finished, exit status %d\n",
           pid, WEXITSTATUS(status));
    return 0;
}
