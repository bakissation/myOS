#include <unistd.h>

int rmdir(const char *path) {
  // Remove the directory named path.
  return syscall(SYS_rmdir, path);
}
