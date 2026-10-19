static volatile sig_atomic_t got = 0;
static void handler(int sig) { got = sig; }  /* tiny! */

sa.sa_handler = handler;
sigaction(SIGINT,  &sa, NULL);   /* Ctrl+C, 2: caught */
sigaction(SIGTERM, &sa, NULL);   /* kill,  15: caught */
if (sigaction(SIGKILL, &sa, NULL) < 0)  /* 9: refused */
    perror("catch: sigaction(SIGKILL)");

for (;;) {
    pause();                     /* sleep until a signal */
    if (got == SIGINT)
        printf("... ignoring it, still running\n");
    if (got == SIGTERM) {
        printf("... cleaning up, bye\n");
        return 0;
    }
}
