#include <time.h>

time_t time(time_t *seconds) {
  // Get the current time in seconds since the Unix epoch.
  time_t current_time = time(NULL);

  // If seconds is not NULL, store the current time in the variable pointed to by seconds.
  if (seconds != NULL) {
    *seconds = current_time;
  }

  return current_time;
}
