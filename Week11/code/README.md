# MCMP117 — Week 11: Permissions, Ownership & Users

**Code pack** · MCMP117 — Fundamentals of Operating Systems  
Istanbul Okan University · Vocational School · 2026–2027 Fall

## What is inside

| File | What it is |
|---|---|
| `mcmp117_lab_setup.sh` | creates the practice folder ~/lab (run once: `bash mcmp117_lab_setup.sh`) |
| `perm_check.py` | verifies every octal/umask number used in the Week 11 slides and notes. |
| `demo_chmod_oct.sh` | chmod in octal mode: r = 4, w = 2, x = 1 cd docs chmod 754 syllabus.txt ls -l syllabus.txt |
| `demo_chmod_sym.sh` | chmod in symbolic mode: who (u g o a), op (+ - =), perms (r w x) |
| `demo_dirperm.sh` | what r, w and x mean for a DIRECTORY mkdir box echo "top secret" > box/secret.txt ls -ld box |
| `demo_group.sh` | sharing through a group (the administrator has added you to 'students') |
| `demo_ls.sh` | reading the mode string with ls -l, ls -ld and stat (Week 11) |
| `demo_order.sh` | only ONE class applies: the owner gets the owner bits, even if they are worse echo "hello" > me.txt chmod 074 me.txt ls -l me.txt |
| `demo_owner.sh` | chown and chgrp as an ordinary user ls -l docs/notes_01.txt chown root docs/notes_01.txt chgrp students docs/notes_01.txt |
| `demo_script.sh` | making a script (and a compiled program) executable cd scripts echo '#!/bin/bash' > hello.sh echo 'echo "Hello, $USER! You are in $PWD"' >> hello.sh |
| `demo_special.sh` | setuid (passwd) and the sticky bit (/tmp) |
| `demo_sudo.sh` | sudo for a user who IS an administrator (member of group sudo) |
| `demo_sudo_denied.sh` | sudo for a user who is NOT an administrator sudo whoami |
| `demo_umask.sh` | default permissions: new file 666 / new directory 777, minus the umask bits mkdir umask_test cd umask_test umask |
| `demo_users.sh` | who am I? users, groups and the account files (Week 11) |
| `out_chmod_oct.txt` | real output captured for the slides/notes (chmod_oct); yours will differ in PIDs, dates, addresses |
| `out_chmod_sym.txt` | real output captured for the slides/notes (chmod_sym); yours will differ in PIDs, dates, addresses |
| `out_dirperm.txt` | real output captured for the slides/notes (dirperm); yours will differ in PIDs, dates, addresses |
| `out_group.txt` | real output captured for the slides/notes (group); yours will differ in PIDs, dates, addresses |
| `out_ls.txt` | real output captured for the slides/notes (ls); yours will differ in PIDs, dates, addresses |
| `out_order.txt` | real output captured for the slides/notes (order); yours will differ in PIDs, dates, addresses |
| `out_owner.txt` | real output captured for the slides/notes (owner); yours will differ in PIDs, dates, addresses |
| `out_perm_check.txt` | real output captured for the slides/notes (perm_check); yours will differ in PIDs, dates, addresses |
| `out_script.txt` | real output captured for the slides/notes (script); yours will differ in PIDs, dates, addresses |
| `out_special.txt` | real output captured for the slides/notes (special); yours will differ in PIDs, dates, addresses |
| `out_sudo.txt` | real output captured for the slides/notes (sudo); yours will differ in PIDs, dates, addresses |
| `out_sudo_denied.txt` | real output captured for the slides/notes (sudo_denied); yours will differ in PIDs, dates, addresses |
| `out_umask.txt` | real output captured for the slides/notes (umask); yours will differ in PIDs, dates, addresses |
| `out_users.txt` | real output captured for the slides/notes (users); yours will differ in PIDs, dates, addresses |

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

`demo_sudo.sh` needs an account that is allowed to use sudo; on the lab PCs you may not have it — just read the output file. Never `chmod 777` to "fix" a problem.

## Windows users

Unzip the pack inside Linux, or copy it into your Linux home (WSL: `cp -r /mnt/c/Users/<you>/Downloads/<folder> ~/`). If a script fails with `bad interpreter` or `required file not found`, it was saved with Windows line endings — fix with `sed -i 's/\r$//' *.sh`. Make scripts executable with `chmod +x *.sh` if you want to run them as `./name.sh`.

## Slides and notes for this week

`Week11/` in the course repository: slides (`.pptx`, `.pdf`) and `notes/MCMP117_Week11_Notes.pdf`.

---
Prepared for MCMP117, Istanbul Okan University, Vocational School — 2026. For course use.

## About this folder in the repository

This `code/` folder holds the same files as the zip next to it, plus a few files that the lecture notes include (shortened `*_excerpt.c` copies shown on slides, generated LaTeX tables, and lab-sheet solution scripts with their outputs). For class work, download the zip.
