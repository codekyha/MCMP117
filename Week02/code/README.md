# MCMP117 — Week 2: Definitions, Goals, Components & OS Structures

**Code pack** · MCMP117 — Fundamentals of Operating Systems  
Istanbul Okan University · Vocational School · 2026–2027 Fall

## What is inside

| File | What it is |
|---|---|
| `Kbuild` | kernel-module build description (used by `make module`) |
| `Makefile` | build all C programs: `make` (clean up: `make clean`) |
| `hello_module.c` | a minimal Linux loadable kernel module (LKM). |
| `hello_syscall.c` | the same message printed in two ways. |
| `syscall_cost.c` | how expensive is a trip into the kernel? |

## Requirements

- A Linux system (lab PCs, WSL on Windows 10/11, or an Ubuntu virtual machine) with `gcc` and `make` (Ubuntu: `sudo apt install build-essential`).

## How to use it

Build all C programs at once:

```bash
make
```

Or one by one (from each file's header):

```bash
make                  (needs the kernel headers package)
sudo insmod hello_module.ko
lsmod | grep hello    and    sudo dmesg | tail -2
sudo rmmod hello_module
gcc hello_syscall.c -o hello_syscall
./hello_syscall
strace ./hello_syscall      (Linux only)
gcc -O2 syscall_cost.c -o syscall_cost
./syscall_cost
```

## Notes for this week

`hello_module.c` is a Linux kernel module: build it with `make module` and load it ONLY inside a virtual machine you are allowed to break. `syscall_cost` timings depend on your machine — the ratio is the lesson.

## Windows users

Unzip the pack inside Linux, or copy it into your Linux home (WSL: `cp -r /mnt/c/Users/<you>/Downloads/<folder> ~/`). If a script fails with `bad interpreter` or `required file not found`, it was saved with Windows line endings — fix with `sed -i 's/\r$//' *.sh`. Make scripts executable with `chmod +x *.sh` if you want to run them as `./name.sh`.

## Slides and notes for this week

`Week02/` in the course repository: slides (`.pptx`, `.pdf`) and `notes/MCMP117_Week02_Notes.pdf`.

---
Prepared for MCMP117, Istanbul Okan University, Vocational School — 2026. For course use.

## About this folder in the repository

This `code/` folder holds the same files as the zip next to it, plus a few files that the lecture notes include (shortened `*_excerpt.c` copies shown on slides, generated LaTeX tables, and lab-sheet solution scripts with their outputs). For class work, download the zip.
