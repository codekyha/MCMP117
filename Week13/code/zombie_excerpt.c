pid_t pid = fork();                /* one process becomes two */

if (pid == 0) {                    /* ---- child ---- */
    printf("child  %d: exiting now with status 7\n", getpid());
    exit(7);                       /* terminated -> zombie until reaped */
}
/* ---- parent: does NOT wait() for secs seconds ---- */
printf("parent %d: child is %d, sleeping %d s without wait()\n",
       getpid(), pid, secs);
sleep(secs);                       /* meanwhile the child is a zombie */

waitpid(pid, &status, 0);          /* collect the exit status: reap */
printf("parent %d: reaped child %d, exit status %d\n",
       getpid(), pid, WEXITSTATUS(status));
