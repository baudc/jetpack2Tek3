/*
** tools.c for  in /home/baud/J2T3/jetpack2Tek3_2016
** 
** Made by baud
** Login   <cesar.baud@epitech.eu>
** 
** Started on  Fri Jul 14 18:09:17 2017 baud
** Last update Wed Jul 19 10:00:56 2017 Quentin Noël
*/

#include "header.h"

void    *my_malloc(int size)
{
  void  *p;

  if ((p = malloc(size)) == 0)
    exit(1);
  return (p);
}

int	my_read(int fd, void *buf, int size)
{
  int   nb;

  if ((nb = read(fd, buf, size)) == -1)
    exit(1);
  return (nb);
}

void	my_error(char *str)
{
  fprintf(stderr, "%s\n", str);
  exit(84);
}
