#include <unistd.h>

int symlink(const char *target, const char *linkpath) {
  // Create a symbolic link named linkpath which contains the string target.
  return syscall(SYS_symlink, target, linkpath);
}
