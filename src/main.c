/*
** main.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Mar  4 13:34:04 2017 Arthur Josso
** Last update Sun Mar  5 13:39:25 2017 Arthur Josso
*/

#include <stdio.h>
#include "memory.h"

int	main()
{
  t_registers reg;

  reg.A = 1;
  reg.F = 0;
  reg.flags = 0;
  printf("%x\n", reg.AF);
  SET_FLAG(reg, NONE0);
  SET_FLAG(reg, Z);
  printf("%d %d\n", GET_FLAG(reg, Z), reg.flags);
  RESET_FLAG(reg, Z);
  printf("%d %d\n", GET_FLAG(reg, Z), reg.flags);
  return (0);
}
