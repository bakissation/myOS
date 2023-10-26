#include <unistd.h>
#include <sys/syscall.h>

ssize_t write(int fd, const void *buf, size_t count) {
  // Write data from the buffer to the file descriptor.
  return syscall(SYS_write, fd, buf, count);
}
