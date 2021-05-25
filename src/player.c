#include "headers.h"

void player_init(struct player_t *plr, struct bar_t *bar){
  plr->bar = bar;
  plr->max_level = 1;
  strncpy(plr->save_file, DEFAULT_SAVENAME, MAX_FILENAME);
}

void player_save(struct player_t *plr){
  int fd = open(plr->save_file, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
  if(fd == -1){
    perror("Couldn't open outfile \n");
    return;
  }
  write(fd, plr->bar, sizeof(struct bar_t));
  write(fd, &plr->max_level, sizeof(int));
}

void player_load(struct player_t *plr, char *filename){
  int fd = open(filename, O_RDONLY);
  if(fd == -1){
    perror("Couldn't open outfile\n");
    return;
  }
  read(fd, plr->bar, sizeof(struct bar_t));
  read(fd, &plr->max_level, sizeof(int));
  strncpy(plr->save_file, filename, MAX_FILENAME);
}