#include <sys/socket.h>

int listen(int fd, int backlog) {
  // Mark the socket specified by the file descriptor fd as a passive socket. This means that the socket will be used to accept incoming connections.
  // The backlog argument specifies the maximum number of pending connections that the socket can have.
  return syscall(SYS_listen, fd, backlog);
}
