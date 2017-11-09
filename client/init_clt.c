/*
** init_clt.c for  in /home/baud_d/Desktop/J2T3/jetpack2Tek3_2016/client
** 
** Made by Cesar Baud
** Login   <baud_d@epitech.net>
** 
** Started on  Tue Jul 18 12:52:43 2017 Cesar Baud
** Last update Tue Jul 18 12:52:49 2017 Cesar Baud
*/

#include "client.h"

void			init_clt(t_arg *arg, t_clt *clt)
{
  clt->b_id = false;
  clt->player[0].id = 0;
  clt->player[1].id = 0;
  clt->player[0].coin = 0;
  clt->player[1].coin = 0;
  clt->b_map = false;
  clt->start = 0;
  clt->port = arg->port;
  clt->sock_fd = -1;
  clt->id = 0;
  clt->ip = strdup(arg->ip);
  clt->map = NULL;
}
