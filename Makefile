CFLAGS = -Wall -g -Iinclude # Warning e debug info, -Iinclude para usar folder include/

PROG = build/main
FONTES = src/main.c src/image.c src/encrypt.c

# Automaticamente mudar os arquivos src/ para build/
OBJETOS = $(patsubst src/%.c, build/%.o, $(FONTES))

$(PROG): $(OBJETOS)
	gcc $(CFLAGS) $(OBJETOS) -o $@

build/%.o: src/%.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	-@ rm -f build/*.o $(PROG)

