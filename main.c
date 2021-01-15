#include <stdio.h>
#include "lib/screen.h"
#include "lib/color.h"
#include "lib/cursor.h"

int main(int argc, char* argv[]) {
  char a[5] = {'H', 'E', 'L', 'L', 'O'};

  clear(ENTIRE_SCREEN);

  for(int i = 0; i < 5; i += 1) {
    // cursor_down(i + 1);
    // cursor_right(i + 1);
    change_fg_bg(FG_BLACK, BG_GREEN);
    change_mode(BOLD);
    cursor_XY(i + 1, i + 1);
    printf("%c", a[i]);
  }
  color_clear();
  printf("\nDONE...\n");
}