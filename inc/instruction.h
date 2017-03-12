/*
** instruction.h for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Mar 11 19:42:01 2017 Arthur Josso
** Last update Sun Mar 12 16:10:20 2017 Arthur Josso
*/

#pragma once

#include "opcode.h"

void inst_LD(t_parameter *param);
void inst_LDH(t_parameter *param);
void inst_LDD(t_parameter *param);
void inst_LDI(t_parameter *param);
void inst_LDHL(t_parameter *param);
void inst_PUSH(t_parameter *param);
void inst_POP(t_parameter *param);
