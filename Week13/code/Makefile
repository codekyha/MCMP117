# Week 13 examples:  make    then   ./zombie 20 &   and   ./catch &
CC = gcc
CFLAGS = -Wall -O2
PROGS = zombie catch

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(PROGS)
