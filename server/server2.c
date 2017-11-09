/*
** server2.c for osef in /home/noel_q/rendu/TEK2/jetpack2Tek3_2016/server
** 
** Made by Quentin Noël
** Login   <noel_q@epitech.net>
** 
** Started on  Sun Jul 16 15:13:34 2017 Quentin Noël
** Last update Wed Jul 19 10:00:10 2017 Quentin Noël
*/

#include "header.h"

void	check_cmd(char **cmds, t_cmd *tab, t_jtp *jtp, int fd)
{
  int	i;
  int	j;

  j = 0;
  while (cmds[j] != NULL)
    {
      i = 0;
      while (tab[i].name != NULL)
	{
	  if (strncmp(tab[i].name, cmds[j], tab[i].len) == 0)
	    {
	      if (jtp->clt[0].fd == fd)
		tab[i].f(cmds[j], &jtp->clt[0], jtp);
	      else if (jtp->clt[1].fd == fd)
		tab[i].f(cmds[j], &jtp->clt[1], jtp);
	      break ;
	    }
	  i++;
	}
      j++;
    }
}
