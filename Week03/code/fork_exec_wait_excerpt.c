int main(void)
{
    printf("parent: my PID is %d\n", getpid());
    fflush(stdout);            /* empty the buffer BEFORE fork */

    pid_t pid = fork();        /* one process calls, two return */

    if (pid == 0) {            /* ---- child: fork returned 0 */
        printf("child : PID %d, my parent is %d\n",
               getpid(), getppid());
        fflush(stdout);
        char list[32];         /* "parent,child" for ps -p */
        snprintf(list, sizeof list, "%d,%d", getppid(), getpid());
        execlp("ps", "ps", "-o", "pid,ppid,stat,comm",
               "-p", list, NULL);   /* replaces this program */
        exit(127);             /* reached only if exec failed */
    }
    int status;                /* ---- parent */
    waitpid(pid, &status, 0);  /* sleep until child ends */
    printf("parent: child %d finished, exit status %d\n",
           pid, WEXITSTATUS(status));
}
/* full program, with error checks: code/fork_exec_wait.c */
