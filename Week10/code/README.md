# MCMP117 — Week 10: File & Directory Operations

**Code pack** · MCMP117 — Fundamentals of Operating Systems  
Istanbul Okan University · Vocational School · 2026–2027 Fall

## What is inside

| File | What it is |
|---|---|
| `Makefile` | build all C programs: `make` (clean up: `make clean`) |
| `mcmp117_lab_setup.sh` | creates the practice folder ~/lab (run once: `bash mcmp117_lab_setup.sh`) |
| `fileops.c` | Week 10: the system calls behind mkdir, touch, ln, ln -s, mv, rm, rmdir. |
| `demo_cp_mv.sh` | Week 10: copying, moving and renaming. |
| `demo_fileops.sh` | Week 10: compile and run fileops.c (the system calls behind the commands). |
| `demo_links.sh` | Week 10: hard and symbolic links, cp vs mv vs ln (recap of Week 7). |
| `demo_mkdir_touch.sh` | Week 10: creating directories and files, timestamps. |
| `demo_quoting.sh` | Week 10: file names that contain spaces. |
| `demo_rm.sh` | Week 10: deleting files and directories. There is NO recycle bin! |
| `demo_stat_du_df.sh` | Week 10: metadata (stat, link to Week 7 inodes) and disk usage. |
| `demo_strace.sh` | Week 10: which system call does each command use? (link to Weeks 2, 3 and 7) |
| `demo_view.sh` | Week 10: looking inside files: cat, head, tail, wc, file. |
| `demo_wildcards.sh` | Week 10: wildcards (globbing) and brace expansion. |
| `out_cp_mv.txt` | real output captured for the slides/notes (cp_mv); yours will differ in PIDs, dates, addresses |
| `out_fileops.txt` | real output captured for the slides/notes (fileops); yours will differ in PIDs, dates, addresses |
| `out_links.txt` | real output captured for the slides/notes (links); yours will differ in PIDs, dates, addresses |
| `out_mkdir_touch.txt` | real output captured for the slides/notes (mkdir_touch); yours will differ in PIDs, dates, addresses |
| `out_quoting.txt` | real output captured for the slides/notes (quoting); yours will differ in PIDs, dates, addresses |
| `out_rm.txt` | real output captured for the slides/notes (rm); yours will differ in PIDs, dates, addresses |
| `out_stat_du_df.txt` | real output captured for the slides/notes (stat_du_df); yours will differ in PIDs, dates, addresses |
| `out_strace.txt` | real output captured for the slides/notes (strace); yours will differ in PIDs, dates, addresses |
| `out_view.txt` | real output captured for the slides/notes (view); yours will differ in PIDs, dates, addresses |
| `out_wildcards.txt` | real output captured for the slides/notes (wildcards); yours will differ in PIDs, dates, addresses |

## Requirements

- A Linux system (lab PCs, WSL on Windows 10/11, or an Ubuntu virtual machine) with `gcc` and `make` (Ubuntu: `sudo apt install build-essential`).
- A Linux terminal with bash (lab PCs, WSL: `wsl --install` in PowerShell, or an Ubuntu virtual machine).

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
gcc -Wall -O2 fileops.c -o fileops      Run it inside ~/lab:  ./fileops
```

The `out_*.txt` files are the real outputs shown on the slides. PIDs, dates, times, sizes, addresses and user names will differ on your machine; outputs were captured with `LC_ALL=C.UTF-8` (on a Turkish-locale system messages may be in Turkish and sort order may differ).

## Notes for this week

`rm` has no recycle bin: work only inside `~/lab` (you can always re-create it with the setup script).

## Windows users

Unzip the pack inside Linux, or copy it into your Linux home (WSL: `cp -r /mnt/c/Users/<you>/Downloads/<folder> ~/`). If a script fails with `bad interpreter` or `required file not found`, it was saved with Windows line endings — fix with `sed -i 's/\r$//' *.sh`. Make scripts executable with `chmod +x *.sh` if you want to run them as `./name.sh`.

## Slides and notes for this week

`Week10/` in the course repository: slides (`.pptx`, `.pdf`) and `notes/MCMP117_Week10_Notes.pdf`.

---
Prepared for MCMP117, Istanbul Okan University, Vocational School — 2026. For course use.

## About this folder in the repository

This `code/` folder holds the same files as the zip next to it, plus a few files that the lecture notes include (shortened `*_excerpt.c` copies shown on slides, generated LaTeX tables, and lab-sheet solution scripts with their outputs). For class work, download the zip.
