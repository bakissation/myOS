#include <unistd.h>
#include <sys/syscall.h>

ssize_t read(int fd, void *buf, size_t count) {
  // Read data from the file descriptor into the buffer.
  return syscall(SYS_read, fd, buf, count);
}
