# Week 4 programs.  Type "make" to build all of them.
CC     = gcc
CFLAGS = -Wall -O2 -pthread
PROGS  = thread_hello array_sum burst create_cost

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(PROGS) burst.tmp
