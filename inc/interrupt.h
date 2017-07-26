/*
** interrupt.h for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jul 24 00:34:06 2017 Arthur Josso
** Last update Wed Jul 26 17:19:04 2017 Arthur Josso
*/

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef bool (*t_interrupt)();

typedef enum
  {
    INT_FIRST = 0,
    INT_VBLANK = INT_FIRST,
    INT_LCDC,
    INT_TIMER,
    INT_SERIAL_IO,
    INT_PIN_TRANSITION,
    INT_NBR,
    INT_NONE
  } t_int_type;

void check_for_interrupts();

bool interrupt_vblank();
bool interrupt_lcdc();
bool interrupt_timer();
bool interrupt_serial_io();
bool interrupt_pin_transition();
