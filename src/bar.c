#include "headers.h"

void bar_init(struct bar_t *b, struct termstyle_t *ts, 
              int max, char *full, char *empty) {
  b->percent    = 0.0;
  b->max_len    = max;
  b->full       = full;
  b->empty      = empty;
  b->ts         = ts;
}

void print_bar(struct bar_t *b) {
  for(int i = 1; i <= b->max_len; i += 1){
    if((b->percent * b->max_len) >= i){
      ts_print(b->ts, b->full);
    }
    else{
      ts_print(b->ts, b->empty);
    }
  }
  char buf[MAXSIZE];
  snprintf(buf, MAXSIZE, "\t%.2f%%", b->percent * 100);
  ts_print(b->ts, buf);
  // ts_println(b->ts, "");
}

void print_loading(struct bar_t *b){
  for(int p = 1; p <= MAX_PERCENT; p += 1){
    b->percent = (p / (1.0 * MAX_PERCENT));
    ts_print(b->ts, "[ lvl 1 ] ");
    print_bar(b);
    usleep(25000);
    ts_print(b->ts, "\r");
  }
}