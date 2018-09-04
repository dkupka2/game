/* loads a room from saved room file and
   shows stats data */

/* exits expressed as int from 0-63 */

#include <stdio.h>
#include "game_func.h"

Room_t load_room(Room_t r) {

  FILE *fp = NULL;

  char room[] = "rooms//0.rmv";

  if (NULL == (fp = fopen(room, "rb"))) {
    printf("Unable to open file '%s' for reading!\n", room);
    return r;
  }

  fread(&r, sizeof(r), 1, fp);

  printf("File: %s\n", room);
  printf("r.room_id: %d\n", r.room_id);
  printf("r.s_desc: %s\n", r.s_desc);
  printf("r.l_desc: %s\n", r.l_desc);

  return r;
}
