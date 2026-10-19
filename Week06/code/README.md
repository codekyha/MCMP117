# MCMP117 — Week 6: Memory Management, Paging & Segmentation

**Code pack** · MCMP117 — Fundamentals of Operating Systems  
Istanbul Okan University · Vocational School · 2026–2027 Fall

## What is inside

| File | What it is |
|---|---|
| `Makefile` | build all C programs: `make` (clean up: `make clean`) |
| `fork_vaddr.c` | same virtual address, different values. |
| `mem_layout.c` | where do code, globals, heap and stack live? |
| `page_split.c` | split an address into page number p and offset d. |
| `fit.py` | first-fit, best-fit and worst-fit on one shared example. |
| `verify.py` | checks every number used in the Week 6 slides and notes. |
| `out_fit.txt` | real output captured for the slides/notes (fit); yours will differ in PIDs, dates, addresses |
| `out_fork_vaddr.txt` | real output captured for the slides/notes (fork_vaddr); yours will differ in PIDs, dates, addresses |
| `out_mem_layout.txt` | real output captured for the slides/notes (mem_layout); yours will differ in PIDs, dates, addresses |
| `out_page_split.txt` | real output captured for the slides/notes (page_split); yours will differ in PIDs, dates, addresses |
| `out_shell.txt` | real output captured for the slides/notes (shell); yours will differ in PIDs, dates, addresses |
| `out_verify.txt` | real output captured for the slides/notes (verify); yours will differ in PIDs, dates, addresses |

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
gcc -Wall -O2 fork_vaddr.c -o fork_vaddr
gcc -Wall -O2 mem_layout.c -o mem_layout
./mem_layout
gcc -Wall -O2 page_split.c -o page_split
./page_split 0x3A7F 0x1234 0x5000
```

The `out_*.txt` files are the real outputs shown on the slides. PIDs, dates, times, sizes, addresses and user names will differ on your machine; outputs were captured with `LC_ALL=C.UTF-8` (on a Turkish-locale system messages may be in Turkish and sort order may differ).

## Notes for this week

Addresses change on every run (address-space layout randomization).

## Windows users

Unzip the pack inside Linux, or copy it into your Linux home (WSL: `cp -r /mnt/c/Users/<you>/Downloads/<folder> ~/`). If a script fails with `bad interpreter` or `required file not found`, it was saved with Windows line endings — fix with `sed -i 's/\r$//' *.sh`. Make scripts executable with `chmod +x *.sh` if you want to run them as `./name.sh`.

## Slides and notes for this week

`Week06/` in the course repository: slides (`.pptx`, `.pdf`) and `notes/MCMP117_Week06_Notes.pdf`.

---
Prepared for MCMP117, Istanbul Okan University, Vocational School — 2026. For course use.

## About this folder in the repository

This `code/` folder holds the same files as the zip next to it, plus a few files that the lecture notes include (shortened `*_excerpt.c` copies shown on slides, generated LaTeX tables, and lab-sheet solution scripts with their outputs). For class work, download the zip.
