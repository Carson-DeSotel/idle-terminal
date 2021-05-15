#include "headers.h"

void ts_init(struct termstyle_t *ts){
  ts->fd = fileno(stdout);
}

void set_termstyle(struct termstyle_t *ts, int fg, int bg){
  ts->color_fg = fg;
  ts->color_bg = bg;
}

void set_color_fg(struct termstyle_t *ts, int fg){
  ts->color_fg = fg;
}

void set_color_bg(struct termstyle_t *ts, int bg){
  ts->color_bg = bg;
}

void set_out(struct termstyle_t *ts, int fd){
  ts->fd = fd;
}

void clear_termstyle(struct termstyle_t *ts){
  ts->color_fg = TERMSTYLE_DEFAULT;
  ts->color_bg = TERMSTYLE_DEFAULT;
}

void ts_print(struct termstyle_t *ts, char *msg){
  int res; 
  char buf[MAXSIZE];

  res = snprintf(buf, MAXSIZE, "\033[%d;%dm%s\033[0m", ts->color_fg, ts->color_bg, msg);
  res = write(ts->fd, buf, res);
}

void ts_println(struct termstyle_t *ts, char *msg){
  int res;
  char buf[MAXSIZE];

  res = snprintf(buf, MAXSIZE, "\033[%d;%dm%s\033[0m\n", ts->color_fg, ts->color_bg, msg);
  res = write(ts->fd, buf, res);
}

void ts_clear(struct termstyle_t *ts){
  // \033[2J : clear entire screen
  cursor_set_home(ts);
  write(ts->fd, "\033[2J", 4);
}

void cursor_set_xy(struct termstyle_t *ts, int x, int y){
  // \033[%d;%dH : move cursor to position y, x
  char buf[MAXSIZE];
  int res = snprintf(buf, MAXSIZE, "\033[%d;%dH", y, x);
  write(ts->fd, buf, res);
}

void cursor_set_home(struct termstyle_t *ts){
  // \033[H  : return to (H)ome cursor position
  write(ts->fd, "\033[H", 4);
}

void cursor_save(struct termstyle_t *ts){
  write(ts->fd, "\033[s", 4);  
}

void cursor_load(struct termstyle_t *ts){
  write(ts->fd, "\033[u", 4);
}