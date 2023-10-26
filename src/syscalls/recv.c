#include <sys/socket.h>

ssize_t recv(int fd, void *buf, size_t len, int flags) {
  // Receive data on the socket specified by the file descriptor fd.
  // The buf argument points to the buffer where the received data will be stored.
  // The len argument specifies the length of the buffer.
  // The flags argument specifies the type of message to be received.
  return syscall(SYS_recv, fd, buf, len, flags);
}
