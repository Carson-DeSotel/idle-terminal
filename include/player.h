struct player_t {
  struct bar_t *bar;
  int max_level;
  char save_file[MAXSIZE];
};

#define MAX_FILENAME 128
#define DEFAULT_SAVENAME "user.dat"

void player_init(struct player_t *plr, struct bar_t *bar);
void player_save(struct player_t *plr);
void player_load(struct player_t *plr, char *filename);