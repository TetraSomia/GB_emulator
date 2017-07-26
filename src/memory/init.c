/*
** memory.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Mar  5 17:55:47 2017 Arthur Josso
** Last update Wed Jul 26 16:59:00 2017 Arthur Josso
*/

#include "memory.h"
#include "opcode.h"
#include "misc.h"

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
  mem->raw[0xFF05] = 0x00;
  mem->raw[0xFF06] = 0x00;
  mem->raw[0xFF07] = 0x00;
  mem->raw[0xFF10] = 0x80;
  mem->raw[0xFF11] = 0xBF;
  mem->raw[0xFF12] = 0xF3;
  mem->raw[0xFF14] = 0xBF;
  mem->raw[0xFF16] = 0x3F;
  mem->raw[0xFF17] = 0x00;
  mem->raw[0xFF19] = 0xBF;
  mem->raw[0xFF1A] = 0x7F;
  mem->raw[0xFF1B] = 0xFF;
  mem->raw[0xFF1C] = 0x9F;
  mem->raw[0xFF1E] = 0xBF;
  mem->raw[0xFF20] = 0xFF;
  mem->raw[0xFF21] = 0x00;
  mem->raw[0xFF22] = 0x00;
  mem->raw[0xFF23] = 0xBF;
  mem->raw[0xFF24] = 0x77;
  mem->raw[0xFF25] = 0xF3;
  mem->raw[0xFF26] = 0xF1;
  mem->raw[0xFF40] = 0x91;
  mem->raw[0xFF42] = 0x00;
  mem->raw[0xFF43] = 0x00;
  mem->raw[0xFF45] = 0x00;
  mem->raw[0xFF47] = 0xFC;
  mem->raw[0xFF48] = 0xFF;
  mem->raw[0xFF49] = 0xFF;
  mem->raw[0xFF4A] = 0x00;
  mem->raw[0xFF4B] = 0x00;
  mem->raw[0xFFFF] = 0x00;
}