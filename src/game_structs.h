typedef struct player {

  char name[50];

  int lvl,
      hp,
      str,
      intel,
      dex,
      wis,
      cha,
      con,
      is_player,
      currency;

} Player_t;

typedef struct room {

  int room_id,
      objects[16];

  char s_desc[48],
       l_desc[256];

} Room_t;
