#include "screen.h"
#include "color.h"
#include "cursor.h"
#include "util.h"

void hard_reset() {
  color_clear();
  clear(ENTIRE_SCREEN);
  cursor_home();
}