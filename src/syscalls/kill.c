#include <signal.h>
#include <sys/types.h>
#include <sys/syscall.h>


int kill(pid_t pid, int sig) {
  // Send the specified signal to the specified process.
  return syscall(SYS_kill, pid, sig);
}
