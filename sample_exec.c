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

    execl("/bin/date", "/bin/date", NULL);
    _exit(0);
  } else {
    /* 親プロセス */
    printf("here is parent process; pid is %d\n", pid);

    int child_status;
    printf("waiting for the child process...\n");
    wait(&child_status);

    printf("child process returns: %d\n", child_status);
    exit(0);
  }

  return 0;
}
