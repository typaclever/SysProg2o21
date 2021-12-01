#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long int power(int y, int x) {
  int i;
  unsigned long long int a = 1;
  for (i = 0; i < x; i++) {
    a *= y;
  }
  return a;
}

int main() {
  struct timespec tmspec1, tmspec2, tmspec3, tmspec4;
  long int leadTime;
  int x;
  int *mas;
  clock_gettime(CLOCK_REALTIME, &tmspec1);
  for (x = 0; x < 64; x++) {
    clock_gettime(CLOCK_REALTIME, &tmspec3);
    mas = (int *)malloc(power(2, x));
    clock_gettime(CLOCK_REALTIME, &tmspec4);
    leadTime = (tmspec4.tv_sec - tmspec3.tv_sec) + (tmspec4.tv_nsec - tmspec3.tv_nsec);
    if (mas == NULL) {
      perror("malloc");
    } else {
      printf("malloc time 2^x (in nanoseconds): %ld\n", leadTime);
    }
  }
  clock_gettime(CLOCK_REALTIME, &tmspec2);
  leadTime = (tmspec2.tv_sec - tmspec1.tv_sec) + (tmspec2.tv_nsec - tmspec1.tv_nsec);
  printf("\nmalloc time 2^x (in nanoseconds): %ld\n\n", leadTime);
  free(mas);
  clock_gettime(CLOCK_REALTIME, &tmspec1);
  for (x = 0; x < 64; x++) {
    clock_gettime(CLOCK_REALTIME, &tmspec3);
    mas = (int *)malloc(power(2, (x + 1)));
    clock_gettime(CLOCK_REALTIME, &tmspec4);
    leadTime = (tmspec4.tv_sec - tmspec3.tv_sec) + (tmspec4.tv_nsec - tmspec3.tv_nsec);
    if (!mas) {
      perror("malloc");
    } else {
      printf("malloc time 2^(x+1) (in nanoseconds): %ld\n", leadTime);
    }
  }
  clock_gettime(CLOCK_REALTIME, &tmspec2);
  leadTime = (tmspec2.tv_sec - tmspec1.tv_sec) + (tmspec2.tv_nsec - tmspec1.tv_nsec);
  printf("\nmalloc time 2^(x+1) (in nanoseconds): %ld\n\n", leadTime);
  free(mas);
  clock_gettime(CLOCK_REALTIME, &tmspec1);
  for (x = 0; x < 64; x++) {
    clock_gettime(CLOCK_REALTIME, &tmspec3);
    mas = (int *)calloc(power(2, x), sizeof(int));
    clock_gettime(CLOCK_REALTIME, &tmspec4);
    leadTime = (tmspec4.tv_sec - tmspec3.tv_sec) + (tmspec4.tv_nsec - tmspec3.tv_nsec);
    if (!mas) {
      perror("calloc");
    } else {
      printf("calloc time 2^x (in nanoseconds): %ld\n", leadTime);
    }
  }
  clock_gettime(CLOCK_REALTIME, &tmspec2);
  leadTime = (tmspec2.tv_sec - tmspec1.tv_sec) + (tmspec2.tv_nsec - tmspec1.tv_nsec);
  printf("\ncalloc time 2^x (in nanoseconds): %ld\n\n", leadTime);
  free(mas);
  clock_gettime(CLOCK_REALTIME, &tmspec1);
  for (x = 0; x < 64; x++) {
    clock_gettime(CLOCK_REALTIME, &tmspec3);
    mas = (int *)calloc(power(2, (x + 1)), sizeof(int));
    clock_gettime(CLOCK_REALTIME, &tmspec4);
    leadTime = (tmspec4.tv_sec - tmspec3.tv_sec) + (tmspec4.tv_nsec - tmspec3.tv_nsec);
    if (!mas) {
      perror("calloc");
    } else {
      printf("calloc time 2^(x+1) (in nanoseconds): %ld\n", leadTime);
    }
  }
  clock_gettime(CLOCK_REALTIME, &tmspec2);
  leadTime = (tmspec2.tv_sec - tmspec1.tv_sec) + (tmspec2.tv_nsec - tmspec1.tv_nsec);
  printf("\ncalloc time 2^(x+1) (in nanoseconds): %ld\n\n", leadTime);
  free(mas);
  clock_gettime(CLOCK_REALTIME, &tmspec1);
  for (x = 0; x < 64; x++) {
    clock_gettime(CLOCK_REALTIME, &tmspec3);
    mas = (int *)alloca(power(2, x) * sizeof(int));
    clock_gettime(CLOCK_REALTIME, &tmspec4);
    leadTime = (tmspec4.tv_sec - tmspec3.tv_sec) + (tmspec4.tv_nsec - tmspec3.tv_nsec);
    if (!mas) {
      perror("alloca");
    } else {
      printf("alloc time 2^x (in nanoseconds): %ld\n", leadTime);
    }
  }
  clock_gettime(CLOCK_REALTIME, &tmspec2);
  leadTime = (tmspec2.tv_sec - tmspec1.tv_sec) + (tmspec2.tv_nsec - tmspec1.tv_nsec);
  printf("\nmalloc time 2^x (in nanoseconds): %ld\n", leadTime);
  free(mas);
  clock_gettime(CLOCK_REALTIME, &tmspec1);
  for (x = 0; x < 64; x++) {
    clock_gettime(CLOCK_REALTIME, &tmspec3);
    mas = (int *)alloca(power(2, (x + 1)) * sizeof(int));
    clock_gettime(CLOCK_REALTIME, &tmspec4);
    leadTime = (tmspec4.tv_sec - tmspec3.tv_sec) + (tmspec4.tv_nsec - tmspec3.tv_nsec);
    if (!mas) {
      perror("alloca");
    } else {
      printf("alloc time 2^(x+1) (in nanoseconds): %ld\n", leadTime);
    }
  }
  clock_gettime(CLOCK_REALTIME, &tmspec2);
  leadTime = (tmspec2.tv_sec - tmspec1.tv_sec) + (tmspec2.tv_nsec - tmspec1.tv_nsec);
  printf("\nalloc time 2^(x+1) (in nanoseconds): %ld\n", leadTime);
  free(mas);
  return 0;
}