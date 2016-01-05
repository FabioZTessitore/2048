/* 2048 */

/* versione ncurses */

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define HALT 5

void welcome();
void stampa_lato_orizzontale(int, int, int, int);
void stampa_scacchiera(Board *b);
int user_choice();

int main()
{
  Board game_board;
  int direction;
  int moved = 0;
  int halted = 0;

  initscr();
  noecho();
  curs_set(0);
  raw();
  keypad(stdscr, TRUE);

  board_init(&game_board);
  board_add_tile(&game_board);


  welcome();

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
        case HALT:
          halted = 1;
          break;
        default:
          fprintf(stderr, "input non valido, non avrebbe dovuto succedere\n");
          exit(-1);
          break;
      };
      clear();
    } while (!moved && !halted);
  } while(board_some_cell_empty(&game_board) && !halted);

  board_destroy(&game_board);

  endwin();

  return 0;
}

void welcome()
{
  int row = 5;
  int col = 0;
  char *msg;
  int msg_len;

  msg = "2048 - Il Gioco";
  msg_len = strlen(msg);
  col = (COLS-msg_len)/2;
  mvprintw(row, col, msg);

  msg_len = 8;
  col = (COLS-msg_len)/2;
  msg = "h - LEFT";
  mvprintw(row+2, col, msg);
  msg = "j - DOWN";
  mvprintw(row+3, col, msg);
  msg = "k - UP";
  mvprintw(row+4, col, msg);
  msg = "l - RIGHT";
  mvprintw(row+5, col, msg);

  msg = "(Premi un tasto per iniziare)";
  msg_len = strlen(msg);
  col = (COLS-msg_len)/2;
  mvprintw(row+8, col, msg);

  refresh();
  getch();
  clear();
}

void stampa_lato_orizzontale(int row, int col, int n_celle, int size_cella)
{
  int i, j;


  for (j=0; j<n_celle; j++) {
    mvaddch(row, col++, '+');
    for (i=0; i<size_cella; i++) mvaddch(row, col++, '-');
  }
  mvaddch(row, col++, '+');
}

void stampa_scacchiera(Board *b)
{
  int i, j;
  int cell_index;
  int tile_value;
  const int size_cella = 4;
  int row, col;

  row = 10;
  col = (COLS-SIZE*size_cella-5)/2;

  for (i=0; i<SIZE; i++) {
    col = (COLS-SIZE*size_cella-5)/2;
    
    stampa_lato_orizzontale(row, col, SIZE, size_cella);
    row++;

    for (j=0; j<SIZE; j++) {
      cell_index = j + i*SIZE;
      tile_value = board_get_tile_value(b, cell_index);
      if (tile_value>0) {
        mvprintw(row, col, "|%4d", tile_value);
      } else {
        mvprintw(row, col, "|    ");
      }
      col += 5;
    }
    mvprintw(row, col, "|");
    row++;

  }
  col = (COLS-SIZE*size_cella-5)/2;
  stampa_lato_orizzontale(row, col, SIZE, size_cella);
  row++;

  refresh();
}

int user_choice()
{
  int c;
  char *msg;
  int msg_len;
  int col;

  do {
    msg = "(h - LEFT   j - DOWN   k - UP   l - RIGHT)";
    msg_len = strlen(msg);
    col = (COLS-msg_len)/2;
    mvprintw(LINES-3, col, msg);

    msg = "<<< F2 per uscire >>>";
    msg_len = strlen(msg);
    col = (COLS-msg_len)/2;
    mvprintw(LINES-2, col, msg);

    refresh();

    c = getch();

    switch(c) {
      case 'j':
        c = DOWN;
        break;
      case 'k':
        c = UP;
        break;
      case 'h':
        c = LEFT;
        break;
      case 'l':
        c = RIGHT;
        break;
      case KEY_F(2):
        c = HALT;
        break;
      default:
        c = 0;
    };
  } while (c==0);

  return c;
}
