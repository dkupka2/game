#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_func.h"

void print_menu(void) {
  printf("\nThe Game\n");
  printf("========\n");
  printf("1. Start The Game\n");
  printf("2. About The Game\n");
  printf("3. Delete character\n");
  printf("0. Quit\n");
}

void about_the_game(void) {
  printf("\nAbout The Game\n");
  printf("==============\n");
  printf("It's a game...!  Or... something.\nBut... it works!\n");
  printf("Created in stupidity by Dan Kupka\n");
}

int play_the_game(Player_t p) {
  char cmdstr[255];
  Room_t r;

  printf("%s logged in...\n\n", p.name);

  while (strcmp(cmdstr, "quit") != 0) {
    load_room(r);
    printf("%s\n\n%s\n\n", r.s_desc, r.l_desc);
    printf("> ");
    fgets(cmdstr, 255, stdin);
    cmdstr[strlen(cmdstr)-1] = '\0';
    printf("Command string: %s\n", cmdstr);
  }
  return 0;
}

int roll_die(int sides) {
  return (rand() % sides) + 1;
}
