#ifndef FORK_H
#define FORK_H

// Define data types
typedef long pid_t;
typedef unsigned long size_t;

// Define function prototypes
pid_t fork(void);
void exit(int status);
pid_t wait(int* status);
void* malloc(size_t size);
void free(void* ptr);

#endif
