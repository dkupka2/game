#include "game_structs.h"

void print_menu(void);

void about_the_game(void);

int play_the_game(Player_t);

int delete_player(Player_t);

Player_t init_player(Player_t);

int check_player_file(char *);

Player_t load_player(Player_t, char *);

Player_t save_player(Player_t, char *);

int save_player_backup(Player_t, char *);

void print_player(Player_t);

Room_t load_room(Room_t);

int save_room(Room_t, const char *);

int cleanup(char *);
