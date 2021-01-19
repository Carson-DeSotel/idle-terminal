#include <stdio.h>
#include "cursor.h"

void cursor_home() {
  printf("\033[H");
}

void cursor_XY(int x, int y) {
  printf("\033[%d;%dH", y, x);
}

void cursor_up(int n) {
  printf("\033[%dA", n);
}

void cursor_down(int n) {
  printf("\033[%dB", n);
}

void cursor_right(int n) {
  printf("\033[%dC", n);
}

void cursor_left(int n) {
  printf("\033[%dD", n);
}

void cursor_save() {
  printf("\033[s");
}

void cursor_load() {
  printf("\033[u");
}