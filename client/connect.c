/*
** connect.c for  in /home/baud/0.RENDU/5.SYNTHESE/1.Jetpack2Tek3/new/jetpack2Tek3_2016/client
** 
** Made by baud
** Login   <cesar.baud@epitech.eu>
** 
** Started on  Sat Jul 15 15:36:24 2017 baud
** Last update Tue Jul 18 11:43:14 2017 baud
*/

#include "client.h"

void			get_cmd(t_clt *clt, int sock_fd)
{
  int			i;
  char			*line;
  t_cmd			tab[] =
    {
      {"COIN ", 5, fct_coin}, {"MAP ", 4, fct_map}, {"ID ", 3, fct_id},
      {"FINISH ", 7, fct_finish}, {"PLAYER ", 7, fct_player},
      {"START", 5, fct_start},
      {0, 0, 0}
    };

  i = 0;
  if ((line = get_next_line(sock_fd)) != 0)
    {
      while (tab[i].name != 0)
	{
	  if (strncmp(tab[i].name, line, tab[i].len) == 0)
	    {
	      tab[i].f(line, clt);
	      break ;
	    }
	  i++;
	}
    }
}

void			handle_clt(t_clt *clt)
{
  FD_ZERO(&clt->fds);
  FD_SET(clt->sock_fd, &clt->fds);
  clt->fd_max = clt->sock_fd;
  while (42)
    {
      clt->rdfds = clt->fds;
      if (select(clt->fd_max + 1, &clt->rdfds, NULL, NULL, NULL) < 0)
	my_error("Failed to select");
      else if (FD_ISSET(clt->sock_fd, &clt->rdfds))
	get_cmd(clt, clt->sock_fd);
    }
}

void			*init_network(void *data)
{
  struct sockaddr_in	s_in;
  t_clt			*clt;

  clt = (t_clt *)data;
  if ((clt->sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    my_error("Failed to create client socket");
  if (strcmp(clt->ip, "localhost") == 0)
    clt->ip = strdup("127.0.0.1");
  s_in.sin_addr.s_addr = inet_addr(clt->ip);
  s_in.sin_port = htons(clt->port);
  s_in.sin_family = AF_INET;
  if (connect(clt->sock_fd, (struct sockaddr *)&s_in, sizeof(s_in)) < 0)
    my_error("Failed to connect to server");
  dprintf(clt->sock_fd, "ID\n");
  dprintf(clt->sock_fd, "MAP\n");
  handle_clt(clt);
  return ((void* )0);
}
