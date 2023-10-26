#include <unistd.h>

int rename(const char *oldpath, const char *newpath) {
  // Rename the file or directory specified by oldpath to the name specified by newpath.
  return syscall(SYS_rename, oldpath, newpath);
}
