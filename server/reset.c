/*
** reset.c for  in /home/baud/0.RENDU/5.SYNTHESE/1.Jetpack2Tek3/jetpack2Tek3_2016/server
** 
** Made by baud
** Login   <cesar.baud@epitech.eu>
** 
** Started on  Wed Jul 19 10:29:26 2017 baud
** Last update Wed Jul 19 15:05:22 2017 Quentin Noël
*/

#include "header.h"

void	reset(t_jtp *jtp, t_arg *arg)
{
  int	i;

  i = 0;
  memset(&jtp->clt[0], 0, sizeof(t_clt));
  memset(&jtp->clt[1], 0, sizeof(t_clt));
  jtp->start = 0;
  jtp->nb_clt = 0;
  while (jtp->map[i] != NULL)
    free(jtp->map[i++]);
  free(jtp->map);
  jtp->map = copy_map(jtp, arg);
  usleep(20000);
}
