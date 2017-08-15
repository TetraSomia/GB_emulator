/*
** screen.h for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jul 24 23:17:00 2017 Arthur Josso
** Last update Wed Aug 16 01:22:50 2017 Arthur Josso
*/

#pragma once

#include <SDL.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define SCREEN_SIZE_X			160
#define SCREEN_SIZE_Y			144

#define BACKGROUND_SIZE			256

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
  int16_t	x;
  int16_t	y;
} t_pos;

typedef t_pos t_size;

typedef struct
{
  uint32_t	*array;
  t_size	size;
} t_pix_array;

typedef struct
{
  SDL_Surface		*surface;
  t_pix_array		pix_scr;
  t_pix_array		pix_bg;
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

typedef struct
{
} t_tile;

void screen_draw_tile(t_pix_array *pix_array, t_tile *tile, t_pos pos);

/*
** CPU
*/

void refresh_screen_state(uint8_t elapsed_cycles);
