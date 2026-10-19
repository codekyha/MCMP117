/* mem_layout.c -- where do the parts of a process live in memory?
 * Prints one address from each region of the process image.
 * Compile:  gcc -Wall -O2 mem_layout.c -o mem_layout
 * Run:      ./mem_layout   (run it twice: the addresses move,
 *                           because Linux randomises them: ASLR)
 */
#include <stdio.h>
#include <stdlib.h>

int initialised = 42;   /* global with a value    -> data */
int uninitialised;      /* global without a value -> bss  */

int main(void)
{
    int local = 7;                   /* local variable -> stack */
    int *dynamic = malloc(sizeof *dynamic);     /* malloc -> heap */

    printf("text  main()        %p\n", (void *)main);
    printf("data  initialised   %p\n", (void *)&initialised);
    printf("bss   uninitialised %p\n", (void *)&uninitialised);
    printf("heap  *dynamic      %p\n", (void *)dynamic);
    printf("stack local         %p\n", (void *)&local);

    free(dynamic);
    return 0;
}
