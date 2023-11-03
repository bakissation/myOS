#include "syscalls/process.h"

pid_t getpid() {
    // Implement the logic to return the current process ID
    // You can use a unique identifier for each process
    // For example, a static variable or a counter.
    // Replace the following line with your actual implementation.
    return 0;
}

pid_t wait(int* status) {
    // Implement waiting for child processes.
    // Replace the following line with your actual implementation.
    return -1;
}

void exit(int status) {
    // Implement process termination.
    // Replace the following line with your actual implementation.
    while (1) {
        // Loop indefinitely or perform necessary cleanup
    }
}
