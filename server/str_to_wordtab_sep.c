/*
** str_to_wordtab_sep.c for jetpack in /home/noel_q/rendu/TEK2/jetpack2Tek3_2016/quentin
** 
** Made by Quentin Noël
** Login   <noel_q@epitech.net>
** 
** Started on  Fri Jul 14 09:46:59 2017 Quentin Noël
** Last update Fri Jul 14 09:53:55 2017 Quentin Noël
*/

#include "header.h"

void	fill_null(char *str, int nb)
{
  int	i;

  i = 0;
  while (i < nb)
    {
      str[i] = 0;
      i++;
    }
}

int	*count_words(char *str, int *nb, char sep)
{
  int	i;
  int	j;
  int	*pos;

  *nb = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if ((i == 0 || str[i - 1] == sep) && str[i] != sep)
	(*nb)++;
      i++;
    }
  if ((pos = malloc(sizeof(int) * (*nb))) == NULL)
    exit(1);
  j = 0;
  i = -1;
  while (str[++i] != '\0')
    {
      if ((i == 0 || str[i - 1] == sep) && str[i] != sep)
	{
	  pos[j] = i;
	  j++;
	}
    }
  return (pos);
}

int	length_word(int pos, char *str, char sep)
{
  int	i;
  int	nb;

  i = pos;
  nb = 0;
  while (str[i] != '\0' && str[i] != sep)
    {
      i++;
      nb++;
    }
  return (nb);
}

char	**str_to_wordtab_sep(char *str, char sep)
{
  int	nb_words;
  char	**tab;
  int	*pos;
  int	i;
  int	l_w;

  if ((pos = count_words(str, &nb_words, sep)) == NULL)
    return (NULL);
  if ((tab = malloc(sizeof(char *) * (nb_words + 1))) == NULL)
    exit(1);
  i = 0;
  while (i < nb_words)
    {
      l_w = length_word(pos[i], str, sep);
      if ((tab[i] = malloc(sizeof(char) * (l_w + 1))) == NULL)
	exit(1);
      fill_null(tab[i], l_w + 1);
      strncpy(tab[i], str + pos[i], l_w);
      i++;
    }
  tab[i] = NULL;
  return (tab);
}
