# MCMP117 — Week 3: OS Services, System Calls & Processes

**Code pack** · MCMP117 — Fundamentals of Operating Systems  
Istanbul Okan University · Vocational School · 2026–2027 Fall

## What is inside

| File | What it is |
|---|---|
| `Makefile` | build all C programs: `make` (clean up: `make clean`) |
| `fork_count.c` | how many processes do n calls to fork() create? |
| `fork_exec_wait.c` | the three system calls that create every program you run from a shell: fork(), exec(), wait(). |
| `mem_layout.c` | where do the parts of a process live in memory? |
| `raw_write.c` | one message, three levels: library, wrapper, raw trap. |

## Requirements

- A Linux system (lab PCs, WSL on Windows 10/11, or an Ubuntu virtual machine) with `gcc` and `make` (Ubuntu: `sudo apt install build-essential`).

## How to use it

Build all C programs at once:

```bash
make
```

Or one by one (from each file's header):

```bash
gcc -Wall -O2 fork_count.c -o fork_count
./fork_count 3            (each process prints one line)
gcc -Wall -O2 fork_exec_wait.c -o fork_exec_wait
./fork_exec_wait
gcc -Wall -O2 mem_layout.c -o mem_layout
./mem_layout
gcc -Wall -O2 raw_write.c -o raw_write
strace ./raw_write
```

## Notes for this week

`raw_write.c` uses x86-64 Linux system-call numbers; it will not build on ARM machines (e.g. some laptops/Raspberry Pi). `fork_count` creates many processes on purpose — keep n small.

## Windows users

Unzip the pack inside Linux, or copy it into your Linux home (WSL: `cp -r /mnt/c/Users/<you>/Downloads/<folder> ~/`). If a script fails with `bad interpreter` or `required file not found`, it was saved with Windows line endings — fix with `sed -i 's/\r$//' *.sh`. Make scripts executable with `chmod +x *.sh` if you want to run them as `./name.sh`.

## Slides and notes for this week

`Week03/` in the course repository: slides (`.pptx`, `.pdf`) and `notes/MCMP117_Week03_Notes.pdf`.

---
Prepared for MCMP117, Istanbul Okan University, Vocational School — 2026. For course use.

## About this folder in the repository

This `code/` folder holds the same files as the zip next to it, plus a few files that the lecture notes include (shortened `*_excerpt.c` copies shown on slides, generated LaTeX tables, and lab-sheet solution scripts with their outputs). For class work, download the zip.
