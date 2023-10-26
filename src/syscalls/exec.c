#include <unistd.h>

int exec(const char *pathname, char *const argv[], char *const envp[]) {
  // Load the program file into memory.
  int err = execve(pathname, argv, envp);
  if (err < 0) {
    return err;
  }

  // Replace the current process with the new program.
  _exit(0);
}
