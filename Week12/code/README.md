# MCMP117 — Week 12: Text Processing, Redirection & Pipes

**Code pack** · MCMP117 — Fundamentals of Operating Systems  
Istanbul Okan University · Vocational School · 2026–2027 Fall

## What is inside

| File | What it is |
|---|---|
| `mcmp117_lab_setup.sh` | creates the practice folder ~/lab (run once: `bash mcmp117_lab_setup.sh`) |
| `demo_analysis.sh` | MCMP117 Week 12: real analyses of logs/access.log, logs/system.log and data/students.csv |
| `demo_cut_tr_wc.sh` | MCMP117 Week 12: cut, tr and wc |
| `demo_find_xargs.sh` | MCMP117 Week 12: find, -exec and xargs |
| `demo_grep.sh` | MCMP117 Week 12: grep: search lines |
| `demo_head_tail_tee.sh` | MCMP117 Week 12: head and tail in pipelines, tee |
| `demo_mistakes.sh` | MCMP117 Week 12: common mistakes, made on purpose |
| `demo_pipes.sh` | MCMP117 Week 12: pipes: processes connected by a pipe |
| `demo_redirect.sh` | MCMP117 Week 12: output, input and error redirection |
| `demo_regex.sh` | MCMP117 Week 12: simple regular expressions with grep |
| `demo_sort_uniq.sh` | MCMP117 Week 12: sort and uniq |
| `demo_strace.sh` | MCMP117 Week 12: what the shell really does: strace shows write(), dup2() and pipe2() |
| `demo_streams.sh` | MCMP117 Week 12: the three standard streams (file descriptors 0, 1, 2) |
| `out_analysis.txt` | real output captured for the slides/notes (analysis); yours will differ in PIDs, dates, addresses |
| `out_cut_tr_wc.txt` | real output captured for the slides/notes (cut_tr_wc); yours will differ in PIDs, dates, addresses |
| `out_find_xargs.txt` | real output captured for the slides/notes (find_xargs); yours will differ in PIDs, dates, addresses |
| `out_grep.txt` | real output captured for the slides/notes (grep); yours will differ in PIDs, dates, addresses |
| `out_head_tail_tee.txt` | real output captured for the slides/notes (head_tail_tee); yours will differ in PIDs, dates, addresses |
| `out_mistakes.txt` | real output captured for the slides/notes (mistakes); yours will differ in PIDs, dates, addresses |
| `out_pipes.txt` | real output captured for the slides/notes (pipes); yours will differ in PIDs, dates, addresses |
| `out_redirect.txt` | real output captured for the slides/notes (redirect); yours will differ in PIDs, dates, addresses |
| `out_regex.txt` | real output captured for the slides/notes (regex); yours will differ in PIDs, dates, addresses |
| `out_sort_uniq.txt` | real output captured for the slides/notes (sort_uniq); yours will differ in PIDs, dates, addresses |
| `out_strace.txt` | real output captured for the slides/notes (strace); yours will differ in PIDs, dates, addresses |
| `out_streams.txt` | real output captured for the slides/notes (streams); yours will differ in PIDs, dates, addresses |

## Requirements

- A Linux terminal with bash (lab PCs, WSL: `wsl --install` in PowerShell, or an Ubuntu virtual machine).

## How to use it

This week works in the common practice folder `~/lab`. Create (or reset) it first — it is safe to run again; it only re-creates `~/lab`:

```bash
bash mcmp117_lab_setup.sh
cd ~/lab
```

The `demo_*.sh` files contain exactly the commands shown in class. Best: type them yourself one by one inside `~/lab` and compare with the matching `out_*.txt`. Files that start with `#!/bin/bash` can also be run as a whole: `cd ~/lab && bash /path/to/demo_name.sh`. Read each file's first lines for its own instructions.

The `out_*.txt` files are the real outputs shown on the slides. PIDs, dates, times, sizes, addresses and user names will differ on your machine; outputs were captured with `LC_ALL=C.UTF-8` (on a Turkish-locale system messages may be in Turkish and sort order may differ).

## Notes for this week

All analyses read `~/lab/logs` and `~/lab/data`, so run the setup script first.

## Windows users

Unzip the pack inside Linux, or copy it into your Linux home (WSL: `cp -r /mnt/c/Users/<you>/Downloads/<folder> ~/`). If a script fails with `bad interpreter` or `required file not found`, it was saved with Windows line endings — fix with `sed -i 's/\r$//' *.sh`. Make scripts executable with `chmod +x *.sh` if you want to run them as `./name.sh`.

## Slides and notes for this week

`Week12/` in the course repository: slides (`.pptx`, `.pdf`) and `notes/MCMP117_Week12_Notes.pdf`.

---
Prepared for MCMP117, Istanbul Okan University, Vocational School — 2026. For course use.

## About this folder in the repository

This `code/` folder holds the same files as the zip next to it, plus a few files that the lecture notes include (shortened `*_excerpt.c` copies shown on slides, generated LaTeX tables, and lab-sheet solution scripts with their outputs). For class work, download the zip.
