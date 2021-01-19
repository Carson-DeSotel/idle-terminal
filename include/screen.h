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

/** 
 * Contains strings that correspond to the clear enum
 * enums cannot contain strings
 * Is input to the escape code.
 */

void clear(int mode);