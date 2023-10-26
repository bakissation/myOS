#include <pty.h>

int forkpty(int *master_fd, char *name, const struct termios *termp, const struct winsize *winp) {
  // Create a new process and pseudo-terminal.
  // The master_fd argument is a pointer to an integer that will be used to store the file descriptor for the master side of the pseudo-terminal.
  // The name argument is a pointer to a string that will be used to store the name of the pseudo-terminal device.
  // The termp argument is a pointer to a termios structure that will be used to initialize the terminal attributes of the pseudo-terminal.
  // The winp argument is a pointer to a winsize structure that will be used to initialize the window size of the pseudo-terminal.
  return syscall(SYS_forkpty, master_fd, name, termp, winp);
}
