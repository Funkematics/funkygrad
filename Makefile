CC = gcc
CFLAGS = -g -Wall -pedantic -std=c17
LDFLAGS = -lm

BIN = funkygrad

SRCS = src/main.c

OBJS = $(SRCS:/c=.o)

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(BIN)
