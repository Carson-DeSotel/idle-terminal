struct user {
  int fg_color;
  int max_level;
  char filename[15];
};

#define FILENAME "user.dat"

struct user user_init();
void user_to_file(struct user u);
struct user user_from_file();
void user_print(struct user u);