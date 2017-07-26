/*
** memory.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Mar  5 17:55:47 2017 Arthur Josso
** Last update Wed Jul 26 18:27:42 2017 Arthur Josso
*/

#include "memory.h"
#include "opcode.h"
#include "misc.h"
#include "special_reg.h"

t_memory	*mem = NULL;
t_registers	reg;

void		init_memory()
{
  init_instructions();
  mem = xalloc(sizeof(*mem));
  reg.AF = 0x0001;
  reg.BC = 0x0013;
  reg.DE = 0x00D8;
  reg.HL = 0x014D;
  reg.SP = 0xFFFE;
  reg.flags = 0xB0;
  SET_FLAG(FLAG_I);
  reg.PC = 0x0100;
  mem->raw[REG_DIV] = 0x00;
  mem->raw[REG_TIMA] = 0x00;
  mem->raw[REG_TMA] = 0x00;
  mem->raw[REG_TAC] = 0x00;
  mem->raw[REG_IF] = 0x00;
  mem->raw[REG_NR10] = 0x80;
  mem->raw[REG_NR11] = 0xBF;
  mem->raw[REG_NR12] = 0xF3;
  mem->raw[REG_NR14] = 0xBF;
  mem->raw[REG_NR21] = 0x3F;
  mem->raw[REG_NR22] = 0x00;
  mem->raw[REG_NR24] = 0xBF;
  mem->raw[REG_NR30] = 0x7F;
  mem->raw[REG_NR31] = 0xFF;
  mem->raw[REG_NR32] = 0x9F;
  mem->raw[REG_NR33] = 0xBF;
  mem->raw[REG_NR41] = 0xFF;
  mem->raw[REG_NR42] = 0x00;
  mem->raw[REG_NR43] = 0x00;
  mem->raw[REG_NR44] = 0xBF;
  mem->raw[REG_NR50] = 0x77;
  mem->raw[REG_NR51] = 0xF3;
  mem->raw[REG_NR52] = 0xF1;
  mem->raw[REG_LCDC] = 0x91;
  mem->raw[REG_STAT] = 0x00;
  mem->raw[REG_SCY] = 0x00;
  mem->raw[REG_SCX] = 0x00;
  mem->raw[REG_LY] = 0x00;
  mem->raw[REG_LYC] = 0x00;
  mem->raw[REG_BGP] = 0xFC;
  mem->raw[REG_OBP0] = 0xFF;
  mem->raw[REG_OBP1] = 0xFF;
  mem->raw[REG_WY] = 0x00;
  mem->raw[REG_WX] = 0x00;
  mem->raw[REG_IE] = 0x00;
}
