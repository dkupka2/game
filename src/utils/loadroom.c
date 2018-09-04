/* loads a character from saved character file and
   shows stats data */

#include <stdio.h>
#include "../game_structs.h"

int main(int argc, char * argv[]) {

  if (argc != 2) {
    printf("\nUsage: %s <room filename>\n\n", argv[0]);
    return 0;
  }

  printf("\nFilename: %s\n\n", argv[1]);

  FILE *fp = NULL;

  if (NULL == (fp = fopen(argv[1], "rb"))) {
    printf("Unable to open file '%s' for reading!\n", argv[1]);
    return -1;
  }

  Room_t r;

  fread(&r, sizeof(r), 1, fp);

  printf("File: %s\n", argv[1]);
  printf("r.room_id: %d\n", r.room_id);
  printf("r.s_desc: %s\n", r.s_desc);
  printf("r.l_desc: %s\n", r.l_desc);

  return 0;
}
