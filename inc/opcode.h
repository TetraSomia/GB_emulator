/*
** instruction.h for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Mar 11 19:42:01 2017 Arthur Josso
** Last update Wed Jul 12 19:31:39 2017 Arthur Josso
*/

#pragma once

#include <stddef.h>
#include <stdint.h>

/*
** Instruction descriptor structures
*/

#define CUSTOM_NB_CYCLES	(255)

typedef enum
  {
    REG_8,
    REG_16,
    IREG_8,
    IREG_16,
    VAL_8,
    VAL_16,
    IVAL_8,
    IVAL_16,
    RAW
  } t_param_type;

typedef struct
{
  t_param_type	type;
  uint16_t	raw;
  void		*addr;
} t_parameter;

typedef struct
{
  uint8_t	opcode;
  uint8_t	nb_cycles;
  uint8_t	byte_size;
  t_parameter	param[2];
  void		(*func)(t_parameter *param);
  const char	*desc;
} t_instruction;

/*
** Array of instructions
*/

extern const t_instruction	inst_tab[];

/*
** Parameter simplifier
*/

#define P_REG_8(R)	{REG_8, 0, &reg.R}
#define P_REG_16(R)	{REG_16, 0, &reg.R}
#define P_IREG_8(R)	{IREG_8, 0, &reg.R}
#define P_IREG_16(R)	{IREG_16, 0, &reg.R}
#define P_VAL_8		{VAL_8, 0, NULL}
#define P_VAL_16	{VAL_16, 0, NULL}
#define P_IVAL_8       	{IVAL_8, 0, NULL}
#define P_IVAL_16	{IVAL_16, 0, NULL}
#define P_RAW(V)	{RAW, V, NULL}

/*
** Parameter specifier
*/

#define IS_16_PARAM(p)	(p->type & 1)
#define IS_8_PARAM(p)	(!IS_16_PARAM(p))
#define PARAM_SIZE(p)	(IS_16_PARAM(p) ? 16 : 8)

/*
** Accessors with parameters
*/

void		set_param_value(t_parameter *param, uint16_t value);
uint16_t	get_param_value(t_parameter *param);
