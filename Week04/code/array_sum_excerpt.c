int  *a;              /* the big array: shared  */
long  partial[MAXT];  /* one slot per thread    */

void *sum_slice(void *arg)
{
    long k = (long)arg;               /* my slice */
    long start = k * N / T, end = (k + 1) * N / T;
    long s = 0;
    for (long i = start; i < end; i++)
        s += a[i];
    partial[k] = s;                   /* my slot  */
    return NULL;
}

/* in main(): */
for (long k = 0; k < T; k++)
    pthread_create(&th[k], NULL, sum_slice, (void *)k);
for (long k = 0; k < T; k++) {
    pthread_join(th[k], NULL);
    total += partial[k];
}
/* full program (adds timing, 20 repeats): code/array_sum.c */
