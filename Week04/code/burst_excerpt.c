/* ./burst cpu : one long CPU burst */
for (long i = 1; i <= 400000000L; i++)
    x += 1.0 / i;

/* ./burst io : 1000 x (tiny CPU burst + I/O wait) */
for (int i = 0; i < 1000; i++) {
    buf[0] = 'A' + i % 26;     /* CPU    */
    write(fd, buf, 4096);      /* I/O... */
    fsync(fd);                 /* ...wait for disk */
}
/* full program: code/burst.c */
