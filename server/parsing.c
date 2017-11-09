/*
** parsing.c for osef in /home/noel_q/rendu/TEK2/jetpack2Tek3_2016/quentin
** 
** Made by Quentin Noël
** Login   <noel_q@epitech.net>
** 
** Started on  Thu Jul 13 15:57:25 2017 Quentin Noël
** Last update Wed Jul 19 09:57:35 2017 Quentin Noël
*/

#include "header.h"

void	check_map(char *file, t_arg *arg, int *cpt)
{
  int	fd;
  char	*str;
  char	*tmp;
  struct stat	st;
  int	sz;

  if ((fd = open(file, O_RDONLY)) == -1)
    my_error("open failed");
  stat(file, &st);
  if (!S_ISREG(st.st_mode))
    my_error("Wrong file");
  sz = st.st_size;
  if ((str = malloc(sizeof(char) * (sz + 1))) == NULL)
    my_error("malloc failed\n");
  sz = 0;
  while ((tmp = get_next_line(fd)) != NULL)
    {
      if (sz++ != 0)
	  strcat(str, "\n");
      strcat(str, tmp);
    }
  arg->map = malloc(sizeof(t_map));
  arg->map->map = str_to_wordtab_sep(str, '\n');
  get_dimensions(arg->map, str);
  check_error_map(arg->map->map, cpt);
}

void	check_gravity(char *gravity, float *my_gravity, int *cpt)
{
  *cpt += 1;
  if (is_number_gravity(gravity) == 1)
    my_error("Wrong gravity.");
  *my_gravity = atof(gravity);
}

void	check_port(char *port, int *my_port, int *cpt)
{
  *cpt += 1;
  if (strlen(port) > 10)
    my_error("Wrong port.");
  if (is_number(port) == 1)
    my_error("port must be a number.");
  *my_port = atoi(port);
}

void	parsing(char **av, t_arg *arg)
{
  int	i;
  int	cpt[3];

  init_var(arg, cpt, &i);
  while (i < 7)
    {
      if (strncmp(av[i], "-", 1) == 0)
	{
	  if (i == 6 || strlen(av[i]) != 2)
	    my_error("Wrong arguments");
	  else
	    {
	      if (av[i][1] == 'm' && av[i][2] == 0)
		check_map(av[i + 1], arg, &cpt[0]);
	      else if (av[i][1] == 'g' && av[i][2] == 0)
		check_gravity(av[i + 1], &(arg->gravity), &cpt[1]);
	      else if (av[i][1] == 'p' && av[i][2] == 0)
		check_port(av[i + 1], &(arg->port), &cpt[2]);
	      i++;
	    }
	}
      i++;
    }
  check_cpt(cpt);
}
