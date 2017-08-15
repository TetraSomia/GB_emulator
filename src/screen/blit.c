/*
** blit.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jul 28 00:54:03 2017 Arthur Josso
** Last update Wed Aug 16 01:15:07 2017 Arthur Josso
*/

#include "screen.h"

void	screen_blit()
{
  if (SDL_MUSTLOCK(screen.surface))
    if (SDL_LockSurface(screen.surface) < 0)
      return ;
  memcpy(screen.surface->pixels, screen.pix_scr.array,
	 SCREEN_SIZE_X * SCREEN_SIZE_Y * sizeof(uint32_t));
  if (SDL_MUSTLOCK(screen.surface))
    SDL_UnlockSurface(screen.surface);
  SDL_UpdateRect(screen.surface, 0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y);
}
