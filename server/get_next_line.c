/*
** get_next_line.c for  in /home/baud/0.RENDU/5.SYNTHESE/1.Jetpack2Tek3/new/jetpack2Tek3_2016/client
** 
** Made by baud
** Login   <cesar.baud@epitech.eu>
** 
** Started on  Sun Jul 16 18:28:55 2017 baud
** Last update Wed Jul 19 10:03:38 2017 Quentin Noël
*/

#include "get_next_line.h"

static char	*my_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

static void	*my_realloc(char *buf, char *str, char *rest)
{
  int		i;
  int		j;
  char		*new_ptr;

  i = 0;
  j = 0;
  while (buf[i++]);
  if (str != NULL)
    {
      while (str[j++] != '\0');
      if ((new_ptr = malloc(sizeof(char) * (i + j + READ_SIZE))) == NULL)
	return (NULL);
      my_strcpy(new_ptr, str);
      my_strcpy(&new_ptr[j - 1], buf);
    }
  else
    {
      while (rest[j++] != '\0');
      if ((new_ptr = malloc(sizeof(char) * (i + j + READ_SIZE))) == NULL)
	return (NULL);
      my_strcpy(new_ptr, rest);
      my_strcpy(&new_ptr[j - 1], buf);
    }
  rest[0] = '\0';
  return (new_ptr);
}

static int	check_n(char *str, char *rest)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	{
	  my_strcpy(rest, &str[i + 1]);
	  str[i] = '\0';
	  return (1);
	}
      else
	rest[0] = '\0';
      i++;
    }
  return (0);
}

char		*get_next_line(const int fd)
{
  static char   rest[READ_SIZE];
  char		*str;
  char		*buf;
  int		rd;
  int		check_N;

  str = NULL;
  check_N = 0;
  rd = 1;
  if ((buf = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
    return (NULL);
  while (rd != 0 && check_N == 0)
    {
      if ((rd = read(fd, buf, READ_SIZE)) == -1)
	return (NULL);
      buf[rd] = '\0';
      if ((str = my_realloc(buf, str, rest)) == NULL)
	return (NULL);
      check_N = check_n(str, rest);
    }
  if (rd == 0 && str[0] == '\0' && rest[0] == '\0')
    return (NULL);
  return (str);
}
