#include <sys/wait.h>

pid_t wait(int *status) {
  // Wait for any child process to terminate.
  pid_t pid = waitpid(-1, status, 0);
  if (pid < 0) {
    return -1;
  }

  return pid;
}
