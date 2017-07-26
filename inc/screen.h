/*
** screen.h for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jul 24 23:17:00 2017 Arthur Josso
** Last update Wed Jul 26 02:14:16 2017 Arthur Josso
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define SCR_COMPLETE_REFRESH_DUR	70224
#define SCR_REFRESH_DUR_WITHOUT_VB	65664
#define SCR_LINE_REFRESH_DUR		456
#define SCR_NBR_LINES			144

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
  uint32_t		clock;
  t_screen_state	state;
  uint8_t		line;
} t_screen;

extern t_screen	screen;

void refresh_screen_state(uint8_t elapsed_cycles);
