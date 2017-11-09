/*
** sdl_display.c for  in /home/baud_d/Desktop/J2T3/jetpack2Tek3_2016/client
** 
** Made by Cesar Baud
** Login   <baud_d@epitech.net>
** 
** Started on  Tue Jul 18 12:51:53 2017 Cesar Baud
** Last update Wed Jul 19 11:21:43 2017 baud
*/

#include "client.h"

pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

void		display_score(t_clt *clt, SDL_Surface *screen)
{
  char		p1[64];
  char		p2[64];
  SDL_Rect	rect[2];
  SDL_Color	colour = {.r = 255, .g = 255, .b = 255};
  SDL_Surface	*txt;
  TTF_Font	*font;

  rect[0].x = 3;
  rect[0].y = clt->height + 20;
  rect[1].x = 3;
  rect[1].y = clt->height;
  font = NULL;
  txt = NULL;
  memset(p1, 0, 64);
  if ((font = TTF_OpenFont("./font/my_font.ttf", 15)) == NULL)
    return ;
  sprintf(p1, "Distance : %.1fm", clt->player[0].x);
  sprintf(p2, "Me : %d coins   You : %d coins",
	  clt->player[0].coin, clt->player[1].coin);
  txt = TTF_RenderText_Blended(font, p1, colour);
  SDL_BlitSurface(txt, NULL, screen, &rect[0]);
  txt = NULL;
  txt = TTF_RenderText_Blended(font, p2, colour);
  SDL_BlitSurface(txt, NULL, screen, &rect[1]);
}

void		add_player(t_clt *clt, SDL_Surface *screen)
{
  int		i;
  SDL_Rect	rect;
  SDL_Surface	*surf;

  i = 0;
  while (i < 2)
    {
      rect.x = clt->player[i].x * W_SIZE;
      rect.y = (clt->height - clt->player[i].y - 1) * H_SIZE;
      surf = SDL_CreateRGBSurface(SDL_HWSURFACE, W_SIZE, H_SIZE,
				  32, 0, 0, 0, 0);
      if (clt->player[i].id == clt->id)
	SDL_FillRect(surf, NULL, SDL_MapRGB(screen->format, 0, 255, 0));
      else
	SDL_FillRect(surf, NULL, SDL_MapRGB(screen->format, 255, 0, 0));
      if (surf)
	SDL_BlitSurface(surf, NULL, screen, &rect);
      i++;
      SDL_FreeSurface(surf);
    }
  display_score(clt, screen);
}

void		display_map(t_clt *clt, SDL_Surface *screen)
{
  int		i[2];
  SDL_Rect	rect;
  SDL_Surface	*surf;

  i[0] = 0;
  while (i[0] < clt->height && clt->map)
    {
      i[1] = 0;
      while (i[1] < clt->width)
	{
	  rect.x = i[1] * W_SIZE;
	  rect.y = i[0] * H_SIZE;
	  surf = SDL_CreateRGBSurface(SDL_HWSURFACE, W_SIZE, H_SIZE, 32,
				      0, 0, 0, 0);
	  SDL_FillRect(surf, NULL, SDL_MapRGB(screen->format, IS_COIN ? 255 :
					      IS_ELEC ? 158 : 0,
					      IS_ELEC ? 43 : IS_COIN ? 255 : 0,
					      IS_ELEC ? 15 : IS_COIN ? 0 : 102));
	  SDL_BlitSurface(surf, NULL, screen, &rect);
	  SDL_FreeSurface(surf);
	  i[1]++;
	}
      i[0]++;
    }
  add_player(clt, screen);
}

void		my_sleep(t_clt *clt, SDL_Surface *screen)
{
  SDL_Event	event;

  while (42)
    {
      SDL_PollEvent(&event);
      if (event.type == SDL_QUIT)
	break ;
      else if (event.type == SDL_KEYDOWN)
	{
	  if (event.key.keysym.sym == SDLK_SPACE)
	    dprintf(clt->sock_fd, "FIRE 1\n");
	  else if (event.key.keysym.sym == SDLK_ESCAPE)
	    {
	      TTF_Quit();
	      SDL_Quit();
	      exit(0);
	    }
	}
      else if (event.type == SDL_KEYUP)
	dprintf(clt->sock_fd, "FIRE 0\n");
      display_map(clt, screen);
      SDL_Flip(screen);
      usleep(25000);
    }
}

void		sdl_display(t_clt *clt)
{
  SDL_Surface	*screen;

  screen = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    my_error("SDL failed init video");
  if (TTF_Init() == -1)
    my_error("Erreur init ttf_init");
  if ((screen = SDL_SetVideoMode(1920, 400, 32,
				 SDL_HWSURFACE | SDL_RESIZABLE)) == NULL)
    my_error("Failed to set video mode");
  SDL_WM_SetCaption("Jetpack2Tek3", NULL);
  display_map(clt, screen);
  SDL_Flip(screen);
  my_sleep(clt, screen);
  SDL_FreeSurface(screen);
  TTF_Quit();
  SDL_Quit();
  exit(0);
}
