# MCMP117 — Week 15: Final Exam Review & Practice

**Code pack** · MCMP117 — Fundamentals of Operating Systems  
Istanbul Okan University · Vocational School · 2026–2027 Fall

## What is inside

| File | What it is |
|---|---|
| `mcmp117_lab_setup.sh` | creates the practice folder ~/lab (run once: `bash mcmp117_lab_setup.sh`) |
| `answers_practice.sh` | verifies every command/pipeline/script answer of the Practice Final in the Week 15 study guide (Parts D, E, F). |
| `count_lines.sh` | print the number of lines of every regular file in a directory |
| `demo_lib.sh` | tiny helpers sourced by the Week 15 demo/answer scripts. |
| `demo_recap.sh` | the practical recap of Weeks 9-14 (slides + study guide). |
| `demo_worked.sh` | worked practical problems 5-7 of the Week 15 slides. |
| `dept_stats.sh` | number of students and average final grade of ONE department |
| `passfail.sh` | how many students reached a given final-exam grade |
| `out_pf_d1.txt` | real output captured for the slides/notes (pf_d1); yours will differ in PIDs, dates, addresses |
| `out_pf_d2.txt` | real output captured for the slides/notes (pf_d2); yours will differ in PIDs, dates, addresses |
| `out_pf_d3.txt` | real output captured for the slides/notes (pf_d3); yours will differ in PIDs, dates, addresses |
| `out_pf_d4.txt` | real output captured for the slides/notes (pf_d4); yours will differ in PIDs, dates, addresses |
| `out_pf_d5.txt` | real output captured for the slides/notes (pf_d5); yours will differ in PIDs, dates, addresses |
| `out_pf_d6.txt` | real output captured for the slides/notes (pf_d6); yours will differ in PIDs, dates, addresses |
| `out_pf_d7.txt` | real output captured for the slides/notes (pf_d7); yours will differ in PIDs, dates, addresses |
| `out_pf_e1.txt` | real output captured for the slides/notes (pf_e1); yours will differ in PIDs, dates, addresses |
| `out_pf_e2.txt` | real output captured for the slides/notes (pf_e2); yours will differ in PIDs, dates, addresses |
| `out_pf_e3.txt` | real output captured for the slides/notes (pf_e3); yours will differ in PIDs, dates, addresses |
| `out_pf_f_run.txt` | real output captured for the slides/notes (pf_f_run); yours will differ in PIDs, dates, addresses |
| `out_pf_f_src.txt` | real output captured for the slides/notes (pf_f_src); yours will differ in PIDs, dates, addresses |
| `out_w09.txt` | real output captured for the slides/notes (w09); yours will differ in PIDs, dates, addresses |
| `out_w10.txt` | real output captured for the slides/notes (w10); yours will differ in PIDs, dates, addresses |
| `out_w11.txt` | real output captured for the slides/notes (w11); yours will differ in PIDs, dates, addresses |
| `out_w12.txt` | real output captured for the slides/notes (w12); yours will differ in PIDs, dates, addresses |
| `out_w13.txt` | real output captured for the slides/notes (w13); yours will differ in PIDs, dates, addresses |
| `out_w14.txt` | real output captured for the slides/notes (w14); yours will differ in PIDs, dates, addresses |
| `out_wp_perm.txt` | real output captured for the slides/notes (wp_perm); yours will differ in PIDs, dates, addresses |
| `out_wp_pipe.txt` | real output captured for the slides/notes (wp_pipe); yours will differ in PIDs, dates, addresses |
| `out_wp_script_run.txt` | real output captured for the slides/notes (wp_script_run); yours will differ in PIDs, dates, addresses |
| `out_wp_script_src.txt` | real output captured for the slides/notes (wp_script_src); yours will differ in PIDs, dates, addresses |

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

Practice-final answers are in `answers_practice.sh` and the `out_pf_*.txt` files — try the Practice Final in the study guide first.

## Windows users

Unzip the pack inside Linux, or copy it into your Linux home (WSL: `cp -r /mnt/c/Users/<you>/Downloads/<folder> ~/`). If a script fails with `bad interpreter` or `required file not found`, it was saved with Windows line endings — fix with `sed -i 's/\r$//' *.sh`. Make scripts executable with `chmod +x *.sh` if you want to run them as `./name.sh`.

## Slides and notes for this week

`Week15/` in the course repository: slides (`.pptx`, `.pdf`) and `notes/MCMP117_Week15_Notes.pdf`.

---
Prepared for MCMP117, Istanbul Okan University, Vocational School — 2026. For course use.

## About this folder in the repository

This `code/` folder holds the same files as the zip next to it, plus a few files that the lecture notes include (shortened `*_excerpt.c` copies shown on slides, generated LaTeX tables, and lab-sheet solution scripts with their outputs). For class work, download the zip.
