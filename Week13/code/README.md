# MCMP117 — Week 13: Processes & Job Control

**Code pack** · MCMP117 — Fundamentals of Operating Systems  
Istanbul Okan University · Vocational School · 2026–2027 Fall

## What is inside

| File | What it is |
|---|---|
| `Makefile` | build all C programs: `make` (clean up: `make clean`) |
| `mcmp117_lab_setup.sh` | creates the practice folder ~/lab (run once: `bash mcmp117_lab_setup.sh`) |
| `catch.c` | a process that handles some signals itself. |
| `zombie.c` | make a zombie process on purpose (links to Week 3). |
| `check_numbers.py` | verifies every number quoted on the Week 13 slides/notes. |
| `demo_catch.sh` | Week 13: a program that catches SIGINT and SIGTERM. |
| `demo_jobs.sh` | Week 13: foreground, background and job control. |
| `demo_nice.sh` | Week 13: nice and renice (links to Week 5 priority scheduling). |
| `demo_nohup.sh` | Week 13: $$, $!, SIGHUP and nohup. |
| `demo_proc.sh` | Week 13: the PCB through /proc (links to Week 3). |
| `demo_ps.sh` | Week 13: looking at processes with ps and pstree. |
| `demo_signals.sh` | Week 13: sending signals with kill, pkill and killall. |
| `demo_top.sh` | Week 13: one snapshot of top (batch mode, -b -n 1). |
| `demo_zombie.sh` | Week 13: seeing process state Z (links to Week 3). |
| `out_catch.txt` | real output captured for the slides/notes (catch); yours will differ in PIDs, dates, addresses |
| `out_check_numbers.txt` | real output captured for the slides/notes (check_numbers); yours will differ in PIDs, dates, addresses |
| `out_jobs.txt` | real output captured for the slides/notes (jobs); yours will differ in PIDs, dates, addresses |
| `out_nice.txt` | real output captured for the slides/notes (nice); yours will differ in PIDs, dates, addresses |
| `out_nohup.txt` | real output captured for the slides/notes (nohup); yours will differ in PIDs, dates, addresses |
| `out_proc.txt` | real output captured for the slides/notes (proc); yours will differ in PIDs, dates, addresses |
| `out_ps.txt` | real output captured for the slides/notes (ps); yours will differ in PIDs, dates, addresses |
| `out_signals.txt` | real output captured for the slides/notes (signals); yours will differ in PIDs, dates, addresses |
| `out_top.txt` | real output captured for the slides/notes (top); yours will differ in PIDs, dates, addresses |
| `out_zombie.txt` | real output captured for the slides/notes (zombie); yours will differ in PIDs, dates, addresses |

## Requirements

- A Linux system (lab PCs, WSL on Windows 10/11, or an Ubuntu virtual machine) with `gcc` and `make` (Ubuntu: `sudo apt install build-essential`).
- A Linux terminal with bash (lab PCs, WSL: `wsl --install` in PowerShell, or an Ubuntu virtual machine).
- Python 3 for the `.py` files (already installed on Ubuntu/WSL): `python3 file.py`.

## How to use it

This week works in the common practice folder `~/lab`. Create (or reset) it first — it is safe to run again; it only re-creates `~/lab`:

```bash
bash mcmp117_lab_setup.sh
cd ~/lab
```

The `demo_*.sh` files contain exactly the commands shown in class. Best: type them yourself one by one inside `~/lab` and compare with the matching `out_*.txt`. Files that start with `#!/bin/bash` can also be run as a whole: `cd ~/lab && bash /path/to/demo_name.sh`. Read each file's first lines for its own instructions.

Build all C programs at once:

```bash
make
```

Or one by one (from each file's header):

```bash
gcc -Wall -O2 catch.c -o catch
./catch &    then   kill -INT %1 ; kill %1    (or kill -9 %1)
gcc -Wall -O2 zombie.c -o zombie
./zombie 20 &      then   ps -o pid,ppid,stat,cmd
```

The `out_*.txt` files are the real outputs shown on the slides. PIDs, dates, times, sizes, addresses and user names will differ on your machine; outputs were captured with `LC_ALL=C.UTF-8` (on a Turkish-locale system messages may be in Turkish and sort order may differ).

## Notes for this week

Job-control demos must be typed in an interactive terminal; `#@key C-z` in a file means "press Ctrl+Z". Use `kill -9` only as a last resort. `./zombie` leaves a zombie for a few seconds on purpose.

## Windows users

Unzip the pack inside Linux, or copy it into your Linux home (WSL: `cp -r /mnt/c/Users/<you>/Downloads/<folder> ~/`). If a script fails with `bad interpreter` or `required file not found`, it was saved with Windows line endings — fix with `sed -i 's/\r$//' *.sh`. Make scripts executable with `chmod +x *.sh` if you want to run them as `./name.sh`.

## Slides and notes for this week

`Week13/` in the course repository: slides (`.pptx`, `.pdf`) and `notes/MCMP117_Week13_Notes.pdf`.

---
Prepared for MCMP117, Istanbul Okan University, Vocational School — 2026. For course use.

## About this folder in the repository

This `code/` folder holds the same files as the zip next to it, plus a few files that the lecture notes include (shortened `*_excerpt.c` copies shown on slides, generated LaTeX tables, and lab-sheet solution scripts with their outputs). For class work, download the zip.
