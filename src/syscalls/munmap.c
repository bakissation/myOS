#include <sys/mman.h>

int munmap(void *addr, size_t length) {
  // Unmap the region of memory starting at addr with the length specified by length.
  return syscall(SYS_munmap, addr, length);
}
