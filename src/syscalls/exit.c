#include <unistd.h>
#include <signal.h>

void exit(int status) {
  // Flush all buffers and close all open files.
  fflush(NULL);
  fclose(NULL);

  // Send a SIGTERM signal to all child processes.
  kill(0, SIGTERM);

  // Wait for all child processes to terminate.
  while (waitpid(-1, NULL, 0) > 0) {}

  // Terminate the current process.
  _exit(status);
}
