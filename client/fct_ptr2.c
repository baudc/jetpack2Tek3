/*
** fct_ptr2.c for  in /home/baud/0.RENDU/5.SYNTHESE/1.Jetpack2Tek3/new/jetpack2Tek3_2016/client
** 
** Made by baud
** Login   <cesar.baud@epitech.eu>
** 
** Started on  Sun Jul 16 19:17:12 2017 baud
** Last update Mon Jul 17 10:57:59 2017 baud
*/

#include "client.h"

void	fct_player(char *buf, t_clt *clt)
{
  char	**tmp;

  tmp = str_split(buf, ' ');
  if (clt->player[0].id == atoi(tmp[1]))
    {
      clt->player[0].x = atof(tmp[2]);
      clt->player[0].y = atof(tmp[3]);
      clt->player[0].coin = atof(tmp[4]);
    }
  else
    {
      clt->player[1].id = atoi(tmp[1]);
      clt->player[1].x = atof(tmp[2]);
      clt->player[1].y = atof(tmp[3]);
      clt->player[1].coin = atoi(tmp[4]);
    }
  return ;
}
