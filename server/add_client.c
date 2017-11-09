/*
** add_client.c for  in /home/baud/jetpack2Tek3_2016
** 
** Made by baud
** Login   <cesar.baud@epitech.eu>
** 
** Started on  Fri Jul 14 15:09:05 2017 baud
** Last update Wed Jul 19 10:33:37 2017 baud
*/

#include "header.h"

void		add_client(t_jtp *jtp, int fd)
{
  static int	i = 0;

  jtp->clt[i % 2].id = 0;
  jtp->clt[i % 2].x = 0;
  jtp->clt[i % 2].y = (float)jtp->height / 2;
  jtp->clt[i % 2].fd = fd;
  jtp->clt[i % 2].coin = 0;
  jtp->clt[i % 2].ready = 0;
  jtp->clt[i % 2].fire = 1;
  i++;
  jtp->nb_clt++;
}
