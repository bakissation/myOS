#include <unistd.h>
#include <sys/stat.h>
#include <sys/syscall.h>

int fstat(int fd, struct stat *buf) {
  // Get the status of the file associated with the specified file descriptor.
  return syscall(SYS_fstat, fd, buf);
}
