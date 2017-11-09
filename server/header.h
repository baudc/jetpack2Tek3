/*
** header.h for  in /home/baud/0.RENDU/5.SYNTHESE/1.Jetpack2Tek3/jetpack2Tek3_2016
** 
** Made by baud
** Login   <cesar.baud@epitech.eu>
** 
** Started on  Thu Jul 13 14:18:34 2017 baud
** Last update Wed Jul 19 22:57:31 2017 baud
*/

#ifndef HEADER_H_
# define HEADER_H_

/*
**	INCLUDES
*/

# include <sys/stat.h>
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
# include <math.h>
# include <time.h>

/*
**	DEFINES
*/

# define BUF_SIZE	512
# define SIZE		512

/*
**	STRUCTURES
*/

typedef struct	s_map
{
  int           height;
  int           length;
  char          **map;
  char          *map_string;
}		t_map;

typedef struct  s_arg
{
  float         gravity;
  int           port;
  t_map         *map;
}		t_arg;

typedef struct  s_cmd
{
  char          *name;
  int           len;
  void          (*f)();
}               t_cmd;

typedef struct	s_clt
{
  float		x;
  float		y;
  int		id;
  int           fd;
  int		coin;
  int		fire;
  int		ready;
  char		**map;
}               t_clt;

typedef struct		s_jtp
{
  int			width;
  int			height;
  int			start;
  int			fd_max;
  int			nb_clt;
  int                   sock_fd;
  char			**map;
  char			*map_string;
  fd_set		fds;
  fd_set		rdfds;
  float			gravity;
  struct sockaddr_in    s_in;
  struct timeval	tv;
  struct s_clt		clt[2];
}			t_jtp;

/*
**	FCT_PTR PROTOTYPES
*/

void	fct_id(char *, t_clt *, t_jtp *);
void	fct_fire(char *, t_clt *, t_jtp *);
void	fct_map(char *, t_clt *, t_jtp *);
void	fct_ready(char *, t_clt *, t_jtp *);

/*
**	TOOLS PROTOTYPES
*/

int     my_read(int, void *, int);
int     is_number(char *);
int     is_number_gravity(char *);
char    *my_itoa(int);
char	*get_next_line(int);
char    **str_to_wordtab_sep(char *, char);
char	**copy_map(t_jtp *, t_arg *);
void	my_error(char *);
void    init_var(t_arg *, int *, int *);
void	check_cpt(int *);
void    check_error_map(char **, int *);
void    get_dimensions(t_map *, char *);
void	print_draw(t_jtp *);
void    *my_malloc(int);
void	check_electric_down(t_jtp *, int, t_arg *);
void	check_electric_up(t_jtp *, int, t_arg * );
void	check_coins_down(t_jtp *, int);
void	check_coins_up(t_jtp *, int);

/*
**	PROTOTYPES
*/

char	new_socket(t_clt *, t_jtp *);
void	check_cmd(char **, t_cmd *, t_jtp *, int);
void	send_player_info(t_jtp *, t_arg *);
void	add_client(t_jtp *, int);
void    read_or_add(t_jtp *, int);
void	usage();
void	launch_nclt(t_jtp *, t_arg *);
void	init_server(t_jtp *, char **, t_arg *);
void	launch_clt(t_jtp *, int);
void    init_pwd(t_clt *);
void    parsing(char **, t_arg *);
void	reset(t_jtp *, t_arg *);

#endif /* HEADER_H_ */
