# MCMP117 — Week 14: Introduction to Shell Scripting

**Code pack** · MCMP117 — Fundamentals of Operating Systems  
Istanbul Okan University · Vocational School · 2026–2027 Fall

## What is inside

| File | What it is |
|---|---|
| `mcmp117_lab_setup.sh` | creates the practice folder ~/lab (run once: `bash mcmp117_lab_setup.sh`) |
| `args.sh` | positional parameters: the words typed after the script name echo "Script name  \$0 = $0 echo "First arg    \$1 = $1 echo "Second arg   \$2 = $2 |
| `backup.sh` | timestamped .tar.gz backup of ~/lab/docs into ~/lab/backup |
| `check.sh` | file tests ([ -f ], [ -d ], [ -e ]) and exit statuses if [ $# -ne 1 ]; then                  # exactly one argument? |
| `demo_args.sh` | Week 14 demo 3: positional parameters and read setup: chmod +x *.sh ./args.sh apple "green tea" 42 ./args.sh |
| `demo_backup.sh` | Week 14 demo 7: the complete backup script setup: chmod +x *.sh ./backup.sh ls -l ../backup |
| `demo_errors.sh` | Week 14 demo 9: the most common scripting mistakes The #setup lines create five broken scripts (run them by hand to rebuild them). |
| `demo_first.sh` | Week 14 demo 1: writing and running a first script Type these commands in ~/lab/scripts (after: bash ~/mcmp117_lab_setup.sh and copying the week's example scripts into ~/lab/scripts). |
| `demo_grade.sh` | Week 14 demo 5: if / elif / else and debugging with bash -x setup: chmod +x *.sh ./grade.sh 92 ./grade.sh 72 |
| `demo_loops.sh` | Week 14 demo 6: for and while loops, functions setup: chmod +x *.sh ./loops.sh ./while.sh |
| `demo_report.sh` | Week 14 demo 8: the complete report script setup: chmod +x *.sh ./report.sh |
| `demo_status.sh` | Week 14 demo 4: exit status, test / [ ], file tests setup: chmod +x *.sh ls ../docs > /dev/null echo $? |
| `demo_variables.sh` | Week 14 demo 2: variables, quoting, $( ) and $(( )) |
| `functions.sh` | define a block of commands once, call it many times line() {                                  # no arguments echo "------------------------------------ } |
| `grade.sh` | numeric tests with if / elif / else |
| `greet.sh` | reading input from the keyboard with read read -r -p "What is your name? " name read -r -p "Which year were you born? " year age=$(( $(date +%Y) - year )) |
| `hello.sh` | my first shell script |
| `loops.sh` | three kinds of for loop for city in Istanbul Ankara Izmir; do       # 1) over a list of words echo "City: $city done |
| `quotes.sh` | double quotes, single quotes, backslash, no quotes name="Ayse file="final report.txt"         # a file name that contains a space shellcheck disable=SC2016     # (on purpose) |
| `report.sh` | one-page summary of logs/access.log and data/students.csv log="$HOME/lab/logs/access.log csv="$HOME/lab/data/students.csv for f in "$log" "$csv"; do |
| `variables.sh` | variables, command substitution and arithmetic name="Ayse"                     # NO spaces around the = sign course=MCMP117 week=14 |
| `while.sh` | a counting loop, and a file read line by line n=3 while [ "$n" -gt 0 ]; do                     # repeat WHILE the test is true echo "Countdown: $n |
| `out_args.txt` | real output captured for the slides/notes (args); yours will differ in PIDs, dates, addresses |
| `out_backup.txt` | real output captured for the slides/notes (backup); yours will differ in PIDs, dates, addresses |
| `out_errors.txt` | real output captured for the slides/notes (errors); yours will differ in PIDs, dates, addresses |
| `out_first.txt` | real output captured for the slides/notes (first); yours will differ in PIDs, dates, addresses |
| `out_grade.txt` | real output captured for the slides/notes (grade); yours will differ in PIDs, dates, addresses |
| `out_loops.txt` | real output captured for the slides/notes (loops); yours will differ in PIDs, dates, addresses |
| `out_report.txt` | real output captured for the slides/notes (report); yours will differ in PIDs, dates, addresses |
| `out_status.txt` | real output captured for the slides/notes (status); yours will differ in PIDs, dates, addresses |
| `out_variables.txt` | real output captured for the slides/notes (variables); yours will differ in PIDs, dates, addresses |

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

Copy the example scripts into `~/lab/scripts`, then `chmod +x *.sh`. Check syntax without running: `bash -n script.sh`; trace a run: `bash -x script.sh`.

## Windows users

Unzip the pack inside Linux, or copy it into your Linux home (WSL: `cp -r /mnt/c/Users/<you>/Downloads/<folder> ~/`). If a script fails with `bad interpreter` or `required file not found`, it was saved with Windows line endings — fix with `sed -i 's/\r$//' *.sh`. Make scripts executable with `chmod +x *.sh` if you want to run them as `./name.sh`.

## Slides and notes for this week

`Week14/` in the course repository: slides (`.pptx`, `.pdf`) and `notes/MCMP117_Week14_Notes.pdf`.

---
Prepared for MCMP117, Istanbul Okan University, Vocational School — 2026. For course use.

## About this folder in the repository

This `code/` folder holds the same files as the zip next to it, plus a few files that the lecture notes include (shortened `*_excerpt.c` copies shown on slides, generated LaTeX tables, and lab-sheet solution scripts with their outputs). For class work, download the zip.
