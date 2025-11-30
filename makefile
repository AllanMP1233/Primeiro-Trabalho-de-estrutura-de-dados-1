CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
LIBS = -lm

SRCS = main.c arena.c chao.c circulo.c retangulo.c linha.c tetxto.c fila.c pilha.c criarsvg.c criartxt.c geo.c qry.c movimento.c disparador.c colisao.c

OBJS = $(SRCS:.c=.o)

ted: $(OBJS)
	$(CC) $(CFLAGS) -o ted $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o ted