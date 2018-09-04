/* saves a room to a room file after 
   generating stats data */
/* char '0' = 48         */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../game_structs.h"

int main(void) {

  srand(time(NULL));

  Room_t r;

  printf("Enter room id (int): ");
  scanf("%d", &r.room_id);
  getchar();

  printf("Enter short room description (48 chars): ");
  fgets(r.s_desc, 48, stdin);
  r.s_desc[strlen(r.s_desc) - 1] = '\0';

  printf("Enter long room description (256 chars): ");
  fgets(r.l_desc, 256, stdin);
  r.l_desc[strlen(r.l_desc) - 1] = '\0';

  printf("\nYou entered: %s\n\n", r.s_desc);

  FILE *fp = NULL;

  char ch = 0, room_num[2], filename[30], temp_name[20];

  room_num[0] = r.room_id + 48;
  room_num[1] = '\0';

  strcpy(temp_name, room_num); 

  strcpy(filename, strcat(temp_name, ".rmv"));
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
      fwrite(&r, sizeof(r), 1, fp);
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
  fwrite(&r, sizeof(r), 1, fp);

  fclose(fp);

  return 0;
}
