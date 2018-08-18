.SUFFIXES : .c .o



CC = gcc
CFLAGS = -g -c

TARGET = main
SOURCES = main.c send.c socket.c capture.c
OBJECTS = $(SOURCES:.c=.o)

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

.c.o : 
	$(CC) $(CFLAGS) $<

clean :
	rm -f $(OBJECTS)

main.o : main.c
send.o : send.c
socket.o : socket.c
capture.o : capture.c
