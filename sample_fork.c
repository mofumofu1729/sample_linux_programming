#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
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

    printf("waiting for the child process...\n");

    int child_status;
    waitpid(pid, &child_status, 0);

    printf("child status: %d\n", child_status);
    exit(0);
  }

  return 0;
}
