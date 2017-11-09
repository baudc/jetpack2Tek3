/*
** tools.c for  in /home/baud/0.RENDU/1.Projets/0.PSU/3.RESEAUX/0.SOURCES/PSU_2016_myftp
** 
** Made by baud
** Login   <cesar.baud@epitech.eu>
** 
** Started on  Sat May 20 14:29:52 2017 baud
** Last update Wed Jul 19 10:02:00 2017 Quentin Noël
*/

#include "get_next_line.h"
#include "client.h"

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
