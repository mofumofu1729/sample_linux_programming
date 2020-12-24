#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {
  pid_t pid;

  pid = fork();

  if (pid == -1) {
    fprintf(stderr, "can't fork, error %d\n", errno);
    exit(EXIT_FAILURE);
  }

  if (pid == 0) {
    /* 子プロセス */

    int j;
    for (j=0; j<10; j++) {
      printf("child: %d\n", j);
      sleep(1);
    }
    _exit(0);
  } else {
    /* 親プロセス */
    printf("here is parent process; pid is %d\n", pid);

    int i;
    for (i=0; i<10; i++) {
      printf("parent(%d): %d\n", pid, i);
      sleep(1);
    }

    exit(0);
  }

  return 0;
}
