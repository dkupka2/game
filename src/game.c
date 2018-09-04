#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_func.h"

int main(void) {
  char input = 0,
       char_name[20],
       file_name[30],
       temp_file[50];

  Player_t p;

  int player_file_exists = 0;

  /* clear screen */
  printf("\033c");

  printf("Enter a character name: ");
  fgets(char_name, 20, stdin);

  char_name[strlen(char_name)-1] = '\0';

  strcpy(p.name, char_name);
  strcat(strcpy(file_name, char_name), ".sav");
  file_name[strlen(file_name)] = '\0';

  strcpy(temp_file, file_name);
  strcat(temp_file, ".tmp");
  temp_file[strlen(temp_file)] = '\0';

  if ((player_file_exists = check_player_file(file_name)) == 1) {
    p = load_player(p, file_name);
  } else if ((player_file_exists = check_player_file(file_name)) == -1) {
    p = init_player(p);
    save_player(p, file_name);
  }

  print_player(p);

  printf("\nWelcome, %s!", p.name);

  while (input != '0') {
    print_menu();
    printf("Choose an option: ");
    scanf("%c", &input);

    switch(input) {
      case '0': cleanup(temp_file); save_player(p, file_name); return 0; break;
      case '1': getchar(); play_the_game(p); break;
      case '2': getchar(); about_the_game(); break;
      case '3': getchar(); delete_player(p); break;
      default: getchar(); printf("\nErr.. what?  Not an option!"); break;
    }
  }
  return 0;
}
