#include <sys/socket.h>

int connect(int fd, const struct sockaddr *addr, socklen_t addrlen) {
  // Connect the socket specified by the file descriptor fd to the address specified by addr.
  return syscall(SYS_connect, fd, addr, addrlen);
}
