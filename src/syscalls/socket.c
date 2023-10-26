#include <sys/socket.h>

int socket(int domain, int type, int protocol) {
  // Create a socket in the specified domain, with the specified type and protocol.
  return syscall(SYS_socket, domain, type, protocol);
}
