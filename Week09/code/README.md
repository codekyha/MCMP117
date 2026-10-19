# MCMP117 — Week 9: Linux Shell Basics & Filesystem Navigation

**Code pack** · MCMP117 — Fundamentals of Operating Systems  
Istanbul Okan University · Vocational School · 2026–2027 Fall

## What is inside

| File | What it is |
|---|---|
| `mcmp117_lab_setup.sh` | creates the practice folder ~/lab (run once: `bash mcmp117_lab_setup.sh`) |
| `check_numbers.py` | Week 9: verifies the numbers quoted on the slides and in the notes. |
| `demo_cd.sh` | Week 9: moving around with cd (absolute and relative paths, ~ . .. -) |
| `demo_errors.sh` | Week 9: common error messages and what they mean cd ~/lab LS sl |
| `demo_fhs.sh` | Week 9: a tour of the Linux directory tree (FHS) |
| `demo_first.sh` | Week 9: first commands Type these lines one by one in a terminal (or run: bash demo_first.sh). |
| `demo_help.sh` | Week 9: getting help (--help, help, type) |
| `demo_keys.sh` | Week 9: tab completion and history TYPE THESE BY HAND: "\t" means "press the Tab key". (History expansion with ! works only when you type commands, not inside a script.) |
| `demo_ls.sh` | Week 9: where am I, and what is here? (pwd, ls and its options) |
| `demo_setup.sh` | Week 9: running the lab setup script (once per computer) |
| `demo_syscalls.sh` | Week 9: commands become system calls (link to Weeks 2 and 3) |
| `demo_tree.sh` | Week 9: looking at a whole subtree (ls -R, tree, ls -d) |
| `out_cd.txt` | real output captured for the slides/notes (cd); yours will differ in PIDs, dates, addresses |
| `out_check_numbers.txt` | real output captured for the slides/notes (check_numbers); yours will differ in PIDs, dates, addresses |
| `out_errors.txt` | real output captured for the slides/notes (errors); yours will differ in PIDs, dates, addresses |
| `out_fhs.txt` | real output captured for the slides/notes (fhs); yours will differ in PIDs, dates, addresses |
| `out_first.txt` | real output captured for the slides/notes (first); yours will differ in PIDs, dates, addresses |
| `out_help.txt` | real output captured for the slides/notes (help); yours will differ in PIDs, dates, addresses |
| `out_keys.txt` | real output captured for the slides/notes (keys); yours will differ in PIDs, dates, addresses |
| `out_ls.txt` | real output captured for the slides/notes (ls); yours will differ in PIDs, dates, addresses |
| `out_setup.txt` | real output captured for the slides/notes (setup); yours will differ in PIDs, dates, addresses |
| `out_syscalls.txt` | real output captured for the slides/notes (syscalls); yours will differ in PIDs, dates, addresses |
| `out_tree.txt` | real output captured for the slides/notes (tree); yours will differ in PIDs, dates, addresses |

## Requirements

- A Linux terminal with bash (lab PCs, WSL: `wsl --install` in PowerShell, or an Ubuntu virtual machine).
- Python 3 for the `.py` files (already installed on Ubuntu/WSL): `python3 file.py`.

## How to use it

This week works in the common practice folder `~/lab`. Create (or reset) it first — it is safe to run again; it only re-creates `~/lab`:

```bash
bash mcmp117_lab_setup.sh
cd ~/lab
```

The `demo_*.sh` files contain exactly the commands shown in class. Best: type them yourself one by one inside `~/lab` and compare with the matching `out_*.txt`. Files that start with `#!/bin/bash` can also be run as a whole: `cd ~/lab && bash /path/to/demo_name.sh`. Read each file's first lines for its own instructions.

The `out_*.txt` files are the real outputs shown on the slides. PIDs, dates, times, sizes, addresses and user names will differ on your machine; outputs were captured with `LC_ALL=C.UTF-8` (on a Turkish-locale system messages may be in Turkish and sort order may differ).

## Notes for this week

No compiling this week. Try the Lab Sheet exercises yourself before looking at any solution.

## Windows users

Unzip the pack inside Linux, or copy it into your Linux home (WSL: `cp -r /mnt/c/Users/<you>/Downloads/<folder> ~/`). If a script fails with `bad interpreter` or `required file not found`, it was saved with Windows line endings — fix with `sed -i 's/\r$//' *.sh`. Make scripts executable with `chmod +x *.sh` if you want to run them as `./name.sh`.

## Slides and notes for this week

`Week09/` in the course repository: slides (`.pptx`, `.pdf`) and `notes/MCMP117_Week09_Notes.pdf`.

---
Prepared for MCMP117, Istanbul Okan University, Vocational School — 2026. For course use.

## About this folder in the repository

This `code/` folder holds the same files as the zip next to it, plus a few files that the lecture notes include (shortened `*_excerpt.c` copies shown on slides, generated LaTeX tables, and lab-sheet solution scripts with their outputs). For class work, download the zip.
