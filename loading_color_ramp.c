#include <stdio.h>
#include <unistd.h>
#include "ansi.h"

#define MAX 100

int main() {
  for(int i = 0; i < MAX; i += 1) {
    // set color ramp:
    if      (i < (MAX / 4)){ change_fg(BLUE); }
    else if (i < (MAX / 2)){ change_fg(GREEN); }
    else if (i < (3 * MAX / 4)){ change_fg(YELLOW); }
    else            { change_fg(RED); }

    // display progress:
    printf("[");
    for(int j = 0; j < 100; j += 1) {
      if(j <= i){
        printf("#");
      } else {
        printf("-");
      }
    }
    printf("]\r");
    fflush(stdout);
    usleep(250000);
  }
  clear(ENTIRE_LINE);
}