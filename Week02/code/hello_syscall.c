/* hello_syscall.c -- the same message printed in two ways.
 * Compile:  gcc hello_syscall.c -o hello_syscall
 * Run:      ./hello_syscall
 * Trace:    strace ./hello_syscall      (Linux only)
 */
#include <stdio.h>    /* printf: library function (user mode)   */
#include <unistd.h>   /* write:  thin wrapper around a system call */

int main(void)
{
    /* 1) Library call: printf formats the text in user mode,
     *    then asks the kernel to output it via write().      */
    printf("Hello from printf!\n");
    fflush(stdout);

    /* 2) Direct system call: file descriptor 1 = the screen
     *    (standard output). 20 = number of bytes to write.   */
    write(1, "Hello from write()!\n", 20);

    return 0;
}
