#include <fcntl.h>
#include <sys/stat.h>
#include <sys/syscall.h>


int open(const char *pathname, int flags) {
  // Check if the file exists.
  struct stat statbuf;
  if (stat(pathname, &statbuf) == 0) {
    // The file exists.
    return syscall(SYS_open, pathname, flags);
  } else {
    // The file does not exist. Create it if necessary.
    if ((flags & O_CREAT) == 0) {
      return -1;
    }

    // Create the file.
    int fd = syscall(SYS_creat, pathname, 0666);
    if (fd < 0) {
      return fd;
    }

    // Return the file descriptor.
    return fd;
  }
}
