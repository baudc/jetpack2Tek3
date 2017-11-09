/*
** main.c for  in /home/baud/0.RENDU/5.SYNTHESE/1.Jetpack2Tek3/jetpack2Tek3_2016
** 
** Made by baud
** Login   <cesar.baud@epitech.eu>
** 
** Started on  Thu Jul 13 14:24:56 2017 baud
** Last update Wed Jul 19 15:01:15 2017 Quentin Noël
*/

#include "header.h"

int			main(int ac, char **av)
{
  t_jtp                 jtp;
  t_arg                 arg;

  if (ac == 7)
    {
      parsing(av, &arg);
      init_server(&jtp, av, &arg);
      launch_nclt(&jtp, &arg);
    }
  else
    my_error("./serverJ2T3 -p <port> -g <gravity> -m <map>\n");
  return (0);
}
