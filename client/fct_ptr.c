/*
** fct_ptr.c for  in /home/baud/0.RENDU/5.SYNTHESE/1.Jetpack2Tek3/new/jetpack2Tek3_2016/client
**
** Made by baud
** Login   <cesar.baud@epitech.eu>
**
** Started on  Sun Jul 16 14:38:37 2017 baud
** Last update Mon Jul 17 19:41:05 2017 baud
*/

#include "client.h"

void	fct_id(char *buf, t_clt *clt)
{
  char	**tmp;

  tmp = str_split(buf, ' ');
  clt->id = atoi(tmp[1]);
  if (clt->player[0].id == 0)
    clt->player[0].id = atoi(tmp[1]);
  else
    clt->player[1].id = atoi(tmp[1]);
  clt->b_id = true;
  is_ready(clt);
}

void	fct_map(char *buf, t_clt *clt)
{
  int	i;
  int	j;
  int	k;
  char	**tmp;

  i = 0;
  j = 0;
  k = 0;
  tmp = str_split(buf, ' ');
  if (clt->map)
    return ;
  clt->width = atoi(tmp[1]);
  clt->height = atoi(tmp[2]);
  clt->map = my_malloc(sizeof(char *) * clt->height);
  while (i < clt->height)
    {
      j = 0;
      clt->map[i] = my_malloc(sizeof(char) * clt->width);
      while (tmp[3][k] && j < clt->width)
	clt->map[i][j++] = tmp[3][k++];
      i++;
    }
  clt->b_map = true;
  is_ready(clt);
}

void	fct_coin(char *buf, t_clt *clt)
{
  int	x;
  int	y;
  char	**tmp;

  tmp = str_split(buf, ' ');
  x = atoi(tmp[2]);
  y = atoi(tmp[3]);
  if (x < clt->width && x >= 0 && y < clt->height && y >= 0)
    clt->map[clt->height - 1 - y][x] = '_';
}

void	fct_finish(char *buf, t_clt *clt)
{
  char	**tmp;

  tmp = str_split(buf, ' ');
  if (atoi(tmp[1]) == clt->id)
    printf("You win !\n");
  else if (strcmp(tmp[1], "-1") == 0)
    printf("Nobody wins\n");
  else
    printf("You loose\n");
  close(clt->sock_fd);
  exit(0);
}

void	fct_start(char *buf, t_clt *clt)
{
  clt->start = true;
  (void)buf;
}
