/*
** server.c for  in /home/baud/J2T3/jetpack2Tek3_2016
** 
** Made by baud
** Login   <cesar.baud@epitech.eu>
** 
** Started on  Fri Jul 14 18:09:01 2017 baud
** Last update Wed Jul 19 15:00:45 2017 Quentin Noël
*/

#include "header.h"

void	init_server(t_jtp *jtp, char **av, t_arg *arg)
{
  jtp->nb_clt = 0;
  jtp->start = 0;
  jtp->width = arg->map->length;
  jtp->height = arg->map->height;
  jtp->map_string = strdup(arg->map->map_string);
  jtp->gravity = arg->gravity;
  jtp->map = copy_map(jtp, arg);
  if ((jtp->sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      my_error("Can not open server socket");
    }
  jtp->s_in.sin_family = AF_INET;
  jtp->s_in.sin_port = htons(atoi(av[2]));
  jtp->s_in.sin_addr.s_addr = INADDR_ANY;
  if (bind(jtp->sock_fd, (struct sockaddr *)&jtp->s_in,
	   sizeof(jtp->s_in)) == -1)
    {
      close(jtp->sock_fd);
      exit(1);
    }
  if ((listen(jtp->sock_fd, 2)) == -1)
    {
      exit(1);
    }
}

void	launch_clt(t_jtp *jtp, int fd)
{
  int	ret;
  char  *line;
  char	**cmds;
  t_cmd	tab[] =
    {
      {"ID", 2, fct_id}, {"READY", 5, fct_ready}, {"FIRE ", 5, fct_fire},
      {"MAP", 3, fct_map}, {NULL, 0, 0}
    };
  line = my_malloc(sizeof(char) * SIZE);
  if ((ret = recv(fd, line, SIZE, 0)) < 0)
      return ;
  cmds = str_to_wordtab_sep(line, '\n');
  check_cmd(cmds, tab, jtp, fd);
  free(line);
}

void			read_or_add(t_jtp *jtp, int sock)
{
  int			new;
  socklen_t		socklen;
  struct sockaddr_in	c_in;

  new = -1;
  if (sock == jtp->sock_fd)
    {
      socklen = sizeof(c_in);
      if (jtp->nb_clt < 2)
	{
	  if ((new = accept(sock, (struct sockaddr *)&c_in, &socklen)) < 0)
	    return ;
	  FD_SET(new, &jtp->fds);
	  jtp->fd_max = jtp->fd_max > new ? jtp->fd_max : new;
	  add_client(jtp, new);
	}
    }
  else
    launch_clt(jtp, sock);
}

void	check(t_jtp *jtp, int sock, t_arg *arg)
{
  int	i;

  i = 0;
  (void)sock;
  send_player_info(jtp, arg);
  while (i < FD_SETSIZE)
    {
      if (FD_ISSET(i, &jtp->rdfds))
	read_or_add(jtp, i);
      i++;
    }
}

void	launch_nclt(t_jtp *jtp, t_arg *arg)
{
  int	new_sock;

  jtp->tv.tv_sec = 0;
  jtp->tv.tv_usec = 2500;
  FD_ZERO(&jtp->fds);
  FD_SET(jtp->sock_fd, &jtp->fds);
  jtp->fd_max = jtp->sock_fd;
  while (1)
    {
      jtp->rdfds = jtp->fds;
      new_sock = select(jtp->fd_max + 1, &jtp->rdfds, NULL, NULL, &jtp->tv);
      if (new_sock < 0)
	return ;
      check(jtp, new_sock, arg);
    }
}
