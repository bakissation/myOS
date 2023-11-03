#include "int/print.h"
#include "syscalls/fork.h"

void main() {
    print_str("Hello from the parent process! My PID is ");
    print_char(getpid());
    print_char("\n");

    int pid = fork();

    if (pid == 0) {
        // Child process code
        print_str("Hello from the child process! My PID is ");
        print_char(getpid());
        print_char("\n");
    } else if (pid > 0) {
        // Parent process code
        print_str("Back in the parent process with PID ");
        print_char(getpid());
        print_char("\n");
        wait(NULL);
    } else {
        // Error
        print_str("Error creating child process.\n");
        exit(1);
    }

    exit(0);
}
