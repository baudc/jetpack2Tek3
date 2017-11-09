/*
** tools3.c for  in /home/baud/0.RENDU/5.SYNTHESE/1.Jetpack2Tek3/new/jetpack2Tek3_2016/client
** 
** Made by baud
** Login   <cesar.baud@epitech.eu>
** 
** Started on  Sun Jul 16 15:11:59 2017 baud
** Last update Sun Jul 16 16:48:11 2017 baud
*/

#include "client.h"

int	get_nb(char *str, char sep)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      if (str[i] == sep)
	j++;
      i++;
    }
  return (j);
}
