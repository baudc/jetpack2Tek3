/*
** fct_ptr.c for  in /home/baud/0.RENDU/5.SYNTHESE/1.Jetpack2Tek3/jetpack2Tek3_2016
** 
** Made by baud
** Login   <cesar.baud@epitech.eu>
** 
** Started on  Thu Jul 13 09:49:22 2017 baud
** Last update Wed Jul 19 16:40:43 2017 baud
*/

#include "header.h"

void		fct_id(char *buf, t_clt *clt, t_jtp *jtp)
{
  static int	i = 0;

  (void)buf;
  (void)jtp;
  if (clt->id == 0)
    {
      i++;
      clt->id = i;
    }
  dprintf(clt->fd, "ID %d\n", i);
}

void	fct_fire(char *buf, t_clt *clt, t_jtp *jtp)
{
  (void)jtp;
  if (buf[5] == '1')
    clt->fire = -1;
  else if (buf[5] == '0')
    clt->fire = 1;
}

void	fct_ready(char *buf, t_clt *clt, t_jtp *jtp)
{
  (void)buf;
  clt->ready = 1;
  if (jtp->clt[0].ready == 1 && jtp->clt[1].ready == 1)
    {
      jtp->start = 1;
      dprintf(jtp->clt[0].fd, "START\n");
      dprintf(jtp->clt[1].fd, "START\n");
    }
}

void	fct_map(char *buf, t_clt *clt, t_jtp *jtp)
{
  (void)buf;
  dprintf(clt->fd, "MAP %d %d %s\n", jtp->width, jtp->height, jtp->map_string);
}
