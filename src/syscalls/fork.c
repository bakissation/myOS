typedef long pid_t;

pid_t fork(void) {
    pid_t pid = vfork();
    if (pid == 0) {
        // Child process code
        return 0;
    } else if (pid > 0) {
        // Parent process code
        return pid;
    } else {
        // Error
        return -1;
    }
}
