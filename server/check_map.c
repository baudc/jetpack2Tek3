/*
** check_map.c for jetpack in /home/noel_q/rendu/TEK2/jetpack2Tek3_2016/quentin
** 
** Made by Quentin Noël
** Login   <noel_q@epitech.net>
** 
** Started on  Fri Jul 14 09:59:58 2017 Quentin Noël
** Last update Wed Jul 19 09:51:41 2017 Quentin Noël
*/

#include "header.h"

int		check_len(char **map)
{
  int		i;
  unsigned int	len;

  i = 0;
  len = strlen(map[0]);
  if (len == 0)
    return (1);
  while (map[i + 1] != NULL)
    {
      if (len != strlen(map[i + 1]))
	return (1);
      i++;
    }
  return (0);
}

int	check_car(char **map)
{
  int	i;
  int	j;

  i = 0;
  while (map[i] != NULL)
    {
      j = 0;
      while (map[i][j] != 0)
	{
	  if (map[i][j] != 'e' && map[i][j] != '_' && map[i][j] != 'c')
	    {
	      return (1);
	    }
	  j++;
	}
      i++;
    }
  return (0);
}

void	check_error_map(char **map, int *cpt)
{
  if (check_len(map) == 1)
    my_error("wrong_map: need all lines to be the same size\n");
  if (check_car(map) == 1)
    my_error("wrong map: the map only needs to have 'e', '_' and 'c'");
  *cpt += 1;
}

void	get_dimensions(t_map *map, char *str)
{
  int	i;
  int	j;

  i = 0;
  if ((map->map_string = malloc(sizeof(char) * strlen(str))) == NULL)
    my_error("malloc failed\n");
  while (map->map[i] != NULL)
    {
      j = 0;
      while (map->map[i][j] != 0)
	j++;
      i++;
    }
  map->length = j;
  map->height = i;
  i = 0;
  while (map->map[i] != NULL)
    {
      j = -1;
      while (map->map[i][++j] != 0)
	map->map_string[(i * map->length) + j] = map->map[i][j];
      i++;
    }
  map->map_string[map->length * map->height] = 0;
}
