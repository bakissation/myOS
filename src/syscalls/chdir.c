#include <unistd.h>

int chdir(const char *path) {
  // Change the current working directory to the directory specified by path.
  return syscall(SYS_chdir, path);
}
