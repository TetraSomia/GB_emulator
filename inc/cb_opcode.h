/*
** cb_opcode.h for lol in /home/tetra/GB
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jul 12 19:11:04 2017 Arthur Josso
** Last update Mon Jul 24 00:01:12 2017 Arthur Josso
*/

#pragma once

#include <stdint.h>

#define Y_NOT_MANDATORY	(255)

typedef union
{
  struct
  {
    uint8_t	z : 3;
    uint8_t	y : 3;
    uint8_t	x : 2;
  };
  struct
  {
    uint8_t	field0 : 3;
    uint8_t	q : 1;
    uint8_t	p : 2;
    uint8_t	field3 : 2;
  };
  uint8_t	raw;
} t_cb_byte;

typedef struct
{
  uint8_t	x;
  uint8_t	y;
  void		(*op)(uint8_t, t_parameter*);
} t_cb_func_desc;

uint8_t	get_last_cb_inst_cycles();
