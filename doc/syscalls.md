### System Calls


System calls are functions that allow a user-mode program to request a service from the kernel. They are the primary way for programs to interact with the operating system.
System Calls in this project are all in C

Here is a list of some of the system calls:

    bind(): Binds a socket to an address.
    listen(): Listens for connections on a socket.
    accept(): Accepts a connection on a socket.
    connect(): Connects a socket to an address.
    send(): Sends data on a socket.
    recv(): Receives data on a socket.
    mkdir(): Creates a directory.
    rmdir(): Removes a directory.
    chdir(): Changes the current working directory.
    rename(): Renames a file or directory.
    unlink(): Deletes a file.
    symlink(): Creates a symbolic link.
    mmap(): Maps a file into memory.
    munmap(): Unmaps a file from memory.
    forkpty(): Creates a new process and pseudo-terminal.

### Examples:

Here are some examples of how to use the system calls:

```
// Bind a socket to an address.
int fd = socket(AF_INET, SOCK_STREAM, 0);
struct sockaddr_in addr;
addr.sin_family = AF_INET;
addr.sin_port = htons(80);
addr.sin_addr.s_addr = INADDR_ANY;
bind(fd, (struct sockaddr *)&addr, sizeof(addr));
```
```
// Listen for connections on a socket.
listen(fd, 10);
```
```
// Accept a connection on a socket.
int client_fd = accept(fd, NULL, NULL);
```
```
// Send data on a socket.
send(client_fd, "Hello, world!", 12, 0);
```
```
// Receive data on a socket.
char buf[1024];
int bytes_received = recv(client_fd, buf, sizeof(buf), 0);
```
```
// Create a directory.
mkdir("new_dir", 0755);
```
```
// Remove a directory.
rmdir("new_dir");
```
```
// Change the current working directory.
chdir("/home/user");
```
```
// Rename a file.
rename("old_file", "new_file");
```
```
// Delete a file.
unlink("new_file");
```
```
// Create a symbolic link.
symlink("/home/user/new_file", "/home/user/link_to_file");
```
```
// Map a file into memory.
void *ptr = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
```
```
// Unmap a file from memory.
munmap(ptr, 1024);
```
```
// Create a new process and pseudo-terminal.
pid_t pid = forkpty(&master_fd, &slave_fd, NULL, NULL);
```