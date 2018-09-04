all: game

game:
	gcc -Wall -Wextra -Ofast -o game game.c gamefunc.c load_player.c
