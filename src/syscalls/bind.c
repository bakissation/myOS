#include <sys/socket.h>

int bind(int fd, const struct sockaddr *addr, socklen_t addrlen) {
  // Bind the socket specified by the file descriptor fd to the address specified by addr.
  return syscall(SYS_bind, fd, addr, addrlen);
}
