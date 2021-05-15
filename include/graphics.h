enum fg_colors {
  FG_BLACK   = 30,
  FG_RED     = 31,
  FG_GREEN   = 32,
  FG_YELLOW  = 33,
  FG_BLUE    = 34,
  FG_MAGENTA = 35,
  FG_CYAN    = 36,
  FG_WHITE   = 37,
};

enum bg_colors {
  BG_BLACK   = 40,
  BG_RED     = 41,
  BG_GREEN   = 42, 
  BG_YELLOW  = 43,
  BG_BLUE    = 44,
  BG_MAGENTA = 45,
  BG_CYAN    = 46,
  BG_WHITE   = 47,
};

struct termstyle_t {
  int color_fg;
  int color_bg;
  int fd;
};

#define TERMSTYLE_DEFAULT -1
#define TERMSTYLE_STDOUT stdout

#define MAXSIZE 1024

void ts_init(struct termstyle_t *ts);

void set_termstyle(struct termstyle_t *ts, int fg, int bg);
void set_color_fg(struct termstyle_t *ts, int color);
void set_color_bg(struct termstyle_t *ts, int color);
void set_out(struct termstyle_t *ts, int fd);

void clear_termstyle(struct termstyle_t *ts);

void ts_print(struct termstyle_t *ts, char* msg);
void ts_println(struct termstyle_t *ts, char *msg);

void ts_clear(struct termstyle_t *ts);

void cursor_set_xy(struct termstyle_t *ts, int x, int y);
void cursor_set_home(struct termstyle_t *ts);
void cursor_save(struct termstyle_t *ts);
void cursor_load(struct termstyle_t *ts);