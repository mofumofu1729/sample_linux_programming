#include <stdlib.h>
#include <stdio.h>

#define N_ARRAY 10

int main(void) {
  int* ptr = malloc(sizeof(int)*N_ARRAY);

  if (ptr == NULL) {
    exit(EXIT_FAILURE);
  } else {
    for (int i=0; i<N_ARRAY; i++) {
      ptr[i] = i*2;
    }
    for (int i=0; i<N_ARRAY; i++) {
      printf("%d\n", ptr[i]);
    }
    free(ptr);
    ptr = NULL;
  }

  return 0;
}
