#include <gtk/gtk.h>
#include "board.h"

Board game_board;
GtkWidget *window;
GtkWidget *board_container = NULL;

void create_board_grid();
void update_board_labels();

static gint
quit_activated (GSimpleAction *action,
                GVariant      *parameter,
                gpointer       app)
{
  board_destroy(&game_board);

  return TRUE;
}

void move_tiles(int ch)
{
  int moved = 0;

  switch(ch) {
    case 'h':
      moved = board_tile_left(&game_board);
      break;
    case 'j':
      moved = board_tile_down(&game_board);
      break;
    case 'k':
      moved = board_tile_up(&game_board);
      break;
    case 'l':
      moved = board_tile_right(&game_board);
      break;
    default:
      break;
  };
  if (moved) board_add_tile(&game_board);
  update_board_labels();
}

gboolean
key_to_board (GtkWidget *widget,
               GdkEvent  *event,
               gpointer   user_data)
{
  int ch;
  
  gdk_event_get_keyval (event, &ch);
  
  switch(ch) {
    case 'h':
    case 'j':
    case 'k':
    case 'l':
      move_tiles(ch);
      break;
    default:
      break;
  };
}

void create_board_grid()
{
  int col, row;
  int tile_value;
  int cell_index;
  char msg[80];

  board_container = gtk_grid_new();
  gtk_grid_set_column_homogeneous (GTK_GRID(board_container), TRUE); 
  gtk_grid_set_row_homogeneous (GTK_GRID(board_container), TRUE); 
  gtk_container_add(GTK_CONTAINER(window), board_container);

  for (row=0; row<SIZE; row++) {
    for (col=0; col<SIZE; col++) {
      cell_index = col + row*SIZE;
      tile_value = board_get_tile_value(&game_board, cell_index);
      if (tile_value>0) {
        sprintf(msg, "%d", tile_value);
      } else {
        msg[0] = '\0';
      }
      GtkWidget *a_frame = gtk_frame_new (NULL);
      GtkWidget *a_label = gtk_label_new(msg);
      gtk_container_add(GTK_CONTAINER(a_frame), GTK_WIDGET(a_label));
      gtk_grid_attach(GTK_GRID(board_container), a_frame, col, row, 1, 1);
    }
  }
  gtk_widget_show_all (window);
}

void update_board_labels()
{
  int row, col;
  int tile_value;
  int cell_index;
  char msg[80];

  for (row=0; row<SIZE; row++) {
    for (col=0; col<SIZE; col++) {
      cell_index = col + row*SIZE;
      tile_value = board_get_tile_value(&game_board, cell_index);
      if (tile_value>0) {
        sprintf(msg, "%d", tile_value);
      } else {
        msg[0] = '\0';
      }
      GtkWidget *a_frame = gtk_grid_get_child_at (GTK_GRID(board_container), col, row);
      GtkWidget *a_label = gtk_bin_get_child(GTK_BIN(a_frame));
      gtk_label_set_text(GTK_LABEL(a_label), msg);
    }
  }
  gtk_widget_show_all (window);
}

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  board_init(&game_board);
  board_add_tile(&game_board);
  board_add_tile(&game_board);

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "2048");
  gtk_window_set_default_size (GTK_WINDOW (window), 600, 600);
  g_signal_connect(window, "key_release_event", G_CALLBACK(key_to_board), NULL);
  g_signal_connect (window, "destroy", G_CALLBACK (quit_activated), NULL);

  create_board_grid();

  gtk_widget_show_all (window);
}


int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
