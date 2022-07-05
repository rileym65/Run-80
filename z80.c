#include <stdio.h>
#define GLOBALS
#include "z80.h"

byte addHalfCarry[8]={0,
               0,
               HALF_CARRY_FLAG,
               0,
               HALF_CARRY_FLAG,
               0,
               HALF_CARRY_FLAG,
               HALF_CARRY_FLAG};
byte subHalfCarry[8]={0,
               HALF_CARRY_FLAG,
               HALF_CARRY_FLAG,
               HALF_CARRY_FLAG,
               0,
               0,
               0,
               HALF_CARRY_FLAG};
byte addflags[8]={0,
               OVERFLOW_FLAG | SIGN_FLAG,
               CARRY_FLAG,
               SIGN_FLAG,
               CARRY_FLAG,
               SIGN_FLAG,
               CARRY_FLAG | OVERFLOW_FLAG,
               CARRY_FLAG | SIGN_FLAG};
byte subflags[8]={0,
    CARRY_FLAG | SIGN_FLAG,
    CARRY_FLAG,
    OVERFLOW_FLAG | CARRY_FLAG | SIGN_FLAG,
    OVERFLOW_FLAG,
    SIGN_FLAG,
    0,
    CARRY_FLAG | SIGN_FLAG};

void _z80_InFlags(struct Z80CPU *z80,byte value) {
  }

word _z80_Offset(word address,byte ofs) {
  return (ofs & 128) ? address - (((~ofs)+1) & 0xff) : address + ofs;
  }

void _z80_Store(struct Z80CPU *z80,word Address,byte Value)
  {
    z80->ts+=3;
    (z80->Store)(z80,Address,Value);
  }

void _z80_Store2(struct Z80CPU *z80,word Address,word Value)
  {
    _z80_Store(z80,Address,Value & 255);
    _z80_Store(z80,Address+1,(Value>>8));
  }

byte _z80_Fetch(struct Z80CPU *z80,word Address)
  {
    z80->ts+=3;
    return (z80->Fetch)(z80,Address);
  }

word _z80_Fetch2(struct Z80CPU *z80,word Address)
  {
    return (_z80_Fetch(z80,Address)+(_z80_Fetch(z80,Address+1)<<8));
  }

byte _z80_InPort(struct Z80CPU *z80,byte port) {
  z80->ts+=3;
  return (z80->In)(z80,port);
  }

void _z80_OutPort(struct Z80CPU *z80,byte port,byte value) {
  z80->ts+=3;
  (z80->Out)(z80,port,value);
  }

void _z80_Push2(struct Z80CPU *z80,word Value)
  {
    z80->SP-=2;
    _z80_Store2(z80,z80->SP,Value);
  }

word _z80_Pop2(struct Z80CPU *z80)
  {
    z80->SP+=2;
    return (_z80_Fetch2(z80,z80->SP-2));
  }

byte _z80_Get_PC(struct Z80CPU *z80)
  {
  byte i;
  i=_z80_Fetch(z80,z80->PC++);
  return i;
  }

word _z80_Get_PC2(struct Z80CPU *z80)
  {
    z80->PC+=2;
    return(_z80_Fetch2(z80,z80->PC-2));
  }

void _z80_Cmp_8(struct Z80CPU *z80,byte *Register,byte Value)
  {
    byte i,j;
    int  flag;
    i=*Register; j=i;
    j -= Value;
    flag=((i&0x88)>>1) | ((Value&0x88)>>2) | ((j&0x88)>>3);
    z80->AF.AFu.F=subHalfCarry[flag&7]|subflags[flag>>4] |
      (Value & (FLAG3 | FLAG5)) | ADD_SUB_FLAG;
    if (j == 0) z80->AF.AFu.F|=ZERO_FLAG;
  }

byte _z80_Parity(byte Value)
  {
    int Count;
    Count=0;
    if (Value & 128) Count++;
    if (Value & 64) Count++;
    if (Value & 32) Count++;
    if (Value & 16) Count++;
    if (Value & 8) Count++;
    if (Value & 4) Count++;
    if (Value & 2) Count++;
    if (Value & 1) Count++;
    if (Count & 1)
      return (0);
     else
      return (1);
  }

byte _z80_add_Flags(int a,int b,int result) {
  int index;
  byte f;
  index=((a & 0x88)>>1) | ((b & 0x88)>>2) | ((result & 0x88)>>3);
  f=addHalfCarry[index & 7] | addflags[index >> 4] |
    (result & (FLAG3 | FLAG5));
  if ((result & 0xff) == 0) f |= ZERO_FLAG;
  return f;
  }

byte _z80_add_16_Flags(struct Z80CPU* z80,int a,int b,int result) {
  int index;
  byte f;
  index=((a & 0x8800) >> 9) | ((b & 0x8800) >> 10) | ((result & 0x8800) >> 11);
  f=addHalfCarry[index & 7] | (addflags[index >> 4] & CARRY_FLAG) |
  (z80->AF.AFu.F & (ZERO_FLAG | OVERFLOW_FLAG | SIGN_FLAG)) |
  ((result >> 8) & (FLAG3 | FLAG5));
  return f;
  }

byte _z80_sub_Flags(int a,int b,int result) {
  int index;
  byte f;
  index=((a & 0x88)>>1) | ((b & 0x88)>>2) | ((result & 0x88)>>3);
  f=ADD_SUB_FLAG | subHalfCarry[index & 7] |
    subflags[index>>4] | (result & (FLAG3 | FLAG5));
  if ((result & 0xff)==0) f |= ZERO_FLAG;
  return f;
  }

void _z80_Logic_Flags(struct Z80CPU *z80,byte Value) {
    z80->AF.AFu.F &= ADD_SUB_OFF;
    z80->AF.AFu.F &= CARRY_OFF;
    if (_z80_Parity(Value)==1) z80->AF.AFu.F |= OVERFLOW_FLAG;
      else z80->AF.AFu.F &= OVERFLOW_OFF;
    if (Value==0) z80->AF.AFu.F |= ZERO_FLAG;
      else z80->AF.AFu.F &= ZERO_OFF;
    if (Value & 128) z80->AF.AFu.F |= SIGN_FLAG;
      else z80->AF.AFu.F &= SIGN_OFF;
    z80->AF.AFu.F |= (Value & (FLAG3 | FLAG5));
  }

void _z80_And_8(struct Z80CPU *z80,byte *Register,byte Value)
  {
    *Register &= Value;
    z80->AF.AFu.F=HALF_CARRY_FLAG;
    _z80_Logic_Flags(z80,*Register);
  }

void _z80_XOr_8(struct Z80CPU *z80,byte *Register,byte Value)
  {
    *Register ^= Value;
    z80->AF.AFu.F=0;
    _z80_Logic_Flags(z80,*Register);
  }

void _z80_Or_8(struct Z80CPU *z80,byte *Register,byte Value)
  {
    *Register |= Value;
    z80->AF.AFu.F=0;
    _z80_Logic_Flags(z80,*Register);
  }

void _z80_Sub_8(struct Z80CPU *z80,byte *Register,byte Value)
  {
    int a,result;
    a=*Register;
    result=a-Value;
    *Register=result;
    z80->AF.AFu.F = _z80_sub_Flags(a,Value,result);
/*
    byte i;
    byte flag;
    i=*Register;
    *Register -= Value;
    flag=((i&0x88)>>1) | ((Value&0x88)>>2) | ((*Register&0x88)>>3);
    z80->AF.AFu.F=subHalfCarry[flag&7]|subflags[flag>>4] |
      (*Register & (FLAG3 | FLAG5)) | ADD_SUB_FLAG;
    if (*Register == 0) z80->AF.AFu.F|=ZERO_FLAG;
*/
  }

void _z80_Neg_8(struct Z80CPU *z80,byte *Register)
  {
    int a;
    a=*Register;
    *Register=-a;
    z80->AF.AFu.F = _z80_sub_Flags(0,a,*Register);
/*
    byte i;
    byte flag;
    i=*Register;
    *Register=0-*Register;
    flag=((0&0x88)>>1) | ((i&0x88)>>2) | ((*Register&0x88)>>3);
    z80->AF.AFu.F=subHalfCarry[flag&7]|subflags[flag>>4] |
      (*Register & (FLAG3 | FLAG5)) | ADD_SUB_FLAG;
    if (*Register == 0) z80->AF.AFu.F|=ZERO_FLAG;
*/
  }

void _z80_Sbc_8(struct Z80CPU *z80,byte *Register,byte Value)
  {
    int a,result;
    a=*Register;
    if (z80->AF.AFu.F & CARRY_FLAG) result=a-(Value + 1);
      else result=a-Value;
    *Register = result;
    z80->AF.AFu.F = _z80_sub_Flags(a,Value,result);
/*
    byte i;
    byte flag;
    byte cy;
    if (z80->AF.AFu.F & CARRY_FLAG) cy=1; else cy=0;
    i=*Register;
    (byte)(*Register -= (Value+cy));
    flag=((i&0x88)>>1) | ((Value&0x88)>>2) | ((*Register&0x88)>>3);
    z80->AF.AFu.F=subHalfCarry[flag&7]|subflags[flag>>4] |
      (*Register & (FLAG3 | FLAG5)) | ADD_SUB_FLAG;
    if (*Register == 0) z80->AF.AFu.F|=ZERO_FLAG;
*/
  }

void _z80_Add_8(struct Z80CPU *z80,byte *Register,byte Value)
  {
    int a,result;
    a=*Register;
    result=a+Value;
    *Register=result;
    z80->AF.AFu.F=_z80_add_Flags(a,Value,result);
/*
    byte i;
    byte flag;
    i=*Register;
    *Register += Value;
    flag=((i&0x88)>>1) | ((Value&0x88)>>2) | ((*Register&0x88)>>3);
    z80->AF.AFu.F=addHalfCarry[flag&7]|addflags[flag>>4] |
      (*Register & (FLAG3 | FLAG5));
    if (*Register == 0) z80->AF.AFu.F|=ZERO_FLAG;
*/
  }

void _z80_Adc_8(struct Z80CPU *z80,byte *Register,byte Value)
  {
    int a,result;
    a=*Register;
    if (z80->AF.AFu.F & CARRY_FLAG) result=a+Value+1;
      else result=a+Value;
    *Register=result;
    z80->AF.AFu.F = _z80_add_Flags(a,Value,result);
/*
    byte i;
    byte flag;
    byte cy;
    if (z80->AF.AFu.F & CARRY_FLAG) cy=1; else cy=0;
    i=*Register;
    (byte)(*Register += (Value+cy));
    flag=((i&0x88)>>1) | ((Value&0x88)>>2) | ((*Register&0x88)>>3);
    z80->AF.AFu.F=addHalfCarry[flag&7]|addflags[flag>>4] |
      (*Register & (FLAG3 | FLAG5));
    if (*Register == 0) z80->AF.AFu.F|=ZERO_FLAG;
*/
  }

void _z80_Add_16(struct Z80CPU *z80,word *Register,word Value)
  {
    word i;
    byte flag;
/*
    z80->AF.AFu.F=z80->AF.AFu.F & (ZERO_FLAG|OVERFLOW_FLAG|SIGN_FLAG);
*/
    i=*Register + Value;
    z80->AF.AFu.F=_z80_add_16_Flags(z80,*Register,Value,i);
/*
    flag=((*Register&0x8800)>>9) | ((Value&0x8800)>>10) | ((i&0x8800)>>11);
    z80->AF.AFu.F |= (addflags[flag>>4]&CARRY_FLAG);
*/
    *Register=i;
  }

void _z80_Adc_16(struct Z80CPU *z80,word *Register,word Value)
  {
    word i;
    byte flag;
    word cy;
    if (z80->AF.AFu.F & CARRY_FLAG) cy=1; else cy=0;
    i=*Register;
    (word)(*Register += (Value+cy));
    flag=((i&0x8800)>>9) | ((Value&0x8800)>>10) | ((*Register&0x8800)>>11);
    z80->AF.AFu.F=addHalfCarry[flag&7]|addflags[flag>>4] |
      ((*Register>>8) & (FLAG3 | FLAG5));
    if ((*Register & 0xffff) == 0) z80->AF.AFu.F|=ZERO_FLAG;
  }

void _z80_Sbc_16(struct Z80CPU *z80,word *Register,word Value)
  {
    word i;
    byte flag;
    word cy;
    if (z80->AF.AFu.F & CARRY_FLAG) cy=1; else cy=0;
    i=*Register;
    (word)(*Register -= (Value+cy));
    flag=((i&0x8800)>>9) | ((Value&0x8800)>>10) | ((*Register&0x8800)>>11);
    z80->AF.AFu.F=subHalfCarry[flag&7]|subflags[flag>>4] | ADD_SUB_FLAG |
      ((*Register>>8) & (FLAG3 | FLAG5));
    if (*Register == 0) z80->AF.AFu.F|=ZERO_FLAG;
  }

void _z80_Inc_8(struct Z80CPU *z80,byte *Register)    /* Increment 8-bit register */
  {
    z80->AF.AFu.F=(z80->AF.AFu.F & CARRY_FLAG);
    *Register=*Register+1;
    if (*Register==128 || *Register==0) z80->AF.AFu.F|=OVERFLOW_FLAG;
    if ((*Register & 15) == 0) z80->AF.AFu.F|=HALF_CARRY_FLAG;
    if (*Register == 0) z80->AF.AFu.F|=ZERO_FLAG;
    if (*Register & 0x80) z80->AF.AFu.F|=SIGN_FLAG;
    z80->AF.AFu.F |= (*Register & (FLAG3 | FLAG5));
  }

void _z80_Inc_16(word *value) {
  *value=*value+1;
  }

void _z80_Dec_16(word *value) {
  *value=*value-1;
  }

void _z80_Dec_8(struct Z80CPU *z80,byte *Register)   /* Increment 8-bit register */
  {
    z80->AF.AFu.F=(z80->AF.AFu.F & CARRY_FLAG) | ADD_SUB_FLAG;
    *Register=*Register-1;
    if (*Register==127) z80->AF.AFu.F|=OVERFLOW_FLAG;
    if ((*Register & 15) == 15) z80->AF.AFu.F|=HALF_CARRY_FLAG;
    if (*Register == 0) z80->AF.AFu.F|=ZERO_FLAG;
    if (*Register & 0x80) z80->AF.AFu.F|=SIGN_FLAG;
    z80->AF.AFu.F |= (*Register & (FLAG3 | FLAG5));
  }

void _z80_Inc_Mem_8(struct Z80CPU *z80,word address) {
  byte value;
  value=_z80_Fetch(z80,address);
  _z80_Inc_8(z80,&value);
  _z80_Store(z80,address,value);
  }

void _z80_Dec_Mem_8(struct Z80CPU *z80,word address) {
  byte value;
  value=_z80_Fetch(z80,address);
  _z80_Dec_8(z80,&value);
  _z80_Store(z80,address,value);
  }

void _z80_Exch_16(word *value1,word *value2) {
   word i;
   i=*value1; *value1=*value2; *value2=i;
   }

byte _z80_rlc_byte(struct Z80CPU *z80,byte value) {
  byte set;
  int result;
  set=0;
  if (value & 0x80) {
    result=((value << 1) & 0xff) | 1;
    set |= CARRY_FLAG;
    } else result=(value<<1) & 0xff;
  if (result & 0x80) set |= SIGN_FLAG;
  if (result == 0) set |= ZERO_FLAG;
  if (_z80_Parity(result)) set |= OVERFLOW_FLAG;
  z80->AF.AFu.F = (result & (FLAG3 | FLAG5)) | set;
  return result;
  }

byte _z80_rrc_byte(struct Z80CPU *z80,byte value) {
  byte set;
  int result;
  set = 0;
  if (value & 0x1) {
    result = (value >> 1) | 0x80;
    set |= CARRY_FLAG;
    } else result = (value >> 1);
  if (result & 0x80) set |= SIGN_FLAG;
  if (result == 0) set |= ZERO_FLAG;
  if (_z80_Parity(result)) set |= OVERFLOW_FLAG;
  z80->AF.AFu.F = (result & (FLAG3 | FLAG5)) | set;
  return result;
  }

byte _z80_rl_byte(struct Z80CPU *z80,byte value) {
  byte set;
  int result;
  set=0;
  if (z80->AF.AFu.F & CARRY_FLAG) result = ((value<<1) & 0xff) | 1;
    else result=(value<<1)&0xff;
  if (result & 0x80) set |= SIGN_FLAG;
  if (result == 0) set |= ZERO_FLAG;
  if (_z80_Parity(result)) set |= OVERFLOW_FLAG;
  if (value & 0x80) set |= CARRY_FLAG;
  z80->AF.AFu.F = (result & (FLAG3 | FLAG5)) | set;
  return result;
  }

byte _z80_rr_byte(struct Z80CPU *z80,byte value) {
  byte set;
  int result;
  set=0;
  if (z80->AF.AFu.F & CARRY_FLAG) result = ((value>>1) & 0xff) | 0x80;
    else result=(value>>1)&0xff;
  if (result & 0x80) set |= SIGN_FLAG;
  if (result == 0) set |= ZERO_FLAG;
  if (_z80_Parity(result)) set |= OVERFLOW_FLAG;
  if (value & 0x1) set |= CARRY_FLAG;
  z80->AF.AFu.F = (result & (FLAG3 | FLAG5)) | set;
  return result;
  }

byte _z80_sla_byte(struct Z80CPU* z80,byte value) {
  byte set;
  int  result;
  set=0;
  result = (value << 1) & 0xff;
  if (result & 0x80) set |= SIGN_FLAG;
  if (result == 0) set |= ZERO_FLAG;
  if (_z80_Parity(result)) set |= OVERFLOW_FLAG;
  if (value & 0x80) set |= CARRY_FLAG;
  z80->AF.AFu.F = (result & (FLAG3 | FLAG5)) | set;
  return result;
  }

byte _z80_sra_byte(struct Z80CPU* z80,byte value) {
  byte set;
  int  result;
  set=0;
  if (value & 0x80) {
    result = (value >> 1) | 0x80;
    set |= SIGN_FLAG;
    } else result = value >> 1;
  if (result == 0) set |= ZERO_FLAG;
  if (_z80_Parity(result)) set |= OVERFLOW_FLAG;
  if (value & 0x1) set |= CARRY_FLAG;
  z80->AF.AFu.F = (result & (FLAG3 | FLAG5)) | set;
  return result;
  }

byte _z80_srl_byte(struct Z80CPU* z80,byte value) {
  byte set;
  int  result;
  set=0;
  result = value >> 1;
  if (result & 0x80) set |= SIGN_FLAG;
  if (result == 0) set |= ZERO_FLAG;
  if (_z80_Parity(result)) set |= OVERFLOW_FLAG;
  if (value & 0x1) set |= CARRY_FLAG;
  z80->AF.AFu.F = (result & (FLAG3 | FLAG5)) | set;
  return result;
  }

void _z80_bit_byte(struct Z80CPU* z80,byte op,byte value,byte bit) {
  if (value & (1 << bit)) {
    z80->AF.AFu.F = (z80->AF.AFu.F & CARRY_FLAG) | HALF_CARRY_FLAG |
      (((op & 0x38) == 0x38) ? SIGN_FLAG : 0);
    } else {
    z80->AF.AFu.F = (z80->AF.AFu.F & CARRY_FLAG) |
      OVERFLOW_FLAG | HALF_CARRY_FLAG | ZERO_FLAG;
    }
  if ((op & 7) != 6) z80->AF.AFu.F |= (value & (FLAG3 | FLAG5));
  }

void z80_nmi(struct Z80CPU *z80) {
  _z80_Push2(z80,z80->PC);
  z80->PC = 0x0066;
  z80->IE2=z80->IE;
  z80->IE=0;
  }

void z80_irq(struct Z80CPU *z80, byte b1) {
  if (z80->IE == 0) return;
  _z80_Push2(z80,z80->PC);
  z80->IE = 0;
  z80->IE2 = 0;
  switch (z80->IM) {
    case 0:
         break;
    case 1:
         z80->PC = 0x0038;
         break;
    case 2:
         z80->PC = _z80_Fetch2(z80, (z80->I << 8) | (b1 & 0xfe));
         break;
    }
  }

void z80_cycle(struct Z80CPU *z80)
  {
    byte bt;
    if (z80->Halt != 0) return;
    z80->ts=1;
    if (z80->Intrpt != 0) {
      z80->Intrpt=0;
      z80->Halt=0;
      if (z80->IE == 0) bt=_z80_Get_PC(z80);
        else {
          bt=0xff;
          z80->IE=0;
          }
      } else bt=_z80_Get_PC(z80);
#ifdef HIST
  hist[0][bt]='*';
#endif
    z80->I1Byte[bt](z80);
    z80->R = (z80->R & 0x80) + ((z80->R+1) &0x7f);
  }

void z80_reset(struct Z80CPU *z80) {
  z80->AF.AF=0;
  z80->BC.BC=0;
  z80->DE.DE=0;
  z80->HL.HL=0;
  z80->IX=0;
  z80->IY=0;
  z80->SP=0;
  z80->PC=0;

  z80->IE=0;
  z80->PC=0;
  z80->R=0;
  z80->Halt=0;
  z80->Intrpt=0;
  }

void z80_prepareZ80(struct Z80CPU *z80) {
#ifdef HIST
  int x,y;
  for (y=0;y<5;y++)
    for (x=0;x<256;x++) hist[y][x]=' ';
#endif
  _z80_prepare1Byte(z80);
  _z80_prepareDD(z80);
  _z80_prepareED(z80);
  _z80_prepareFD(z80);
  }

void z80_printHist() {
#ifdef HIST
  int x,y;
  printf("      0 1 2 3 4 5 6 7 8 9 a b c d e f\n");
  for (y=0;y<16;y++) {
    printf("   %2x ",y*16);
    for (x=0;x<16;x++) printf("%c ",hist[0][x+y*16]);
    printf("\n");
    }
  printf("\n");
  printf("      0 1 2 3 4 5 6 7 8 9 a b c d e f\n");
  for (y=0;y<16;y++) {
    printf("CB %2x ",y*16);
    for (x=0;x<16;x++) printf("%c ",hist[1][x+y*16]);
    printf("\n");
    }
  printf("\n");
  printf("      0 1 2 3 4 5 6 7 8 9 a b c d e f\n");
  for (y=0;y<16;y++) {
    printf("DD %2x ",y*16);
    for (x=0;x<16;x++) printf("%c ",hist[2][x+y*16]);
    printf("\n");
    }
  printf("\n");
  printf("      0 1 2 3 4 5 6 7 8 9 a b c d e f\n");
  for (y=0;y<16;y++) {
    printf("ED %2x ",y*16);
    for (x=0;x<16;x++) printf("%c ",hist[3][x+y*16]);
    printf("\n");
    }
  printf("\n");
  printf("      0 1 2 3 4 5 6 7 8 9 a b c d e f\n");
  for (y=0;y<16;y++) {
    printf("FD %2x ",y*16);
    for (x=0;x<16;x++) printf("%c ",hist[4][x+y*16]);
    printf("\n");
    }
#endif
  }

