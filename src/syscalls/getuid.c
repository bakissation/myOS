#include <unistd.h>

uid_t getuid(void) {
  // Get the user ID of the current process.
  return syscall(SYS_getuid);
}
