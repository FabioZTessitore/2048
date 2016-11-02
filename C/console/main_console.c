/* 2048 */

/* versione console */

#include <stdio.h>
#include <stdlib.h>
#include "board.h"

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

void clear_screen();
int user_choice();
void stampa_scacchiera(Board *b);
void stampa_lato_orizzontale(int, int);

int main()
{
  Board game_board;
  int direction;
  int moved = 0;
  int size;
  const int size_min = 2;
  const int size_max = 15;

  printf("\n\n\n2048 ... il gioco!\n");
  printf("******************\n\n");

  do {
    printf("Numero di celle per lato (%d-%d):\n", size_min, size_max);
    printf("? ");
    scanf("%d", &size);
  } while (size<size_min || size>size_max);

  board_init(&game_board, size);
  board_add_tile(&game_board);

  do {
    board_add_tile(&game_board);
    do {
      stampa_scacchiera(&game_board);
      direction = user_choice();

      switch(direction) {
        case UP:
          moved = board_tile_up(&game_board);
          break;
        case DOWN:
          moved = board_tile_down(&game_board);
          break;
        case LEFT:
          moved = board_tile_left(&game_board);
          break;
        case RIGHT:
          moved = board_tile_right(&game_board);
          break;
        default:
          fprintf(stderr, "input non valido, non doveva succedere\n");
          exit(-1);
          break;
      };
      clear_screen();
    } while (!moved);
  } while(board_some_cell_empty(&game_board));

  printf("\n\n\nGioco Finito!\n");
  printf("*************\n\n");
  
  board_destroy(&game_board);

  return 0;
}

void clear_screen() {
  int i = 35;
  for (; i>0; i--) {
    putchar('\n');
  }
}

int user_choice()
{
  int ch, temp;

  do {
    printf("\n\nh LEFT, j DOWN, k UP, l RIGHT\n? ");
    while ( (ch=getchar())!='\n' && ch!='h' && ch!='j' && ch!='k' && ch!='l' )
      ;

    if (ch!='\n') {
      while((temp=getchar())!='\n')
        ;
    }
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

void stampa_scacchiera(Board *b)
{
  int row, col;
  int cell_index;
  int tile_value;
  const int size_cella = 4;

  for (row=0; row<b->size; row++) {
    
    stampa_lato_orizzontale(b->size, size_cella);

    printf("   ");
    for (col=0; col<b->size; col++) {
      cell_index = col + row*b->size;
      tile_value = tile_get(board_get(b, cell_index));
      if (tile_value>0) {
        printf("|%4d", tile_value);
      } else {
        printf("|    ");
      }
    }
    printf("|\n");

  }
  stampa_lato_orizzontale(b->size, size_cella);
  putchar('\n');
}
void stampa_lato_orizzontale(int n_celle, int size_cella)
{
  int i, j;

  printf("   ");
  for (j=0; j<n_celle; j++) {
    putchar('+');
    for (i=0; i<size_cella; i++) putchar('-');
  }
  putchar('+');
  putchar('\n');
}
