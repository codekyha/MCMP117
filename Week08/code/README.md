# MCMP117 — Week 8: Midterm Review & Practice

**Code pack** · MCMP117 — Fundamentals of Operating Systems  
Istanbul Okan University · Vocational School · 2026–2027 Fall

## What is inside

| File | What it is |
|---|---|
| `osim.py` | small simulators shared by the Week 8 check scripts. |
| `practice_exam.py` | checks every number in the Practice Exam of the Week 8 Study Guide (notes, Sections "Practice Exam" and "Worked Solutions"). |
| `review_problems.py` | checks every number in the Week 8 slides and in the worked examples / typical questions of the Study Guide (notes, Sections 2-8). |
| `review_results.json` | results computed by the checker script (used by the slides) |
| `out_practice.txt` | real output captured for the slides/notes (practice); yours will differ in PIDs, dates, addresses |
| `out_review.txt` | real output captured for the slides/notes (review); yours will differ in PIDs, dates, addresses |

## Requirements

- A Linux system (lab PCs, WSL on Windows 10/11, or an Ubuntu virtual machine) with `gcc` and `make` (Ubuntu: `sudo apt install build-essential`).
- Python 3 for the `.py` files (already installed on Ubuntu/WSL): `python3 file.py`.

## How to use it

The `out_*.txt` files are the real outputs shown on the slides. PIDs, dates, times, sizes, addresses and user names will differ on your machine; outputs were captured with `LC_ALL=C.UTF-8` (on a Turkish-locale system messages may be in Turkish and sort order may differ).

## Notes for this week

Python checkers reproduce every number of the review slides and of the practice exam in the study guide: `python3 review_problems.py`, `python3 practice_exam.py`.

## Windows users

Unzip the pack inside Linux, or copy it into your Linux home (WSL: `cp -r /mnt/c/Users/<you>/Downloads/<folder> ~/`). If a script fails with `bad interpreter` or `required file not found`, it was saved with Windows line endings — fix with `sed -i 's/\r$//' *.sh`. Make scripts executable with `chmod +x *.sh` if you want to run them as `./name.sh`.

## Slides and notes for this week

`Week08/` in the course repository: slides (`.pptx`, `.pdf`) and `notes/MCMP117_Week08_Notes.pdf`.

---
Prepared for MCMP117, Istanbul Okan University, Vocational School — 2026. For course use.

## About this folder in the repository

This `code/` folder holds the same files as the zip next to it, plus a few files that the lecture notes include (shortened `*_excerpt.c` copies shown on slides, generated LaTeX tables, and lab-sheet solution scripts with their outputs). For class work, download the zip.
