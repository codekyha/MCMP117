# Week 5 hands-on programs.  Type "make" to build all, "make clean" to tidy up.
CC     = gcc
CFLAGS = -Wall -O2 -pthread

all: race race_fixed prodcons cpu_hog

race: race.c
	$(CC) $(CFLAGS) race.c -o race

race_fixed: race_fixed.c
	$(CC) $(CFLAGS) race_fixed.c -o race_fixed

prodcons: prodcons.c
	$(CC) $(CFLAGS) prodcons.c -o prodcons

cpu_hog: cpu_hog.c
	$(CC) -Wall -O2 cpu_hog.c -o cpu_hog

# the scheduling numbers used on the slides
sched:
	python3 sched_check.py

clean:
	rm -f race race_fixed prodcons cpu_hog
