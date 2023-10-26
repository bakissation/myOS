#include <sys/stat.h>

int mkdir(const char *path, mode_t mode) {
  // Create a directory named path with the specified mode.
  return syscall(SYS_mkdir, path, mode);
}
