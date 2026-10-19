# MCMP117 — Week 4: Threads & CPU Scheduling Basics

**Code pack** · MCMP117 — Fundamentals of Operating Systems  
Istanbul Okan University · Vocational School · 2026–2027 Fall

## What is inside

| File | What it is |
|---|---|
| `Makefile` | build all C programs: `make` (clean up: `make clean`) |
| `array_sum.c` | add up a big array using T threads. |
| `burst.c` | a CPU-bound and an I/O-bound program in one file. |
| `create_cost.c` | is a thread really cheaper than a process? |
| `thread_hello.c` | one process, several threads. |

## Requirements

- A Linux system (lab PCs, WSL on Windows 10/11, or an Ubuntu virtual machine) with `gcc` and `make` (Ubuntu: `sudo apt install build-essential`).

## How to use it

Build all C programs at once:

```bash
make
```

Or one by one (from each file's header):

```bash
gcc -Wall -O2 -pthread array_sum.c -o array_sum
./array_sum 1     ./array_sum 2     ./array_sum 4
gcc -Wall -O2 burst.c -o burst
gcc -Wall -O2 -pthread create_cost.c -o create_cost
./create_cost
gcc -Wall -O2 -pthread thread_hello.c -o thread_hello
./thread_hello
```

## Notes for this week

Thread programs need `-pthread` (the Makefile adds it). Timings differ from machine to machine.

## Windows users

Unzip the pack inside Linux, or copy it into your Linux home (WSL: `cp -r /mnt/c/Users/<you>/Downloads/<folder> ~/`). If a script fails with `bad interpreter` or `required file not found`, it was saved with Windows line endings — fix with `sed -i 's/\r$//' *.sh`. Make scripts executable with `chmod +x *.sh` if you want to run them as `./name.sh`.

## Slides and notes for this week

`Week04/` in the course repository: slides (`.pptx`, `.pdf`) and `notes/MCMP117_Week04_Notes.pdf`.

---
Prepared for MCMP117, Istanbul Okan University, Vocational School — 2026. For course use.

## About this folder in the repository

This `code/` folder holds the same files as the zip next to it, plus a few files that the lecture notes include (shortened `*_excerpt.c` copies shown on slides, generated LaTeX tables, and lab-sheet solution scripts with their outputs). For class work, download the zip.
