/* saves a character to a character file after 
   generating stats data */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../gamestructs.h"

int main(void) {

  srand(time(NULL));
  Player_t p;
  printf("Enter a character name: ");
  fgets(p.name, 20, stdin);
  p.name[strlen(p.name) - 1] = '\0';

  printf("\nYou entered: %s\n\n", p.name);

  p.lvl = 1;
  p.hp = 100;
  p.str = (rand() % 20) + 1;
  p.intel = (rand() % 20) + 1;
  p.dex = (rand() % 20) + 1;
  p.wis = (rand() % 20) + 1;
  p.cha = (rand() % 20) + 1;
  p.con = (rand() % 20) + 1;
  p.is_player = 0;
  p.currency = 0;

  FILE *fp = NULL;

  char ch = 0, filename[30], temp_name[20];

  strcpy(temp_name, p.name);

  strcpy(filename, strcat(temp_name, ".sav"));
  filename[strlen(filename)] = '\0';
  printf("\nFile: %s\n", filename);
  if (NULL != (fp = fopen(filename, "rb"))) {
    printf("File '%s' already exists - do you want to overwrite (y / n) ? ", filename);
    scanf("%c", &ch);

    if (ch == 'n' || ch == 'N') {
      printf("Bye\n");
      fclose(fp);
      return 0;
    } else if (ch == 'y' || ch == 'Y') {
      if (NULL == (fp = fopen(filename, "wb"))) {
        printf("Unable to open file '%s' for writing!\n", filename);
        return -1;
      }
      fwrite(&p, sizeof(p), 1, fp);
    } else {
      printf("Invalid option.  Aborting.\n");
      return 0;
    }
  }

  if (NULL == (fp = fopen(filename, "wb"))) {
    printf("Unable to open file '%s' for writing!\n", filename);
    return -1;
  }
  printf("File: %s\n", filename);
  fwrite(&p, sizeof(p), 1, fp);

  fclose(fp);

  /* name, str, intel, dex, wis, cha, con, is_player, currency */
  printf("name\t\tlvl\thp\tstr\tint\tdex\twis\tcha\tcon\tis_player\tcurrency\n\n");
  printf("%s\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\t%d\n", p.name, p.lvl, p.hp, p.str, p.intel, p.dex, p.wis, p.cha, p.con, p.is_player, p.currency);

  return 0;
}
