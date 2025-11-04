CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
LDFLAGS = -lm
TARGET = programa
SRCS = main.c arena.c chao.c circulo.c colisao.c criarsvg.c criartxt.c disparador.c fila.c geo.c linha.c movimento.c pilha.c qry.c retangulo.c texto.c
OBJS = $(SRCS:.c=.o)
DEPS = arena.h chao.h circulo.h colisao.h criarsvg.h criartxt.h disparador.h fila.h geo.h linha.h movimento.h pilha.h qry.h retangulo.h texto.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
