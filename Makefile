CC = mpicc
CFLAGS = -g -Wall -pedantic -std=c17 -fopenmp
LDFLAGS = -lm

BIN = funkygrad

SRCS = src/main.c \
			src/graph.c \
			src/f_matrix.c \
			src/utils.c \
			src/operations.c

OBJS = $(SRCS:/c=.o)

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(BIN)
