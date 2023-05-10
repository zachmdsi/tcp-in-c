tcp: src/main.c src/server.c
	gcc -o tcp src/main.c src/server.c -I./include

clean:
	rm -f tcp
