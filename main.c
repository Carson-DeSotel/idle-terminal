#include <stdio.h>
#include <unistd.h>
#include "lib/screen.h"
#include "lib/color.h"
#include "lib/cursor.h"

#define BORDER_HEIGHT 10
#define BORDER_WIDTH  25
#define BLOCK "\u2588"
#define BG_COLOR BG_BLUE

void print_border() {
  for(int i = 0; i < BORDER_HEIGHT; i += 1) {
    change_bg(BG_COLOR);
    for(int j = 0; j < BORDER_WIDTH; j += 1) {
      if(i == 0 || i == BORDER_HEIGHT - 1) {
        printf(BLOCK);
      } else if((j == 0 || j == BORDER_WIDTH - 1)) {
        printf(BLOCK);
      } else {
        printf(" ");
      }
    }
    change_bg(RESET);
    printf("\n");
  }
}

void print_progress(int p) {
  int bar_size = BORDER_WIDTH - 4;

  change_bg(BG_COLOR);
  cursor_save();
  cursor_XY(2,2);
  printf("[");
  for(int j = 0; j < bar_size; j += 1) {
    if(j <= p){ printf("#"); }
    else      { printf("-"); }
  }
  printf("]");
  cursor_load();
  change_bg(RESET);
}

void print_loading(int p) {
  p *= 5;
  change_bg(BG_COLOR);
  change_fg(FG_BLACK);
  cursor_save();
  cursor_XY(5,5);
  printf("Now loading...%d%%", p);
  cursor_load();
  change_bg(RESET);
}

void print_finished() {
  change_bg(BG_COLOR);
  change_fg(FG_BLACK);
  cursor_save();
  cursor_XY(9,5);
  printf("Finished!");
  cursor_load();
  change_bg(RESET);
}

int main(int argc, char* argv[]) {
  for(int i = 1; i <= 21; i += 1) {
    clear(ENTIRE_SCREEN);
    print_border();
    print_progress(i);

    if(i != 21) {
      print_loading(i);
    } else {
      print_finished();
    }

    fflush(stdout); // needed as no \n or other stream flushers are used.
    sleep(1);
  }

  clear(SCREEN);
}