/*
** parsing.c for client in /home/noel_q/rendu/TEK2/jetpack2Tek3_2016/quentin/client
** 
** Made by Quentin Noël
** Login   <noel_q@epitech.net>
** 
** Started on  Fri Jul 14 16:04:50 2017 Quentin Noël
** Last update Sun Jul 16 19:43:04 2017 baud
*/

#include "client.h"

void	check_port(char *port, int *my_port, int *cpt)
{
  *cpt += 1;
  if (strlen(port) > 10)
    my_error("Wrong port.");
  if (is_number(port) == 1)
    my_error("port must be a number.");
  *my_port = atoi(port);
}

void	check_ip(char *ip, char **my_ip, int *cpt)
{
  int	i;

  i = 0;
  *cpt += 1;
  if (strcmp(ip, "localhost") == 0)
    return ;
  while (ip[i] != 0)
    {
      if ((ip[i] < '0' || ip[i] > '9') && ip[i] != '.')
	my_error("Wrong adress");
      i++;
    }
  *my_ip = strdup(ip);
}

void	parsing(char **av, t_arg *arg)
{
  int	i;
  int	cpt[2];

  i = 0;
  memset(cpt, 0, 8);
  while (i < 5)
    {
      if (strncmp(av[i], "-", 1) == 0)
	{
	  if (i == 4 || strlen(av[i]) != 2)
	    my_error("Wrong arguments");
	  else
	    {
	      if (av[i][1] == 'p' && av[i][2] == 0)
		check_port(av[i + 1], &(arg->port), &cpt[0]);
	      else if (av[i][1] == 'h' && av[i][2] == 0)
		check_ip(av[i + 1], &(arg->ip), &cpt[1]);
	      i++;
	    }
	}
      i++;
    }
  if (cpt[0] != 1 || cpt[1] != 1)
    my_error("Usage : ./clientJ2T3 -h <ip> -p <port>");
}
