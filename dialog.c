#include "dialog.h"

void really_quit(GtkWidget *widget,gpointer data)
{
	GtkWidget *dialog;
	GtkWidget *label;
	gint status;

	dialog=gtk_dialog_new();
	gtk_window_set_title(GTK_WINDOW(dialog),"Really Quit?");
	label=gtk_label_new("Are You Really Want to Quit Application Now?\nClick OK To Quit,Click NO To Continue!");
	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog)->vbox),label,FALSE,FALSE,5);
	gtk_widget_show(label);

	gtk_dialog_add_buttons(GTK_DIALOG(dialog),GTK_STOCK_NO,GTK_RESPONSE_NO,GTK_STOCK_OK,GTK_RESPONSE_OK,NULL);

	status=gtk_dialog_run(GTK_DIALOG(dialog));

	switch(status)
	{
		case GTK_RESPONSE_NO:
			break;
		case GTK_RESPONSE_OK:
			gtk_main_quit();
		default:
			break;
	}

	gtk_widget_destroy(dialog);
}

void error_message(GtkWidget *widget,gchar *error)
{
	GtkWidget *dialog;

	dialog=gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"%s\n",error);

	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);

	//gtk_main_quit();
}
