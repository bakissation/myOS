#include <unistd.h>
#include <sys/syscall.h>

int close(int fd) {
  // Close the file descriptor.
  return syscall(SYS_close, fd);
}
