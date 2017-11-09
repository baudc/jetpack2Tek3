/*
** main.c for osef in /home/noel_q/rendu/TEK2/jetpack2Tek3_2016/quentin/client
** 
** Made by Quentin Noël
** Login   <noel_q@epitech.net>
** 
** Started on  Fri Jul 14 15:35:26 2017 Quentin Noël
** Last update Tue Jul 18 09:29:33 2017 Quentin Noël
*/

#include "client.h"

int	main(int ac, char **av)
{
  t_clt	clt;
  t_arg	args;

  if (ac != 5)
    my_error("Usage : ./clientJ2T3 -h <ip> -p <port>");
  else
    {
      parsing(av, &args);
      init_clt(&args, &clt);
      pthread_create(&clt.thread, NULL, init_network, &clt);
      sdl_display(&clt);
      pthread_join(clt.thread, NULL);
    }
  return (0);
}
