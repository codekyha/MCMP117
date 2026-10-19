# Week 2 programs.  make  -> builds hello_syscall and syscall_cost
#                  make module -> builds the kernel module (needs the kernel headers;
#                  try it ONLY inside a virtual machine), make clean -> tidy up
CC     = gcc
CFLAGS = -Wall -O2
PROGS  = hello_syscall syscall_cost

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

module:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	rm -f $(PROGS)
	-$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean 2>/dev/null
