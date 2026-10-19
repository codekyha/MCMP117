#define RECSZ 32                       /* bytes per record */
int fd = open("students.dat", O_CREAT | O_RDWR | O_TRUNC, 0644);
/* ... write 5 records: "0 Ayse", "1 Mehmet", ... "4 Zeynep" */

lseek(fd, 0, SEEK_SET);                /* 1) sequential   */
while (read(fd, rec, RECSZ) == RECSZ)
    printf("  [%s]", rec);

lseek(fd, 3 * RECSZ, SEEK_SET);        /* 2) direct: byte 96 */
read(fd, rec, RECSZ);

lseek(fd, 1 * RECSZ, SEEK_SET);        /* 3) overwrite rec 1 */
write(fd, rec, RECSZ);
close(fd);
/* full program: code/file_access.c */
