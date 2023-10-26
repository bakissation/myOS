#include <unistd.h>

char *pwd(char *buf, size_t size) {
  // Get the current working directory.
  return syscall(SYS_getcwd, buf, size);
}
