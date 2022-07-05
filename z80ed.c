#include "z80.h"

void _z80_E0(struct Z80CPU *z80) { }
void _z80_E1(struct Z80CPU *z80) { }
void _z80_E2(struct Z80CPU *z80) { }
void _z80_E3(struct Z80CPU *z80) { }
void _z80_E4(struct Z80CPU *z80) { }
void _z80_E5(struct Z80CPU *z80) { }
void _z80_E6(struct Z80CPU *z80) { }
void _z80_E7(struct Z80CPU *z80) { }
void _z80_E8(struct Z80CPU *z80) { }
void _z80_E9(struct Z80CPU *z80) { }
void _z80_EA(struct Z80CPU *z80) { }
void _z80_EB(struct Z80CPU *z80) { }
void _z80_EC(struct Z80CPU *z80) { }
void _z80_ED(struct Z80CPU *z80) { }
void _z80_EE(struct Z80CPU *z80) { }
void _z80_EF(struct Z80CPU *z80) { }
void _z80_E10(struct Z80CPU *z80) { }
void _z80_E11(struct Z80CPU *z80) { }
void _z80_E12(struct Z80CPU *z80) { }
void _z80_E13(struct Z80CPU *z80) { }
void _z80_E14(struct Z80CPU *z80) { }
void _z80_E15(struct Z80CPU *z80) { }
void _z80_E16(struct Z80CPU *z80) { }
void _z80_E17(struct Z80CPU *z80) { }
void _z80_E18(struct Z80CPU *z80) { }
void _z80_E19(struct Z80CPU *z80) { }
void _z80_E1A(struct Z80CPU *z80) { }
void _z80_E1B(struct Z80CPU *z80) { }
void _z80_E1C(struct Z80CPU *z80) { }
void _z80_E1D(struct Z80CPU *z80) { }
void _z80_E1E(struct Z80CPU *z80) { }
void _z80_E1F(struct Z80CPU *z80) { }
void _z80_E20(struct Z80CPU *z80) { }
void _z80_E21(struct Z80CPU *z80) { }
void _z80_E22(struct Z80CPU *z80) { }
void _z80_E23(struct Z80CPU *z80) { }
void _z80_E24(struct Z80CPU *z80) { }
void _z80_E25(struct Z80CPU *z80) { }
void _z80_E26(struct Z80CPU *z80) { }
void _z80_E27(struct Z80CPU *z80) { }
void _z80_E28(struct Z80CPU *z80) { }
void _z80_E29(struct Z80CPU *z80) { }
void _z80_E2A(struct Z80CPU *z80) { }
void _z80_E2B(struct Z80CPU *z80) { }
void _z80_E2C(struct Z80CPU *z80) { }
void _z80_E2D(struct Z80CPU *z80) { }
void _z80_E2E(struct Z80CPU *z80) { }
void _z80_E2F(struct Z80CPU *z80) { }
void _z80_E30(struct Z80CPU *z80) { }
void _z80_E31(struct Z80CPU *z80) { }
void _z80_E32(struct Z80CPU *z80) { }
void _z80_E33(struct Z80CPU *z80) { }
void _z80_E34(struct Z80CPU *z80) { }
void _z80_E35(struct Z80CPU *z80) { }
void _z80_E36(struct Z80CPU *z80) { }
void _z80_E37(struct Z80CPU *z80) { }
void _z80_E38(struct Z80CPU *z80) { }
void _z80_E39(struct Z80CPU *z80) { }
void _z80_E3A(struct Z80CPU *z80) { }
void _z80_E3B(struct Z80CPU *z80) { }
void _z80_E3C(struct Z80CPU *z80) { }
void _z80_E3D(struct Z80CPU *z80) { }
void _z80_E3E(struct Z80CPU *z80) { }
void _z80_E3F(struct Z80CPU *z80) { }

void _z80_E40(struct Z80CPU *z80)                         /* IN B,(C) */
  {
    z80->BC.BCu.B=_z80_InPort(z80,z80->BC.BCu.C);
    _z80_InFlags(z80,z80->BC.BCu.B);
  }

void _z80_E41(struct Z80CPU *z80)                         /* OUT (C),B */
  {
    _z80_OutPort(z80,z80->BC.BCu.C,z80->BC.BCu.B);
    z80->ts++;
  }

void _z80_E42(struct Z80CPU *z80)                         /* SBC HL,BC */
  {
    _z80_Sbc_16(z80,&z80->HL.HL,z80->BC.BC);
    z80->ts+=8;
  }

void _z80_E43(struct Z80CPU *z80)                         /* LD (nn),BC */
  {
    _z80_Store2(z80,_z80_Get_PC2(z80),z80->BC.BC);
  }

void _z80_E44(struct Z80CPU *z80)                         /* NEG */
  {
    _z80_Neg_8(z80,&z80->AF.AFu.A);
  }

void _z80_E45(struct Z80CPU *z80)                         /* RETN */
  {
    z80->PC=_z80_Pop2(z80);
    z80->IE = z80->IE2;
  }

void _z80_E46(struct Z80CPU *z80)                         /* IM 0 */
  {
    z80->IM=0;
  }

void _z80_E47(struct Z80CPU *z80)                         /* LD I,A */
  {
    z80->I=z80->AF.AFu.A;
    z80->ts++;
  }

void _z80_E48(struct Z80CPU *z80)                         /* IN C,(C) */
  {
    z80->BC.BCu.C=_z80_InPort(z80,z80->BC.BCu.C);
    _z80_InFlags(z80,z80->BC.BCu.C);
  }

void _z80_E49(struct Z80CPU *z80)                         /* OUT (C),C */
  {
    _z80_OutPort(z80,z80->BC.BCu.C,z80->BC.BCu.C);
    z80->ts++;
  }

void _z80_E4A(struct Z80CPU *z80)                         /* ADC HL,BC */
  {
    _z80_Adc_16(z80,&z80->HL.HL,z80->BC.BC);
    z80->ts+=7;
  }

void _z80_E4B(struct Z80CPU *z80)                         /* LD BC,(nn) */
  {
    z80->BC.BC=_z80_Fetch2(z80,_z80_Get_PC2(z80));
  }

void _z80_E4C(struct Z80CPU *z80) { }

void _z80_E4D(struct Z80CPU *z80)                         /* RETI */
  {
    z80->PC=_z80_Pop2(z80);
  }

void _z80_E4E(struct Z80CPU *z80) { }

void _z80_E4F(struct Z80CPU *z80)                         /* LD R,A */
  {
    z80->R=z80->AF.AFu.A;
    z80->ts++;
  }

void _z80_E50(struct Z80CPU *z80)                         /* IN D,(C) */
  {
    z80->DE.DEu.D=_z80_InPort(z80,z80->BC.BCu.C);
    _z80_InFlags(z80,z80->DE.DEu.D);
  }

void _z80_E51(struct Z80CPU *z80)                         /* OUT (C),D */
  {
    _z80_OutPort(z80,z80->BC.BCu.C,z80->DE.DEu.D);
    z80->ts++;
  }

void _z80_E52(struct Z80CPU *z80)                         /* SBC HL,DE */
  {
    _z80_Sbc_16(z80,&z80->HL.HL,z80->DE.DE);
    z80->ts+=7;
  }

void _z80_E53(struct Z80CPU *z80)                         /* LD (nn),DE */
  {
    _z80_Store2(z80,_z80_Get_PC2(z80),z80->DE.DE);
  }

void _z80_E54(struct Z80CPU *z80) { }
void _z80_E55(struct Z80CPU *z80) { }

void _z80_E56(struct Z80CPU *z80)                         /* IM 1 */
  {
    z80->IM=1;
  }

void _z80_E57(struct Z80CPU *z80)                         /* LD A,I */
  {
    z80->AF.AFu.A=z80->I;
    z80->AF.AFu.F &= (HALF_CARRY_OFF & ADD_SUB_OFF);
    if (z80->AF.AFu.A==0) z80->AF.AFu.F |= ZERO_FLAG;
      else z80->AF.AFu.F &= ZERO_OFF;
    if (z80->AF.AFu.A & 0x80) z80->AF.AFu.F |= SIGN_FLAG;
      else z80->AF.AFu.F &= SIGN_OFF;
    if (_z80_Parity(z80->AF.AFu.A)==1) z80->AF.AFu.F |= OVERFLOW_FLAG;
      else z80->AF.AFu.F &= OVERFLOW_OFF;
    z80->ts++;
  }

void _z80_E58(struct Z80CPU *z80)                         /* IN E,(C) */
  {
    z80->DE.DEu.E=_z80_InPort(z80,z80->BC.BCu.C);
    _z80_InFlags(z80,z80->DE.DEu.E);
  }

void _z80_E59(struct Z80CPU *z80)                         /* OUT (C),E */
  {
    _z80_OutPort(z80,z80->BC.BCu.C,z80->DE.DEu.E);
    z80->ts++;
  }

void _z80_E5A(struct Z80CPU *z80)                         /* ADC HL,DE */
  {
    _z80_Adc_16(z80,&z80->HL.HL,z80->DE.DE);
    z80->ts+=7;
  }

void _z80_E5B(struct Z80CPU *z80)                         /* LD DE,(nn) */
  {
    z80->DE.DE=_z80_Fetch2(z80,_z80_Get_PC2(z80));
  }

void _z80_E5C(struct Z80CPU *z80) { }
void _z80_E5D(struct Z80CPU *z80) { }

void _z80_E5E(struct Z80CPU *z80)                         /* IM 2 */
  {
    z80->IM=2;
  }

void _z80_E5F(struct Z80CPU *z80)                         /* LD A,R */
  {
    z80->AF.AFu.A=z80->R;
    z80->AF.AFu.F=z80->AF.AFu.F & (255-(HALF_CARRY_FLAG+ADD_SUB_FLAG));
    if (z80->AF.AFu.A==0) z80->AF.AFu.F=z80->AF.AFu.F | ZERO_FLAG;
      else z80->AF.AFu.F=z80->AF.AFu.F & (255-ZERO_FLAG);
    if (z80->AF.AFu.A>127) z80->AF.AFu.F=z80->AF.AFu.F | SIGN_FLAG;
      else z80->AF.AFu.F=z80->AF.AFu.F & (255-SIGN_FLAG);
    if (_z80_Parity(z80->AF.AFu.A)==1) z80->AF.AFu.F=z80->AF.AFu.F | OVERFLOW_FLAG;
      else z80->AF.AFu.F=z80->AF.AFu.F & (255-OVERFLOW_FLAG);
    z80->ts++;
  }

void _z80_E60(struct Z80CPU *z80)                         /* IN H,(C) */
  {
    z80->HL.HLu.H=_z80_InPort(z80,z80->BC.BCu.C);
    _z80_InFlags(z80,z80->HL.HLu.H);
  }

void _z80_E61(struct Z80CPU *z80)                         /* OUT (C),H */
  {
    _z80_OutPort(z80,z80->BC.BCu.C,z80->HL.HLu.H);
    z80->ts++;
  }

void _z80_E62(struct Z80CPU *z80)                         /* SBC HL,HL */
  {
    _z80_Sbc_16(z80,&z80->HL.HL,z80->HL.HL);
    z80->ts+=7;
  }

void _z80_E63(struct Z80CPU *z80) { }
void _z80_E64(struct Z80CPU *z80) { }
void _z80_E65(struct Z80CPU *z80) { }
void _z80_E66(struct Z80CPU *z80) { }

void _z80_E67(struct Z80CPU *z80)                         /* RRD */
  {
    byte hl;
    byte tmp;
    hl=_z80_Fetch(z80,z80->HL.HL);
    tmp=hl;
    hl=(hl >> 4) + ((z80->AF.AFu.A & 15) << 4);
    z80->AF.AFu.A=(z80->AF.AFu.A & 0xf0) + (tmp & 15);
    _z80_Store(z80,z80->HL.HL,hl);
    z80->AF.AFu.F=z80->AF.AFu.F & (255-(HALF_CARRY_FLAG+ADD_SUB_FLAG));
    if (z80->AF.AFu.A==0)z80->AF.AFu.F=z80->AF.AFu.F | ZERO_FLAG;
      else z80->AF.AFu.F=z80->AF.AFu.F & (255-ZERO_FLAG);
    if (z80->AF.AFu.A>127) z80->AF.AFu.F=z80->AF.AFu.F | SIGN_FLAG;
      else z80->AF.AFu.F=z80->AF.AFu.F & (255-SIGN_FLAG);
    if (_z80_Parity(z80->AF.AFu.A)==1) z80->AF.AFu.F=z80->AF.AFu.F | OVERFLOW_FLAG;
      else z80->AF.AFu.F=z80->AF.AFu.F & (255-OVERFLOW_FLAG);
    z80->ts+=4;
  }

void _z80_E68(struct Z80CPU *z80)                         /* IN L,(C) */
  {
    z80->HL.HLu.L=_z80_InPort(z80,z80->BC.BCu.C);
    _z80_InFlags(z80,z80->HL.HLu.L);
  }

void _z80_E69(struct Z80CPU *z80)                         /* OUT (C),L */
  {
    _z80_OutPort(z80,z80->BC.BCu.C,z80->HL.HLu.L);
    z80->ts++;
  }

void _z80_E6A(struct Z80CPU *z80)                         /* ADC HL,HL */
  {
    _z80_Adc_16(z80,&z80->HL.HL,z80->HL.HL);
    z80->ts+=7;
  }

void _z80_E6B(struct Z80CPU *z80) { }
void _z80_E6C(struct Z80CPU *z80) { }
void _z80_E6D(struct Z80CPU *z80) { }
void _z80_E6E(struct Z80CPU *z80) { }

void _z80_E6F(struct Z80CPU *z80)                         /* RLD */
  {
    byte hl;
    byte tmp;
    hl=_z80_Fetch(z80,z80->HL.HL);
    tmp=hl;
    hl=(hl << 4) + (z80->AF.AFu.A & 15);
    z80->AF.AFu.A=(z80->AF.AFu.A & 0xf0) + ((tmp >> 4) & 15);
    _z80_Store(z80,z80->HL.HL,hl);
    z80->AF.AFu.F=z80->AF.AFu.F & (255-(HALF_CARRY_FLAG+ADD_SUB_FLAG));
    if (z80->AF.AFu.A==0)z80->AF.AFu.F=z80->AF.AFu.F | ZERO_FLAG;
      else z80->AF.AFu.F=z80->AF.AFu.F & (255-ZERO_FLAG);
    if (z80->AF.AFu.A>127) z80->AF.AFu.F=z80->AF.AFu.F | SIGN_FLAG;
      else z80->AF.AFu.F=z80->AF.AFu.F & (255-SIGN_FLAG);
    if (_z80_Parity(z80->AF.AFu.A)==1) z80->AF.AFu.F=z80->AF.AFu.F | OVERFLOW_FLAG;
      else z80->AF.AFu.F=z80->AF.AFu.F & (255-OVERFLOW_FLAG);
    z80->ts+=4;
  }

void _z80_E70(struct Z80CPU *z80) { }
void _z80_E71(struct Z80CPU *z80) { }

void _z80_E72(struct Z80CPU *z80)                         /* SBC HL,SP */
  {
    _z80_Sbc_16(z80,&z80->HL.HL,z80->SP);
    z80->ts+=7;
  }

void _z80_E73(struct Z80CPU *z80)                         /* LD (nn),SP */
  {
    _z80_Store2(z80,_z80_Get_PC2(z80),z80->SP);
  }

void _z80_E74(struct Z80CPU *z80) { }
void _z80_E75(struct Z80CPU *z80) { }
void _z80_E76(struct Z80CPU *z80) { }
void _z80_E77(struct Z80CPU *z80) { }

void _z80_E78(struct Z80CPU *z80)                         /* IN A,(C) */
  {
    z80->AF.AFu.A=_z80_InPort(z80,z80->BC.BCu.C);
    _z80_InFlags(z80,z80->AF.AFu.A);
  }

void _z80_E79(struct Z80CPU *z80)                         /* OUT (C),A */
  {
    _z80_OutPort(z80,z80->BC.BCu.C,z80->AF.AFu.A);
    z80->ts++;
  }

void _z80_E7A(struct Z80CPU *z80)                         /* ADC HL,SP */
  {
    _z80_Adc_16(z80,&z80->HL.HL,z80->SP);
    z80->ts+=7;
  }

void _z80_E7B(struct Z80CPU *z80)                         /* LD SP,(nn) */
  {
    z80->SP=_z80_Fetch2(z80,_z80_Get_PC2(z80));
  }

void _z80_E7C(struct Z80CPU *z80) { }
void _z80_E7D(struct Z80CPU *z80) { }
void _z80_E7E(struct Z80CPU *z80) { }
void _z80_E7F(struct Z80CPU *z80) { }

void _z80_E80(struct Z80CPU *z80) { }
void _z80_E81(struct Z80CPU *z80) { }
void _z80_E82(struct Z80CPU *z80) { }
void _z80_E83(struct Z80CPU *z80) { }
void _z80_E84(struct Z80CPU *z80) { }
void _z80_E85(struct Z80CPU *z80) { }
void _z80_E86(struct Z80CPU *z80) { }
void _z80_E87(struct Z80CPU *z80) { }
void _z80_E88(struct Z80CPU *z80) { }
void _z80_E89(struct Z80CPU *z80) { }
void _z80_E8A(struct Z80CPU *z80) { }
void _z80_E8B(struct Z80CPU *z80) { }
void _z80_E8C(struct Z80CPU *z80) { }
void _z80_E8D(struct Z80CPU *z80) { }
void _z80_E8E(struct Z80CPU *z80) { }
void _z80_E8F(struct Z80CPU *z80) { }

void _z80_E90(struct Z80CPU *z80) { }
void _z80_E91(struct Z80CPU *z80) { }
void _z80_E92(struct Z80CPU *z80) { }
void _z80_E93(struct Z80CPU *z80) { }
void _z80_E94(struct Z80CPU *z80) { }
void _z80_E95(struct Z80CPU *z80) { }
void _z80_E96(struct Z80CPU *z80) { }
void _z80_E97(struct Z80CPU *z80) { }
void _z80_E98(struct Z80CPU *z80) { }
void _z80_E99(struct Z80CPU *z80) { }
void _z80_E9A(struct Z80CPU *z80) { }
void _z80_E9B(struct Z80CPU *z80) { }
void _z80_E9C(struct Z80CPU *z80) { }
void _z80_E9D(struct Z80CPU *z80) { }
void _z80_E9E(struct Z80CPU *z80) { }
void _z80_E9F(struct Z80CPU *z80) { }

void _z80_EA0(struct Z80CPU *z80)                         /* LDI */
  {
    _z80_Store(z80,z80->DE.DE,_z80_Fetch(z80,z80->HL.HL));
    z80->HL.HL++;
    z80->DE.DE++;
    z80->BC.BC--;
    z80->AF.AFu.F &= (255-(HALF_CARRY_FLAG+ADD_SUB_FLAG));
    if (z80->BC.BC == 0) z80->AF.AFu.F=z80->AF.AFu.F & (255-OVERFLOW_FLAG);
      else z80->AF.AFu.F=z80->AF.AFu.F | OVERFLOW_FLAG;
    z80->ts+=2;
  }

void _z80_EA1(struct Z80CPU *z80)                         /* CPI */
  {
    int oldcarry;
    int a,value,result;
    oldcarry=z80->AF.AFu.F & CARRY_FLAG;
    value = _z80_Fetch(z80,z80->HL.HL);
    a=z80->AF.AFu.A;
    result = a - value;
    z80->HL.HL++;
    z80->BC.BC--;
    _z80_sub_Flags(a,value,result);
    z80->AF.AFu.F = (z80->AF.AFu.F & ~(CARRY_FLAG | OVERFLOW_FLAG | FLAG5)) |
      oldcarry | ((z80->BC.BC == 0) ? 0 : OVERFLOW_FLAG) |
      (((result - ((z80->AF.AFu.F & HALF_CARRY_FLAG) >> 4)) & 2) << 4);
    if ((result & 15) == 8 && (z80->AF.AFu.F & HALF_CARRY_FLAG) != 0)
      z80->AF.AFu.F &= ~FLAG3;
    z80->ts+=16;
/*
    byte cy;
    cy=z80->AF.AFu.F & CARRY_FLAG;
    _z80_Cmp_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,z80->HL.HL));
    z80->HL.HL++;
    z80->BC.BC--;
    z80->AF.AFu.F &= CARRY_OFF;
    z80->AF.AFu.F |= cy;
    if (z80->BC.BC == 0) z80->AF.AFu.F &= OVERFLOW_OFF;
      else z80->AF.AFu.F |= OVERFLOW_FLAG;
    z80->ts+=5;
*/
  }

void _z80_EA2(struct Z80CPU *z80)                         /* INI */
  {
    _z80_Store(z80,z80->HL.HL,_z80_InPort(z80,z80->BC.BCu.C));
    z80->HL.HL++;
    z80->AF.AFu.F=z80->AF.AFu.F | ADD_SUB_FLAG;
    z80->BC.BCu.B--;
    if (z80->BC.BCu.B==0) z80->AF.AFu.F=z80->AF.AFu.F | ZERO_FLAG;
      else z80->AF.AFu.F=z80->AF.AFu.F & (255-ZERO_FLAG);
    z80->ts++;
  }

void _z80_EA3(struct Z80CPU *z80)                         /* OUTI */
  {
    _z80_OutPort(z80,z80->BC.BCu.C,_z80_Fetch(z80,z80->HL.HL));
    z80->HL.HL++;
    z80->AF.AFu.F=z80->AF.AFu.F | ADD_SUB_FLAG;
    z80->BC.BCu.B--;
    if (z80->BC.BCu.B==0) z80->AF.AFu.F=z80->AF.AFu.F | ZERO_FLAG;
      else z80->AF.AFu.F=z80->AF.AFu.F & (255-ZERO_FLAG);
    z80->ts++;
  }

void _z80_EA4(struct Z80CPU *z80) { }
void _z80_EA5(struct Z80CPU *z80) { }
void _z80_EA6(struct Z80CPU *z80) { }
void _z80_EA7(struct Z80CPU *z80) { }

void _z80_EA8(struct Z80CPU *z80)                         /* LDD */
  {
    _z80_Store(z80,z80->DE.DE,_z80_Fetch(z80,z80->HL.HL));
    z80->HL.HL--;
    z80->DE.DE--;
    z80->BC.BC--;
    z80->AF.AFu.F &= (255-(HALF_CARRY_FLAG+ADD_SUB_FLAG));
    if (z80->BC.BC!=0) z80->AF.AFu.F=z80->AF.AFu.F | OVERFLOW_FLAG;
      else z80->AF.AFu.F=z80->AF.AFu.F & (255-OVERFLOW_FLAG);
    z80->ts+=2;
  }

void _z80_EA9(struct Z80CPU *z80)                         /* CPD */
  {
    int oldcarry;
    int a,value,result;
    oldcarry=z80->AF.AFu.F & CARRY_FLAG;
    value = _z80_Fetch(z80,z80->HL.HL);
    a=z80->AF.AFu.A;
    result = a - value;
    z80->HL.HL--;
    z80->BC.BC--;
    _z80_sub_Flags(a,value,result);
    z80->AF.AFu.F = (z80->AF.AFu.F & ~(CARRY_FLAG | OVERFLOW_FLAG | FLAG5)) |
      oldcarry | ((z80->BC.BC == 0) ? 0 : OVERFLOW_FLAG) |
      (((result - ((z80->AF.AFu.F & HALF_CARRY_FLAG) >> 4)) & 2) << 4);
    if ((result & 15) == 8 && (z80->AF.AFu.F & HALF_CARRY_FLAG) != 0)
      z80->AF.AFu.F &= ~FLAG3;
    z80->ts+=16;
/*
    byte cy;
    cy=z80->AF.AFu.F & CARRY_FLAG;
    _z80_Cmp_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,z80->HL.HL));
    z80->HL.HL--;
    z80->BC.BC--;
    z80->AF.AFu.F &= CARRY_OFF;
    z80->AF.AFu.F |= cy;
    if (z80->BC.BCu.B!=0) z80->AF.AFu.F |= OVERFLOW_FLAG;
      else z80->AF.AFu.F &= OVERFLOW_OFF;
    z80->ts+=5;
*/
  }

void _z80_EAA(struct Z80CPU *z80)                         /* IND */
  {
    _z80_Store(z80,z80->HL.HL,_z80_InPort(z80,z80->BC.BCu.C));
    z80->HL.HL--;
    z80->AF.AFu.F=z80->AF.AFu.F | ADD_SUB_FLAG;
    z80->BC.BCu.B--;
    if (z80->BC.BCu.B==0)  z80->AF.AFu.F=z80->AF.AFu.F | ZERO_FLAG;
      else z80->AF.AFu.F=z80->AF.AFu.F & (255-ZERO_FLAG);
    z80->ts++;
  }

void _z80_EAB(struct Z80CPU *z80)                         /* OUTD */
  {
    _z80_OutPort(z80,z80->BC.BCu.C,_z80_Fetch(z80,z80->HL.HL));
    z80->HL.HL--;
    z80->AF.AFu.F=z80->AF.AFu.F | ADD_SUB_FLAG;
    z80->BC.BCu.B--;
    if (z80->BC.BCu.B==0)  z80->AF.AFu.F=z80->AF.AFu.F | ZERO_FLAG;
      else z80->AF.AFu.F=z80->AF.AFu.F & (255-ZERO_FLAG);
    z80->ts++;
  }

void _z80_EAC(struct Z80CPU *z80) { }
void _z80_EAD(struct Z80CPU *z80) { }
void _z80_EAE(struct Z80CPU *z80) { }
void _z80_EAF(struct Z80CPU *z80) { }

void _z80_EB0(struct Z80CPU *z80)                         /* LDIR */
  {
    do {
      _z80_Store(z80,z80->DE.DE,_z80_Fetch(z80,z80->HL.HL));
      z80->HL.HL++;
      z80->DE.DE++;
      z80->BC.BC--;
      z80->ts+=15;
      } while (z80->BC.BC != 0);
    z80->AF.AFu.F=z80->AF.AFu.F & (255-(OVERFLOW_FLAG+ADD_SUB_FLAG+HALF_CARRY_FLAG));
  z80->ts-=5;
  }

void _z80_EB1(struct Z80CPU *z80)                         /* CPIR */
  {
    int oldcarry;
    int a,value,result;
    oldcarry=z80->AF.AFu.F & CARRY_FLAG;
    a=z80->AF.AFu.A;
    do {
      value = _z80_Fetch(z80,z80->HL.HL);
      result = a - value;
      z80->HL.HL++;
      z80->BC.BC--;
      z80->ts+=21;
      } while ((z80->BC.BC != 0) && (result != 0));
    _z80_sub_Flags(a,value,result);
    z80->AF.AFu.F = (z80->AF.AFu.F & ~(CARRY_FLAG | OVERFLOW_FLAG | FLAG5)) |
      oldcarry | ((z80->BC.BC == 0) ? 0 : OVERFLOW_FLAG) |
      (((result - ((z80->AF.AFu.F & HALF_CARRY_FLAG) >> 4)) & 2) << 4);
    if ((result & 15) == 8 && (z80->AF.AFu.F & HALF_CARRY_FLAG) != 0)
      z80->AF.AFu.F &= ~FLAG3;
    z80->ts-=5;
/*
    byte cy;
    cy=z80->AF.AFu.F & CARRY_FLAG;
    do {
      _z80_Cmp_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,z80->HL.HL));
      z80->HL.HL++;
      z80->BC.BC--;
      z80->ts+=18;
      } while (z80->BC.BC !=0 && (z80->AF.AFu.F & ZERO_FLAG) != ZERO_FLAG);
    z80->AF.AFu.F &= CARRY_OFF;
    z80->AF.AFu.F |= cy;
    if (z80->BC.BC==0) z80->AF.AFu.F &= OVERFLOW_OFF;
      else z80->AF.AFu.F |= OVERFLOW_FLAG;
    z80->ts-=5;
*/
  }

void _z80_EB2(struct Z80CPU *z80)                         /* INIR */
  {
    do {
      _z80_Store(z80,z80->HL.HL,_z80_InPort(z80,z80->BC.BCu.C));
      z80->HL.HL++;
      z80->AF.AFu.F=z80->AF.AFu.F | ADD_SUB_FLAG;
      z80->BC.BCu.B--;
      z80->ts+=14;
      } while (z80->BC.BCu.B != 0);
    z80->AF.AFu.F=z80->AF.AFu.F | ZERO_FLAG | ADD_SUB_FLAG;
    z80->ts-=5;
  }

void _z80_EB3(struct Z80CPU *z80)                         /* OTIR */
  {
    do {
      _z80_OutPort(z80,z80->BC.BCu.C,_z80_Fetch(z80,z80->HL.HL));
      z80->HL.HL++;
      z80->AF.AFu.F=z80->AF.AFu.F | ADD_SUB_FLAG;
      z80->BC.BCu.B--;
      z80->ts+=14;
      } while (z80->BC.BCu.B != 0);
    z80->AF.AFu.F=z80->AF.AFu.F | ZERO_FLAG | ADD_SUB_FLAG;
    z80->ts-=5;
  }

void _z80_EB4(struct Z80CPU *z80) { }
void _z80_EB5(struct Z80CPU *z80) { }
void _z80_EB6(struct Z80CPU *z80) { }
void _z80_EB7(struct Z80CPU *z80) { }

void _z80_EB8(struct Z80CPU *z80)                         /* LDDR */
  {
    do {
      _z80_Store(z80,z80->DE.DE,_z80_Fetch(z80,z80->HL.HL));
      z80->HL.HL--;
      z80->DE.DE--;
      z80->BC.BC--;
      z80->ts+=15;
      } while (z80->BC.BC != 0);
    z80->AF.AFu.F=z80->AF.AFu.F & (255-(OVERFLOW_FLAG+ADD_SUB_FLAG+HALF_CARRY_FLAG));
    z80->ts-=5;
  }

void _z80_EB9(struct Z80CPU *z80)                         /* CPDR */
  {
    int oldcarry;
    int a,value,result;
    oldcarry=z80->AF.AFu.F & CARRY_FLAG;
    a=z80->AF.AFu.A;
    do {
      value = _z80_Fetch(z80,z80->HL.HL);
      result = a - value;
      z80->HL.HL--;
      z80->BC.BC--;
      z80->ts+=21;
      } while ((z80->BC.BC != 0) && (result != 0));
    _z80_sub_Flags(a,value,result);
    z80->AF.AFu.F = (z80->AF.AFu.F & ~(CARRY_FLAG | OVERFLOW_FLAG | FLAG5)) |
      oldcarry | ((z80->BC.BC == 0) ? 0 : OVERFLOW_FLAG) |
      (((result - ((z80->AF.AFu.F & HALF_CARRY_FLAG) >> 4)) & 2) << 4);
    if ((result & 15) == 8 && (z80->AF.AFu.F & HALF_CARRY_FLAG) != 0)
      z80->AF.AFu.F &= ~FLAG3;
    z80->ts-=5;
/*
    byte cy;
    cy=z80->AF.AFu.F & CARRY_FLAG;
    do {
      _z80_Cmp_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,z80->HL.HL));
      z80->HL.HL--;
      z80->BC.BC--;
      z80->ts+=18;
      } while (z80->BC.BC !=0 && (z80->AF.AFu.F & ZERO_FLAG) != ZERO_FLAG);
    if (z80->BC.BC==0) z80->AF.AFu.F &= OVERFLOW_OFF;
      else z80->AF.AFu.F |= OVERFLOW_FLAG;
    z80->ts-=5;
*/
  }

void _z80_EBA(struct Z80CPU *z80)                         /* INDR */
  {
    do {
      _z80_Store(z80,z80->HL.HL,_z80_InPort(z80,z80->BC.BCu.C));
      z80->HL.HL--;
      z80->AF.AFu.F=z80->AF.AFu.F | ADD_SUB_FLAG;
      z80->BC.BCu.B--;
      z80->ts+=14;
      } while (z80->BC.BCu.B != 0);
    z80->AF.AFu.F=z80->AF.AFu.F | ZERO_FLAG | ADD_SUB_FLAG;
    z80->ts-=5;
  }

void _z80_EBB(struct Z80CPU *z80)                         /* OTDR */
  {
    do {
      _z80_OutPort(z80,z80->BC.BCu.C,_z80_Fetch(z80,z80->HL.HL));
      z80->HL.HL--;
      z80->AF.AFu.F=z80->AF.AFu.F | ADD_SUB_FLAG;
      z80->BC.BCu.B--;
      z80->ts+=14;
      } while (z80->BC.BCu.B != 0);
    z80->AF.AFu.F=z80->AF.AFu.F | ZERO_FLAG | ADD_SUB_FLAG;
    z80->ts-=5;
  }

void _z80_EBC(struct Z80CPU *z80) { }
void _z80_EBD(struct Z80CPU *z80) { }
void _z80_EBE(struct Z80CPU *z80) { }
void _z80_EBF(struct Z80CPU *z80) { }


void _z80_EC0(struct Z80CPU *z80) { }
void _z80_EC1(struct Z80CPU *z80) { }
void _z80_EC2(struct Z80CPU *z80) { }
void _z80_EC3(struct Z80CPU *z80) { }
void _z80_EC4(struct Z80CPU *z80) { }
void _z80_EC5(struct Z80CPU *z80) { }
void _z80_EC6(struct Z80CPU *z80) { }
void _z80_EC7(struct Z80CPU *z80) { }
void _z80_EC8(struct Z80CPU *z80) { }
void _z80_EC9(struct Z80CPU *z80) { }
void _z80_ECA(struct Z80CPU *z80) { }
void _z80_ECB(struct Z80CPU *z80) { }
void _z80_ECC(struct Z80CPU *z80) { }
void _z80_ECD(struct Z80CPU *z80) { }
void _z80_ECE(struct Z80CPU *z80) { }
void _z80_ECF(struct Z80CPU *z80) { }

void _z80_ED0(struct Z80CPU *z80) { }
void _z80_ED1(struct Z80CPU *z80) { }
void _z80_ED2(struct Z80CPU *z80) { }
void _z80_ED3(struct Z80CPU *z80) { }
void _z80_ED4(struct Z80CPU *z80) { }
void _z80_ED5(struct Z80CPU *z80) { }
void _z80_ED6(struct Z80CPU *z80) { }
void _z80_ED7(struct Z80CPU *z80) { }
void _z80_ED8(struct Z80CPU *z80) { }
void _z80_ED9(struct Z80CPU *z80) { }
void _z80_EDA(struct Z80CPU *z80) { }
void _z80_EDB(struct Z80CPU *z80) { }
void _z80_EDC(struct Z80CPU *z80) { }
void _z80_EDD(struct Z80CPU *z80) { }
void _z80_EDE(struct Z80CPU *z80) { }
void _z80_EDF(struct Z80CPU *z80) { }

void _z80_EE0(struct Z80CPU *z80) { }
void _z80_EE1(struct Z80CPU *z80) { }
void _z80_EE2(struct Z80CPU *z80) { }
void _z80_EE3(struct Z80CPU *z80) { }
void _z80_EE4(struct Z80CPU *z80) { }
void _z80_EE5(struct Z80CPU *z80) { }
void _z80_EE6(struct Z80CPU *z80) { }
void _z80_EE7(struct Z80CPU *z80) { }
void _z80_EE8(struct Z80CPU *z80) { }
void _z80_EE9(struct Z80CPU *z80) { }
void _z80_EEA(struct Z80CPU *z80) { }
void _z80_EEB(struct Z80CPU *z80) { }
void _z80_EEC(struct Z80CPU *z80) { }
void _z80_EED(struct Z80CPU *z80) { }
void _z80_EEE(struct Z80CPU *z80) { }
void _z80_EEF(struct Z80CPU *z80) { }

void _z80_EF0(struct Z80CPU *z80) { }
void _z80_EF1(struct Z80CPU *z80) { }
void _z80_EF2(struct Z80CPU *z80) { }
void _z80_EF3(struct Z80CPU *z80) { }
void _z80_EF4(struct Z80CPU *z80) { }
void _z80_EF5(struct Z80CPU *z80) { }
void _z80_EF6(struct Z80CPU *z80) { }
void _z80_EF7(struct Z80CPU *z80) { }
void _z80_EF8(struct Z80CPU *z80) { }
void _z80_EF9(struct Z80CPU *z80) { }
void _z80_EFA(struct Z80CPU *z80) { }
void _z80_EFB(struct Z80CPU *z80) { }
void _z80_EFC(struct Z80CPU *z80) { }
void _z80_EFD(struct Z80CPU *z80) { }
void _z80_EFE(struct Z80CPU *z80) { }
void _z80_EFF(struct Z80CPU *z80) { }

void _z80_PED(struct Z80CPU *z80)
  {
    byte bt;
    bt=_z80_Get_PC(z80);
    z80->ts++;
#ifdef HIST
    hist[3][bt]='*';
#endif
    z80->IED[bt](z80);
  }


void _z80_prepareED(struct Z80CPU *z80) {
  z80->IED[0x00]=_z80_E0; z80->IED[0x01]=_z80_E1; z80->IED[0x02]=_z80_E2; z80->IED[0x03]=_z80_E3;
  z80->IED[0x04]=_z80_E4; z80->IED[0x05]=_z80_E5; z80->IED[0x06]=_z80_E6; z80->IED[0x07]=_z80_E7;
  z80->IED[0x08]=_z80_E8; z80->IED[0x09]=_z80_E9; z80->IED[0x0a]=_z80_EA; z80->IED[0x0b]=_z80_EB;
  z80->IED[0x0c]=_z80_EC; z80->IED[0x0d]=_z80_ED; z80->IED[0x0e]=_z80_EE; z80->IED[0x0f]=_z80_EF;

  z80->IED[0x10]=_z80_E10; z80->IED[0x11]=_z80_E11; z80->IED[0x12]=_z80_E12; z80->IED[0x13]=_z80_E13;
  z80->IED[0x14]=_z80_E14; z80->IED[0x15]=_z80_E15; z80->IED[0x16]=_z80_E16; z80->IED[0x17]=_z80_E17;
  z80->IED[0x18]=_z80_E18; z80->IED[0x19]=_z80_E19; z80->IED[0x1a]=_z80_E1A; z80->IED[0x1b]=_z80_E1B;
  z80->IED[0x1c]=_z80_E1C; z80->IED[0x1d]=_z80_E1D; z80->IED[0x1e]=_z80_E1E; z80->IED[0x1f]=_z80_E1F;

  z80->IED[0x20]=_z80_E20; z80->IED[0x21]=_z80_E21; z80->IED[0x22]=_z80_E22; z80->IED[0x23]=_z80_E23;
  z80->IED[0x24]=_z80_E24; z80->IED[0x25]=_z80_E25; z80->IED[0x26]=_z80_E26; z80->IED[0x27]=_z80_E27;
  z80->IED[0x28]=_z80_E28; z80->IED[0x29]=_z80_E29; z80->IED[0x2a]=_z80_E2A; z80->IED[0x2b]=_z80_E2B;
  z80->IED[0x2c]=_z80_E2C; z80->IED[0x2d]=_z80_E2D; z80->IED[0x2e]=_z80_E2E; z80->IED[0x2f]=_z80_E2F;

  z80->IED[0x30]=_z80_E30; z80->IED[0x31]=_z80_E31; z80->IED[0x32]=_z80_E32; z80->IED[0x33]=_z80_E33;
  z80->IED[0x34]=_z80_E34; z80->IED[0x35]=_z80_E35; z80->IED[0x36]=_z80_E36; z80->IED[0x37]=_z80_E37;
  z80->IED[0x38]=_z80_E38; z80->IED[0x39]=_z80_E39; z80->IED[0x3a]=_z80_E3A; z80->IED[0x3b]=_z80_E3B;
  z80->IED[0x3c]=_z80_E3C; z80->IED[0x3d]=_z80_E3D; z80->IED[0x3e]=_z80_E3E; z80->IED[0x3f]=_z80_E3F;

  z80->IED[0x40]=_z80_E40; z80->IED[0x41]=_z80_E41; z80->IED[0x42]=_z80_E42; z80->IED[0x43]=_z80_E43;
  z80->IED[0x44]=_z80_E44; z80->IED[0x45]=_z80_E45; z80->IED[0x46]=_z80_E46; z80->IED[0x47]=_z80_E47;
  z80->IED[0x48]=_z80_E48; z80->IED[0x49]=_z80_E49; z80->IED[0x4a]=_z80_E4A; z80->IED[0x4b]=_z80_E4B;
  z80->IED[0x4c]=_z80_E4C; z80->IED[0x4d]=_z80_E4D; z80->IED[0x4e]=_z80_E4E; z80->IED[0x4f]=_z80_E4F;

  z80->IED[0x50]=_z80_E50; z80->IED[0x51]=_z80_E51; z80->IED[0x52]=_z80_E52; z80->IED[0x53]=_z80_E53;
  z80->IED[0x54]=_z80_E54; z80->IED[0x55]=_z80_E55; z80->IED[0x56]=_z80_E56; z80->IED[0x57]=_z80_E57;
  z80->IED[0x58]=_z80_E58; z80->IED[0x59]=_z80_E59; z80->IED[0x5a]=_z80_E5A; z80->IED[0x5b]=_z80_E5B;
  z80->IED[0x5c]=_z80_E5C; z80->IED[0x5d]=_z80_E5D; z80->IED[0x5e]=_z80_E5E; z80->IED[0x5f]=_z80_E5F;

  z80->IED[0x60]=_z80_E60; z80->IED[0x61]=_z80_E61; z80->IED[0x62]=_z80_E62; z80->IED[0x63]=_z80_E63;
  z80->IED[0x64]=_z80_E64; z80->IED[0x65]=_z80_E65; z80->IED[0x66]=_z80_E66; z80->IED[0x67]=_z80_E67;
  z80->IED[0x68]=_z80_E68; z80->IED[0x69]=_z80_E69; z80->IED[0x6a]=_z80_E6A; z80->IED[0x6b]=_z80_E6B;
  z80->IED[0x6c]=_z80_E6C; z80->IED[0x6d]=_z80_E6D; z80->IED[0x6e]=_z80_E6E; z80->IED[0x6f]=_z80_E6F;

  z80->IED[0x70]=_z80_E70; z80->IED[0x71]=_z80_E71; z80->IED[0x72]=_z80_E72; z80->IED[0x73]=_z80_E73;
  z80->IED[0x74]=_z80_E74; z80->IED[0x75]=_z80_E75; z80->IED[0x76]=_z80_E76; z80->IED[0x77]=_z80_E77;
  z80->IED[0x78]=_z80_E78; z80->IED[0x79]=_z80_E79; z80->IED[0x7a]=_z80_E7A; z80->IED[0x7b]=_z80_E7B;
  z80->IED[0x7c]=_z80_E7C; z80->IED[0x7d]=_z80_E7D; z80->IED[0x7e]=_z80_E7E; z80->IED[0x7f]=_z80_E7F;

  z80->IED[0x80]=_z80_E80; z80->IED[0x81]=_z80_E81; z80->IED[0x82]=_z80_E82; z80->IED[0x83]=_z80_E83;
  z80->IED[0x84]=_z80_E84; z80->IED[0x85]=_z80_E85; z80->IED[0x86]=_z80_E86; z80->IED[0x87]=_z80_E87;
  z80->IED[0x88]=_z80_E88; z80->IED[0x89]=_z80_E89; z80->IED[0x8a]=_z80_E8A; z80->IED[0x8b]=_z80_E8B;
  z80->IED[0x8c]=_z80_E8C; z80->IED[0x8d]=_z80_E8D; z80->IED[0x8e]=_z80_E8E; z80->IED[0x8f]=_z80_E8F;

  z80->IED[0x90]=_z80_E90; z80->IED[0x91]=_z80_E91; z80->IED[0x92]=_z80_E92; z80->IED[0x93]=_z80_E93;
  z80->IED[0x94]=_z80_E94; z80->IED[0x95]=_z80_E95; z80->IED[0x96]=_z80_E96; z80->IED[0x97]=_z80_E97;
  z80->IED[0x98]=_z80_E98; z80->IED[0x99]=_z80_E99; z80->IED[0x9a]=_z80_E9A; z80->IED[0x9b]=_z80_E9B;
  z80->IED[0x9c]=_z80_E9C; z80->IED[0x9d]=_z80_E9D; z80->IED[0x9e]=_z80_E9E; z80->IED[0x9f]=_z80_E9F;

  z80->IED[0xa0]=_z80_EA0; z80->IED[0xa1]=_z80_EA1; z80->IED[0xa2]=_z80_EA2; z80->IED[0xa3]=_z80_EA3;
  z80->IED[0xa4]=_z80_EA4; z80->IED[0xa5]=_z80_EA5; z80->IED[0xa6]=_z80_EA6; z80->IED[0xa7]=_z80_EA7;
  z80->IED[0xa8]=_z80_EA8; z80->IED[0xa9]=_z80_EA9; z80->IED[0xaa]=_z80_EAA; z80->IED[0xab]=_z80_EAB;
  z80->IED[0xac]=_z80_EAC; z80->IED[0xad]=_z80_EAD; z80->IED[0xae]=_z80_EAE; z80->IED[0xaf]=_z80_EAF;

  z80->IED[0xb0]=_z80_EB0; z80->IED[0xb1]=_z80_EB1; z80->IED[0xb2]=_z80_EB2; z80->IED[0xb3]=_z80_EB3;
  z80->IED[0xb4]=_z80_EB4; z80->IED[0xb5]=_z80_EB5; z80->IED[0xb6]=_z80_EB6; z80->IED[0xb7]=_z80_EB7;
  z80->IED[0xb8]=_z80_EB8; z80->IED[0xb9]=_z80_EB9; z80->IED[0xba]=_z80_EBA; z80->IED[0xbb]=_z80_EBB;
  z80->IED[0xbc]=_z80_EBC; z80->IED[0xbd]=_z80_EBD; z80->IED[0xbe]=_z80_EBE; z80->IED[0xbf]=_z80_EBF;

  z80->IED[0xc0]=_z80_EC0; z80->IED[0xc1]=_z80_EC1; z80->IED[0xc2]=_z80_EC2; z80->IED[0xc3]=_z80_EC3;
  z80->IED[0xc4]=_z80_EC4; z80->IED[0xc5]=_z80_EC5; z80->IED[0xc6]=_z80_EC6; z80->IED[0xc7]=_z80_EC7;
  z80->IED[0xc8]=_z80_EC8; z80->IED[0xc9]=_z80_EC9; z80->IED[0xca]=_z80_ECA; z80->IED[0xcb]=_z80_ECB;
  z80->IED[0xcc]=_z80_ECC; z80->IED[0xcd]=_z80_ECD; z80->IED[0xce]=_z80_ECE; z80->IED[0xcf]=_z80_ECF;

  z80->IED[0xd0]=_z80_ED0; z80->IED[0xd1]=_z80_ED1; z80->IED[0xd2]=_z80_ED2; z80->IED[0xd3]=_z80_ED3;
  z80->IED[0xd4]=_z80_ED4; z80->IED[0xd5]=_z80_ED5; z80->IED[0xd6]=_z80_ED6; z80->IED[0xd7]=_z80_ED7;
  z80->IED[0xd8]=_z80_ED8; z80->IED[0xd9]=_z80_ED9; z80->IED[0xda]=_z80_EDA; z80->IED[0xdb]=_z80_EDB;
  z80->IED[0xdc]=_z80_EDC; z80->IED[0xdd]=_z80_EDD; z80->IED[0xde]=_z80_EDE; z80->IED[0xdf]=_z80_EDF;

  z80->IED[0xe0]=_z80_EE0; z80->IED[0xe1]=_z80_EE1; z80->IED[0xe2]=_z80_EE2; z80->IED[0xe3]=_z80_EE3;
  z80->IED[0xe4]=_z80_EE4; z80->IED[0xe5]=_z80_EE5; z80->IED[0xe6]=_z80_EE6; z80->IED[0xe7]=_z80_EE7;
  z80->IED[0xe8]=_z80_EE8; z80->IED[0xe9]=_z80_EE9; z80->IED[0xea]=_z80_EEA; z80->IED[0xeb]=_z80_EEB;
  z80->IED[0xec]=_z80_EEC; z80->IED[0xed]=_z80_EED; z80->IED[0xee]=_z80_EEE; z80->IED[0xef]=_z80_EEF;

  z80->IED[0xf0]=_z80_EF0; z80->IED[0xf1]=_z80_EF1; z80->IED[0xf2]=_z80_EF2; z80->IED[0xf3]=_z80_EF3;
  z80->IED[0xf4]=_z80_EF4; z80->IED[0xf5]=_z80_EF5; z80->IED[0xf6]=_z80_EF6; z80->IED[0xf7]=_z80_EF7;
  z80->IED[0xf8]=_z80_EF8; z80->IED[0xf9]=_z80_EF9; z80->IED[0xfa]=_z80_EFA; z80->IED[0xfb]=_z80_EFB;
  z80->IED[0xfc]=_z80_EFC; z80->IED[0xfd]=_z80_EFD; z80->IED[0xfe]=_z80_EFE; z80->IED[0xff]=_z80_EFF;
  }

