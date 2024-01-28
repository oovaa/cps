CC = gcc
CFLAGS = -Wall -Werror -g

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

tree: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f tree $(OBJ)
