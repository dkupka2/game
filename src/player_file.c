/* player file handling facilities */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game_func.h"

void print_player(Player_t p) {
/* p.name, p.lvl, p.hp, p.str, p.intel, p.dex, p.wis, p.cha, p.con,p.
   is_player, p.currency */
  printf("Name: %s\tLevel: %d, HP: %d\nSTR: %d, INT: %d, DEX: %d\n", p.name, p.lvl, p.hp, p.str, p.intel, p.dex);
  printf("WIS: %d, CHA: %d, CON: %d\n", p.wis, p.cha, p.con);
  printf("IS_PLAYER: %d, CURRENCY: %d\n", p.is_player, p.currency);
}

Player_t init_player(Player_t p) {
  srand(time(NULL));

  p.lvl = 1;
  p.hp = 100;
  p.str = (rand() % 20) + 1;
  p.intel = (rand() % 20) + 1;
  p.dex = (rand() % 20) + 1;
  p.wis = (rand() % 20) + 1;
  p.cha = (rand() % 20) + 1;
  p.con = (rand() % 20) + 1;
  p.is_player = 1;
  p.currency = 0;

  return p;
}

int check_player_file(char * file_name) {
  FILE *fp = NULL;

  if (NULL == (fp = fopen(file_name, "rb"))) {
    return -1;
  }
  if (NULL != (fp = fopen(file_name, "rb"))) {
    fclose(fp);
    return 1;
  }
  return 0;
}

Player_t save_player(Player_t p, char * file_name) {

  FILE *fp = NULL;

  if (NULL == (fp = fopen(file_name, "rb"))) {
    printf("New player, creating player file '%s'...\n", file_name);

    if (NULL == (fp = fopen(file_name, "wb"))) {
      printf("Unable to open player file for writing... Aborting.\n");
      return p = init_player(p);
    }
  }
  return p;
}

int save_player_backup(Player_t p, char * bkup_file_name) {

  FILE *fp = NULL;
  
  if (NULL != (fp = fopen(bkup_file_name, "rb"))) {
    fclose(fp);
    printf("Writing data to '%s'...\n", bkup_file_name);
    fp = fopen(bkup_file_name, "wb");
    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);
  }

  return 0;
}

int delete_player(Player_t p) {
  char choice_yn = 0,
       char_name[20],
       file_name[30];

  printf("Delete player '%s' ?  Are you sure (y/n) ? ", p.name);
  scanf("%c", &choice_yn);
  getchar();
  
  strcpy(file_name, strcat(strcpy(char_name, p.name), ".sav"));
  file_name[strlen(file_name)] = '\0';

  switch(choice_yn) {
    case 'y': { printf("Deleting %s...", char_name); remove(file_name); } break;
    case 'Y': { printf("Deleting %s...", char_name); remove(file_name); } break;
    case 'n': break;
    case 'N': break;
    default: printf("Sorry, I don't understand..."); break;
  }
  return 0;
}

Player_t load_player(Player_t p, char * file_name) {

  FILE *fp = NULL;

  printf("load_player p.name: %s\n", p.name);
  printf("\nFile name: %s\n\n", file_name);

  if (NULL == (fp = fopen(file_name, "rb"))) {
    printf("File '%s' does not exist...\n\n", file_name);
  }

  if (NULL != (fp = fopen(file_name, "rb"))) {
    fread(&p, sizeof(p), 1, fp);
  }

  return p;
}

int cleanup(char *temp_file) {
  if (0 != remove(temp_file)) {
    printf("Unable to remove temporary file, this must be done manually\n");
    return -1;
  }
  return 0;
}
