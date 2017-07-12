/*
** instruction.h for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Mar 11 19:42:01 2017 Arthur Josso
** Last update Wed Jul 12 17:38:22 2017 Arthur Josso
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
void inst_ADD(t_parameter *param);
void inst_ADD_SP(t_parameter *param);
void inst_ADC(t_parameter *param);
void inst_SUB(t_parameter *param);
void inst_SBC(t_parameter *param);
