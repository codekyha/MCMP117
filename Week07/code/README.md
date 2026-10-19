# MCMP117 — Week 7: Virtual Memory & File Systems

**Code pack** · MCMP117 — Fundamentals of Operating Systems  
Istanbul Okan University · Vocational School · 2026–2027 Fall

## What is inside

| File | What it is |
|---|---|
| `Makefile` | build all C programs: `make` (clean up: `make clean`) |
| `cow_fork.c` | copy-on-write after fork() (links to Week 3). |
| `file_access.c` | sequential vs direct (relative) access. |
| `page_faults.c` | watch demand paging happen. |
| `page_replacement.py` | simulate FIFO, OPT and LRU page replacement. |
| `links_demo.sh` | inodes, hard links and symbolic links. |
| `out_cow_fork.txt` | real output captured for the slides/notes (cow_fork); yours will differ in PIDs, dates, addresses |
| `out_file_access.txt` | real output captured for the slides/notes (file_access); yours will differ in PIDs, dates, addresses |
| `out_file_cmd.txt` | real output captured for the slides/notes (file_cmd); yours will differ in PIDs, dates, addresses |
| `out_links.txt` | real output captured for the slides/notes (links); yours will differ in PIDs, dates, addresses |
| `out_page_faults.txt` | real output captured for the slides/notes (page_faults); yours will differ in PIDs, dates, addresses |
| `out_page_replacement.txt` | real output captured for the slides/notes (page_replacement); yours will differ in PIDs, dates, addresses |
| `out_time_v.txt` | real output captured for the slides/notes (time_v); yours will differ in PIDs, dates, addresses |

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
gcc -Wall -O2 cow_fork.c -o cow_fork
gcc -Wall -O2 file_access.c -o file_access
gcc -Wall -O2 page_faults.c -o page_faults
./page_faults        or   /usr/bin/time -v ./page_faults
```

The `out_*.txt` files are the real outputs shown on the slides. PIDs, dates, times, sizes, addresses and user names will differ on your machine; outputs were captured with `LC_ALL=C.UTF-8` (on a Turkish-locale system messages may be in Turkish and sort order may differ).

## Notes for this week

`links_demo.sh` creates and removes files only in its own temporary folder.

## Windows users

Unzip the pack inside Linux, or copy it into your Linux home (WSL: `cp -r /mnt/c/Users/<you>/Downloads/<folder> ~/`). If a script fails with `bad interpreter` or `required file not found`, it was saved with Windows line endings — fix with `sed -i 's/\r$//' *.sh`. Make scripts executable with `chmod +x *.sh` if you want to run them as `./name.sh`.

## Slides and notes for this week

`Week07/` in the course repository: slides (`.pptx`, `.pdf`) and `notes/MCMP117_Week07_Notes.pdf`.

---
Prepared for MCMP117, Istanbul Okan University, Vocational School — 2026. For course use.

## About this folder in the repository

This `code/` folder holds the same files as the zip next to it, plus a few files that the lecture notes include (shortened `*_excerpt.c` copies shown on slides, generated LaTeX tables, and lab-sheet solution scripts with their outputs). For class work, download the zip.
