CC              = cc
CFLAGS          = -std=c11 -I. -O1 -Wall
SRCS            = $(wildcard *.c)
OBJS            = $(SRCS:.c=.o)
BIN				= sorterlab

.PHONY : all clean
.DEFAULT_GOAL = all

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all: $(BIN)

clean:
	@rm -f $(OBJS) $(BIN)
