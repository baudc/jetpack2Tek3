/*
** ready.c for  in /home/baud/0.RENDU/5.SYNTHESE/1.Jetpack2Tek3/new/jetpack2Tek3_2016/client
** 
** Made by baud
** Login   <cesar.baud@epitech.eu>
** 
** Started on  Sun Jul 16 18:50:24 2017 baud
** Last update Sun Jul 16 19:09:14 2017 baud
*/

#include "client.h"

void	is_ready(t_clt *clt)
{
  if (clt->b_id == true && clt->b_map == true)
    dprintf(clt->sock_fd, "READY\n");
}
