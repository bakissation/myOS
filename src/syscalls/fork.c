#include <unistd.h>
#include <sys/types.h>

pid_t fork(void) {
  pid_t pid = vfork();
  if (pid == 0) {
    // Child process.
    return pid;
  } else if (pid > 0) {
    // Parent process.
    return pid;
  } else {
    // Error.
    return -1;
  }
}
