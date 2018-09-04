/* loads a room from saved room file and
   allows editing of data */

#include <stdio.h>
#include <string.h>
#include "../game_structs.h"

Room_t load_room(Room_t r, char * roomfile) {

  printf("\nFilename: %s\n\n", roomfile);

  FILE *fp = NULL;

  if (NULL == (fp = fopen(roomfile, "rb"))) {
    printf("Unable to open file '%s' for reading!\n", roomfile);
    return r;
  }

  fread(&r, sizeof(r), 1, fp);

  printf("File: %s\n", roomfile);
  printf("r.room_id: %d\n", r.room_id);
  printf("r.s_desc: %s\n", r.s_desc);
  printf("r.l_desc: %s\n", r.l_desc);

  return r;
}

/* saves a room to a room file after 
   generating stats data */
/* char '0' = 48         */

int save_room(Room_t r, char *roomfile) {

  int neswud;
  char c_neswud[] = "neswud", temp = 0;

  printf("Enter room id (int): ");
  scanf("%d", &r.room_id);
  getchar();

  printf("Enter short room description (48 chars): ");
  fgets(r.s_desc, 48, stdin);
  r.s_desc[strlen(r.s_desc) - 1] = '\0';

  printf("Enter long room description (256 chars): ");
  fgets(r.l_desc, 256, stdin);
  r.l_desc[strlen(r.l_desc) - 1] = '\0';

  for (int i = 0; i < 6; i++) {
    printf("Exit %c (1 = yes, 0 = no)? ", c_neswud[i]);
    scanf("%d", &neswud);
    temp += (i + 1) << 2;
    printf("%d\n", temp);
  }

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

void print_menu(void) {
  printf("(L)oad file for editing.\n");
  printf("(S)ave file.\n");
  printf("(Q)uit\n > ");
}

int main(int argc, char * argv[]) {
  if (argc < 2) {
    printf("Usage: %s <filename>\n\n", argv[1]);
    return 0;
  }

  Room_t r;
  char ch = 0;

  print_menu();
  scanf("%c", &ch);
  getchar();
  switch(ch) {
    case 'L': r = load_room(r, argv[1]); break;
    case 'l': r = load_room(r, argv[1]); break;
    case 'S': save_room(r, argv[1]); break;
    case 's': save_room(r, argv[1]); break;
    case 'Q': return 0; break;
    case 'q': return 0; break;
    default: printf("Invalid option\n\n"); break;
  }

  return 0;
}
