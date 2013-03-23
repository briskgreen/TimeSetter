PKG=`pkg-config --cflags --libs gtk+-2.0`

timesetter:timesetter.o dialog.o callback.o
	gcc -o timesetter timesetter.o dialog.o callback.o $(PKG)

timesetter.o:timesetter.c dialog.h
	gcc -c timesetter.c $(PKG)

dialog.o:dialog.c dialog.h 
	gcc -c dialog.c $(PKG)

callback.o:callback.h dialog.h callback.c
	gcc -c callback.c $(PKG)

clean:
	rm timesetter *.o
