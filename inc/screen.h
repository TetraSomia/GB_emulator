/*
** screen.h for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jul 24 23:17:00 2017 Arthur Josso
** Last update Fri Jul 28 19:02:56 2017 Arthur Josso
*/

#pragma once

#include <SDL.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define SCREEN_SIZE_X			160
#define SCREEN_SIZE_Y			144

#define SCR_COMPLETE_REFRESH_DUR	17556
#define SCR_REFRESH_DUR_WITHOUT_VB	16416
#define SCR_LINE_REFRESH_DUR		114
#define SCR_NBR_LINES			SCREEN_SIZE_Y

typedef enum
  {
    SCR_HBLANK = 0,
    SCR_VBLANK,
    SCR_OAM_SEARCH,
    SCR_DATA_TRANSFER,
    SCR_COINCIDENCE = SCR_DATA_TRANSFER,
    SCR_STATE_NBR
  } t_screen_state;

typedef struct
{
  SDL_Surface		*surface;
  uint32_t		*pixels;
  uint32_t		clock;
  t_screen_state	state;
  bool			changed_state;
  uint8_t		line;
} t_screen;

extern t_screen	screen;

/*
** GPU
*/

bool screen_init();
void screen_blit();

void screen_check_for_update();

void screen_draw_background();
void screen_draw_line(uint8_t line);

/*
** CPU
*/

void refresh_screen_state(uint8_t elapsed_cycles);
