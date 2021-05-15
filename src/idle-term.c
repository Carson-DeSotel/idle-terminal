#include "headers.h"

struct termstyle_t ts;
struct bar_t bar;

int main(int argc, char *argv[]){
  // initialize termstyle
  ts_init(&ts);
  set_termstyle(&ts, FG_WHITE, BG_CYAN);

  // initialize bar
  bar_init(&bar, &ts, 25, BLOCK, LIGHT);

  
  print_loading(&bar);

  // clean up terminal
  ts_clear(&ts);
}