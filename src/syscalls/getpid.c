#include <unistd.h>

pid_t getpid(void) {
  // Get the process ID of the current process.
  return syscall(SYS_getpid);
}
