#include "kernel.h"
#include "syscalls/process.h"
#include <stddef.h>


void kernel_main() {
    // Implement the main function of your kernel.
    // Replace the following lines with your actual implementation.
    while (1) {
        pid_t pid = fork();
        if (pid == 0) {
            // Child process code
        } else if (pid > 0) {
            // Parent process code
            wait(NULL);
        }
    }
}
