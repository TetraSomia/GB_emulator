/*
** opcode.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Mar 11 19:43:47 2017 Arthur Josso
** Last update Sun Jul  9 21:27:36 2017 Arthur Josso
*/

#include "memory.h"
#include "instruction.h"
#include "opcode.h"

t_instruction	inst_tab[] =
  {
    // LD

    {0x3E, 2, {P_REG_8(B), P_VAL_8}, inst_LD, "LD A, #"},
    {0x06, 2, {P_REG_8(B), P_VAL_8}, inst_LD, "LD B, n"},
    {0x0E, 2, {P_REG_8(C), P_VAL_8}, inst_LD, "LD C, n"},
    {0x16, 2, {P_REG_8(D), P_VAL_8}, inst_LD, "LD D, n"},
    {0x1E, 2, {P_REG_8(E), P_VAL_8}, inst_LD, "LD E, n"},
    {0x26, 2, {P_REG_8(H), P_VAL_8}, inst_LD, "LD H, n"},
    {0x2E, 2, {P_REG_8(L), P_VAL_8}, inst_LD, "LD L, n"},
    
    {0x7F, 1, {P_REG_8(A), P_REG_8(A)}, inst_LD, "LD A, A"},
    {0x78, 1, {P_REG_8(A), P_REG_8(B)}, inst_LD, "LD A, B"},
    {0x79, 1, {P_REG_8(A), P_REG_8(C)}, inst_LD, "LD A, C"},
    {0x7A, 1, {P_REG_8(A), P_REG_8(D)}, inst_LD, "LD A, D"},
    {0x7B, 1, {P_REG_8(A), P_REG_8(E)}, inst_LD, "LD A, E"},
    {0x7C, 1, {P_REG_8(A), P_REG_8(H)}, inst_LD, "LD A, H"},
    {0x7D, 1, {P_REG_8(A), P_REG_8(L)}, inst_LD, "LD A, L"},
    {0x7E, 2, {P_REG_8(A), P_IREG_8(HL)}, inst_LD, "LD A, (HL)"},

    {0x47, 1, {P_REG_8(B), P_REG_8(A)}, inst_LD, "LD B, A"},
    {0x40, 1, {P_REG_8(B), P_REG_8(B)}, inst_LD, "LD B, B"},
    {0x41, 1, {P_REG_8(B), P_REG_8(C)}, inst_LD, "LD B, C"},
    {0x42, 1, {P_REG_8(B), P_REG_8(D)}, inst_LD, "LD B, D"},
    {0x43, 1, {P_REG_8(B), P_REG_8(E)}, inst_LD, "LD B, E"},
    {0x44, 1, {P_REG_8(B), P_REG_8(H)}, inst_LD, "LD B, H"},
    {0x45, 1, {P_REG_8(B), P_REG_8(L)}, inst_LD, "LD B, L"},
    {0x46, 2, {P_REG_8(B), P_IREG_8(HL)}, inst_LD, "LD B, (HL)"},

    {0x4F, 1, {P_REG_8(C), P_REG_8(A)}, inst_LD, "LD C, A"},
    {0x48, 1, {P_REG_8(C), P_REG_8(B)}, inst_LD, "LD C, B"},
    {0x49, 1, {P_REG_8(C), P_REG_8(C)}, inst_LD, "LD C, C"},
    {0x4A, 1, {P_REG_8(C), P_REG_8(D)}, inst_LD, "LD C, D"},
    {0x4B, 1, {P_REG_8(C), P_REG_8(E)}, inst_LD, "LD C, E"},
    {0x4C, 1, {P_REG_8(C), P_REG_8(H)}, inst_LD, "LD C, H"},
    {0x4D, 1, {P_REG_8(C), P_REG_8(L)}, inst_LD, "LD C, L"},
    {0x4E, 2, {P_REG_8(C), P_IREG_8(HL)}, inst_LD, "LD C, (HL)"},

    {0x57, 1, {P_REG_8(D), P_REG_8(A)}, inst_LD, "LD D, A"},
    {0x50, 1, {P_REG_8(D), P_REG_8(B)}, inst_LD, "LD D, B"},
    {0x51, 1, {P_REG_8(D), P_REG_8(C)}, inst_LD, "LD D, C"},
    {0x52, 1, {P_REG_8(D), P_REG_8(D)}, inst_LD, "LD D, D"},
    {0x53, 1, {P_REG_8(D), P_REG_8(E)}, inst_LD, "LD D, E"},
    {0x54, 1, {P_REG_8(D), P_REG_8(H)}, inst_LD, "LD D, H"},
    {0x55, 1, {P_REG_8(D), P_REG_8(L)}, inst_LD, "LD D, L"},
    {0x56, 2, {P_REG_8(D), P_IREG_8(HL)}, inst_LD, "LD D, (HL)"},

    {0x5F, 1, {P_REG_8(E), P_REG_8(A)}, inst_LD, "LD E, A"},
    {0x58, 1, {P_REG_8(E), P_REG_8(B)}, inst_LD, "LD E, B"},
    {0x59, 1, {P_REG_8(E), P_REG_8(C)}, inst_LD, "LD E, C"},
    {0x5A, 1, {P_REG_8(E), P_REG_8(D)}, inst_LD, "LD E, D"},
    {0x5B, 1, {P_REG_8(E), P_REG_8(E)}, inst_LD, "LD E, E"},
    {0x5C, 1, {P_REG_8(E), P_REG_8(H)}, inst_LD, "LD E, H"},
    {0x5D, 1, {P_REG_8(E), P_REG_8(L)}, inst_LD, "LD E, L"},
    {0x5E, 2, {P_REG_8(E), P_IREG_8(HL)}, inst_LD, "LD E, (HL)"},

    {0x67, 1, {P_REG_8(H), P_REG_8(A)}, inst_LD, "LD H, A"},
    {0x60, 1, {P_REG_8(H), P_REG_8(B)}, inst_LD, "LD H, B"},
    {0x61, 1, {P_REG_8(H), P_REG_8(C)}, inst_LD, "LD H, C"},
    {0x62, 1, {P_REG_8(H), P_REG_8(D)}, inst_LD, "LD H, D"},
    {0x63, 1, {P_REG_8(H), P_REG_8(E)}, inst_LD, "LD H, E"},
    {0x64, 1, {P_REG_8(H), P_REG_8(H)}, inst_LD, "LD H, H"},
    {0x65, 1, {P_REG_8(H), P_REG_8(L)}, inst_LD, "LD H, L"},
    {0x66, 2, {P_REG_8(H), P_IREG_8(HL)}, inst_LD, "LD H, (HL)"},

    {0x6F, 1, {P_REG_8(L), P_REG_8(A)}, inst_LD, "LD L, A"},
    {0x68, 1, {P_REG_8(L), P_REG_8(B)}, inst_LD, "LD L, B"},
    {0x69, 1, {P_REG_8(L), P_REG_8(C)}, inst_LD, "LD L, C"},
    {0x6A, 1, {P_REG_8(L), P_REG_8(D)}, inst_LD, "LD L, D"},
    {0x6B, 1, {P_REG_8(L), P_REG_8(E)}, inst_LD, "LD L, E"},
    {0x6C, 1, {P_REG_8(L), P_REG_8(H)}, inst_LD, "LD L, H"},
    {0x6D, 1, {P_REG_8(L), P_REG_8(L)}, inst_LD, "LD L, L"},
    {0x6E, 2, {P_REG_8(L), P_IREG_8(HL)}, inst_LD, "LD L, (HL)"},

    {0x70, 2, {P_IREG_8(HL), P_REG_8(B)}, inst_LD, "LD (HL), B"},
    {0x71, 2, {P_IREG_8(HL), P_REG_8(C)}, inst_LD, "LD (HL), C"},
    {0x72, 2, {P_IREG_8(HL), P_REG_8(D)}, inst_LD, "LD (HL), D"},
    {0x73, 2, {P_IREG_8(HL), P_REG_8(E)}, inst_LD, "LD (HL), E"},
    {0x74, 2, {P_IREG_8(HL), P_REG_8(H)}, inst_LD, "LD (HL), H"},
    {0x75, 2, {P_IREG_8(HL), P_REG_8(L)}, inst_LD, "LD (HL), L"},
    {0x36, 3, {P_IREG_8(HL), P_VAL_8}, inst_LD, "LD (HL), n"},

    {0x0A, 2, {P_REG_8(A), P_IREG_8(BC)}, inst_LD, "LD A, (BC)"},
    {0x1A, 2, {P_REG_8(A), P_IREG_8(DE)}, inst_LD, "LD A, (DE)"},
    {0xFA, 4, {P_REG_8(A), P_IVAL_8}, inst_LD, "LD A, (nn)"},
    {0x02, 2, {P_IREG_8(BC), P_REG_8(A)}, inst_LD, "LD (BC), A"},
    {0x12, 2, {P_IREG_8(DE), P_REG_8(A)}, inst_LD, "LD (DE), A"},
    {0x77, 2, {P_IREG_8(HL), P_REG_8(A)}, inst_LD, "LD (HL), A"},
    {0xEA, 4, {P_IVAL_8, P_REG_8(A)}, inst_LD, "LD (nn), A"},

    // LD + offset

    {0xF2, 2, {P_REG_8(A), P_REG_8(C)}, inst_LDH, "LD A, ($FF00 + C)"},
    {0xE2, 2, {P_REG_8(C), P_REG_8(A)}, inst_LDH, "LD ($FF00 + C), A"},
    {0xF0, 3, {P_REG_8(A), P_VAL_8}, inst_LDH, "LD A, ($FF00 + n)"},
    {0xE0, 3, {P_VAL_8, P_REG_8(A)}, inst_LDH, "LD ($FF00 + n), A"},

    // LD + inc or dec

    {0x3A, 2, {P_REG_8(A), P_IREG_8(HL)}, inst_LDD, "LDD A, (HL)"},
    {0x32, 2, {P_IREG_8(HL), P_REG_8(A)}, inst_LDD, "LDD (HL), A"},
    {0x2A, 2, {P_REG_8(A), P_IREG_8(HL)}, inst_LDI, "LDI A, (HL)"},
    {0x22, 2, {P_IREG_8(HL), P_REG_8(A)}, inst_LDI, "LDI (HL), A"},

    // LD 16 bits

    {0x01, 3, {P_REG_16(BC), P_VAL_16}, inst_LD, "LD BC, nn"},
    {0x11, 3, {P_REG_16(DE), P_VAL_16}, inst_LD, "LD DE, nn"},
    {0x21, 3, {P_REG_16(HL), P_VAL_16}, inst_LD, "LD HL, nn"},
    {0x31, 3, {P_REG_16(SP), P_VAL_16}, inst_LD, "LD SP, nn"},

    {0xF9, 2, {P_REG_16(SP), P_REG_16(HL)}, inst_LD, "LD SP, HL"},

    {0x08, 5, {P_IVAL_16, P_REG_16(SP)}, inst_LD, "LD (nn), SP"},

    {0xF8, 3, {P_REG_16(SP), P_VAL_8}, inst_LDHL, "LDHL SP, n"},

    // PUSH and POP

    {0xF5, 4, {P_IREG_16(SP), P_REG_16(AF)}, inst_PUSH, "PUSH AF"},
    {0xC5, 4, {P_IREG_16(SP), P_REG_16(BC)}, inst_PUSH, "PUSH BC"},
    {0xD5, 4, {P_IREG_16(SP), P_REG_16(DE)}, inst_PUSH, "PUSH DE"},
    {0xE5, 4, {P_IREG_16(SP), P_REG_16(HL)}, inst_PUSH, "PUSH HL"},

    {0xF1, 3, {P_REG_16(AF), P_IREG_16(SP)}, inst_POP, "POP AF"},
    {0xC1, 3, {P_REG_16(BC), P_IREG_16(SP)}, inst_POP, "POP BC"},
    {0xD1, 3, {P_REG_16(DE), P_IREG_16(SP)}, inst_POP, "POP DE"},
    {0xE1, 3, {P_REG_16(HL), P_IREG_16(SP)}, inst_POP, "POP HL"},
    
    // 3.3.3 ALU
  };

void	set_param_value(t_parameter *param, uint16_t value)
{
  switch (param->type)
    {
    case REG_8:
      *(uint8_t*)(param->addr) = value;
      break;
    case REG_16:
      *(uint16_t*)(param->addr) = value;
      break;
    case IREG_8:
      set_byte(*(uint16_t*)(param->addr), value);
      break;
    case IREG_16:
      set_word(*(uint16_t*)(param->addr), value);
      break;
    case VAL_8:
      set_byte(reg.PC + 1, value);
      break;
    case VAL_16:
      set_word(reg.PC + 2, value);
      break;
    case IVAL_8:
      set_byte(get_word(reg.PC + 2), value);
      break;
    case IVAL_16:
      set_word(get_word(reg.PC + 2), value);
      break;
    default:
      return;
    }
}

uint16_t	get_param_value(t_parameter *param)
{
  switch (param->type)
    {
    case REG_8:
      return (*(uint8_t*)(param->addr));
    case REG_16:
      return (*(uint16_t*)(param->addr));
    case IREG_8:
      return (get_byte(*(uint16_t*)(param->addr)));
    case IREG_16:
      return (get_word(*(uint16_t*)(param->addr)));
    case VAL_8:
      return (get_byte(reg.PC + 1));
    case VAL_16:
      return (get_word(reg.PC + 2));
    case IVAL_8:
      return (get_byte(get_word(reg.PC + 2)));
    case IVAL_16:
      return (get_word(get_word(reg.PC + 2)));
    case RAW:
      return (param->raw);
    default:
      return (0);
    }
}
