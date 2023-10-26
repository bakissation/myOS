#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>

off_t lseek(int fd, off_t offset, int whence) {
  // Move the file pointer to the specified offset.
  return syscall(SYS_lseek, fd, offset, whence);
}
