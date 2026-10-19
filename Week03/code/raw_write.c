/* raw_write.c -- one message, three levels: library, wrapper, raw trap.
 * Shows how a system call is identified by a NUMBER and how its
 * parameters travel in CPU registers (x86-64 Linux only).
 * Compile:  gcc -Wall -O2 raw_write.c -o raw_write
 * Trace:    strace ./raw_write
 */
#include <stdio.h>    /* printf: C library (user mode) */
#include <unistd.h>   /* write : thin libc wrapper     */

int main(void)
{
    printf("1) printf  -> libc -> write\n");     /* level 1 */
    fflush(stdout);

    /* level 2 */
    if (write(1, "2) write() -> libc wrapper\n", 27) != 27)
        return 1;

    /* level 3: do what the wrapper does, by hand.
     *   rax = 1   system-call number of write (x86-64)
     *   rdi = 1   1st parameter: file descriptor (stdout)
     *   rsi = msg 2nd parameter: address of the bytes
     *   rdx = 26  3rd parameter: number of bytes
     * The 'syscall' instruction traps into the kernel; the
     * kernel's return value comes back in rax.         */
    static const char msg[] = "3) syscall instruction!!!\n";
    long ret;
    __asm__ volatile ("syscall"
                      : "=a"(ret)                /* out: rax */
                      : "a"(1L), "D"(1L), "S"(msg), "d"(26L)
                      : "rcx", "r11", "memory"); /* clobbered */
    printf("kernel returned %ld (bytes written)\n", ret);
    return 0;
}
