#include <stdio.h>
#include <stdlib.h>

#include "../include/color.h"
#include "../include/user.h"

struct user user_init() {
  struct user u = { FG_WHITE, 1, FILENAME };
  return u;
}

void user_to_file(struct user u) {
  FILE* fout;
  fout = fopen(u.filename, "w");
  fprintf(fout, "%d;%d;%s", u.fg_color, u.max_level, u.filename);
  fclose(fout);
}

struct user user_from_file(char* filename) {
  FILE* fin;
  fin = fopen(filename, "r");
  if(fin == NULL) {
    printf("FILE NOT OPENED...\n");
    exit(1);
  }
  struct user u = {0, 0};
  fscanf(fin, "%d;%d;%s", &u.fg_color, &u.max_level, u.filename);

  fclose(fin);
  return u;
}

void user_print(struct user u) {
  printf("{ \n\tfg_color: %d\n\tmax_level: %d\n\tfilename: %s\n}\n", u.fg_color, u.max_level, u.filename);
}