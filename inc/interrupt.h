/*
** interrupt.h for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jul 24 00:34:06 2017 Arthur Josso
** Last update Mon Jul 24 01:01:00 2017 Arthur Josso
*/

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define RAISE_INTERRUPT(i)	(mem->raw[0xFF0F] |= 1 << i)

typedef bool (*t_interrupt)(uint8_t elapsed_cycles);

typedef enum
  {
    INT_FIRST = 0,
    INT_VBLANK = INT_FIRST,
    INT_LCDC,
    INT_TIMER,
    INT_SERIAL_IO,
    INT_PIN_TRANSITION,
    INT_NBR
  } t_int_type;

bool interrupt_vblank(uint8_t elapsed_cycles);
bool interrupt_lcdc(uint8_t elapsed_cycles);
bool interrupt_timer(uint8_t elapsed_cycles);
bool interrupt_serial_io(uint8_t elapsed_cycles);
bool interrupt_pin_transition(uint8_t elapsed_cycles);
