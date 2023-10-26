#include <sys/socket.h>

int accept(int fd, struct sockaddr *addr, socklen_t *addrlen) {
  // Accept a connection request on the socket specified by the file descriptor fd.
  // The addr and addrlen arguments are used to return the address of the remote peer.
  return syscall(SYS_accept, fd, addr, addrlen);
}
