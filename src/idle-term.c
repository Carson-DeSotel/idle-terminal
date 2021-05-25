#include "headers.h"

struct termstyle_t ts;
struct bar_t bar;
struct player_t plr;

int main(int argc, char *argv[]){
  // initialize termstyle
  ts_init(&ts);
  set_termstyle(&ts, FG_BLACK, BG_CYAN);

  // initialize bar
  bar_init(&bar, &ts, 25, BLOCK, LIGHT);

  // initialize player
  player_init(&plr, &bar);

  plr.bar->ts->color_fg = FG_RED;
  player_save(&plr);
  plr.bar->ts->color_fg = FG_BLACK;
  plr.bar->ts->color_fg = FG_RED;
  player_load(&plr, plr.save_file);
  print_loading(plr.bar);

  // clean up terminal
  ts_clear(&ts);
}