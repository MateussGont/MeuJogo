# Compilador
CC=gcc

# Arquivos fonte .c
SRCS=$(wildcard *.c)

# Arquivos objeto .o
OBJS=$(SRCS:.c=.o)

# Nome do executável
EXEC=main

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $@ $^ -lncurses

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJS)
