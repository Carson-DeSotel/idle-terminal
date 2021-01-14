#define ESC "\033"

enum colors {
  BLACK   = 30,
  RED     = 31,
  GREEN   = 32,
  YELLOW  = 33,
  BLUE    = 34,
  MAGENTA = 35,
  CYAN    = 36,
  WHITE   = 37,
  RESET   = 0,
};

enum clear {
  SCREEN,
  CURSOR_TO_END,
  CURSOR_TO_BEGIN,
  ENTIRE_SCREEN,
  LINE,
  CURSOR_TO_END_LINE,
  CURSOR_TO_BEGIN_LINE,
  ENTIRE_LINE,
};

const char* clear_strings[] = {
  "J",
  "\0J",
  "1J",
  "2J",
  "K",
  "\0K",
  "1K",
  "2K", 
};

void change_fg(int color){
  printf("\033[%dm", color);
}

void clear(int mode) {
  printf("\033[%s", clear_strings[mode]);
}