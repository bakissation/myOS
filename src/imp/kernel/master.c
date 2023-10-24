#include "print.h"

// This function is the entry point for the kernel.
void kernel_main() {
  // Clear the screen.
  print_clear();

  // Set the text color to yellow on black.
  print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);

  // Print a welcome message.
  print_str("Welcome to my 64-bit kernel!");
}
