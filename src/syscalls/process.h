#ifndef PROCESS_H
#define PROCESS_H

typedef long pid_t;
typedef int status_t;

pid_t getpid(void);
pid_t wait(status_t* status);
void exit(status_t status);

#endif
