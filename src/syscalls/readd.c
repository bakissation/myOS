#include <unistd.h>
#include <sys/syscall.h>

ssize_t readd(int fd, void *buf, size_t count) {
  // Read data from the device associated with the specified file descriptor into the buffer.
  return syscall(SYS_read, fd, buf, count);
}
