/*
** special_reg.h for gb in /home/tetra/en_cours/GB_emulator
**
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
**
** Started on  Tue Jul 25 00:05:05 2017 Arthur Josso
** Last update Tue Jul 25 01:25:29 2017 Arthur Josso
*/

#pragma once

typedef enum
  {
    REG_TIMA = 0xFF05,
    REG_TMA = 0xFF06,
    REG_TAC = 0xFF07,
    REG_IF = 0xFF0F,
    REG_NR10 = 0xFF10,
    REG_NR11 = 0xFF11,
    REG_NR12 = 0xFF12,
    REG_NR14 = 0xFF14,
    REG_NR21 = 0xFF16,
    REG_NR22 = 0xFF17,
    REG_NR24 = 0xFF19,
    REG_NR30 = 0xFF1A,
    REG_NR31 = 0xFF1B,
    REG_NR32 = 0xFF1C,
    REG_NR33 = 0xFF1E,
    REG_NR41 = 0xFF20,
    REG_NR42 = 0xFF21,
    REG_NR43 = 0xFF22,
    REG_NR44 = 0xFF23,
    REG_NR50 = 0xFF24,
    REG_NR51 = 0xFF25,
    REG_NR52 = 0xFF26,
    REG_LCDC = 0xFF40,
    REG_STAT = 0xFF41,
    REG_SCY = 0xFF42,
    REG_SCX = 0xFF43,
    REG_LY = 0xFF44,
    REG_LYC = 0xFF45,
    REG_BGP = 0xFF47,
    REG_OBP0 = 0xFF48,
    REG_OBP1 = 0xFF49,
    REG_WY = 0xFF4A,
    REG_WX = 0xFF4B,
    REG_IE = 0xFFFF
  } t_spe_reg_addr;

typedef struct
{
  uint8_t	state : 2;
  uint8_t	coincidence : 1;
  uint8_t	interrupt : 4;
  uint8_t	none : 1;
} t_spereg_stat;

