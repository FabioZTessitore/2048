#include <gtk/gtk.h>

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  GtkWidget *window;

  int i;
  int j;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "2048");
  gtk_window_set_default_size (GTK_WINDOW (window), 600, 600);

  GtkWidget *board_container = gtk_grid_new();
  gtk_grid_set_column_homogeneous ((GtkGrid*)board_container, TRUE); 
  gtk_grid_set_row_homogeneous ((GtkGrid*)board_container, TRUE); 
  for (j=0; j<4; j++) {
    gtk_grid_insert_row((GtkGrid*)board_container, j);
  }
  for (i=0; i<4; i++) {
    gtk_grid_insert_column((GtkGrid*)board_container, i);
  }
  gtk_container_add(GTK_CONTAINER(window), board_container);

  for (j=0; j<4; j++) {
  for (i=0; i<4; i++) {
    char msg[80];
    sprintf(msg, "Test %d %d", j, i);
    GtkWidget *a_label = gtk_label_new(msg);
    gtk_label_set_xalign((GtkLabel*)a_label, 0.5);

    /* assegnare gli handler */

    /* assegnare qui gli elementi al container */
    gtk_grid_attach((GtkGrid*)board_container, a_label, i, j, 1, 1);
  }
  }

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
