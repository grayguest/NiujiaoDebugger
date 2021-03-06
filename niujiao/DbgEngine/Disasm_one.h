#pragma once
/*
定义反汇编引擎的部分结构  gOneByteCodeMap 是基于intel手册2517页的One-byte Opcode Map进行整理的
*/
#include "Disasm.h"

static UCHAR gNumbericType[][16] = { "byte ptr","word ptr","dword ptr","qword ptr" };
static UCHAR gSegRegStr[][4] = { "es:","cs:","ss:","ds:","fs:","gs:" };

static char gRegister[][8] = { "al","cl","dl","bl","ah","ch","dh","bh","","","","","","","","",
						"ax","cx","dx","bx","sp","bp","si","di", "es", "ss", "cs", "ds", "gs", "fs", "","",
					"eax","ecx","edx","ebx","esp","ebp","esi","edi", "es", "ss", "cs", "ds", "gs", "", "","",
					"rax","rcx","rdx","rbx","rsp","rbp","rsi","rdi", "es", "ss", "cs", "ds", "gs", "", "","",
					"mm0","mm1","mm2","mm3","mm4","mm5","mm6","mm7","","","","","","","","",
					"xmm0","xmm1","xmm2","xmm3","xmm4","xmm5","xmm6","xmm7","","","","","","","","", };
static UCHAR gDebugRegister[][4] = { "cr0","","cr2","cr3","","","cr6","cr7" };
static UCHAR gControlRegister[][4] = { "dr0","dr1","dr2","dr3","dr4","dr5","dr6","dr7" };
static UCHAR gSegmentRegister[][4] = { "es","cs","ss","ds","fs","gs","","" };
#define GET_REGISTER(BIT,REG) gRegister[((BIT-AT__REG8)*RG__MAX+REG)]

static STR_MAP_CODE gOneByteCodeMap[] =
{
	{0x00,"add"            ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__b,AT__G,OT__b,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x01,"add"            ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__v,AT__G,OT__v,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x02,"add"            ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__b,AT__E,OT__b,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x03,"add"            ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__v,AT__E,OT__v,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x04,"add"            ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__I,OT__b,0,0,0,0)       ,Disasm::Disasm_reg_or_imm},
	{0x05,"add"            ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__AX,AT__I,OT__z,0,0,0,0)          ,Disasm::Disasm_reg_or_imm},
	{0x06,"push"           ,PACK_OPERAND(ONE_OPERAND,AT_XX,RG__ES,0,0,0,0,0,0)                   ,Disasm::Disasm_reg_or_imm},
	{0x07,"pop"            ,PACK_OPERAND(ONE_OPERAND,AT_XX,RG__ES,0,0,0,0,0,0)                   ,Disasm::Disasm_reg_or_imm},
	{0x08,"or"             ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__b,AT__G,OT__b,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x09,"or"             ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__v,AT__G,OT__v,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x0a,"or"             ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__b,AT__E,OT__b,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x0b,"or"             ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__v,AT__E,OT__v,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x0c,"or"             ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__I,OT__b,0,0,0,0)       ,Disasm::Disasm_reg_or_imm},
	{0x0d,"or"             ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__AX,AT__I,OT__z,0,0,0,0)          ,Disasm::Disasm_reg_or_imm},
	{0x0e,"push"           ,PACK_OPERAND(ONE_OPERAND,AT_XX,RG__CS,0,0,0,0,0,0)                   ,Disasm::Disasm_reg_or_imm},
	{0x0f,""               ,0                                                                    ,Disasm::Disasm_two_opcode},
	{0x10,"adc"            ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__b,AT__G,OT__b,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x11,"adc"            ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__v,AT__G,OT__v,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x12,"adc"            ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__b,AT__E,OT__b,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x13,"adc"            ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__v,AT__E,OT__v,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x14,"adc"            ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__I,OT__b,0,0,0,0)       ,Disasm::Disasm_reg_or_imm},
	{0x15,"adc"            ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__AX,AT__I,OT__z,0,0,0,0)          ,Disasm::Disasm_reg_or_imm},
	{0x16,"push"           ,PACK_OPERAND(ONE_OPERAND,AT_XX,RG__SS,0,0,0,0,0,0)                   ,Disasm::Disasm_reg_or_imm},
	{0x17,"pop"            ,PACK_OPERAND(ONE_OPERAND,AT_XX,RG__SS,0,0,0,0,0,0)                   ,Disasm::Disasm_reg_or_imm},
	{0x18,"sbb"            ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__b,AT__G,OT__b,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x19,"sbb"            ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__v,AT__G,OT__v,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x1a,"sbb"            ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__b,AT__E,OT__b,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x1b,"sbb"            ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__v,AT__E,OT__v,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x1c,"sbb"            ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__I,OT__b,0,0,0,0)       ,Disasm::Disasm_reg_or_imm},
	{0x1d,"sbb"            ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__AX,AT__I,OT__z,0,0,0,0)          ,Disasm::Disasm_reg_or_imm},
	{0x1e,"push"           ,PACK_OPERAND(ONE_OPERAND,AT_XX,RG__DS,0,0,0,0,0,0)                   ,Disasm::Disasm_reg_or_imm},
	{0x1f,"pop"            ,PACK_OPERAND(ONE_OPERAND,AT_XX,RG__DS,0,0,0,0,0,0)                   ,Disasm::Disasm_reg_or_imm},
	{0x20,"and"            ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__b,AT__G,OT__b,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x21,"and"            ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__v,AT__G,OT__v,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x22,"and"            ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__b,AT__E,OT__b,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x23,"and"            ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__v,AT__E,OT__v,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x24,"and"            ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__I,OT__b,0,0,0,0)       ,Disasm::Disasm_reg_or_imm},
	{0x25,"and"            ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__AX,AT__I,OT__z,0,0,0,0)          ,Disasm::Disasm_reg_or_imm},
	{0x26,""               ,PREFIX_Seg_ES_26                                                     ,Disasm::Disasm_set_prefix},
	{0x27,"daa"            ,0                                                                    ,Disasm::Disasm_no_operand},
	{0x28,"sub"            ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__b,AT__G,OT__b,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x29,"sub"            ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__v,AT__G,OT__v,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x2a,"sub"            ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__b,AT__E,OT__b,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x2b,"sub"            ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__v,AT__E,OT__v,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x2c,"sub"            ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__I,OT__b,0,0,0,0)       ,Disasm::Disasm_reg_or_imm},
	{0x2d,"sub"            ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__AX,AT__I,OT__z,0,0,0,0)          ,Disasm::Disasm_reg_or_imm},
	{0x2e,""               ,PREFIX_Seg_CS_2E                                                     ,Disasm::Disasm_set_prefix},
	{0x2f,"das"            ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                           ,Disasm::Disasm_no_operand},
	{0x30,"xor"            ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__b,AT__G,OT__b,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x31,"xor"            ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__v,AT__G,OT__v,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x32,"xor"            ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__b,AT__E,OT__b,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x33,"xor"            ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__v,AT__E,OT__v,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x34,"xor"            ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__I,OT__b,0,0,0,0)       ,Disasm::Disasm_reg_or_imm},
	{0x35,"xor"            ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__AX,AT__I,OT__z,0,0,0,0)          ,Disasm::Disasm_reg_or_imm},
	{0x36,""               ,PREFIX_Seg_SS_36                                                     ,Disasm::Disasm_set_prefix},
	{0x37,"aaa"            ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                           ,Disasm::Disasm_no_operand},
	{0x38,"cmp"            ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__b,AT__G,OT__b,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x39,"cmp"            ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__v,AT__G,OT__v,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x3a,"cmp"            ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__b,AT__E,OT__b,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x3b,"cmp"            ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__v,AT__E,OT__v,0,0,0,0)            ,Disasm::Disasm_ModRM},
	{0x3c,"cmp"            ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__I,OT__b,0,0,0,0)       ,Disasm::Disasm_reg_or_imm},
	{0x3d,"cmp"            ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__AX,AT__I,OT__z,0,0,0,0)          ,Disasm::Disasm_reg_or_imm},
	{0x3e,""               ,PREFIX_Seg_DS_3E                                                     ,Disasm::Disasm_set_prefix},
	{0x3f,"aas"            ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                           ,Disasm::Disasm_no_operand},
	{0x40,"inc"            ,PACK_OPERAND(ONE_OPERAND,AT_eXX,RG__AX,0,0,0,0,0,0)                  ,Disasm::Disasm_RexPrefix},
	{0x41,"inc"            ,PACK_OPERAND(ONE_OPERAND,AT_eXX,RG__CX,0,0,0,0,0,0)                  ,Disasm::Disasm_RexPrefix},
	{0x42,"inc"            ,PACK_OPERAND(ONE_OPERAND,AT_eXX,RG__DX,0,0,0,0,0,0)                  ,Disasm::Disasm_RexPrefix},
	{0x43,"inc"            ,PACK_OPERAND(ONE_OPERAND,AT_eXX,RG__BX,0,0,0,0,0,0)                  ,Disasm::Disasm_RexPrefix},
	{0x44,"inc"            ,PACK_OPERAND(ONE_OPERAND,AT_eXX,RG__SP,0,0,0,0,0,0)                  ,Disasm::Disasm_RexPrefix},
	{0x45,"inc"            ,PACK_OPERAND(ONE_OPERAND,AT_eXX,RG__BP,0,0,0,0,0,0)                  ,Disasm::Disasm_RexPrefix},
	{0x46,"inc"            ,PACK_OPERAND(ONE_OPERAND,AT_eXX,RG__SI,0,0,0,0,0,0)                  ,Disasm::Disasm_RexPrefix},
	{0x47,"inc"            ,PACK_OPERAND(ONE_OPERAND,AT_eXX,RG__DI,0,0,0,0,0,0)                  ,Disasm::Disasm_RexPrefix},
	{0x48,"dec"            ,PACK_OPERAND(ONE_OPERAND,AT_eXX,RG__AX,0,0,0,0,0,0)                  ,Disasm::Disasm_RexPrefix},
	{0x49,"dec"            ,PACK_OPERAND(ONE_OPERAND,AT_eXX,RG__CX,0,0,0,0,0,0)                  ,Disasm::Disasm_RexPrefix},
	{0x4a,"dec"            ,PACK_OPERAND(ONE_OPERAND,AT_eXX,RG__DX,0,0,0,0,0,0)                  ,Disasm::Disasm_RexPrefix},
	{0x4b,"dec"            ,PACK_OPERAND(ONE_OPERAND,AT_eXX,RG__BX,0,0,0,0,0,0)                  ,Disasm::Disasm_RexPrefix},
	{0x4c,"dec"            ,PACK_OPERAND(ONE_OPERAND,AT_eXX,RG__SP,0,0,0,0,0,0)                  ,Disasm::Disasm_RexPrefix},
	{0x4d,"dec"            ,PACK_OPERAND(ONE_OPERAND,AT_eXX,RG__BP,0,0,0,0,0,0)                  ,Disasm::Disasm_RexPrefix},
	{0x4e,"dec"            ,PACK_OPERAND(ONE_OPERAND,AT_eXX,RG__SI,0,0,0,0,0,0)                  ,Disasm::Disasm_RexPrefix},
	{0x4f,"dec"            ,PACK_OPERAND(ONE_OPERAND,AT_eXX,RG__DI,0,0,0,0,0,0)                  ,Disasm::Disasm_RexPrefix},
	{0x50,"push"           ,PACK_OPERAND(ONE_OPERAND,AT_rXX,RG__AX,0,0,0,0,0,0)                  ,Disasm::Disasm_reg_or_imm},
	{0x51,"push"           ,PACK_OPERAND(ONE_OPERAND,AT_rXX,RG__CX,0,0,0,0,0,0)                  ,Disasm::Disasm_reg_or_imm},
	{0x52,"push"           ,PACK_OPERAND(ONE_OPERAND,AT_rXX,RG__DX,0,0,0,0,0,0)                  ,Disasm::Disasm_reg_or_imm},
	{0x53,"push"           ,PACK_OPERAND(ONE_OPERAND,AT_rXX,RG__BX,0,0,0,0,0,0)                  ,Disasm::Disasm_reg_or_imm},
	{0x54,"push"           ,PACK_OPERAND(ONE_OPERAND,AT_rXX,RG__SP,0,0,0,0,0,0)                  ,Disasm::Disasm_reg_or_imm},
	{0x55,"push"           ,PACK_OPERAND(ONE_OPERAND,AT_rXX,RG__BP,0,0,0,0,0,0)                  ,Disasm::Disasm_reg_or_imm},
	{0x56,"push"           ,PACK_OPERAND(ONE_OPERAND,AT_rXX,RG__SI,0,0,0,0,0,0)                  ,Disasm::Disasm_reg_or_imm},
	{0x57,"push"           ,PACK_OPERAND(ONE_OPERAND,AT_rXX,RG__DI,0,0,0,0,0,0)                  ,Disasm::Disasm_reg_or_imm},
	{0x58, "pop"           ,PACK_OPERAND(ONE_OPERAND,AT_rXX,RG__AX,0,0,0,0,0,0)                  ,Disasm::Disasm_reg_or_imm },
	{0x59, "pop"           ,PACK_OPERAND(ONE_OPERAND,AT_rXX,RG__CX,0,0,0,0,0,0)                  ,Disasm::Disasm_reg_or_imm },
	{0x5a, "pop"           ,PACK_OPERAND(ONE_OPERAND,AT_rXX,RG__DX,0,0,0,0,0,0)                  ,Disasm::Disasm_reg_or_imm },
	{0x5b, "pop"           ,PACK_OPERAND(ONE_OPERAND,AT_rXX,RG__BX,0,0,0,0,0,0)                  ,Disasm::Disasm_reg_or_imm },
	{0x5c, "pop"           ,PACK_OPERAND(ONE_OPERAND,AT_rXX,RG__SP,0,0,0,0,0,0)                  ,Disasm::Disasm_reg_or_imm },
	{0x5d, "pop"           ,PACK_OPERAND(ONE_OPERAND,AT_rXX,RG__BP,0,0,0,0,0,0)                  ,Disasm::Disasm_reg_or_imm },
	{0x5e, "pop"           ,PACK_OPERAND(ONE_OPERAND,AT_rXX,RG__SI,0,0,0,0,0,0)                  ,Disasm::Disasm_reg_or_imm },
	{0x5f, "pop"           ,PACK_OPERAND(ONE_OPERAND,AT_rXX,RG__DI,0,0,0,0,0,0)                  ,Disasm::Disasm_reg_or_imm },
	{0x60,""               ,PACK_OPERAND(ZERO_OPERAND,AT__I,OT__b,0,0,0,0,0,0)                   ,Disasm::Disasm_pusha},
	{0x61,""               ,PACK_OPERAND(ZERO_OPERAND,AT__I,OT__b,0,0,0,0,0,0)                   ,Disasm::Disasm_popa},
	{0x62,"bound"          ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__v,AT__M,OT__a,0,0,0,0)            ,Disasm::Disasm_bound},
	{0x63,""               ,0                                                                    ,Disasm::Disasm_0x63 },
	{0x64,""               ,PREFIX_Seg_FS_64                                                     ,Disasm::Disasm_set_prefix },
	{0x65,""               ,PREFIX_Seg_GS_65                                                     ,Disasm::Disasm_set_prefix },
	{0x66,""               ,PREFIX_Oprand_Size_66                                                ,Disasm::Disasm_set_prefix },
	{0x67,""               ,PREFIX_Address_Size_67                                               ,Disasm::Disasm_set_prefix },
	{0x68,"push"           ,PACK_OPERAND(ONE_OPERAND,AT__I,OT__z,0,0,0,0,0,0)                    ,Disasm::Disasm_reg_or_imm },
	{0x69,"imul"           ,PACK_OPERAND(THREE_OPERAND,AT__G,OT__v,AT__E,OT__v,AT__I,OT__z,0,0)  ,Disasm::Disasm_imul },
	{0x6a,"push"           ,PACK_OPERAND(ONE_OPERAND,AT__I,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_GetEachOperand },
	{0x6b,"imul"           ,PACK_OPERAND(THREE_OPERAND,AT__G,OT__v,AT__E,OT__v,AT__I,OT__b,0,0)  ,Disasm::Disasm_imul },
	{0x6c,""               ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                           ,Disasm::Disasm_6c_6d },
	{0x6d,""               ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                           ,Disasm::Disasm_6c_6d },
	{0x6e,""               ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                           ,Disasm::Disasm_6e_6f },
	{0x6f,""               ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                           ,Disasm::Disasm_6e_6f },
	{ 0x70,"jo short"      ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_reg_or_imm },
	{ 0x71,"jno short"     ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_reg_or_imm },
	{ 0x72,"jb short"      ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_reg_or_imm },
	{ 0x73,"jnb short"     ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_reg_or_imm },
	{ 0x74,"je short"      ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_reg_or_imm },
	{ 0x75,"jnz short"     ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_reg_or_imm },
	{ 0x76,"jbe short"     ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_reg_or_imm },
	{ 0x77,"ja short"      ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_reg_or_imm },
	{ 0x78,"js short"      ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_reg_or_imm },
	{ 0x79,"jns short"     ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_reg_or_imm },
	{ 0x7a,"jp short"      ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_reg_or_imm },
	{ 0x7b,"jnp short"     ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_reg_or_imm },
	{ 0x7c,"jl short"      ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_reg_or_imm },
	{ 0x7d,"jnl short"     ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_reg_or_imm },
	{ 0x7e,"jle short"     ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_reg_or_imm },
	{ 0x7f,"jg short"      ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_reg_or_imm },
	{ 0x80,""              ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__b,AT__I,OT__b,0,0,0,0)            ,Disasm::Disasm_grp_80_83 },
	{ 0x81,""              ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__v,AT__I,OT__z,0,0,0,0)            ,Disasm::Disasm_grp_80_83 },
	{ 0x82,""              ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__b,AT__I,OT__b,0,0,0,0)            ,Disasm::Disasm_grp_80_83 },
	{ 0x83,""              ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__v,AT__I,OT__b,0,0,0,0)            ,Disasm::Disasm_grp_80_83 },
	{ 0x84,"test"          ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__b,AT__G,OT__b,0,0,0,0)            ,Disasm::Disasm_ModRM },
	{ 0x85,"test"          ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__v,AT__G,OT__v,0,0,0,0)            ,Disasm::Disasm_ModRM },
	{ 0x86,"xchg"          ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__b,AT__G,OT__b,0,0,0,0)            ,Disasm::Disasm_ModRM },
	{ 0x87,"xchg"          ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__v,AT__G,OT__v,0,0,0,0)            ,Disasm::Disasm_ModRM },
	{ 0x88,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__b,AT__G,OT__b,0,0,0,0)            ,Disasm::Disasm_ModRM },
	{ 0x89,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__v,AT__G,OT__v,0,0,0,0)            ,Disasm::Disasm_ModRM },
	{ 0x8a,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__b,AT__E,OT__b,0,0,0,0)            ,Disasm::Disasm_ModRM },
	{ 0x8b,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__v,AT__E,OT__v,0,0,0,0)            ,Disasm::Disasm_ModRM },
	{ 0x8c,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT__E,OT__v,AT__S,OT__w,0,0,0,0)            ,Disasm::Disasm_ModRM },
	{ 0x8d,"lea"           ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__v,AT__M,0,0,0,0,0)                ,Disasm::Disasm_ModRM },  
	{ 0x8e,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT__S,OT__w,AT__E,OT__w,0,0,0,0)            ,Disasm::Disasm_ModRM },
	{ 0x8f,""              ,PACK_OPERAND(ONE_OPERAND,AT__E,OT__v,0,0,0,0,0,0)                    ,Disasm::Disasm_grp_8f },
	{ 0x90,"nop"           ,0                                                                    ,Disasm::Disasm_0x90 },
	{ 0x91,"xchg"          ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__AX,AT_rXX,RG__CX,0,0,0,0)        ,Disasm::Disasm_reg_or_imm},
	{ 0x92,"xchg"          ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__AX,AT_rXX,RG__DX,0,0,0,0)        ,Disasm::Disasm_reg_or_imm},
	{ 0x93,"xchg"          ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__AX,AT_rXX,RG__BX,0,0,0,0)        ,Disasm::Disasm_reg_or_imm},
	{ 0x94,"xchg"          ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__AX,AT_rXX,RG__SP,0,0,0,0)        ,Disasm::Disasm_reg_or_imm},
	{ 0x95,"xchg"          ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__AX,AT_rXX,RG__BP,0,0,0,0)        ,Disasm::Disasm_reg_or_imm},
	{ 0x96,"xchg"          ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__AX,AT_rXX,RG__SI,0,0,0,0)        ,Disasm::Disasm_reg_or_imm},
	{ 0x97,"xchg"          ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__AX,AT_rXX,RG__DI,0,0,0,0)        ,Disasm::Disasm_reg_or_imm},
	{ 0x98,""              ,0                                                                    ,Disasm::Disasm_0x98 },
	{ 0x99,""              ,0                                                                    ,Disasm::Disasm_0x99 },
	{ 0x9a,"call"          ,PACK_OPERAND(ONE_OPERAND,AT__A,OT__p,0,0,0,0,0,0)                    ,Disasm::Disasm_reg_or_imm },
	{ 0x9b,"fwait"          ,0                                                                    ,Disasm::Disasm_no_operand },
	{ 0x9c,""              ,PACK_OPERAND(ONE_OPERAND,AT__F,OT__v,0,0,0,0,0,0)                    ,Disasm::Disasm_pushf },
	{ 0x9d,""              ,PACK_OPERAND(ONE_OPERAND,AT__F,OT__v,0,0,0,0,0,0)                    ,Disasm::Disasm_popf },
	{ 0x9e,"sahf"          ,0                                                                    ,Disasm::Disasm_no_operand },
	{ 0x9f,"lahf"          ,0                                                                    ,Disasm::Disasm_no_operand },
	{ 0xa0,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__O,OT__b,0,0,0,0)       ,Disasm::Disasm_reg_or_imm},
	{ 0xa1,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__AX,AT__O,OT__v,0,0,0,0)          ,Disasm::Disasm_reg_or_imm},
	{ 0xa2,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT__O,OT__b,AT__REG8,RG8__AL,0,0,0,0)       ,Disasm::Disasm_reg_or_imm},
	{ 0xa3,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT__O,OT__v,AT_rXX,RG__AX,0,0,0,0)          ,Disasm::Disasm_reg_or_imm},
	{ 0xa4,""              ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                           ,Disasm::Disasm_a4_a5 },
	{ 0xa5,""              ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                           ,Disasm::Disasm_a4_a5 },
	{ 0xa6,""              ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                           ,Disasm::Disasm_a6_a7 },
	{ 0xa7,""              ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                           ,Disasm::Disasm_a6_a7 },
	{ 0xa8,"test"          ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__I,OT__b,0,0,0,0)       ,Disasm::Disasm_reg_or_imm },
	{ 0xa9,"test"          ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__AX,AT__I,OT__z,0,0,0,0)          ,Disasm::Disasm_reg_or_imm },
	{ 0xaa,"stos"          ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                           ,Disasm::Disasm_aa_ab },
	{ 0xab,"stos"          ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                           ,Disasm::Disasm_aa_ab },
	{ 0xac,"lods"          ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                           ,Disasm::Disasm_ac_a4_6e_9d_aa_ae },
	{ 0xad,"lods"          ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                           ,Disasm::Disasm_ac_ad },
	{ 0xae,"scas"          ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                           ,Disasm::Disasm_ae_af },
	{ 0xaf,"scas"          ,PACK_OPERAND(ZERO_OPERAND,0,0,0,0,0,0,0,0)                           ,Disasm::Disasm_ae_af },
	{ 0xb0,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__I,OT__b,0,0,0,0)       ,Disasm::Disasm_reg_or_imm },
	{ 0xb1,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__CL,AT__I,OT__b,0,0,0,0)       ,Disasm::Disasm_reg_or_imm },
	{ 0xb2,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__DL,AT__I,OT__b,0,0,0,0)       ,Disasm::Disasm_reg_or_imm },
	{ 0xb3,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__BL,AT__I,OT__b,0,0,0,0)       ,Disasm::Disasm_reg_or_imm },
	{ 0xb4,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AH,AT__I,OT__b,0,0,0,0)       ,Disasm::Disasm_reg_or_imm },
	{ 0xb5,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__CH,AT__I,OT__b,0,0,0,0)       ,Disasm::Disasm_reg_or_imm },
	{ 0xb6,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__DH,AT__I,OT__b,0,0,0,0)       ,Disasm::Disasm_reg_or_imm },
	{ 0xb7,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__BH,AT__I,OT__b,0,0,0,0)       ,Disasm::Disasm_reg_or_imm },
	{ 0xb8,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__AX,AT__I,OT__v,0,0,0,0)          ,Disasm::Disasm_reg_or_imm },
	{ 0xb9,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__CX,AT__I,OT__v,0,0,0,0)          ,Disasm::Disasm_reg_or_imm },
	{ 0xba,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__DX,AT__I,OT__v,0,0,0,0)          ,Disasm::Disasm_reg_or_imm },
	{ 0xbb,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__BX,AT__I,OT__v,0,0,0,0)          ,Disasm::Disasm_reg_or_imm },
	{ 0xbc,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__SP,AT__I,OT__v,0,0,0,0)          ,Disasm::Disasm_reg_or_imm },
	{ 0xbd,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__BP,AT__I,OT__v,0,0,0,0)          ,Disasm::Disasm_reg_or_imm },
	{ 0xbe,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__SI,AT__I,OT__v,0,0,0,0)          ,Disasm::Disasm_reg_or_imm },
	{ 0xbf,"mov"           ,PACK_OPERAND(TWO_OPERAND,AT_rXX,RG__DI,AT__I,OT__v,0,0,0,0)          ,Disasm::Disasm_reg_or_imm },
	{ 0xc0,""              ,0                                                                    ,Disasm::Disasm_grp_shift },
	{ 0xc1,""              ,0                                                                    ,Disasm::Disasm_grp_shift },
	{ 0xc2,"retn"          ,PACK_OPERAND(ONE_OPERAND,AT__I,OT__w,0,0,0,0,0,0)                    ,Disasm::Disasm_ret },
	{ 0xc3,"ret "          ,0                                                                    ,Disasm::Disasm_no_operand },
	{ 0xc4,"les"           ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__z,AT__M,OT__p,0,0,0,0)            ,Disasm::Disasm_ModRM },
	{ 0xc5,"lds"           ,PACK_OPERAND(TWO_OPERAND,AT__G,OT__z,AT__M,OT__p,0,0,0,0)            ,Disasm::Disasm_ModRM },
	{ 0xc6,""              ,0                                                                    ,Disasm::Disasm_grp_c6_c7 },
	{ 0xc7,""              ,0                                                                    ,Disasm::Disasm_grp_c6_c7 },
	{ 0xc8,"enter"         ,PACK_OPERAND(TWO_OPERAND,AT__I,OT__w,AT__I,OT__b,0,0,0,0)            ,Disasm::Disasm_reg_or_imm },
	{ 0xc9,"leave"         ,0                                                                    ,Disasm::Disasm_no_operand },
	{ 0xca,"retn"          ,PACK_OPERAND(ONE_OPERAND,AT__I,OT__w,0,0,0,0,0,0)                    ,Disasm::Disasm_ret },
	{ 0xcb,"ret"           ,0                                                                    ,Disasm::Disasm_no_operand },
	{ 0xcc,"int"           ,0                                                                    ,Disasm::Disasm_cc },
	{ 0xcd,"int"           ,PACK_OPERAND(ONE_OPERAND,AT__I,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_GetEachOperand },
	{ 0xce,"into"          ,0                                                                    ,Disasm::Disasm_no_operand },
	{ 0xcf,"iret"          ,PACK_OPERAND(ONE_OPERAND,AT__I,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_cf },
	{ 0xd0,""              ,0                                                                    ,Disasm::Disasm_grp_shift },
	{ 0xd1,""              ,0                                                                    ,Disasm::Disasm_grp_shift },
	{ 0xd2,""              ,0                                                                    ,Disasm::Disasm_grp_shift },
	{ 0xd3,""              ,0                                                                    ,Disasm::Disasm_grp_shift },
	{ 0xd4,"aam"           ,PACK_OPERAND(ONE_OPERAND,AT__I,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_d4_d5 },
	{ 0xd5,"aad"           ,PACK_OPERAND(ONE_OPERAND,AT__I,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_d4_d5 },
	{ 0xd6,""              ,0                                                                    ,Disasm::Disasm_reserve },
	{ 0xd7,"xlatb"         ,PACK_OPERAND(ONE_OPERAND,AT__I,OT__b,0,0,0,0,0,0)                    ,Disasm::Disasm_no_operand },
	{ 0xd8,""             ,PACK_OPERAND(ONE_OPERAND,AT__E,OT__v,0,0,0,0,0,0)                     ,Disasm::Disasm_ESC_0xd8 },
	{ 0xd9,""             ,PACK_OPERAND(ONE_OPERAND,AT__E,OT__w,0,0,0,0,0,0)                     ,Disasm::Disasm_ESC_0xd9 },
	{ 0xda,""             ,PACK_OPERAND(ONE_OPERAND,AT__E,OT__v,0,0,0,0,0,0)                     ,Disasm::Disasm_ESC_0xda },
	{ 0xdb,""             ,PACK_OPERAND(ONE_OPERAND,AT__E,OT__v,0,0,0,0,0,0)                     ,Disasm::Disasm_ESC_0xdb },
	{ 0xdc,""             ,PACK_OPERAND(ONE_OPERAND,AT__E,OT__v,0,0,0,0,0,0)                     ,Disasm::Disasm_ESC_0xdc },
	{ 0xdd,""             ,PACK_OPERAND(ONE_OPERAND,AT__E,OT__v,0,0,0,0,0,0)                     ,Disasm::Disasm_ESC_0xdd },
	{ 0xde,""             ,PACK_OPERAND(ONE_OPERAND,AT__E,OT__v,0,0,0,0,0,0)                     ,Disasm::Disasm_ESC_0xde },
	{ 0xdf,""             ,PACK_OPERAND(ONE_OPERAND,AT__E,OT__v,0,0,0,0,0,0)                     ,Disasm::Disasm_ESC_0xdf },
	{ 0xe0,"loopne"       ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__b,0,0,0,0,0,0)                     ,Disasm::Disasm_reg_or_imm },
	{ 0xe1,"loope"        ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__b,0,0,0,0,0,0)                     ,Disasm::Disasm_reg_or_imm },
	{ 0xe2,"loop"         ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__b,0,0,0,0,0,0)                     ,Disasm::Disasm_reg_or_imm },
	{ 0xe3,"jecxz"        ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__b,0,0,0,0,0,0)                     ,Disasm::Disasm_reg_or_imm },
	{ 0xe4,"in"           ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT__I,OT__b,0,0,0,0)        ,Disasm::Disasm_reg_or_imm },
	{ 0xe5,"in"           ,PACK_OPERAND(TWO_OPERAND,AT_eXX,RG__AX,AT__I,OT__b,0,0,0,0)           ,Disasm::Disasm_reg_or_imm },
	{ 0xe6,"out"          ,PACK_OPERAND(TWO_OPERAND,AT__I,OT__b,AT__REG8,RG8__AL,0,0,0,0)        ,Disasm::Disasm_reg_or_imm },
	{ 0xe7,"out"          ,PACK_OPERAND(TWO_OPERAND,AT__I,OT__b,AT_eXX,RG__AX,0,0,0,0)           ,Disasm::Disasm_reg_or_imm },
	{ 0xe8,"call"         ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__z,0,0,0,0,0,0)                     ,Disasm::Disasm_reg_or_imm },
	{ 0xe9,"jmp"          ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__z,0,0,0,0,0,0)                     ,Disasm::Disasm_reg_or_imm },
	{ 0xea,"jmp"          ,PACK_OPERAND(ONE_OPERAND,AT__A,OT__p,0,0,0,0,0,0)                     ,Disasm::Disasm_reg_or_imm },
	{ 0xeb,"jmp short"    ,PACK_OPERAND(ONE_OPERAND,AT__J,OT__b,0,0,0,0,0,0)                     ,Disasm::Disasm_reg_or_imm },
	{ 0xec,"in"           ,PACK_OPERAND(TWO_OPERAND,AT__REG8,RG8__AL,AT_XX,RG__DX,0,0,0,0)       ,Disasm::Disasm_reg_or_imm},
	{ 0xed,"in"           ,PACK_OPERAND(TWO_OPERAND,AT_eXX,RG__AX,AT_XX,RG__DX,0,0,0,0)          ,Disasm::Disasm_reg_or_imm},
	{ 0xee,"out"          ,PACK_OPERAND(TWO_OPERAND,AT_XX,RG__DX,AT__REG8,RG8__AL,0,0,0,0)       ,Disasm::Disasm_reg_or_imm},
	{ 0xef,"out"          ,PACK_OPERAND(TWO_OPERAND,AT_XX,RG__DX,AT_eXX,RG__AX,0,0,0,0)          ,Disasm::Disasm_reg_or_imm},
	{ 0xf0,""             ,PREFIX_Lock_F0                                                        ,Disasm::Disasm_set_prefix },
	{ 0xf1,""             ,0                                                                     ,Disasm::Disasm_reserve },
	{ 0xf2,""             ,PREFIX_Repne_F2                                                       ,Disasm::Disasm_set_prefix },
	{ 0xf3,""             ,PREFIX_Repe_F3                                                        ,Disasm::Disasm_set_prefix },
	{ 0xf4,"hlt"          ,0                                                                     ,Disasm::Disasm_no_operand },
	{ 0xf5,"cmc"          ,0                                                                     ,Disasm::Disasm_no_operand },
	{ 0xf6,""             ,PACK_OPERAND(ONE_OPERAND,AT__E,OT__b,0,0,0,0,0,0)                     ,Disasm::Disasm_grp_f6_f7 },
	{ 0xf7,""             ,PACK_OPERAND(ONE_OPERAND,AT__E,OT__v,0,0,0,0,0,0)                     ,Disasm::Disasm_grp_f6_f7 },
	{ 0xf8,"clc"          ,0                                                                     ,Disasm::Disasm_no_operand },
	{ 0xf9,"stc"          ,0                                                                     ,Disasm::Disasm_no_operand },
	{ 0xfa,"cli"          ,0                                                                     ,Disasm::Disasm_no_operand },
	{ 0xfb,"sti"          ,0                                                                     ,Disasm::Disasm_no_operand },
	{ 0xfc,"cld"          ,0                                                                     ,Disasm::Disasm_no_operand },
	{ 0xfd,"std"          ,0                                                                     ,Disasm::Disasm_no_operand },
	{ 0xfe,""             ,PACK_OPERAND(ONE_OPERAND,AT__E,OT__b,0,0,0,0,0,0)                     ,Disasm::Disasm_grp_fe },
	{ 0xff,""             ,0                                                                     ,Disasm::Disasm_grp_ff }
};