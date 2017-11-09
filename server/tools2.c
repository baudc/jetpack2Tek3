/*
** tools2.c for osef in /home/noel_q/rendu/TEK2/jetpack2Tek3_2016/quentin
** 
** Made by Quentin Noël
** Login   <noel_q@epitech.net>
** 
** Started on  Fri Jul 14 14:16:06 2017 Quentin Noël
** Last update Wed Jul 19 15:02:58 2017 Quentin Noël
*/

#include "header.h"

void	check_cpt(int *cpt)
{
  if (cpt[0] != 1 || cpt[1] != 1 || cpt[2] != 1)
    my_error("Usage : -p <port> -g <gravity> -m <map>");
}

int	is_number(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] >= '0' && str[i] <= '9')
	i++;
      else
	return (1);
    }
  return (0);
}

int	is_number_gravity(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (i == 0)
	{
	  if (str[i] == '-')
	    i++;
	}
      if (str[i] >= '0' && str[i] <= '9')
	;
      else if (str[i] == '.' && j == 0)
	j++;
      else
	return (1);
      i++;
    }
    return (0);
}

void	init_var(t_arg *arg, int *cpt, int *i)
{
  *i = 0;
  arg->gravity = 0.0;
  arg->port = 0;
  memset(cpt, 0, 12);
}

char	**copy_map(t_jtp *jtp, t_arg *arg)
{
  char	**map;
  int	i;

  i = 0;
  if ((map = malloc(sizeof(char *) * (jtp->height + 1))) == NULL)
    return (NULL);
  while (arg->map->map[i] != NULL)
    {
      map[i] = strdup(arg->map->map[i]);
      i++;
    }
  map[i] = NULL;
  return (map);
}
