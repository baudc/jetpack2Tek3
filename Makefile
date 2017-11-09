##
## Makefile for  in /home/baud_d/Desktop/J2T3/jetpack2Tek3_2016
## 
## Made by Cesar Baud
## Login   <baud_d@epitech.net>
## 
## Started on  Tue Jul 18 12:53:19 2017 Cesar Baud
## Last update Wed Jul 19 19:44:24 2017 Quentin Noël
##

CLT	= clientJ2T3

CLT_SRC	= client/main.c \
	client/connect.c \
	client/fct_ptr.c \
	client/fct_ptr2.c \
	client/get_next_line.c \
	client/init_clt.c \
	client/parsing.c \
	client/ready.c \
	client/sdl_display.c \
	client/tools.c \
	client/tools2.c \
	client/tools3.c

CLT_OBJ	= $(CLT_SRC:.c=.o)

SRV	= serverJ2T3

SRV_SRC	= server/main.c \
	server/add_client.c \
	server/check_map.c \
	server/parsing.c \
	server/send_player_info.c \
	server/server2.c \
	server/server.c \
	server/str_to_wordtab_sep.c \
	server/tools2.c \
	server/tools3.c \
	server/tools.c \
	server/fct_ptr.c \
	server/get_next_line.c \
	server/reset.c

SRV_OBJ	= $(SRV_SRC:.c=.o)

CC	= gcc

CFLAGS	= -W -Wall -Wextra -Werror `sdl-config --cflags` `sdl-config --libs`

LDFLAGS	= -lpthread -lSDL -lSDL_ttf

RM	= rm -f

all:	client server

$(CLT): $(CLT_OBJ)
	$(CC) $(CLT_OBJ) $(LDFLAGS) -o $(CLT)

$(SRV): $(SRV_OBJ)
	$(CC) $(SRV_OBJ) -o $(SRV)

client: $(CLT)

server: $(SRV)

clean:
	$(RM) $(CLT_OBJ) $(SRV_OBJ)

fclean: clean
	$(RM) $(CLT) $(SRV)

re: fclean all

.PHONY: all clean fclean re
