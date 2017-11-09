/*
** tools3.c for jetpack in /home/noel_q/rendu/TEK2/jetpack2Tek3_2016/server
** 
** Made by Quentin Noël
** Login   <noel_q@epitech.net>
** 
** Started on  Mon Jul 17 15:19:17 2017 Quentin Noël
** Last update Wed Jul 19 18:28:23 2017 Quentin Noël
*/

#include "header.h"

void	print_draw(t_jtp *jtp)
{
  dprintf(jtp->clt[0].fd, "FINISH -1\n");
  dprintf(jtp->clt[1].fd, "FINISH -1\n");
}

void	check_electric_down(t_jtp *jtp, int i, t_arg *arg)
{
  if (jtp->map[(int)(jtp->height -
		     (jtp->clt[i].y + 0.01))][(int)(jtp->clt[i].x) + 0] == 'e' ||
      jtp->map[(int)(jtp->height -
		     (jtp->clt[i].y + 0.01))][(int)(jtp->clt[i].x) + 1] == 'e')
    {
      if (jtp->map[(int)(jtp->height - (jtp->clt[(i + 1) % 2].y + 0.01))]
	  [(int)(jtp->clt[(i + 1) % 2].x) + 0] == 'e' ||
	  jtp->map[(int)(jtp->height - (jtp->clt[(i + 1) % 2].y + 0.01))]
	  [(int)(jtp->clt[(i + 1) % 2].x) + 1] == 'e')
	print_draw(jtp);
      if (i == 0)
	{
	  dprintf(jtp->clt[0].fd, "FINISH %d\n", jtp->clt[1].id);
	  dprintf(jtp->clt[1].fd, "FINISH %d\n", jtp->clt[1].id);
	}
      else
	{
	  dprintf(jtp->clt[0].fd, "FINISH %d\n", jtp->clt[0].id);
	  dprintf(jtp->clt[1].fd, "FINISH %d\n", jtp->clt[0].id);
	}
      jtp->nb_clt = 0;
      reset(jtp, arg);
    }
}

void	check_electric_up(t_jtp *jtp, int i, t_arg *arg)
{
  if (jtp->map[(int)(jtp->height -
		     (jtp->clt[i].y + 0.97))][(int)(jtp->clt[i].x) + 0] == 'e' ||
      jtp->map[(int)(jtp->height -
		     (jtp->clt[i].y + 0.99))][(int)(jtp->clt[i].x) + 1] == 'e')
    {
      if (jtp->map[(int)(jtp->height - (jtp->clt[(i + 1) % 2].y + 0.99))]
	  [(int)(jtp->clt[(i + 1) % 2].x) + 0] == 'e' ||
	  jtp->map[(int)(jtp->height - (jtp->clt[(i + 1) % 2].y + 0.99))]
	  [(int)(jtp->clt[(i + 1) % 2].x) + 1] == 'e')
	print_draw(jtp);
      if (i == 0)
	{
	  dprintf(jtp->clt[0].fd, "FINISH %d\n", jtp->clt[1].id);
	  dprintf(jtp->clt[1].fd, "FINISH %d\n", jtp->clt[1].id);
	}
      else
	{
	  dprintf(jtp->clt[0].fd, "FINISH %d\n", jtp->clt[0].id);
	  dprintf(jtp->clt[1].fd, "FINISH %d\n", jtp->clt[0].id);
	}
      jtp->nb_clt = 0;
      reset(jtp, arg);
    }
}

void	check_coins_up(t_jtp *jtp, int i)
{
  (void)(i);
  (void)(jtp);
  if (jtp->map[(int)(jtp->height -
		     (jtp->clt[i].y + 0.99))][(int)((jtp->clt[i].x) + 0)] == 'c')
    {
      jtp->clt[i].coin += 1;
      dprintf(jtp->clt[0].fd, "COIN %d %d %d\n", jtp->clt[i].id,
	      (int)(jtp->clt[i].x), (int)(jtp->clt[i].y + 0.99));
      dprintf(jtp->clt[1].fd, "COIN %d %d %d\n", jtp->clt[i].id,
	      (int)(jtp->clt[i].x), (int)(jtp->clt[i].y + 0.99));
      jtp->map[(int)(jtp->height - (jtp->clt[i].y + 0.99))]
	[(int)((jtp->clt[i].x) + 0)] = '_';
    }
  if (jtp->map[(int)(jtp->height -
		     (jtp->clt[i].y + 0.99))][(int)((jtp->clt[i].x) + 1)] == 'c')
    {
      jtp->clt[i].coin += 1;
      dprintf(jtp->clt[0].fd, "COIN %d %d %d\n", jtp->clt[i].id,
	      (int)(jtp->clt[i].x + 1), (int)(jtp->clt[i].y + 0.99));
      dprintf(jtp->clt[1].fd, "COIN %d %d %d\n", jtp->clt[i].id,
	      (int)(jtp->clt[i].x + 1), (int)(jtp->clt[i].y + 0.99));
      jtp->map[(int)(jtp->height - (jtp->clt[i].y + 0.99))]
	[(int)((jtp->clt[i].x) + 1)] = '_';
    }
}

void	check_coins_down(t_jtp *jtp, int i)
{
  (void)(jtp);
  (void)(i);
  if (jtp->map[(int)(jtp->height -
		     (jtp->clt[i].y + 0.01))][(int)((jtp->clt[i].x))] == 'c')
    {
      jtp->clt[i].coin += 1;
      dprintf(jtp->clt[0].fd, "COIN %d %d %d\n", jtp->clt[i].id,
	      (int)(jtp->clt[i].x), (int)(jtp->clt[i].y + 0.01));
      dprintf(jtp->clt[1].fd, "COIN %d %d %d\n", jtp->clt[i].id,
	      (int)(jtp->clt[i].x), (int)(jtp->clt[i].y + 0.01));
      jtp->map[(int)(jtp->height - (jtp->clt[i].y + 0.01))]
	[(int)((jtp->clt[i].x))] = '_';
    }
  if (jtp->map[(int)(jtp->height -
		     (jtp->clt[i].y + 0.01))][(int)((jtp->clt[i].x) + 1)] == 'c')
    {
      jtp->clt[i].coin += 1;
      dprintf(jtp->clt[0].fd, "COIN %d %d %d\n", jtp->clt[i].id,
	      (int)(jtp->clt[i].x + 1), (int)(jtp->clt[i].y + 0.01));
      dprintf(jtp->clt[1].fd, "COIN %d %d %d\n", jtp->clt[i].id,
	      (int)(jtp->clt[i].x + 1), (int)(jtp->clt[i].y + 0.01));
      jtp->map[(int)(jtp->height - (jtp->clt[i].y + 0.01))]
	[(int)((jtp->clt[i].x) + 1)] = '_';
    }
}
