#include <stdio.h>
#include "color.h"
#include "screen.h"

void change_fg(int color) {
  printf("\033[%dm", color);
}

void change_bg(int color) {
  printf("\033[%dm", color);
}

void change_fg_bg(int c1, int c2) {
    printf("\033[%d;%dm", c1, c2);
}

void change_mode(int mode) {
  printf("\033[%dm", mode);
}

void color_clear() {
  printf("\033[0m");
}