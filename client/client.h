/*
** client.h for  in /home/baud_d/Desktop/J2T3/jetpack2Tek3_2016/client
** 
** Made by Cesar Baud
** Login   <baud_d@epitech.net>
** 
** Started on  Tue Jul 18 12:53:00 2017 Cesar Baud
** Last update Wed Jul 19 11:18:09 2017 baud
*/

#ifndef CLIENT_H_
# define CLIENT_H_

/*
**	INCLUDES
*/

# include <stdlib.h>
# include <pthread.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <time.h>
# include <SDL/SDL_ttf.h>
# include "SDL.h"
# include "SDL_ttf.h"

/*
**	DEFINES
*/

# define H_SIZE		(400 / clt->height)
# define W_SIZE		(1920 / clt->width)
# define BUF_SIZE	512
# define SIZE		512
# define IS_COIN	(clt->map[i[0]][i[1]] == 'c')
# define IS_ELEC	(clt->map[i[0]][i[1]] == 'e')

/*
**	STRUCTURES
*/

typedef struct	s_arg
{
  int		port;
  char		*ip;
}		t_arg;

typedef struct	s_player
{
  int		coin;
  int		id;
  float		x;
  float		y;
}		t_player;

typedef struct	s_clt
{
  int		width;
  int		height;
  int		fd_max;
  int		port;
  int		sock_fd;
  int		id;
  bool		b_id;
  bool		b_map;
  bool		start;
  char		*ip;
  char		**map;
  fd_set	fds;
  fd_set	rdfds;
  t_player	player[2];
  pthread_t	thread;
}		t_clt;

typedef struct	s_cmd
{
  char		*name;
  int		len;
  void		(*f)();
}		t_cmd;

/*
**	TOOLS
*/

int		get_nb(char *, char);
int		is_number(char *);
int		my_read(int, void *, int);
char		**str_split(char *, char);
char            *get_next_line(int);
void		*my_malloc(int);
void		my_error(char *);

/*
**	FCT_PTR PROTOTYPES
*/

void		fct_player(char *, t_clt *);
void		fct_start(char *, t_clt *);
void		fct_coin(char *, t_clt *);
void		fct_id(char *, t_clt *);
void		fct_map(char *, t_clt *);
void		fct_finish(char *, t_clt *);

/*
**	PROTOTYPES
*/

void            display_map(t_clt *, SDL_Surface *);
void            add_player(t_clt *, SDL_Surface *);
void            my_sleep(t_clt *, SDL_Surface *);
void		is_ready(t_clt *);
void		handle_clt(t_clt *);
void		parsing(char **, t_arg *);
void		init_clt(t_arg *, t_clt *);
void		*init_network(void *);
void		sdl_display(t_clt *);

#endif /*CLIENT_H_*/
