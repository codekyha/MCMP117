# MCMP117 · Fundamentals of Operating Systems

![Language](https://img.shields.io/badge/language-C%20%7C%20Bash-36454F)
![Platform](https://img.shields.io/badge/platform-Linux%20(Ubuntu%2024.04%20%2F%20WSL2)-E95420)
![Notes](https://img.shields.io/badge/notes-XeLaTeX-008080)
![Weeks](https://img.shields.io/badge/weeks-15-14213D)
![License](https://img.shields.io/badge/license-MIT-green)

Course materials for **MCMP117 Fundamentals of Operating Systems**, Istanbul Okan University, Vocational School, 2026–2027 Fall semester.

The course explains what an operating system does and how it does it: processes and threads, CPU scheduling, synchronization, memory management, virtual memory and file systems. The second half turns theory into practice on the **Linux command line and the Bash shell**. Every week has:

| | What it is | Format |
|---|---|---|
| **Slides** | The lecture presentation, with speaker notes | `.pptx` and `.pdf` |
| **Notes** | Lecture notes: explanations, worked examples with formulas, diagrams, real program output, glossary, review questions with answers and (Weeks 9–14) a graded lab sheet | `.pdf` (+ XeLaTeX source) |
| **Code** | Every example program and command demo from the lecture, ready to run | `.zip` (C programs with a `Makefile`, Bash demos, Python checkers) |

---

## Contents

- [Weekly materials](#weekly-materials)
- [Getting started (students)](#getting-started-students)
- [Running the example code](#running-the-example-code)
- [The Linux practice folder (Weeks 9–15)](#the-linux-practice-folder-weeks-915)
- [Repository layout](#repository-layout)
- [Course information](#course-information)
- [Conventions used in the materials](#conventions-used-in-the-materials)
- [Rebuilding the lecture notes](#rebuilding-the-lecture-notes)
- [Feedback](#feedback)
- [License](#license)

---

## Weekly materials

| Week | Topic | Slides | Notes | Code |
|:---:|---|---|---|---|
| 1 | Course introduction · What a computer and an OS are · A history of operating systems | [pptx](Week01/MCMP117_Week01_Introduction_History.pptx) · [pdf](Week01/MCMP117_Week01_Introduction_History.pdf) | [pdf](Week01/notes/MCMP117_Week01_Notes.pdf) | — |
| 2 | Definitions and goals · Components (interrupts, storage hierarchy, dual mode) · OS structures | [pptx](Week02/MCMP117_Week02_Definitions_Structures.pptx) · [pdf](Week02/MCMP117_Week02_Definitions_Structures.pdf) | [pdf](Week02/notes/MCMP117_Week02_Notes.pdf) | [zip](Week02/MCMP117_Week02_Code.zip) · 3 C programs |
| 3 | OS services · System calls · Processes, process states, PCB, context switch | [pptx](Week03/MCMP117_Week03_Services_SystemCalls_Processes.pptx) · [pdf](Week03/MCMP117_Week03_Services_SystemCalls_Processes.pdf) | [pdf](Week03/notes/MCMP117_Week03_Notes.pdf) | [zip](Week03/MCMP117_Week03_Code.zip) · 4 C programs |
| 4 | Threads and multithreading models · CPU-scheduling concepts and criteria | [pptx](Week04/MCMP117_Week04_Threads_SchedulingBasics.pptx) · [pdf](Week04/MCMP117_Week04_Threads_SchedulingBasics.pdf) | [pdf](Week04/notes/MCMP117_Week04_Notes.pdf) | [zip](Week04/MCMP117_Week04_Code.zip) · 4 C programs |
| 5 | FCFS, SJF/SRTF, Priority, Round Robin · Race conditions, critical sections, mutexes, semaphores | [pptx](Week05/MCMP117_Week05_Scheduling_Synchronization.pptx) · [pdf](Week05/MCMP117_Week05_Scheduling_Synchronization.pdf) | [pdf](Week05/notes/MCMP117_Week05_Notes.pdf) | [zip](Week05/MCMP117_Week05_Code.zip) · 4 C programs + simulator |
| 6 | Memory management · Contiguous allocation and fragmentation · Paging, TLB, segmentation | [pptx](Week06/MCMP117_Week06_Memory_Paging_Segmentation.pptx) · [pdf](Week06/MCMP117_Week06_Memory_Paging_Segmentation.pdf) | [pdf](Week06/notes/MCMP117_Week06_Notes.pdf) | [zip](Week06/MCMP117_Week06_Code.zip) · 3 C programs + 2 checkers |
| 7 | Virtual memory, page faults, page replacement, thrashing · File systems and directories | [pptx](Week07/MCMP117_Week07_VirtualMemory_FileSystems.pptx) · [pdf](Week07/MCMP117_Week07_VirtualMemory_FileSystems.pdf) | [pdf](Week07/notes/MCMP117_Week07_Notes.pdf) | [zip](Week07/MCMP117_Week07_Code.zip) · 3 C programs + simulator |
| 8 | **Midterm**: review, formula sheet, practice exam and sample paper | [pptx](Week08/MCMP117_Week08_Midterm_Review.pptx) · [pdf](Week08/MCMP117_Week08_Midterm_Review.pdf) | [pdf](Week08/notes/MCMP117_Week08_Notes.pdf) · [sample paper](Week08/exam/MCMP117_Midterm_Sample.pdf) | [zip](Week08/MCMP117_Week08_Code.zip) · 3 Python checkers |
| 9 | Linux shell basics · Paths and the directory tree · Getting help | [pptx](Week09/MCMP117_Week09_Shell_Navigation.pptx) · [pdf](Week09/MCMP117_Week09_Shell_Navigation.pdf) | [pdf](Week09/notes/MCMP117_Week09_Notes.pdf) | [zip](Week09/MCMP117_Week09_Code.zip) · 10 demos |
| 10 | File and directory operations · Wildcards · Links and inodes | [pptx](Week10/MCMP117_Week10_File_Operations.pptx) · [pdf](Week10/MCMP117_Week10_File_Operations.pdf) | [pdf](Week10/notes/MCMP117_Week10_Notes.pdf) | [zip](Week10/MCMP117_Week10_Code.zip) · 10 demos + 1 C program |
| 11 | Permissions, ownership, users and groups · `chmod`, `umask`, `sudo` | [pptx](Week11/MCMP117_Week11_Permissions_Users.pptx) · [pdf](Week11/MCMP117_Week11_Permissions_Users.pdf) | [pdf](Week11/notes/MCMP117_Week11_Notes.pdf) | [zip](Week11/MCMP117_Week11_Code.zip) · 13 demos |
| 12 | Standard streams and redirection · Pipes · `grep`, `sort`, `uniq`, `cut`, `find` | [pptx](Week12/MCMP117_Week12_TextProcessing_Pipes.pptx) · [pdf](Week12/MCMP117_Week12_TextProcessing_Pipes.pdf) | [pdf](Week12/notes/MCMP117_Week12_Notes.pdf) | [zip](Week12/MCMP117_Week12_Code.zip) · 12 demos |
| 13 | Processes and job control · `ps`, `top`, signals, `nice` | [pptx](Week13/MCMP117_Week13_Processes_JobControl.pptx) · [pdf](Week13/MCMP117_Week13_Processes_JobControl.pdf) | [pdf](Week13/notes/MCMP117_Week13_Notes.pdf) | [zip](Week13/MCMP117_Week13_Code.zip) · 9 demos + 2 C programs |
| 14 | Shell scripting: variables, conditions, loops, functions · Two automation scripts | [pptx](Week14/MCMP117_Week14_Shell_Scripting.pptx) · [pdf](Week14/MCMP117_Week14_Shell_Scripting.pdf) | [pdf](Week14/notes/MCMP117_Week14_Notes.pdf) | [zip](Week14/MCMP117_Week14_Code.zip) · 12 scripts + 9 demos |
| 15 | **Final**: cumulative review, cheat sheets, practice final and sample paper | [pptx](Week15/MCMP117_Week15_Final_Review.pptx) · [pdf](Week15/MCMP117_Week15_Final_Review.pdf) | [pdf](Week15/notes/MCMP117_Week15_Notes.pdf) · [sample paper](Week15/exam/MCMP117_Final_Sample.pdf) | [zip](Week15/MCMP117_Week15_Code.zip) · 7 scripts |

> **Tip:** On GitHub, a `.pdf` opens in the browser. To download a `.pptx` or `.zip`, open the file and press the **Download raw file** button (↓). Each week's code is also browsable directly in its `WeekNN/code/` folder.

---

## Getting started (students)

1. **Before every lecture**, skim the slides PDF. **After the lecture**, read the notes and answer the review questions; the answers to the numerical questions are at the end of each set of notes.
2. **Get a Linux terminal** (needed from Week 2 for the C examples, essential from Week 9). Any of these works:
   - the Linux PCs in the lab;
   - **WSL2** on Windows 10/11: open PowerShell as administrator and run `wsl --install`, then restart and open *Ubuntu* from the Start menu;
   - an **Ubuntu 24.04 virtual machine** (for example in VirtualBox).
3. **Install the tools once** (inside Ubuntu/WSL):
   ```bash
   sudo apt update
   sudo apt install build-essential strace tree htop python3 unzip
   ```
4. **Check the installation:**
   ```bash
   gcc --version && make --version | head -1 && python3 --version
   ```
5. Download each week's code zip and **run every example yourself**. Change the numbers, break the code, read the error messages. The `out_*.txt` files show what the programs printed in class.

---

## Running the example code

Each `MCMP117_WeekNN_Code.zip` unpacks to one folder:

```
MCMP117_Week05_Code/
├── README.md            ← what every file does, how to build and run it, week-specific warnings
├── Makefile             ← `make` builds all C programs of the week
├── race.c               ← example programs (heavily commented)
├── race_fixed.c
├── ...
├── sched_check.py       ← checker that reproduces the numbers on the slides
└── run_output.txt       ← real output shown in the lecture
```

**C weeks (2–7, plus 10 and 13):**

```bash
unzip MCMP117_Week05_Code.zip
cd MCMP117_Week05_Code
make            # builds every program of the week
./race          # run one of them
make clean      # remove the binaries
```

**Linux weeks (9–15):** create the practice folder once (next section), then type the commands from the `demo_*.sh` files yourself inside `~/lab`, and compare with the matching `out_*.txt`. Files that start with `#!/bin/bash` can also be run as a whole, e.g. `cd ~/lab && bash ~/MCMP117_Week12_Code/demo_grep.sh`.

Good to know:

- All code was compiled with `gcc -Wall -O2` (threads: `-pthread`) and runs on Ubuntu 24.04 and WSL2. `raw_write.c` (Week 3) uses x86-64 system-call numbers and does not build on ARM.
- The Week 2 kernel module is built separately with `make module`; it needs `linux-headers-$(uname -r)`, does **not** build under WSL2, and should only be loaded inside a virtual machine.
- PIDs, memory addresses (ASLR), dates, times, file sizes and user names on your machine will differ from the recorded outputs. That is expected.
- If a script fails with `bad interpreter` or `required file not found`, it was saved with Windows line endings: `sed -i 's/\r$//' *.sh`.

---

## The Linux practice folder (Weeks 9–15)

Every Linux week's code pack contains `mcmp117_lab_setup.sh`. It creates the practice folder `~/lab` (sample web-server and system logs, a student-grades CSV, documents, a small project tree) that all demos and lab exercises use. The data are generated by formulas, not at random, so **everybody gets exactly the same files and the same command output as the slides**.

```bash
bash mcmp117_lab_setup.sh      # builds ~/lab from scratch
cd ~/lab && ls
```

> **Warning:** every run deletes `~/lab` and rebuilds it. Keep your own work outside `~/lab`. If a directory with removed permissions is left in it (Week 11 exercises), run `chmod -R u+rwx ~/lab` first.

The recorded outputs were captured with `LC_ALL=C.UTF-8`. On a system with another locale, messages may be translated and `ls`/`sort` order may differ; to compare with the recording, run e.g. `LC_ALL=C.UTF-8 ls`.

---

## Repository layout

```
.
├── README.md
├── LICENSE
├── Week01/
│   ├── MCMP117_Week01_Introduction_History.pptx   ← slides (editable)
│   ├── MCMP117_Week01_Introduction_History.pdf    ← slides (handout)
│   └── notes/
│       ├── MCMP117_Week01_Notes.pdf               ← lecture notes
│       ├── MCMP117_Week01_Notes.tex               ← XeLaTeX source
│       └── figures/
├── Week02/
│   ├── MCMP117_Week02_Definitions_Structures.pptx
│   ├── MCMP117_Week02_Definitions_Structures.pdf
│   ├── MCMP117_Week02_Code.zip                    ← student code pack
│   ├── code/                                      ← the same code, browsable (+ files used by the notes)
│   └── notes/
├── ...
├── Week08/
│   ├── ...
│   └── exam/MCMP117_Midterm_Sample.pdf            ← sample midterm paper
└── Week15/
    ├── ...
    └── exam/MCMP117_Final_Sample.pdf              ← sample final paper
```

---

## Course information

| | |
|---|---|
| **Course** | MCMP117 Fundamentals of Operating Systems |
| **Institution** | Istanbul Okan University, Vocational School, Electronical Communication Technology Programme |
| **Semester** | 2026–2027 Fall |
| **Language of instruction** | English (a parallel Turkish section is taught as MBLP131 *İşletim Sistemleri Temelleri*) |
| **Tools** | Linux (Ubuntu 24.04 / WSL2), C (gcc), Bash, Python 3 |
| **Instructor** | Asst. Prof. Hasan Oğuz, PhD |
| **Assessment** | Midterm exam (Week 8) · Final exam (Week 15) |

### Learning outcomes

By the end of the semester you will be able to:

1. **Explain what an operating system is** and how it is structured (monolithic, layered, microkernel, modular, hybrid).
2. **Describe processes and threads**: their states, the PCB, context switches and system calls such as `fork`, `exec` and `wait`.
3. **Apply CPU-scheduling algorithms** (FCFS, SJF/SRTF, Priority, Round Robin) and compute waiting and turnaround times.
4. **Recognise race conditions** and protect critical sections with mutexes and semaphores.
5. **Translate addresses and analyse memory schemes**: contiguous allocation, paging with a TLB, segmentation, virtual memory and page replacement.
6. **Work confidently on the Linux command line**: navigate the file system, manage files, permissions, processes and jobs, and process text with pipelines.
7. **Automate tasks with Bash scripts** using variables, conditions, loops and functions.

### How the weeks build on each other

```
what an OS is → structures → system calls & processes → threads & scheduling → algorithms & synchronization
   → memory & paging → virtual memory & files → [MIDTERM]
   → shell & navigation → files & links → permissions → pipes & text → processes & signals → scripts → [FINAL]
```

The practical weeks deliberately revisit the theory: `strace` shows the system calls of Week 3, `ls -i` and `ln` show the inodes and links of Week 7, `chmod` is the protection of Weeks 2 and 7, a pipeline is processes connected through the kernel (Week 3), and `ps` displays the process states of Week 3 and the priorities of Week 5.

---

## Conventions used in the materials

- **Formulas** use the notation introduced in the notes, e.g. $T_{\text{turnaround}} = T_{\text{completion}} - T_{\text{arrival}}$, $T_{\text{waiting}} = T_{\text{turnaround}} - T_{\text{burst}}$, and $\text{EAT} = (1-p)\,t_{m} + p\,t_{\text{fault}}$.
- **Scheduling ties** go to the earlier arrival; in priority scheduling a **smaller number means higher priority**; context-switch time is taken as $0$ unless stated otherwise.
- **Every number** in a worked example was computed by a program (the `*.py` checkers in the code packs), and **every terminal output** shown is a real run.
- **Terminal prompts** are shown as `student@okan-lab:~/lab$`; lines you type follow the `$`.
- Items written in **[square brackets]** in the exam-week materials (date, room, duration, allowed materials) are placeholders that are confirmed in class.

---

## Rebuilding the lecture notes

The PDFs are ready to use; rebuilding is optional. The notes are XeLaTeX documents that read code listings from `../code/`:

```bash
cd Week03/notes
xelatex MCMP117_Week03_Notes.tex
xelatex MCMP117_Week03_Notes.tex     # second run: table of contents and cross-references
```

A full TeX distribution (TeX Live or MiKTeX) is needed. The documents use Calibri/Cambria/Consolas when installed and fall back to the metric-compatible Carlito/Caladea/DejaVu Sans Mono otherwise.

---

## Feedback

Found a mistake in the slides, notes or code? Please open an **Issue** in this repository with the week, the page or slide number and a short description.

---

## License

This repository (slides, notes and example code) is released under the [MIT License](LICENSE).
You may use, copy, modify and redistribute the materials, provided that the copyright notice and the license text are kept.  The materials are provided "as is", without warranty of any kind;

the author accepts no liability for their use. 

© 2026 Hasan Oğuz · Istanbul Okan University
