CC = gcc
CFLAGS = -I./include
SRCDIR = src

all: tcp_client tcp_server

tcp_server: $(SRCDIR)/server_main.c $(SRCDIR)/server.c
	$(CC) $(CFLAGS) -o $(SRCDIR)/tcp_server $(SRCDIR)/server_main.c $(SRCDIR)/server.c 

tcp_client: $(SRCDIR)/client_main.c $(SRCDIR)/client.c
	$(CC) $(CFLAGS) -o $(SRCDIR)/tcp_client $(SRCDIR)/client_main.c $(SRCDIR)/client.c 

clean:
	rm -f $(SRCDIR)/tcp_server
	rm -f $(SRCDIR)/tcp_client
