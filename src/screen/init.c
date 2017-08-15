/*
** init.c for gb in /home/tetra/GB
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jul 28 00:29:53 2017 Arthur Josso
** Last update Wed Aug 16 01:18:02 2017 Arthur Josso
*/

#include "screen.h"
#include "misc.h"

t_screen	screen =
  {
    .surface = NULL,
    .clock = 0,
    .state = SCR_HBLANK,
    .changed_state = false,
    .line = 0
  };

bool	screen_init()
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    return (false);
  SDL_WM_SetCaption("GameBoy Emulator", NULL);
  screen.surface = SDL_SetVideoMode(SCREEN_SIZE_X,
				    SCREEN_SIZE_Y,
				    32, SDL_HWSURFACE | SDL_RESIZABLE);
  if (screen.surface == NULL)
    return (false);
  screen.pix_scr.size.x = SCREEN_SIZE_X;
  screen.pix_scr.size.y = SCREEN_SIZE_Y;
  screen.pix_scr.array = xalloc(SCREEN_SIZE_X * SCREEN_SIZE_Y *
				sizeof(uint32_t));
  screen.pix_bg.size.x = BACKGROUND_SIZE;
  screen.pix_bg.size.y = BACKGROUND_SIZE;
  screen.pix_bg.array = xalloc(BACKGROUND_SIZE * BACKGROUND_SIZE *
			       sizeof(uint32_t));
  return (true);
}
