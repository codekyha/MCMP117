# MCMP117 — Week 5: CPU Scheduling Algorithms & Process Synchronization

**Code pack** · MCMP117 — Fundamentals of Operating Systems  
Istanbul Okan University · Vocational School · 2026–2027 Fall

## What is inside

| File | What it is |
|---|---|
| `Makefile` | build all C programs: `make` (clean up: `make clean`) |
| `cpu_hog.c` | a program that only burns CPU time (a pure "CPU burst"). |
| `prodcons.c` | bounded-buffer producer-consumer with POSIX semaphores. |
| `race.c` | two threads increment ONE shared counter, with NO lock. |
| `race_fixed.c` | the same program, but the increment is a CRITICAL SECTION protected by a mutex lock. |
| `sched_check.py` | a tiny CPU-scheduling simulator for Week 5. |
| `sched_results.json` | results computed by the checker script (used by the slides) |
| `nice_output.txt` | real output captured for the slides/notes (nice_output); yours will differ in PIDs, dates, addresses |
| `run_output.txt` | real output captured for the slides/notes (run_output); yours will differ in PIDs, dates, addresses |

## Requirements

- A Linux system (lab PCs, WSL on Windows 10/11, or an Ubuntu virtual machine) with `gcc` and `make` (Ubuntu: `sudo apt install build-essential`).
- Python 3 for the `.py` files (already installed on Ubuntu/WSL): `python3 file.py`.

## How to use it

Build all C programs at once:

```bash
make
```

Or one by one (from each file's header):

```bash
gcc -Wall -O2 cpu_hog.c -o cpu_hog
gcc -Wall -O2 -pthread prodcons.c -o prodcons
./prodcons
gcc -Wall -O2 -pthread race.c -o race
./race
gcc -Wall -O2 -pthread race_fixed.c -o race_fixed
./race_fixed
```

The `out_*.txt` files are the real outputs shown on the slides. PIDs, dates, times, sizes, addresses and user names will differ on your machine; outputs were captured with `LC_ALL=C.UTF-8` (on a Turkish-locale system messages may be in Turkish and sort order may differ).

## Notes for this week

`race` gives a different (wrong) result each run — that is the point. `cpu_hog` runs until you stop it: `pkill cpu_hog`.

## Windows users

Unzip the pack inside Linux, or copy it into your Linux home (WSL: `cp -r /mnt/c/Users/<you>/Downloads/<folder> ~/`). If a script fails with `bad interpreter` or `required file not found`, it was saved with Windows line endings — fix with `sed -i 's/\r$//' *.sh`. Make scripts executable with `chmod +x *.sh` if you want to run them as `./name.sh`.

## Slides and notes for this week

`Week05/` in the course repository: slides (`.pptx`, `.pdf`) and `notes/MCMP117_Week05_Notes.pdf`.

---
Prepared for MCMP117, Istanbul Okan University, Vocational School — 2026. For course use.

## About this folder in the repository

This `code/` folder holds the same files as the zip next to it, plus a few files that the lecture notes include (shortened `*_excerpt.c` copies shown on slides, generated LaTeX tables, and lab-sheet solution scripts with their outputs). For class work, download the zip.
