#include <unistd.h>

int unlink(const char *path) {
  // Delete the file named by path.
  return syscall(SYS_unlink, path);
}
