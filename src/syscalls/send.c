#include <sys/socket.h>

ssize_t send(int fd, const void *buf, size_t len, int flags) {
  // Send data on the socket specified by the file descriptor fd.
  // The buf argument points to the data to be sent.
  // The len argument specifies the length of the data to be sent.
  // The flags argument specifies the type of message to be sent.
  return syscall(SYS_send, fd, buf, len, flags);
}
