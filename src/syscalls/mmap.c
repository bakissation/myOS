#include <sys/mman.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {
  // Map the file specified by the file descriptor fd into memory at the address specified by addr.
  // The length argument specifies the length of the region to be mapped.
  // The prot argument specifies the protection of the mapped region.
  // The flags argument specifies the flags that control how the mapping is created.
  // The offset argument specifies the offset in the file from which to start the mapping.
  return syscall(SYS_mmap, addr, length, prot, flags, fd, offset);
}
