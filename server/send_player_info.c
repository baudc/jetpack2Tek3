/*
** send_player_info.c for  in /home/baud/0.RENDU/5.SYNTHESE/1.Jetpack2Tek3/new/jetpack2Tek3_2016/server
** 
** Made by baud
** Login   <cesar.baud@epitech.eu>
** 
** Started on  Sat Jul 15 10:35:11 2017 baud
** Last update Wed Jul 19 20:00:40 2017 Quentin Noël
*/

#include "header.h"

void	check_coins(t_jtp *jtp, int i)
{
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
    check_coins_down(jtp, i);
  check_coins_up(jtp, i);
}

void	check_electric(t_jtp *jtp, int i, t_arg *arg)
{
  if (jtp->map[(int)(jtp->height -
		     (jtp->clt[i].y + 0.99))][(int)(jtp->clt[i].x) + 1] == 'e' ||
      jtp->map[(int)(jtp->height -
		     (jtp->clt[i].y + 0.01))][(int)(jtp->clt[i].x) + 1] == 'e')
    {
      if (jtp->map[(int)(jtp->height - (jtp->clt[(i + 1) % 2].y + 0.99))]
	  [(int)(jtp->clt[(i + 1) % 2].x) + 1] == 'e' ||
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
      reset(jtp, arg);
      return ;
    }
  check_electric_down(jtp, i, arg);
  check_electric_up(jtp, i, arg);
}

void	check_pos_players(t_jtp *jtp, t_arg *arg)
{
  int	i;

  i = 0;
  while (i < 2)
    {
      check_electric(jtp, i, arg);
      if (jtp->clt[i].x + 0.95 >= jtp->width)
	{
	  if (jtp->clt[0].coin < jtp->clt[1].coin)
	    {
	      dprintf(jtp->clt[0].fd, "FINISH %d\n", jtp->clt[1].id);
	      dprintf(jtp->clt[1].fd, "FINISH %d\n", jtp->clt[1].id);
	    }
	  else if (jtp->clt[1].coin < jtp->clt[0].coin)
	    {
	      dprintf(jtp->clt[0].fd, "FINISH %d\n", jtp->clt[0].id);
	      dprintf(jtp->clt[1].fd, "FINISH %d\n", jtp->clt[0].id);
	    }
	  else
	    print_draw(jtp);
	  reset(jtp, arg);
	  return ;
	}
      check_coins(jtp, i++);
    }
}

void	movement_players(t_jtp *jtp)
{
  int		i;

  i = 0;
  while (i < 2)
    {
      if (jtp->clt[i].y + (jtp->gravity * jtp->clt[i].fire) /
	  50 > 0 && jtp->clt[i].y + (jtp->gravity * jtp->clt[i].fire)
	  / 50 + 0.99 < jtp->height)
	jtp->clt[i].y += (jtp->gravity * jtp->clt[i].fire) / 50;
      else
	{
	  if (jtp->clt[i].y + (jtp->gravity * jtp->clt[i].fire) /
	      50 < 0)
	    jtp->clt[i].y = 0;
	  else if (jtp->clt[i].y + (jtp->gravity * jtp->clt[i].fire) /
				    50 + 0.99 > jtp->height)
	    jtp->clt[i].y = jtp->clt[i].y;
	}
      jtp->clt[i].x += 0.087;
      i++;
    }
}

void	send_player_info(t_jtp *jtp, t_arg *arg)
{
  if (jtp->start != 1)
    return ;
  movement_players(jtp);
  check_pos_players(jtp, arg);
  usleep(20000);
  if (jtp->clt[0].fd != 0 && jtp->clt[1].fd != 1)
    dprintf(jtp->clt[0].fd, "PLAYER %d %.1f %.1f %d\nPLAYER %d %.1f %.1f %d\n",
	    jtp->clt[0].id, jtp->clt[0].x, jtp->clt[0].y, jtp->clt[0].coin,
	    jtp->clt[1].id, jtp->clt[1].x, jtp->clt[1].y, jtp->clt[1].coin);
  if (jtp->clt[0].fd != 0 && jtp->clt[1].fd != 1)
    dprintf(jtp->clt[1].fd, "PLAYER %d %.1f %.1f %d\nPLAYER %d %.1f %.1f %d\n",
	    jtp->clt[1].id, jtp->clt[1].x, jtp->clt[1].y, jtp->clt[1].coin,
	    jtp->clt[0].id, jtp->clt[0].x, jtp->clt[0].y, jtp->clt[0].coin);
}
