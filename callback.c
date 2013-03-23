#include "callback.h"
#include "dialog.h"
#include <string.h>
#include <time.h>

int change_data(const char *string);

void display_time(gpointer data)
{
	time_t t;
	char buf[30];

	t=time(NULL);
	snprintf(buf,strlen(ctime(&t)),"%s",ctime(&t));
	gtk_label_set_text(GTK_LABEL(data),buf);

}

void set_time(GtkWidget *widget,gpointer data)
{
	struct tm ti;
	time_t t;
	int i,tmp[6];
	TIME *day=(TIME *)data;

	for(i=0;i<6;i++)
		tmp[i]=change_data(gtk_entry_get_text(GTK_ENTRY(day->data[i])));

	if(tmp[0]<=1900)
	{
		error_message(widget,"输入的年份有误,请重新输入!");
		return;
	}
	if(tmp[1]<1 || tmp[1]>12)
	{
		error_message(widget,"输入的月份有误,请重新输入!");
		return;
	}
	if(tmp[2]<=0 || tmp[2]>31)
	{
		error_message(widget,"输入的日期有误,请重新输入!");
		return;
	}
	if(tmp[3]<=0 || tmp[3]>24)
	{
		error_message(widget,"输入的小时有误,请重新输入!");
		return;
	}
	if(tmp[4]<0 || tmp[4]>59)
	{
		error_message(widget,"输入的分钟数有误,请重新输入!");
		return;
	}
	if(tmp[5]<0 || tmp[5]>59)
	{
		error_message(widget,"输入的秒数有误,请重新输入!");
		return;
	}

	tmp[0]-=1900;
	ti.tm_year=tmp[0];
	ti.tm_mon=tmp[1];
	ti.tm_mday=tmp[2];
	ti.tm_hour=tmp[3];
	ti.tm_min=tmp[4];
	ti.tm_sec=tmp[5];

	t=mktime(&ti);
	stime(&t);
	error_message(widget,"设置成功!");
}

int change_data(const char *string)
{
	int data;

	sscanf(string,"%d",&data);
	
	return data;
}
