#include "dialog.h"
#include "callback.h"
#include <stdio.h>

int main(int argc,char **argv)
{
	GtkWidget *win;
	GtkWidget *vbox;
	GtkWidget *hbox;
	GtkWidget *ok;
	GtkWidget *quit;
	GtkWidget *menu_bar;
	GtkWidget *menu;
	GtkWidget *label;
	TIME data;
	guint loop_t;

	gtk_init(&argc,&argv);

	win=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(win),GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(win),"TimeSetter");
	g_signal_connect(G_OBJECT(win),"delete_event",G_CALLBACK(really_quit),NULL);

	vbox=gtk_vbox_new(FALSE,0);
	gtk_container_add(GTK_CONTAINER(win),vbox);
	hbox=gtk_hbox_new(FALSE,0);

	gtk_box_pack_start(GTK_BOX(vbox),hbox,FALSE,FALSE,0);
	label=gtk_label_new("当前时间为:");
	gtk_box_pack_start(GTK_BOX(hbox),label,FALSE,FALSE,5);
	label=gtk_label_new("00:00:00");
	gtk_box_pack_start(GTK_BOX(hbox),label,FALSE,FALSE,5);
	loop_t=g_timeout_add(1000,(GSourceFunc)display_time,label);

	gtk_box_pack_start(GTK_BOX(vbox),gtk_hseparator_new(),FALSE,FALSE,5);
	char *text[]={"年: ","月: ","日: ","时: ","分: ","秒: "};
	int i;
	for(i=0;i<6;++i)
	{
		hbox=gtk_hbox_new(FALSE,0);
		label=gtk_label_new(text[i]);
		data.data[i]=gtk_entry_new();
		gtk_box_pack_start(GTK_BOX(vbox),hbox,FALSE,FALSE,5);
		gtk_box_pack_start(GTK_BOX(hbox),label,FALSE,FALSE,0);
		gtk_box_pack_start(GTK_BOX(hbox),data.data[i],FALSE,FALSE,0);
	}

	gtk_box_pack_start(GTK_BOX(vbox),gtk_hseparator_new(),FALSE,FALSE,5);

	ok=gtk_button_new_with_label("OK");
	quit=gtk_button_new_with_label("Quit");
	hbox=gtk_hbox_new(FALSE,0);
	gtk_box_pack_start(GTK_BOX(vbox),hbox,FALSE,FALSE,5);
	gtk_box_pack_start(GTK_BOX(hbox),ok,FALSE,FALSE,5);
	gtk_box_pack_end(GTK_BOX(hbox),quit,FALSE,FALSE,5);
	g_signal_connect(G_OBJECT(ok),"clicked",G_CALLBACK(set_time),&data);
	g_signal_connect(G_OBJECT(quit),"clicked",G_CALLBACK(really_quit),NULL);

	gtk_widget_show_all(win);
	gtk_main();
	g_source_remove(loop_t);
	return 0;

}
