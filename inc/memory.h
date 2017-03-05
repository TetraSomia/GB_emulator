/*
** memory.h for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Mar  5 12:55:18 2017 Arthur Josso
** Last update Sun Mar  5 19:19:02 2017 Arthur Josso
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>

/*
** Register structure
*/

#define REG_PAIR(X, Y) union{struct{uint8_t Y;uint8_t X;};uint16_t X##Y;};

typedef struct
{
  REG_PAIR(A, F);
  REG_PAIR(B, C);
  REG_PAIR(D, E);
  REG_PAIR(H, L);
  uint16_t	PC;
  uint16_t	SP;
  uint8_t	flags;
} t_registers;

/*
** Flag Management
*/

typedef enum 
  {
    NONE0 = 0,
    NONE1,
    NONE2,
    NONE3,
    C,
    H,
    N,
    Z
  } t_flag_bit;

#define SET_FLAG(f)    	(reg->flags |= 1 << f)
#define GET_FLAG(f)    	((reg->flags >> f) & 1)
#define RESET_FLAG(f)	(reg->flags &= ~(1 << f))

/*
** Memory Map
*/

typedef union
{
  uint8_t	raw[0x10000];
  struct
  {
    union
    {
      uint8_t	ROM[0x8000];
      struct
      {
	uint8_t	ROM_0[0x4000];
	uint8_t	ROM_sw[0x4000];
      };
    };
    uint8_t	VRAM[0x2000];
    uint8_t	RAM_sw[0x2000];
    uint8_t	RAM[0x2000];
    uint8_t	RAM_echo[0x1E00];
    uint8_t	OAM[0xA0];
    uint8_t	blank_0[0x60];
    uint8_t	IOs[0x4C];
    uint8_t	blank_1[0x34];
    uint8_t	HRAM[0x7F];
    uint8_t	IE_reg;
  };
} t_memory;

/*
** Globals
*/

extern t_memory		*mem;
extern t_registers	*reg;

/*
** Accessers
*/

uint8_t		get_byte(uint16_t addr);
uint16_t	get_word(uint16_t addr);
void		set_byte(uint16_t addr, uint8_t value);
void		set_word(uint16_t addr, uint16_t value);

/*
** Misc functions
*/

void            init_memory();
void		free_memory();
bool            dump_file(const char *path);
