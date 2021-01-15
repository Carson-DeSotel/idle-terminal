#define RESET 0

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

enum type_modes {
  BOLD       = 1,
  UNDERLINE  = 4,
  BLINK_ON   = 5,
  REVERSE_ON = 7,
  INVISIBLE  = 8,
};

void change_fg(int color);

void change_bg(int color);

void change_fg_bg(int c1, int c2);

void change_mode(int mode);

void color_clear();