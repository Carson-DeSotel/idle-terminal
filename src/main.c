#include <stdio.h>
#include <unistd.h>
#include "../include/color.h"
#include "../include/cursor.h"
#include "../include/screen.h"
#include "../include/user.h"
#include "../include/util.h"



// change the amount of sleep time per cycle
// to change increment

#define BAR_SIZE 25
#define MAX_PERCENT 100
#define BLOCK "\u2588"
#define LIGHT_SHADE "\u2591"

void print_closing() {
  printf("\rClosing in...\r");
  fflush(stdout);
  sleep(1);
  change_fg(FG_RED);
  for(int i = 3; i > 0; i -= 1) {
    clear(LINE);
    printf("%d...\r", i);
    fflush(stdout);
    sleep(1);
  }
  color_clear();
  printf("Goodbye!\r");
  fflush(stdout);
  sleep(1);
}

void print_progress(double p) {
  for(int i = 1; i <= BAR_SIZE; i += 1) {
    // compare p as percentage of BAR_SIZE
    if(p * BAR_SIZE >= i) {
      printf(BLOCK);
    } else {
      printf(LIGHT_SHADE);
    }
  }
  printf("\t%.2f%%", p * 100);
}

void game(struct user player) {
  int max_round = player.max_level;
  change_fg(player.fg_color);

  const int ROUND_TEXT_OFFSET = 13;
  for(int round = 1; round <= max_round; round += 1) {
    cursor_XY(1, round);
    printf("[ lvl %3d ] ", round);
    for(int p = 1; p <= MAX_PERCENT * round; p += 1) {
      cursor_XY(ROUND_TEXT_OFFSET, round);
      print_progress( (p / (100.0 * round) ) );
      fflush(stdout);
      usleep(25000);
    }
    printf("\n");
  }

  player.max_level += 1;
  user_to_file(player);
}

int main(int argc, char* argv[]) {
  char c;
  struct user player;

  hard_reset();

  if(argc < 2) {
    printf("This program uses a file to save user data...\n");
    printf("A filename was not given for the user data...\n");
    printf("If you create a new file, it will overwrite a file of the same name...\n");
    printf("Would you like to make a new file? (y/n) \n");
    scanf(" %c", &c);
    if(c == 'y' || c == 'Y') {
      printf("Positive? (y/n) \n");
      scanf(" %c", &c);
      if(c == 'y' || c == 'Y') {
        player = user_init();
        user_to_file(player);
        clear(ENTIRE_SCREEN);
        game(player);
      } else {
        print_closing();
      }
    } else {
      print_closing();
    }
  } else if (argc > 2) {
    printf("This program does not take more than one additional argument...\n");
    printf("Please only input your user filename as an additional argument when running...\n");
    print_closing();
  } else {
    char* filename = argv[1];
    player = user_from_file(filename);
    game(player);
  }

  hard_reset();
}