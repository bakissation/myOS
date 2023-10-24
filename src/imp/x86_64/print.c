#include "print.h"

// The number of columns on the screen.
const static size_t NUM_COLS = 80;

// The number of rows on the screen.
const static size_t NUM_ROWS = 25;

// A structure to represent a character on the screen.
struct Char {
  // The character itself.
  uint8_t character;

  // The color of the character.
  uint8_t color;
};

// A pointer to the start of the screen buffer.
struct Char* buffer = (struct Char*) 0xb8000;

// The current column position.
size_t col = 0;

// The current row position.
size_t row = 0;

// The current text color.
uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;

// Clears a single row on the screen.
void clear_row(size_t row) {
  // Create an empty character.
  struct Char empty = {
    .character = ' ',
    .color = color,
  };

  // Fill the entire row with empty characters.
  for (size_t col = 0; col < NUM_COLS; col++) {
    buffer[col + NUM_COLS * row] = empty;
  }
}

// Clears the entire screen.
void print_clear() {
  // Clear each row on the screen.
  for (size_t i = 0; i < NUM_ROWS; i++) {
    clear_row(i);
  }
}

// Prints a newline character.
void print_newline() {
  // Reset the column position to 0.
  col = 0;

  // If we're not on the last row, increment the row position.
  if (row < NUM_ROWS - 1) {
    row++;
    return;
  }

  // Otherwise, scroll the screen up by one row.
  for (size_t row = 1; row < NUM_ROWS; row++) {
    for (size_t col = 0; col < NUM_COLS; col++) {
      // Copy the character at the current row and column to the row above.
      struct Char character = buffer[col + NUM_COLS * row];
      buffer[col + NUM_COLS * (row - 1)] = character;
    }
  }

  // Clear the bottom row of the screen.
  clear_row(NUM_COLS - 1);
}

// Prints a single character.
void print_char(char character) {
  // If the character is a newline character, print a newline.
  if (character == '\n') {
    print_newline();
    return;
  }

  // If we're at the end of the line, print a newline.
  if (col > NUM_COLS) {
    print_newline();
  }

  // Write the character to the screen buffer at the current row and column.
  buffer[col + NUM_COLS * row] = (struct Char) {
    .character = (uint8_t) character,
    .color = color,
  };

  // Increment the column position.
  col++;
}

// Prints a string of characters.
void print_str(char* str) {
  // Iterate over the string, printing each character.
  for (size_t i = 0; 1; i++) {
    char character = (uint8_t) str[i];

    // If we reach the end of the string, stop.
    if (character == '\0') {
      return;
    }

    // Print the character.
    print_char(character);
  }
}

// Sets the current text color.
void print_set_color(uint8_t foreground, uint8_t background) {
  color = foreground + (background << 4);
}
