#include <stdio.h>
#include "screen.h"

const char* clear_strings[] = { "J", "\0J", "1J", "2J", "K", "\0K", "1K", "2K", };

void clear(int mode) {
  printf("\033[%s", clear_strings[mode]);
}