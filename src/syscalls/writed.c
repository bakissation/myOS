#include <unistd.h>
#include <sys/syscall.h>

ssize_t writed(int fd, const void *buf, size_t count) {
  // Write data from the buffer to the device associated with the specified file descriptor.
  return syscall(SYS_write, fd, buf, count);
}
