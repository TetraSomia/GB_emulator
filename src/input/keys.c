/*
** keys.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jul 28 00:45:26 2017 Arthur Josso
** Last update Fri Jul 28 00:47:11 2017 Arthur Josso
*/

#include <SDL.h>

void	check_for_inputs()
{
  SDL_Event     event;

  while (SDL_PollEvent(&event))
    {
      switch (event.type)
	{
        case SDL_KEYUP:
          if (event.key.keysym.sym == SDLK_ESCAPE)
	    exit(0);
          break;
        case SDL_QUIT:
	  exit(0);
	  break;
	default:
	  break;
        }
    }
}
