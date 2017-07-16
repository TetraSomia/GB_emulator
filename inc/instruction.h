/*
** instruction.h for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Mar 11 19:42:01 2017 Arthur Josso
** Last update Sun Jul 16 23:09:04 2017 Arthur Josso
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
void inst_AND(t_parameter *param);
void inst_OR(t_parameter *param);
void inst_XOR(t_parameter *param);
void inst_INC(t_parameter *param);
void inst_DEC(t_parameter *param);
void inst_CP(t_parameter *param);

void inst_RLC(t_parameter *param);
void inst_RRC(t_parameter *param);
void inst_RL(t_parameter *param);
void inst_RR(t_parameter *param);
void inst_SLA(t_parameter *param);
void inst_SRA(t_parameter *param);
void inst_SRL(t_parameter *param);

void inst_JP(t_parameter *param);
void inst_JR(t_parameter *param);
void inst_CALL(t_parameter *param);
void inst_RST(t_parameter *param);
void inst_RET(t_parameter *param);
void inst_RETI(t_parameter *param);

void inst_DAA(t_parameter *param);
void inst_CPL(t_parameter *param);
void inst_CCF(t_parameter *param);
void inst_SCF(t_parameter *param);
void inst_NOP(t_parameter *param);
void inst_EI(t_parameter *param);
void inst_DI(t_parameter *param);

void inst_CB_prefix(t_parameter *param);
