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

int welcome(int size_min, int size_max);
void stampa_lato_orizzontale(int, int, int, int);
void stampa_scacchiera(Board *b);
int user_choice();

int main()
{
  Board game_board;
  int direction;
  int moved = 0;
  int halted = 0;
  const int size_min = 2;
  const int size_max = 15;
  int size = 4;

  initscr();
  raw();
  keypad(stdscr, TRUE);
  start_color();

  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_BLACK, COLOR_CYAN);
  init_pair(3, COLOR_BLACK, COLOR_BLUE);
  init_pair(4, COLOR_BLACK, COLOR_GREEN);
  init_pair(5, COLOR_BLACK, COLOR_YELLOW);
  init_pair(6, COLOR_BLACK, COLOR_RED);

  do {
    size = welcome(size_min, size_max);
  } while (size<size_min || size>size_max);

  curs_set(0);
  noecho();

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

int welcome(int size_min, int size_max)
{
  int row = 5;
  int col = 0;
  char msg[80];
  int msg_len;
  int size;

  strcpy(msg, "2048 - Il Gioco");
  msg_len = strlen(msg);
  col = (COLS-msg_len)/2;
  mvprintw(row, col, msg);

  msg_len = 8;
  col = (COLS-msg_len)/2;
  strcpy(msg, "h - LEFT");
  mvprintw(row+2, col, msg);
  strcpy(msg, "j - DOWN");
  mvprintw(row+3, col, msg);
  strcpy(msg, "k - UP");
  mvprintw(row+4, col, msg);
  strcpy(msg, "l - RIGHT");
  mvprintw(row+5, col, msg);

  sprintf(msg, "Numero di celle per lato (%d-%d): ", size_min, size_max);
  msg_len = strlen(msg);
  col = (COLS-msg_len)/2;
  mvprintw(row+8, col, msg);
  mvscanw(row+8, col+msg_len+2, "%d", &size);
  /*
  msg = "(Premi un tasto per iniziare)";
  msg_len = strlen(msg);
  col = (COLS-msg_len)/2;
  mvprintw(row+8, col, msg);
  */

  refresh();
  /*
  getch();
  */
  clear();

  return size;
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
  int cod_color = 1;

  row = 0;
  col = (COLS-b->size*size_cella-5)/2;

  for (i=0; i<b->size; i++) {
    col = (COLS-b->size*size_cella-5)/2;
    
    stampa_lato_orizzontale(row, col, b->size, size_cella);
    row++;

    for (j=0; j<b->size; j++) {
      cell_index = j + i*b->size;
      tile_value = tile_get(board_get(b, cell_index));
      if (tile_value>0) {
        mvaddch(row, col++, '|');
        if (tile_value >= 1024) {
          cod_color = 6;
        } else if (tile_value >= 256) {
          cod_color = 5;
        } else if (tile_value >= 64) {
          cod_color = 4;
        } else if (tile_value >= 16) {
          cod_color = 3;
        } else if (tile_value >= 8) {
          cod_color = 2;
        } else {
          cod_color = 1;
        }
        attron(COLOR_PAIR(cod_color));
        mvprintw(row, col, "%4d", tile_value);
        attroff(COLOR_PAIR(cod_color));
        col += 4;
      } else {
        mvprintw(row, col, "|    ");
        col += 5;
      }
    }
    mvprintw(row, col, "|");
    row++;

  }
  col = (COLS-b->size*size_cella-5)/2;
  stampa_lato_orizzontale(row, col, b->size, size_cella);
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
