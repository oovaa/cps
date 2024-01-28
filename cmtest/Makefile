# Comments start with a '#'

# Variables
CC = gcc
CFLAGS = -Wall -O2 -g

# Target and dependencies
all: my_program

# Rule to build the executable
my_program: main.c f1.c
	$(CC) $(CFLAGS) -o x *.c

# Clean rule
clean:
	@echo "cleaning"
	@rm -f x
