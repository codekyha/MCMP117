#!/bin/bash
# links_demo.sh -- inodes, hard links and symbolic links.
# Run it in an EMPTY folder:   mkdir week7 && cd week7 && bash ../links_demo.sh
# (or type the commands one by one -- that is the better exercise).
run() { echo "\$ $*"; eval "$@" 2>&1; }   # print each command, then run it

run 'echo "hello" > notes.txt'   # a new file = a new inode
run 'ls -li notes.txt'           # 1st column: inode number; 3rd: link count
run 'ln notes.txt hard.txt'      # hard link: a 2nd NAME for the same inode
run 'ln -s notes.txt soft.txt'   # symbolic link: a new file storing a PATH
run 'ls -li'
run 'stat notes.txt'             # all attributes kept in the inode
run 'rm notes.txt'               # removes one name (link count 2 -> 1)
run 'cat hard.txt'               # data still reachable
run 'cat soft.txt'               # dangling: the stored path is gone
run 'ls -li'
