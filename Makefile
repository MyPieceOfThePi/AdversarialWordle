CC = gcc
CFLAGS = -Iinclude
SRCS = $(wildcard src/*.c)
TARGET = AdvWordle

all:
	$(CC) $(CFLAGS) $(SRCS) -g -o $(TARGET)

clean:
	rm -f $(TARGET)