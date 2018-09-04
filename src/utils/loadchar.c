/* loads a character from saved character file and
   shows stats data */

#include <stdio.h>
#include "../gamestructs.h"

int main(int argc, char * argv[]) {
  if (argc != 2) {
    printf("\nUsage: %s <character filename>\n\n", argv[0]);
    return 0;
  }

  printf("\nFilename: %s\n\n", argv[1]);

  FILE *fp = NULL;

  if (NULL == (fp = fopen(argv[1], "rb"))) {
    printf("Unable to open file '%s' for reading!\n", argv[1]);
    return -1;
  }

  Player_t p;

  fread(&p, sizeof(p), 1, fp);

  printf("name\t\tlvl\thp\tstr\tint\tdex\twis\tcha\tcon\tis_player\tcurrency\n\n");
  printf("%s\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\t%d\n", p.name, p.lvl, p.hp, p.str, p.intel, p.dex, p.wis, p.cha, p.con, p.is_player, p.currency);

  return 0;
}
