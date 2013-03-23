#ifndef _DIALOG_H
#define _DIALOG_H 

#include <gtk/gtk.h>

typedef struct
{
	GtkWidget *data[6];
}TIME;

void really_quit(GtkWidget *widget,gpointer data);
void error_message(GtkWidget *widget,gchar *data);

#endif
