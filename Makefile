.SUFFIXES : .c .o



CC = gcc
CFLAGS = -g -c

TARGET = main
SOURCES = main.c sendImage.c
OBJECTS = $(SOURCES:.c=.o)

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

.c.o : 
	$(CC) $(CFLAGS) $<

clean :
	rm -f $(OBJECTS)

main.o : main.c
sendImage.o : sendImage.c
