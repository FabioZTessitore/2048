#include <stdio.h>
#include <stdlib.h>
#include "board.h"

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

void clear_screen() {
  int i = 25;
  for (; i>0; i--) {
    putchar('\n');
  }
}

int user_choice()
{
  int ch, temp;

  do {
    ch = getchar();
  
    while((temp=getchar())!='\n')
      ;

  } while (ch!='h' && ch!='j' && ch!='k' && ch!='l');

  switch(ch) {
    case 'j':
      ch = DOWN;
      break;
    case 'k':
      ch = UP;
      break;
    case 'h':
      ch = LEFT;
      break;
    case 'l':
      ch = RIGHT;
      break;
    default:
      ch = 0;
  };

  return ch;
}

int main()
{
  Board game_board;
  int direction;

  printf("2048 ... il gioco!\n\n\n");

  board_init(&game_board);
  
  board_add_tile(&game_board);

  do {
    board_add_tile(&game_board);
    board_dump(&game_board);
    direction = user_choice();
    printf("direction: %d\n", direction);

    switch(direction) {
      case UP:
        board_tile_up(&game_board);
        break;
      case DOWN:
        board_tile_down(&game_board);
        break;
      case LEFT:
        board_tile_left(&game_board);
        break;
      case RIGHT:
        board_tile_right(&game_board);
        break;
      default:
        printf("input non valido, non avrebbe dovuto succedere\n");
        exit(-1);
        break;
    };
    clear_screen();
  } while(board_get_freepos(&game_board) && board_some_cell_empty(&game_board));
  
  board_destroy(&game_board);

  return 0;
}
