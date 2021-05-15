#define BLOCK "\u2588"
#define LIGHT "\u2591"

#define MAX_PERCENT 100

struct bar_t {
  double percent;
  int max_len;
  char* full;
  char* empty;
  struct termstyle_t *ts;
};

void bar_init(struct bar_t *b, struct termstyle_t *ts, int max, char *full, char *empty);
void set_bar_colors(struct bar_t *b, int fg, int bg);
void print_bar(struct bar_t *b);
void print_loading(struct bar_t *b);