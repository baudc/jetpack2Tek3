/*
** tools2.c for osef in /home/noel_q/rendu/TEK2/jetpack2Tek3_2016/quentin
** 
** Made by Quentin Noël
** Login   <noel_q@epitech.net>
** 
** Started on  Fri Jul 14 14:16:06 2017 Quentin Noël
** Last update Sun Jul 16 19:45:51 2017 baud
*/

#include "client.h"

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

  i = 0;
  while (str[i] != '\0')
    {
      if (i == 0)
	{
	  if (str[i] == '-')
	    i++;
	}
      if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	i++;
      else
	return (1);
    }
    return (0);
}

void	init_var(t_arg *arg, int *cpt, int *i)
{
  *i = 0;
  arg->port = 0;
  memset(cpt, 0, 12);
}

char	**str_split(char *str, char sep)
{
  int	i;
  char	c[2];
  char	*tmp;
  char	**tab;

  c[0] = sep;
  c[1] = 0;
  tab = my_malloc(sizeof(char *) * (get_nb(str, sep) + 2));
  i = 0;
  while ((tmp = strtok(i == 0 ? str : NULL, c)))
    {
      tab[i] = tmp;
      i++;
    }
  tab[i] = 0;
  return (tab);
}
