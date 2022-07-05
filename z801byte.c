#include "z80.h"


void _z80_WPCB(struct Z80CPU *z80) {
    _z80_PCB(z80);
  }

void _z80_WPDD(struct Z80CPU *z80) {
    _z80_PDD(z80);
  }

void _z80_WPED(struct Z80CPU *z80) {
    _z80_PED(z80);
  }

void _z80_WPFD(struct Z80CPU *z80) {
    _z80_PFD(z80);
  }

void _z80_P0(struct Z80CPU *z80)                          /* NOP */
  {
  }

void _z80_P1(struct Z80CPU *z80)                          /* LD BC,nn */
  {
    z80->BC.BC=_z80_Get_PC2(z80);
  }

void _z80_P2(struct Z80CPU *z80)                          /* LD (BC),A */
  {
    _z80_Store(z80,z80->BC.BC,z80->AF.AFu.A);
  }

void _z80_P3(struct Z80CPU *z80)                          /* INC BC */
  {
    z80->BC.BC++;
    z80->ts+=2;
  }

void _z80_P4(struct Z80CPU *z80)                          /* INC B */
  {
    _z80_Inc_8(z80,&z80->BC.BCu.B);
  }

void _z80_P5(struct Z80CPU *z80)                          /* DEC B */
  {
    _z80_Dec_8(z80,&z80->BC.BCu.B);
  }

void _z80_P6(struct Z80CPU *z80)                          /* LD B,n */
  {
    z80->BC.BCu.B=_z80_Get_PC(z80);
  }

void _z80_P7(struct Z80CPU *z80)                          /* RLCA */
  {
    byte set;
    set=0;
    if (z80->AF.AFu.A & 0x80) {
      z80->AF.AFu.A = ((z80->AF.AFu.A << 1) & 0xff) | 1;
      set |= CARRY_FLAG;
      } else z80->AF.AFu.A = (z80->AF.AFu.A << 1) & 0xff;
    z80->AF.AFu.F = (z80->AF.AFu.F & (OVERFLOW_FLAG | ZERO_FLAG | SIGN_FLAG)) |
      set | (z80->AF.AFu.A & (FLAG3 | FLAG5));
/*
    byte Cy;
    z80->AF.AFu.F=z80->AF.AFu.F & (255-(HALF_CARRY_FLAG+ADD_SUB_FLAG));
    if ((z80->AF.AFu.A & 128)==128) Cy=1; else Cy=0;
    z80->AF.AFu.A=(z80->AF.AFu.A<<1)|Cy;
    if (Cy==1) z80->AF.AFu.F |= CARRY_FLAG; else z80->AF.AFu.F &= CARRY_OFF;
*/
  }

void _z80_P8(struct Z80CPU *z80)                          /* EX AF,AF' */
  {
    _z80_Exch_16(&z80->AF.AF,&z80->AFa);
  }

void _z80_P9(struct Z80CPU *z80)                          /* ADD HL,BC */
  {
    _z80_Add_16(z80,&z80->HL.HL,z80->BC.BC);
    z80->ts+=7;
  }

void _z80_PA(struct Z80CPU *z80)                          /* LD A,(BC) */
  {
    z80->AF.AFu.A=_z80_Fetch(z80,z80->BC.BC);
  }

void _z80_PB(struct Z80CPU *z80)                          /* DEC BC */
  {
    z80->BC.BC--;
    z80->ts+=2;
  }

void _z80_PC(struct Z80CPU *z80)                          /* INC C */
  {
    _z80_Inc_8(z80,&z80->BC.BCu.C);
  }
    
void _z80_PD(struct Z80CPU *z80)                          /* DEC C */
  {
    _z80_Dec_8(z80,&z80->BC.BCu.C);
  }

void _z80_PE(struct Z80CPU *z80)                          /* LD C,n */
  {
    z80->BC.BCu.C=_z80_Get_PC(z80);
  }

void _z80_PF(struct Z80CPU *z80)                          /* RRCA */
  {
    byte set;
    set=0;
    if (z80->AF.AFu.A & 0x1) {
      z80->AF.AFu.A = ((z80->AF.AFu.A >> 1) | 0x80);
      set |= CARRY_FLAG;
      } else z80->AF.AFu.A = z80->AF.AFu.A >> 1;
    z80->AF.AFu.F = (z80->AF.AFu.F & (OVERFLOW_FLAG | ZERO_FLAG | SIGN_FLAG)) |
      set | (z80->AF.AFu.A & (FLAG3 | FLAG5));
/*
    byte Cy;
    z80->AF.AFu.F=z80->AF.AFu.F & (255-(HALF_CARRY_FLAG+ADD_SUB_FLAG));
    if ((z80->AF.AFu.A & 1)==1) Cy=128; else Cy= 0;
    z80->AF.AFu.A=(z80->AF.AFu.A>>1)|Cy;
    if (Cy==128) z80->AF.AFu.F |= CARRY_FLAG; else z80->AF.AFu.F &= CARRY_OFF;
*/
  }

void _z80_P10(struct Z80CPU *z80)                         /* DJNZ */
  {
    byte i;
    z80->BC.BCu.B--;
    if (z80->BC.BCu.B == 0)
      { z80->PC++; z80->ts+=4; }
     else { 
       i = _z80_Get_PC(z80);
       z80->PC=_z80_Offset(z80->PC,i);
       z80->ts+=6;
       }
  }

void _z80_P11(struct Z80CPU *z80)                         /* LD DE,nn */
  {
    z80->DE.DE=_z80_Get_PC2(z80);
  }

void _z80_P12(struct Z80CPU *z80)                         /* LD (DE),A */
  {
    _z80_Store(z80,z80->DE.DE,z80->AF.AFu.A);
  }

void _z80_P13(struct Z80CPU *z80)                         /* INC DE */
  {
    z80->DE.DE++;
    z80->ts+=2;
  }

void _z80_P14(struct Z80CPU *z80)                         /* INC D */
  {
    _z80_Inc_8(z80,&z80->DE.DEu.D);
  }

void _z80_P15(struct Z80CPU *z80)                         /* DEC D */
  {
    _z80_Dec_8(z80,&z80->DE.DEu.D);
  }

void _z80_P16(struct Z80CPU *z80)                         /* LD D,n */
  {
    z80->DE.DEu.D=_z80_Get_PC(z80);
  }

void _z80_P17(struct Z80CPU *z80)                         /* RLA */
  {
    byte Cy,Cy2;
    z80->AF.AFu.F=z80->AF.AFu.F & (HALF_CARRY_OFF&ADD_SUB_OFF);
    if ((z80->AF.AFu.A & 128)==128) Cy=1; else Cy=0;
    if ((z80->AF.AFu.F & CARRY_FLAG)==CARRY_FLAG) Cy2=1; else Cy2=0;
    z80->AF.AFu.A=(z80->AF.AFu.A<<1)|Cy2;
    if (Cy==1) z80->AF.AFu.F |= CARRY_FLAG; else z80->AF.AFu.F &= CARRY_OFF;
  }

void _z80_P18(struct Z80CPU *z80)                         /* JR e */
  {
  byte i;
  i = _z80_Get_PC(z80);
    z80->PC=_z80_Offset(z80->PC,i);
    z80->ts+=5;
  }

void _z80_P19(struct Z80CPU *z80)                         /* ADD HL,DE */
  {
    _z80_Add_16(z80,&z80->HL.HL,z80->DE.DE);
    z80->ts+=7;
  }

void _z80_P1A(struct Z80CPU *z80)                         /* LD A,(DE) */
  {
    z80->AF.AFu.A=_z80_Fetch(z80,z80->DE.DE);
  }

void _z80_P1B(struct Z80CPU *z80)                         /* DEC DE */
  {
    z80->DE.DE--;
    z80->ts+=2;
  }

void _z80_P1C(struct Z80CPU *z80)                         /* INC E */
  {
    _z80_Inc_8(z80,&z80->DE.DEu.E);
  }

void _z80_P1D(struct Z80CPU *z80)                         /* DEC E */
  {
    _z80_Dec_8(z80,&z80->DE.DEu.E);
  }


void _z80_P1E(struct Z80CPU *z80)                         /* LD E,n */
  {
    z80->DE.DEu.E=_z80_Get_PC(z80);
  }

void _z80_P1F(struct Z80CPU *z80)                         /* RRA */
  {
    byte Cy2;
    z80->AF.AFu.F=z80->AF.AFu.F & (HALF_CARRY_OFF & ADD_SUB_OFF);
    if ((z80->AF.AFu.F & CARRY_FLAG)==CARRY_FLAG) Cy2=128; else Cy2=0;
    if ((z80->AF.AFu.A & 1)==1) z80->AF.AFu.F |= CARRY_FLAG;
      else z80->AF.AFu.F &= CARRY_OFF;
    z80->AF.AFu.A=(z80->AF.AFu.A>>1)|Cy2;
  }

void _z80_P20(struct Z80CPU *z80)                         /* JR NZ,e */
  {
    byte i;
    i=_z80_Get_PC(z80);
    if ((z80->AF.AFu.F & ZERO_FLAG) == 0) {
      z80->PC=_z80_Offset(z80->PC,i);
      z80->ts+=5;
      }
  }

void _z80_P21(struct Z80CPU *z80)                         /* LD HL,nn */
  {
    z80->HL.HL=_z80_Get_PC2(z80);
  }

void _z80_P22(struct Z80CPU *z80)                         /* LD (nn),HL */
  {
    _z80_Store2(z80,_z80_Get_PC2(z80),z80->HL.HL);
  }

void _z80_P23(struct Z80CPU *z80)                         /* INC HL */
  {
    z80->HL.HL++;
    z80->ts+=2;
  }

void _z80_P24(struct Z80CPU *z80)                         /* INC H */
  {
    _z80_Inc_8(z80,&z80->HL.HLu.H);
  }

void _z80_P25(struct Z80CPU *z80)                         /* DEC H */
  {
    _z80_Dec_8(z80,&z80->HL.HLu.H);
  }

void _z80_P26(struct Z80CPU *z80)                         /* LD H,n */
  {
    z80->HL.HLu.H=_z80_Get_PC(z80);
  }

void _z80_P27(struct Z80CPU *z80)                         /* DAA */
  {
    if ((z80->AF.AFu.F & ADD_SUB_FLAG) == 0)
      {
        if ((z80->AF.AFu.F & CARRY_FLAG) == 0 &&
            (z80->AF.AFu.F & HALF_CARRY_FLAG) == 0 &&
            (z80->AF.AFu.A & 0xf0) < 0xA0 &&
            (z80->AF.AFu.A & 0x0f) < 0x0A)
          {
          }
        else if ((z80->AF.AFu.F & CARRY_FLAG) == 0 &&
            (z80->AF.AFu.F & HALF_CARRY_FLAG) == 0 &&
            (z80->AF.AFu.A & 0xf0) < 0x90 &&
            (z80->AF.AFu.A & 0x0f) > 0x09)
          {
            z80->AF.AFu.A=z80->AF.AFu.A+0x06;
            z80->AF.AFu.F=z80->AF.AFu.F & CARRY_OFF;
          }
        else if ((z80->AF.AFu.F & CARRY_FLAG) == 0 &&
            (z80->AF.AFu.F & HALF_CARRY_FLAG) == HALF_CARRY_FLAG &&
            (z80->AF.AFu.A & 0xf0) < 0xa0 &&
            (z80->AF.AFu.A & 0x0f) < 0x04)
          {
            z80->AF.AFu.A=z80->AF.AFu.A+0x06;
            z80->AF.AFu.F=z80->AF.AFu.F & CARRY_OFF;
          }
        else if ((z80->AF.AFu.F & CARRY_FLAG) == 0 &&
            (z80->AF.AFu.F & HALF_CARRY_FLAG) == 0 &&
            (z80->AF.AFu.A & 0xf0) > 0x90 &&
            (z80->AF.AFu.A & 0x0f) < 0x0a)
          {
            z80->AF.AFu.A=z80->AF.AFu.A+0x60;
            z80->AF.AFu.F=z80->AF.AFu.F | CARRY_FLAG;
          }
        else if ((z80->AF.AFu.F & CARRY_FLAG) == 0 &&
            (z80->AF.AFu.F & HALF_CARRY_FLAG) == 0 &&
            (z80->AF.AFu.A & 0xf0) > 0x80 &&
            (z80->AF.AFu.A & 0x0f) > 0x09)
          {
            z80->AF.AFu.A=z80->AF.AFu.A+0x66;
            z80->AF.AFu.F=z80->AF.AFu.F | CARRY_FLAG;
          }
        else if ((z80->AF.AFu.F & CARRY_FLAG) == 0 &&
            (z80->AF.AFu.F & HALF_CARRY_FLAG) == HALF_CARRY_FLAG &&
            (z80->AF.AFu.A & 0xf0) > 0x90 &&
            (z80->AF.AFu.A & 0x0f) < 0x04)
          {
            z80->AF.AFu.A=z80->AF.AFu.A+0x66;
            z80->AF.AFu.F=z80->AF.AFu.F | CARRY_FLAG;
          }
        else if ((z80->AF.AFu.F & CARRY_FLAG) == CARRY_FLAG &&
            (z80->AF.AFu.F & HALF_CARRY_FLAG) == 0 &&
            (z80->AF.AFu.A & 0xf0) < 0x30 &&
            (z80->AF.AFu.A & 0x0f) < 0x0A)
          {
            z80->AF.AFu.A=z80->AF.AFu.A+0x60;
            z80->AF.AFu.F=z80->AF.AFu.F | CARRY_FLAG;
          }
        else if ((z80->AF.AFu.F & CARRY_FLAG) == CARRY_FLAG &&
            (z80->AF.AFu.F & HALF_CARRY_FLAG) == 0 &&
            (z80->AF.AFu.A & 0xf0) < 0x30 &&
            (z80->AF.AFu.A & 0x0f) > 0x09)
          {
            z80->AF.AFu.A=z80->AF.AFu.A+0x66;
            z80->AF.AFu.F=z80->AF.AFu.F | CARRY_FLAG;
          }
        else if ((z80->AF.AFu.F & CARRY_FLAG) == CARRY_FLAG &&
            (z80->AF.AFu.F & HALF_CARRY_FLAG) == HALF_CARRY_FLAG &&
            (z80->AF.AFu.A & 0xf0) < 0x40 &&
            (z80->AF.AFu.A & 0x0f) < 0x04)
          {
            z80->AF.AFu.A=z80->AF.AFu.A+0x66;
            z80->AF.AFu.F=z80->AF.AFu.F | CARRY_FLAG;
          }
      }
     else
      {
        if ((z80->AF.AFu.F & CARRY_FLAG) == 0 &&
            (z80->AF.AFu.F & HALF_CARRY_FLAG) == 0 &&
            (z80->AF.AFu.A & 0xf0) < 0xA0 &&
            (z80->AF.AFu.A & 0x0f) < 0x0A)
          {
          }
        else if ((z80->AF.AFu.F & CARRY_FLAG) == 0 &&
            (z80->AF.AFu.F & HALF_CARRY_FLAG) == HALF_CARRY_FLAG &&
            (z80->AF.AFu.A & 0xf0) < 0x90 &&
            (z80->AF.AFu.A & 0x0f) > 0x05)
          {
            z80->AF.AFu.A=z80->AF.AFu.A+0xfa;
            z80->AF.AFu.F=z80->AF.AFu.F & CARRY_OFF;
          }
        else if ((z80->AF.AFu.F & CARRY_FLAG) == CARRY_FLAG &&
            (z80->AF.AFu.F & HALF_CARRY_FLAG) == 0 &&
            (z80->AF.AFu.A & 0xf0) > 0x60 &&
            (z80->AF.AFu.A & 0x0f) < 0x0A)
          {
            z80->AF.AFu.A=z80->AF.AFu.A+0xa0;
            z80->AF.AFu.F=z80->AF.AFu.F | CARRY_FLAG;
          }
        else if ((z80->AF.AFu.F & CARRY_FLAG) == CARRY_FLAG &&
            (z80->AF.AFu.F & HALF_CARRY_FLAG) == HALF_CARRY_FLAG &&
            (z80->AF.AFu.A & 0xf0) > 0x50 &&
            (z80->AF.AFu.A & 0xf0) < 0x80 &&
            (z80->AF.AFu.A & 0x0f) > 0x05)
          {
            z80->AF.AFu.A=z80->AF.AFu.A+0x9A;
            z80->AF.AFu.F=z80->AF.AFu.F | CARRY_FLAG;
          }
      }
  }

void _z80_P28(struct Z80CPU *z80)                         /* JR Z,e */
  {
    byte i;
    i=_z80_Get_PC(z80);
    if ((z80->AF.AFu.F & ZERO_FLAG) == ZERO_FLAG)
      { z80->PC=_z80_Offset(z80->PC,i); z80->ts+=5; }
  }

void _z80_P29(struct Z80CPU *z80)                         /* ADD HL,HL */
  {
    _z80_Add_16(z80,&z80->HL.HL,z80->HL.HL);
    z80->ts+=7;
  }

void _z80_P2A(struct Z80CPU *z80)                         /* LD HL,(nn) */
  {
    z80->HL.HL=_z80_Fetch2(z80,_z80_Get_PC2(z80));
  }

void _z80_P2B(struct Z80CPU *z80)                         /* DEC HL */
  {
    z80->HL.HL--;
    z80->ts+=2;
  }

void _z80_P2C(struct Z80CPU *z80)                         /* INC L */
  {
    _z80_Inc_8(z80,&z80->HL.HLu.L);
  }

void _z80_P2D(struct Z80CPU *z80)                         /* DEC L */
  {
    _z80_Dec_8(z80,&z80->HL.HLu.L);
  }

void _z80_P2E(struct Z80CPU *z80)                         /* LD L,n */
  {
    z80->HL.HLu.L=_z80_Get_PC(z80);
  }


void _z80_P2F(struct Z80CPU *z80)                         /* CPL */
  {
    z80->AF.AFu.A=~z80->AF.AFu.A;
    z80->AF.AFu.F=z80->AF.AFu.F | (ADD_SUB_FLAG + HALF_CARRY_FLAG);
  }

void _z80_P30(struct Z80CPU *z80)                         /* JR NC,e */
  {
    byte i;
    i=_z80_Get_PC(z80);
    if ((z80->AF.AFu.F & CARRY_FLAG) != CARRY_FLAG)
      { z80->PC=_z80_Offset(z80->PC,i); z80->ts+=5; }
  }

void _z80_P31(struct Z80CPU *z80)                         /* LD SP,nn */
  {
    z80->SP=_z80_Get_PC2(z80);
  }

void _z80_P32(struct Z80CPU *z80)                         /* LD (nn),A */
  {
    _z80_Store(z80,_z80_Get_PC2(z80),z80->AF.AFu.A);
  }

void _z80_P33(struct Z80CPU *z80)                         /* INC SP */
  {
    z80->SP++;
    z80->ts+=2;
  }

void _z80_P34(struct Z80CPU *z80)                         /* INC (HL) */
  {
    _z80_Inc_Mem_8(z80,z80->HL.HL);
    z80->ts++;
  }

void _z80_P35(struct Z80CPU *z80)                         /* DEC (HL) */
  {
    _z80_Dec_Mem_8(z80,z80->HL.HL);
    z80->ts++;
  }

void _z80_P36(struct Z80CPU *z80)                         /* LD (HL),n */
  {
    _z80_Store(z80,z80->HL.HL,_z80_Get_PC(z80));
  }

void _z80_P37(struct Z80CPU *z80)                         /* SCF */
  {
    z80->AF.AFu.F=z80->AF.AFu.F | CARRY_FLAG;
    z80->AF.AFu.F=z80->AF.AFu.F & (255-(ADD_SUB_FLAG+HALF_CARRY_FLAG));
  }

void _z80_P38(struct Z80CPU *z80)                         /* JR C,e */
  {
    byte i;
    i=_z80_Get_PC(z80);
    if ((z80->AF.AFu.F & CARRY_FLAG) == CARRY_FLAG)
      { z80->PC=_z80_Offset(z80->PC,i); z80->ts+=5; }
  }

void _z80_P39(struct Z80CPU *z80)                         /* ADD HL,SP */
  {
    _z80_Add_16(z80,&z80->HL.HL,z80->SP);
    z80->ts+=7;
  }

void _z80_P3A(struct Z80CPU *z80)                         /* LD A,(nn) */
  {
    z80->AF.AFu.A=_z80_Fetch(z80,_z80_Get_PC2(z80));
  }

void _z80_P3B(struct Z80CPU *z80)                         /* DEC SP */
  {
    z80->SP--;
    z80->ts+=2;
  }

void _z80_P3C(struct Z80CPU *z80)                         /* INC A */
  {
    _z80_Inc_8(z80,&z80->AF.AFu.A);
  }

void _z80_P3D(struct Z80CPU *z80)                         /* DEC A */
  {
    _z80_Dec_8(z80,&z80->AF.AFu.A);
  }

void _z80_P3E(struct Z80CPU *z80)                         /* LD A,n */
  {
    z80->AF.AFu.A=_z80_Get_PC(z80);
  }

void _z80_P3F(struct Z80CPU *z80)                         /* CCF */
  {
    z80->AF.AFu.F=z80->AF.AFu.F ^ CARRY_FLAG;
    z80->AF.AFu.F=z80->AF.AFu.F & (255-ADD_SUB_FLAG);
  }

void _z80_P40(struct Z80CPU *z80)                         /* LD B,B */
  {
    z80->BC.BCu.B=z80->BC.BCu.B;
  }

void _z80_P41(struct Z80CPU *z80)                         /* LD B,C */
  {
    z80->BC.BCu.B=z80->BC.BCu.C;
  }

void _z80_P42(struct Z80CPU *z80)                         /* LD B,D */
  {
    z80->BC.BCu.B=z80->DE.DEu.D;
  }

void _z80_P43(struct Z80CPU *z80)                         /* LD B,E */
  {
    z80->BC.BCu.B=z80->DE.DEu.E;
  }

void _z80_P44(struct Z80CPU *z80)                         /* LD B,H */
  {
    z80->BC.BCu.B=z80->HL.HLu.H;
  }

void _z80_P45(struct Z80CPU *z80)                         /* LD B,L */
  {
    z80->BC.BCu.B=z80->HL.HLu.L;
  }

void _z80_P46(struct Z80CPU *z80)                         /* LD B,(HL) */
  {
    z80->BC.BCu.B=_z80_Fetch(z80,z80->HL.HL);
  }

void _z80_P47(struct Z80CPU *z80)                         /* LD B,A */
  {
    z80->BC.BCu.B=z80->AF.AFu.A;
  }

void _z80_P48(struct Z80CPU *z80)                         /* LD C,B */
  {
    z80->BC.BCu.C=z80->BC.BCu.B;
  }

void _z80_P49(struct Z80CPU *z80)                         /* LD C,C */
  {
    z80->BC.BCu.C=z80->BC.BCu.C;
  }

void _z80_P4A(struct Z80CPU *z80)                         /* LD C,D */
  {
    z80->BC.BCu.C=z80->DE.DEu.D;
  }

void _z80_P4B(struct Z80CPU *z80)                         /* LD C,E */
  {
    z80->BC.BCu.C=z80->DE.DEu.E;
  }

void _z80_P4C(struct Z80CPU *z80)                         /* LD C,H */
  {
    z80->BC.BCu.C=z80->HL.HLu.H;
  }

void _z80_P4D(struct Z80CPU *z80)                         /* LD C,L */
  {
    z80->BC.BCu.C=z80->HL.HLu.L;
  }

void _z80_P4E(struct Z80CPU *z80)                         /* LD C,(HL) */
  {
    z80->BC.BCu.C=_z80_Fetch(z80,z80->HL.HL);
  }

void _z80_P4F(struct Z80CPU *z80)                         /* LD C,A */
  {
    z80->BC.BCu.C=z80->AF.AFu.A;
  }

void _z80_P50(struct Z80CPU *z80)                         /* LD D,B */
  {
    z80->DE.DEu.D=z80->BC.BCu.B;
  }

void _z80_P51(struct Z80CPU *z80)                         /* LD D,C */
  {
    z80->DE.DEu.D=z80->BC.BCu.C;
  }

void _z80_P52(struct Z80CPU *z80)                         /* LD D,D */
  {
    z80->DE.DEu.D=z80->DE.DEu.D;
  }

void _z80_P53(struct Z80CPU *z80)                         /* LD D,E */
  {
    z80->DE.DEu.D=z80->DE.DEu.E;
  }

void _z80_P54(struct Z80CPU *z80)                         /* LD D,H */
  {
    z80->DE.DEu.D=z80->HL.HLu.H;
  }

void _z80_P55(struct Z80CPU *z80)                         /* LD D,L */
  {
    z80->DE.DEu.D=z80->HL.HLu.L;
  }

void _z80_P56(struct Z80CPU *z80)                         /* LD D,(HL) */
  {
    z80->DE.DEu.D=_z80_Fetch(z80,z80->HL.HL);
  }

void _z80_P57(struct Z80CPU *z80)                         /* LD D,A */
  {
    z80->DE.DEu.D=z80->AF.AFu.A;
  }

void _z80_P58(struct Z80CPU *z80)                         /* LD E,B */
  {
    z80->DE.DEu.E=z80->BC.BCu.B;
  }

void _z80_P59(struct Z80CPU *z80)                         /* LD E,C */
  {
    z80->DE.DEu.E=z80->BC.BCu.C;
  }

void _z80_P5A(struct Z80CPU *z80)                         /* LD E,D */
  {
    z80->DE.DEu.E=z80->DE.DEu.D;
  }

void _z80_P5B(struct Z80CPU *z80)                         /* LD E,E */
  {
    z80->DE.DEu.E=z80->DE.DEu.E;
  }

void _z80_P5C(struct Z80CPU *z80)                         /* LD E,H */
  {
    z80->DE.DEu.E=z80->HL.HLu.H;
  }

void _z80_P5D(struct Z80CPU *z80)                         /* LD E,L */
  {
    z80->DE.DEu.E=z80->HL.HLu.L;
  }

void _z80_P5E(struct Z80CPU *z80)                         /* LD E,(HL) */
  {
    z80->DE.DEu.E=_z80_Fetch(z80,z80->HL.HL);
  }

void _z80_P5F(struct Z80CPU *z80)                         /* LD E,A */
  {
    z80->DE.DEu.E=z80->AF.AFu.A;
  }

void _z80_P60(struct Z80CPU *z80)                         /* LD H,B */
  {
    z80->HL.HLu.H=z80->BC.BCu.B;
  }

void _z80_P61(struct Z80CPU *z80)                         /* LD H,C */
  {
    z80->HL.HLu.H=z80->BC.BCu.C;
  }

void _z80_P62(struct Z80CPU *z80)                         /* LD H,D */
  {
    z80->HL.HLu.H=z80->DE.DEu.D;
  }

void _z80_P63(struct Z80CPU *z80)                         /* LD H,E */
  {
    z80->HL.HLu.H=z80->DE.DEu.E;
  }

void _z80_P64(struct Z80CPU *z80)                         /* LD H,H */
  {
    z80->HL.HLu.H=z80->HL.HLu.H;
  }

void _z80_P65(struct Z80CPU *z80)                         /* LD H,L */
  {
    z80->HL.HLu.H=z80->HL.HLu.L;
  }

void _z80_P66(struct Z80CPU *z80)                         /* LD H,(HL) */
  {
    z80->HL.HLu.H=_z80_Fetch(z80,z80->HL.HL);
  }

void _z80_P67(struct Z80CPU *z80)                         /* LD H,A */
  {
    z80->HL.HLu.H=z80->AF.AFu.A;
  }

void _z80_P68(struct Z80CPU *z80)                         /* LD L,B */
  {
    z80->HL.HLu.L=z80->BC.BCu.B;
  }

void _z80_P69(struct Z80CPU *z80)                         /* LD L,C */
  {
    z80->HL.HLu.L=z80->BC.BCu.C;
  }

void _z80_P6A(struct Z80CPU *z80)                         /* LD L,D */
  {
    z80->HL.HLu.L=z80->DE.DEu.D;
  }

void _z80_P6B(struct Z80CPU *z80)                         /* LD L,E */
  {
    z80->HL.HLu.L=z80->DE.DEu.E;
  }

void _z80_P6C(struct Z80CPU *z80)                         /* LD L,H */
  {
    z80->HL.HLu.L=z80->HL.HLu.H;
  }

void _z80_P6D(struct Z80CPU *z80)                         /* LD L,L */
  {
    z80->HL.HLu.L=z80->HL.HLu.L;
  }

void _z80_P6E(struct Z80CPU *z80)                         /* LD L,(HL) */
  {
    z80->HL.HLu.L=_z80_Fetch(z80,z80->HL.HL);
  }

void _z80_P6F(struct Z80CPU *z80)                         /* LD L,A */
  {
    z80->HL.HLu.L=z80->AF.AFu.A;
  }

void _z80_P70(struct Z80CPU *z80)                         /* LD (HL),B */
  {
    _z80_Store(z80,z80->HL.HL,z80->BC.BCu.B);
  }

void _z80_P71(struct Z80CPU *z80)                         /* LD (HL),C */
  {
    _z80_Store(z80,z80->HL.HL,z80->BC.BCu.C);
  }

void _z80_P72(struct Z80CPU *z80)                         /* LD (HL),D */
  {
    _z80_Store(z80,z80->HL.HL,z80->DE.DEu.D);
  }

void _z80_P73(struct Z80CPU *z80)                         /* LD (HL),E */
  {
    _z80_Store(z80,z80->HL.HL,z80->DE.DEu.E);
  }

void _z80_P74(struct Z80CPU *z80)                         /* LD (HL),H */
  {
    _z80_Store(z80,z80->HL.HL,z80->HL.HLu.H);
  }

void _z80_P75(struct Z80CPU *z80)                         /* LD (HL),L */
  {
    _z80_Store(z80,z80->HL.HL,z80->HL.HLu.L);
  }

void _z80_P76(struct Z80CPU *z80)                         /* HALT */
  {
    z80->Halt=1;
  }

void _z80_P77(struct Z80CPU *z80)                         /* LD (HL),A */
  {
    _z80_Store(z80,z80->HL.HL,z80->AF.AFu.A);
  }

void _z80_P78(struct Z80CPU *z80)                         /* LD A,B */
  {
    z80->AF.AFu.A=z80->BC.BCu.B;
  }

void _z80_P79(struct Z80CPU *z80)                         /* LD A,C */
  {
    z80->AF.AFu.A=z80->BC.BCu.C;
  }

void _z80_P7A(struct Z80CPU *z80)                         /* LD A,D */
  {
    z80->AF.AFu.A=z80->DE.DEu.D;
  }

void _z80_P7B(struct Z80CPU *z80)                         /* LD A,E */
  {
    z80->AF.AFu.A=z80->DE.DEu.E;
  }

void _z80_P7C(struct Z80CPU *z80)                         /* LD A,H */
  {
    z80->AF.AFu.A=z80->HL.HLu.H;
  }

void _z80_P7D(struct Z80CPU *z80)                         /* LD A,L */
  {
    z80->AF.AFu.A=z80->HL.HLu.L;
  }

void _z80_P7E(struct Z80CPU *z80)                         /* LD A,(HL) */
  {
    z80->AF.AFu.A=_z80_Fetch(z80,z80->HL.HL);
  }

void _z80_P7F(struct Z80CPU *z80)                         /* LD A,A */
  {
    z80->AF.AFu.A=z80->AF.AFu.A;
  }

void _z80_P80(struct Z80CPU *z80)                         /* ADD A,B */
  {
    _z80_Add_8(z80,&z80->AF.AFu.A,z80->BC.BCu.B);
  }

void _z80_P81(struct Z80CPU *z80)                         /* ADD A,C */
  {
    _z80_Add_8(z80,&z80->AF.AFu.A,z80->BC.BCu.C);
  }

void _z80_P82(struct Z80CPU *z80)                         /* ADD A,D */
  {
    _z80_Add_8(z80,&z80->AF.AFu.A,z80->DE.DEu.D);
  }

void _z80_P83(struct Z80CPU *z80)                         /* ADD A,E */
  {
    _z80_Add_8(z80,&z80->AF.AFu.A,z80->DE.DEu.E);
  }

void _z80_P84(struct Z80CPU *z80)                         /* ADD A,H */
  {
    _z80_Add_8(z80,&z80->AF.AFu.A,z80->HL.HLu.H);
  }

void _z80_P85(struct Z80CPU *z80)                         /* ADD A,L */
  {
    _z80_Add_8(z80,&z80->AF.AFu.A,z80->HL.HLu.L);
  }

void _z80_P86(struct Z80CPU *z80)                         /* ADD A,(HL) */
  {
    _z80_Add_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,z80->HL.HL));
  }

void _z80_P87(struct Z80CPU *z80)                         /* ADD A,A */
  {
    _z80_Add_8(z80,&z80->AF.AFu.A,z80->AF.AFu.A);
  }

void _z80_P88(struct Z80CPU *z80)                         /* ADC A,B */
  {
    _z80_Adc_8(z80,&z80->AF.AFu.A,z80->BC.BCu.B);
  }

void _z80_P89(struct Z80CPU *z80)                         /* ADC A,C */
  {
    _z80_Adc_8(z80,&z80->AF.AFu.A,z80->BC.BCu.C);
  }

void _z80_P8A(struct Z80CPU *z80)                         /* ADC A,D */
  {
    _z80_Adc_8(z80,&z80->AF.AFu.A,z80->DE.DEu.D);
  }

void _z80_P8B(struct Z80CPU *z80)                         /* ADC A,E */
  {
    _z80_Adc_8(z80,&z80->AF.AFu.A,z80->DE.DEu.E);
  }

void _z80_P8C(struct Z80CPU *z80)                         /* ADC A,H */
  {
    _z80_Adc_8(z80,&z80->AF.AFu.A,z80->HL.HLu.H);
  }

void _z80_P8D(struct Z80CPU *z80)                         /* ADC A,L */
  {
    _z80_Adc_8(z80,&z80->AF.AFu.A,z80->HL.HLu.L);
  }

void _z80_P8E(struct Z80CPU *z80)                         /* ADC A,(HL) */
  {
    _z80_Adc_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,z80->HL.HL));
  }

void _z80_P8F(struct Z80CPU *z80)                         /* ADC A,A */
  {
    _z80_Adc_8(z80,&z80->AF.AFu.A,z80->AF.AFu.A);
  }

void _z80_P90(struct Z80CPU *z80)                         /* SUB B */
  {
    _z80_Sub_8(z80,&z80->AF.AFu.A,z80->BC.BCu.B);
  }

void _z80_P91(struct Z80CPU *z80)                         /* SUB C */
  {
    _z80_Sub_8(z80,&z80->AF.AFu.A,z80->BC.BCu.C);
  }

void _z80_P92(struct Z80CPU *z80)                         /* SUB D */
  {
    _z80_Sub_8(z80,&z80->AF.AFu.A,z80->DE.DEu.D);
  }

void _z80_P93(struct Z80CPU *z80)                         /* SUB E */
  {
    _z80_Sub_8(z80,&z80->AF.AFu.A,z80->DE.DEu.E);
  }

void _z80_P94(struct Z80CPU *z80)                         /* SUB H */
  {
    _z80_Sub_8(z80,&z80->AF.AFu.A,z80->HL.HLu.H);
  }

void _z80_P95(struct Z80CPU *z80)                         /* SUB L */
  {
    _z80_Sub_8(z80,&z80->AF.AFu.A,z80->HL.HLu.L);
  }

void _z80_P96(struct Z80CPU *z80)                         /* SUB (HL) */
  {
    _z80_Sub_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,z80->HL.HL));
  }

void _z80_P97(struct Z80CPU *z80)                         /* SUB A */
  {
    _z80_Sub_8(z80,&z80->AF.AFu.A,z80->AF.AFu.A);
  }

void _z80_P98(struct Z80CPU *z80)                         /* SBC B */
  {
    _z80_Sbc_8(z80,&z80->AF.AFu.A,z80->BC.BCu.B);
  }

void _z80_P99(struct Z80CPU *z80)                         /* SBC C */
  {
    _z80_Sbc_8(z80,&z80->AF.AFu.A,z80->BC.BCu.C);
  }

void _z80_P9A(struct Z80CPU *z80)                         /* SBC D */
  {
    _z80_Sbc_8(z80,&z80->AF.AFu.A,z80->DE.DEu.D);
  }

void _z80_P9B(struct Z80CPU *z80)                         /* SBC E */
  {
    _z80_Sbc_8(z80,&z80->AF.AFu.A,z80->DE.DEu.E);
  }

void _z80_P9C(struct Z80CPU *z80)                         /* SBC H */
  {
    _z80_Sbc_8(z80,&z80->AF.AFu.A,z80->HL.HLu.H);
  }

void _z80_P9D(struct Z80CPU *z80)                         /* SBC L */
  {
    _z80_Sbc_8(z80,&z80->AF.AFu.A,z80->HL.HLu.L);
  }

void _z80_P9E(struct Z80CPU *z80)                         /* SBC (HL) */
  {
    _z80_Sbc_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,z80->HL.HL));
  }

void _z80_P9F(struct Z80CPU *z80)                         /* SBC A */
  {
    _z80_Sbc_8(z80,&z80->AF.AFu.A,z80->AF.AFu.A);
  }

void _z80_PA0(struct Z80CPU *z80)                         /* AND B */
  {
    _z80_And_8(z80,&z80->AF.AFu.A,z80->BC.BCu.B);
  }

void _z80_PA1(struct Z80CPU *z80)                         /* AND C */
  {
    _z80_And_8(z80,&z80->AF.AFu.A,z80->BC.BCu.C);
  }

void _z80_PA2(struct Z80CPU *z80)                         /* AND D */
  {
    _z80_And_8(z80,&z80->AF.AFu.A,z80->DE.DEu.D);
  }

void _z80_PA3(struct Z80CPU *z80)                         /* AND E */
  {
    _z80_And_8(z80,&z80->AF.AFu.A,z80->DE.DEu.E);
  }

void _z80_PA4(struct Z80CPU *z80)                         /* AND H */
  {
    _z80_And_8(z80,&z80->AF.AFu.A,z80->HL.HLu.H);
  }

void _z80_PA5(struct Z80CPU *z80)                         /* AND L */
  {
    _z80_And_8(z80,&z80->AF.AFu.A,z80->HL.HLu.L);
  }

void _z80_PA6(struct Z80CPU *z80)                         /* AND (HL) */
  {
    _z80_And_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,z80->HL.HL));
  }

void _z80_PA7(struct Z80CPU *z80)                         /* AND A */
  {
    _z80_And_8(z80,&z80->AF.AFu.A,z80->AF.AFu.A);
  }

void _z80_PA8(struct Z80CPU *z80)                         /* XOR B */
  {
    _z80_XOr_8(z80,&z80->AF.AFu.A,z80->BC.BCu.B);
  }

void _z80_PA9(struct Z80CPU *z80)                         /* XOR C */
  {
    _z80_XOr_8(z80,&z80->AF.AFu.A,z80->BC.BCu.C);
  }

void _z80_PAA(struct Z80CPU *z80)                         /* XOR D */
  {
    _z80_XOr_8(z80,&z80->AF.AFu.A,z80->DE.DEu.D);
  }

void _z80_PAB(struct Z80CPU *z80)                         /* XOR E */
  {
    _z80_XOr_8(z80,&z80->AF.AFu.A,z80->DE.DEu.E);
  }

void _z80_PAC(struct Z80CPU *z80)                         /* XOR H */
  {
    _z80_XOr_8(z80,&z80->AF.AFu.A,z80->HL.HLu.H);
  }

void _z80_PAD(struct Z80CPU *z80)                         /* XOR L */
  {
    _z80_XOr_8(z80,&z80->AF.AFu.A,z80->HL.HLu.L);
  }

void _z80_PAE(struct Z80CPU *z80)                         /* XOR (HL) */
  {
    _z80_XOr_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,z80->HL.HL));
  }

void _z80_PAF(struct Z80CPU *z80)                         /* XOR A */
  {
    _z80_XOr_8(z80,&z80->AF.AFu.A,z80->AF.AFu.A);
  }

void _z80_PB0(struct Z80CPU *z80)                         /* OR B */
  {
    _z80_Or_8(z80,&z80->AF.AFu.A,z80->BC.BCu.B);
  }

void _z80_PB1(struct Z80CPU *z80)                         /* OR C */
  {
    _z80_Or_8(z80,&z80->AF.AFu.A,z80->BC.BCu.C);
  }

void _z80_PB2(struct Z80CPU *z80)                         /* OR D */
  {
    _z80_Or_8(z80,&z80->AF.AFu.A,z80->DE.DEu.D);
  }

void _z80_PB3(struct Z80CPU *z80)                         /* OR E */
  {
    _z80_Or_8(z80,&z80->AF.AFu.A,z80->DE.DEu.E);
  }

void _z80_PB4(struct Z80CPU *z80)                         /* OR H */
  {
    _z80_Or_8(z80,&z80->AF.AFu.A,z80->HL.HLu.H);
  }

void _z80_PB5(struct Z80CPU *z80)                         /* OR L */
  {
    _z80_Or_8(z80,&z80->AF.AFu.A,z80->HL.HLu.L);
  }

void _z80_PB6(struct Z80CPU *z80)                         /* OR (HL) */
  {
    _z80_Or_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,z80->HL.HL));
  }

void _z80_PB7(struct Z80CPU *z80)                         /* OR A */
  {
    _z80_Or_8(z80,&z80->AF.AFu.A,z80->AF.AFu.A);
  }

void _z80_PB8(struct Z80CPU *z80)                         /* CP B */
  {
    _z80_Cmp_8(z80,&z80->AF.AFu.A,z80->BC.BCu.B);
  }

void _z80_PB9(struct Z80CPU *z80)                         /* CP C */
  {
    _z80_Cmp_8(z80,&z80->AF.AFu.A,z80->BC.BCu.C);
  }

void _z80_PBA(struct Z80CPU *z80)                         /* CP D */
  {
    _z80_Cmp_8(z80,&z80->AF.AFu.A,z80->DE.DEu.D);
  }

void _z80_PBB(struct Z80CPU *z80)                         /* CP E */
  {
    _z80_Cmp_8(z80,&z80->AF.AFu.A,z80->DE.DEu.E);
  }

void _z80_PBC(struct Z80CPU *z80)                         /* CP H */
  {
    _z80_Cmp_8(z80,&z80->AF.AFu.A,z80->HL.HLu.H);
  }

void _z80_PBD(struct Z80CPU *z80)                         /* CP L */
  {
    _z80_Cmp_8(z80,&z80->AF.AFu.A,z80->HL.HLu.L);
  }

void _z80_PBE(struct Z80CPU *z80)                         /* CP (HL) */
  {
    _z80_Cmp_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,z80->HL.HL));
  }

void _z80_PBF(struct Z80CPU *z80)                         /* CP A */
  {
    _z80_Cmp_8(z80,&z80->AF.AFu.A,z80->AF.AFu.A);
  }

void _z80_PC0(struct Z80CPU *z80)                         /* RET NZ */
  {
    z80->ts++;
    if ((z80->AF.AFu.F & ZERO_FLAG) == 0)
      z80->PC=_z80_Pop2(z80);
  }

void _z80_PC1(struct Z80CPU *z80)                         /* POP BC */
  {
    z80->BC.BC=_z80_Pop2(z80);
  }

void _z80_PC2(struct Z80CPU *z80)                         /* JP NZ,nn */
  {
    word i;
    if ((z80->AF.AFu.F & ZERO_FLAG) == 0)
      z80->PC=_z80_Get_PC2(z80);
     else
      i=_z80_Get_PC2(z80);
  }

void _z80_PC3(struct Z80CPU *z80)                         /* JP nn */
  {
    z80->PC=_z80_Get_PC2(z80);
  }

void _z80_PC4(struct Z80CPU *z80)                         /* CALL NZ,nn */
  {
    word i;
    if ((z80->AF.AFu.F & ZERO_FLAG) == 0)
      {
        _z80_Push2(z80,z80->PC+2);
        z80->PC=_z80_Get_PC2(z80);
        z80->ts++;
      }
     else
      i=_z80_Get_PC2(z80);
  }

void _z80_PC5(struct Z80CPU *z80)                         /* PUSH BC */
  {
    _z80_Push2(z80,z80->BC.BC);
    z80->ts++;
  }

void _z80_PC6(struct Z80CPU *z80)                         /* ADD A,n */
  {
    _z80_Add_8(z80,&z80->AF.AFu.A,_z80_Get_PC(z80));
  }

void _z80_PC7(struct Z80CPU *z80)                         /* RST 00H */
  {
    _z80_Push2(z80,z80->PC);
    z80->PC=0;
    z80->ts++;
  }

void _z80_PC8(struct Z80CPU *z80)                         /* RET Z */
  {
    z80->ts++;
    if ((z80->AF.AFu.F & ZERO_FLAG) == ZERO_FLAG)
      z80->PC=_z80_Pop2(z80);
  }

void _z80_PC9(struct Z80CPU *z80)                         /* RET */
  {
    z80->PC=_z80_Pop2(z80);
  }

void _z80_PCA(struct Z80CPU *z80)                         /* JP Z,nn */
  {
    word i;
    if ((z80->AF.AFu.F & ZERO_FLAG) == ZERO_FLAG)
      z80->PC=_z80_Get_PC2(z80);
     else
      i=_z80_Get_PC2(z80);
  }

void _z80_PCC(struct Z80CPU *z80)                         /* CALL Z,nn */
  {
    word i;
    if ((z80->AF.AFu.F & ZERO_FLAG) == ZERO_FLAG)
      {
        _z80_Push2(z80,z80->PC+2);
        z80->PC=_z80_Get_PC2(z80);
        z80->ts++;
      }
     else
      i=_z80_Get_PC2(z80);
  }

void _z80_PCD(struct Z80CPU *z80)                         /* CALL nn */
  {
    _z80_Push2(z80,z80->PC+2);
    z80->PC=_z80_Get_PC2(z80);
    z80->ts++;
  }

void _z80_PCE(struct Z80CPU *z80)                         /* ADC A,n */
  {
    _z80_Adc_8(z80,&z80->AF.AFu.A,_z80_Get_PC(z80));
  }

void _z80_PCF(struct Z80CPU *z80)                         /* RST 08H */
  {
    _z80_Push2(z80,z80->PC);
    z80->PC=8;
    z80->ts++;
  }

void _z80_PD0(struct Z80CPU *z80)                         /* RET NC */
  {
    z80->ts++;
    if ((z80->AF.AFu.F & CARRY_FLAG) == 0)
      z80->PC=_z80_Pop2(z80);
  }

void _z80_PD1(struct Z80CPU *z80)                         /* POP DE */
  {
    z80->DE.DE=_z80_Pop2(z80);
  }

void _z80_PD2(struct Z80CPU *z80)                         /* JP NC,nn */
  {
    word i;
    if ((z80->AF.AFu.F & CARRY_FLAG) == 0)
      z80->PC=_z80_Get_PC2(z80);
     else
      i=_z80_Get_PC2(z80);
  }

void _z80_PD3(struct Z80CPU *z80)                         /* OUT (n),A */
  {
    _z80_OutPort(z80,_z80_Get_PC(z80),z80->AF.AFu.A);
    z80->ts++;
  }

void _z80_PD4(struct Z80CPU *z80)                         /* CALL NC,nn */
  {
    word i;
    if ((z80->AF.AFu.F & CARRY_FLAG) == 0)
      {
        _z80_Push2(z80,z80->PC+2);
        z80->PC=_z80_Get_PC2(z80);
        z80->ts++;
      }
     else
      i=_z80_Get_PC2(z80);
  }

void _z80_PD5(struct Z80CPU *z80)                         /* PUSH DE */
  {
    _z80_Push2(z80,z80->DE.DE);
    z80->ts++;
  }

void _z80_PD6(struct Z80CPU *z80)                         /* SUB n */
  {
    _z80_Sub_8(z80,&z80->AF.AFu.A,_z80_Get_PC(z80));
  }

void _z80_PD7(struct Z80CPU *z80)                         /* RST 10H */
  {
    _z80_Push2(z80,z80->PC);
    z80->PC=0x10;
    z80->ts++;
  }

void _z80_PD8(struct Z80CPU *z80)                         /* RET C */
  {
    z80->ts++;
    if ((z80->AF.AFu.F & CARRY_FLAG) == CARRY_FLAG)
      z80->PC=_z80_Pop2(z80);
  }

void _z80_PD9(struct Z80CPU *z80)                         /* EXX */
  {
    word i;
    i=z80->BC.BC; z80->BC.BC=z80->BCa; z80->BCa=i;
    i=z80->DE.DE; z80->DE.DE=z80->DEa; z80->DEa=i;
    i=z80->HL.HL; z80->HL.HL=z80->HLa; z80->HLa=i;
  }

void _z80_PDA(struct Z80CPU *z80)                         /* JP C,nn */
  {
    word i;
    if ((z80->AF.AFu.F & CARRY_FLAG) == CARRY_FLAG)
      z80->PC=_z80_Get_PC2(z80);
     else
      i=_z80_Get_PC2(z80);
  }

void _z80_PDB(struct Z80CPU *z80)                         /* IN A,(n) */
  {
    z80->AF.AFu.A=_z80_InPort(z80,_z80_Get_PC(z80));
  }

void _z80_PDC(struct Z80CPU *z80)                         /* CALL C,nn */
  {
    word i;
    if ((z80->AF.AFu.F & CARRY_FLAG) == CARRY_FLAG)
      {
        _z80_Push2(z80,z80->PC+2);
        z80->PC=_z80_Get_PC2(z80);
        z80->ts++;
      }
     else
      i=_z80_Get_PC2(z80);
  }

void _z80_PDE(struct Z80CPU *z80)                         /* SBC A,n */
  {
    _z80_Sbc_8(z80,&z80->AF.AFu.A,_z80_Get_PC(z80));
  }

void _z80_PDF(struct Z80CPU *z80)                         /* RST 18H */
  {
    _z80_Push2(z80,z80->PC);
    z80->PC=0x18;
    z80->ts++;
  }

void _z80_PE0(struct Z80CPU *z80)                         /* RET PO */
  {
    z80->ts++;
    if ((z80->AF.AFu.F & OVERFLOW_FLAG) != OVERFLOW_FLAG)
      z80->PC=_z80_Pop2(z80);
  }

void _z80_PE1(struct Z80CPU *z80)                         /* POP HL */
  {
    z80->HL.HL=_z80_Pop2(z80);
  }

void _z80_PE2(struct Z80CPU *z80)                         /* JP PO,nn */
  {
    word i;
    if ((z80->AF.AFu.F & OVERFLOW_FLAG) != OVERFLOW_FLAG)
      z80->PC=_z80_Get_PC2(z80);
     else
      i=_z80_Get_PC2(z80);
  }

void _z80_PE3(struct Z80CPU *z80)                         /* EX (SP),HL */
  {
    word i;
    i=_z80_Fetch2(z80,z80->SP);
    _z80_Store2(z80,z80->SP,z80->HL.HL);
    z80->HL.HL=i;
    z80->ts+=3;
  }

void _z80_PE4(struct Z80CPU *z80)                         /* CALL PO,nn */
  {
    word i;
    if ((z80->AF.AFu.F & OVERFLOW_FLAG) != OVERFLOW_FLAG)
      {
        _z80_Push2(z80,z80->PC+2);
        z80->PC=_z80_Get_PC2(z80);
        z80->ts++;
      }
     else
      i=_z80_Get_PC2(z80);
  }

void _z80_PE5(struct Z80CPU *z80)                         /* PUSH HL */
  {
    _z80_Push2(z80,z80->HL.HL);
    z80->ts++;
  }

void _z80_PE6(struct Z80CPU *z80)                         /* AND n */
  {
    _z80_And_8(z80,&z80->AF.AFu.A,_z80_Get_PC(z80));
  }

void _z80_PE7(struct Z80CPU *z80)                         /* RST 20H */
  {
    _z80_Push2(z80,z80->PC);
    z80->PC=0x20;
    z80->ts++;
  }

void _z80_PE8(struct Z80CPU *z80)                         /* RET PE */
  {
    z80->ts++;
    if ((z80->AF.AFu.F & OVERFLOW_FLAG) == OVERFLOW_FLAG)
      z80->PC=_z80_Pop2(z80);
  }

void _z80_PE9(struct Z80CPU *z80)                         /* JP (HL) */
  {
    z80->PC=z80->HL.HL;
  }

void _z80_PEA(struct Z80CPU *z80)                         /* JP PE,nn */
 {
   word i;
   if ((z80->AF.AFu.F & OVERFLOW_FLAG) == OVERFLOW_FLAG)
     z80->PC=_z80_Get_PC2(z80);
    else
     i=_z80_Get_PC2(z80);
 }

void _z80_PEB(struct Z80CPU *z80)                         /* EX DE,HL */
  {
    word i;
    i=z80->DE.DE;
    z80->DE.DE=z80->HL.HL;
    z80->HL.HL=i;
  }

void _z80_PEC(struct Z80CPU *z80)                         /* CALL PE,nn */
  {
    word i;
    z80->ts++;
    if ((z80->AF.AFu.F & OVERFLOW_FLAG) == OVERFLOW_FLAG)
      {
        _z80_Push2(z80,z80->PC+2);
        z80->PC=_z80_Get_PC2(z80);
      }
     else
      i=_z80_Get_PC2(z80);
  }

void _z80_PEE(struct Z80CPU *z80)                         /* XOR n */
  {
    _z80_XOr_8(z80,&z80->AF.AFu.A,_z80_Get_PC(z80));
  }

void _z80_PEF(struct Z80CPU *z80)                         /* RST 28H */
  { 
    z80->ts++;
    _z80_Push2(z80,z80->PC);
    z80->PC=0x28;
  }

void _z80_PF0(struct Z80CPU *z80)                         /* RET P */
  {
    z80->ts++;
    if ((z80->AF.AFu.F & SIGN_FLAG) == 0)
      z80->PC=_z80_Pop2(z80);
  }

void _z80_PF1(struct Z80CPU *z80)                         /* POP AF */
  {
    z80->AF.AF=_z80_Pop2(z80);
  }

void _z80_PF2(struct Z80CPU *z80)                         /* JP P,nn */
  {
    word i;
    if ((z80->AF.AFu.F & SIGN_FLAG) == 0)
      z80->PC=_z80_Get_PC2(z80);
     else
      i=_z80_Get_PC2(z80);
  }

void _z80_PF3(struct Z80CPU *z80)                         /* DI */
  {
    z80->IE=0;
    z80->IE2=0;
  }

void _z80_PF4(struct Z80CPU *z80)                         /* CALL P,nn */
  {
    word i;
    if ((z80->AF.AFu.F & SIGN_FLAG) == 0)
      {
        _z80_Push2(z80,z80->PC+2);
        z80->PC=_z80_Get_PC2(z80);
        z80->ts++;
      }
     else
      i=_z80_Get_PC2(z80);
  }

void _z80_PF5(struct Z80CPU *z80)                         /* PUSH AF */
  {
    _z80_Push2(z80,z80->AF.AF);
    z80->ts++;
  }

void _z80_PF6(struct Z80CPU *z80)                         /* OR a */
  {
    _z80_Or_8(z80,&z80->AF.AFu.A,_z80_Get_PC(z80));
  }

void _z80_PF7(struct Z80CPU *z80)                         /* RST 30H */
  {
    _z80_Push2(z80,z80->PC);
    z80->PC=0x30;
    z80->ts++;
  }

void _z80_PF8(struct Z80CPU *z80)                         /* RET M */
  {
    z80->ts++;
    if ((z80->AF.AFu.F & SIGN_FLAG) == SIGN_FLAG)
      z80->PC=_z80_Pop2(z80);
  }

void _z80_PF9(struct Z80CPU *z80)                         /* LD SP,HL */
  {
    z80->SP=z80->HL.HL;
    z80->ts+=2;
  }

void _z80_PFA(struct Z80CPU *z80)                         /* JP M,nn */
  {
    word i;
    if ((z80->AF.AFu.F & SIGN_FLAG) == SIGN_FLAG)
      z80->PC=_z80_Get_PC2(z80);
     else
      i=_z80_Get_PC2(z80);
  }

void _z80_PFB(struct Z80CPU *z80)                         /* EI */
  {
    z80->IE=1;
    z80->IE2=1;
  }

void _z80_PFC(struct Z80CPU *z80)                         /* CALL M,nn */
  {
    word i;
    if ((z80->AF.AFu.F & SIGN_FLAG) == SIGN_FLAG)
      {
        _z80_Push2(z80,z80->PC+2);
        z80->PC=_z80_Get_PC2(z80);
        z80->ts++;
      }
     else
      i=_z80_Get_PC2(z80);
  }

void _z80_PFE(struct Z80CPU *z80)                         /* CP n */
  {
    _z80_Cmp_8(z80,&z80->AF.AFu.A,_z80_Get_PC(z80));
  }

void _z80_PFF(struct Z80CPU *z80)                         /* RST 38H */
  {
    _z80_Push2(z80,z80->PC);
    z80->PC=0x38;
    z80->ts++;
  }

void _z80_prepare1Byte(struct Z80CPU *z80) {
  z80->I1Byte[0x00]=_z80_P0; z80->I1Byte[0x01]=_z80_P1; z80->I1Byte[0x02]=_z80_P2; z80->I1Byte[0x03]=_z80_P3;
  z80->I1Byte[0x04]=_z80_P4; z80->I1Byte[0x05]=_z80_P5; z80->I1Byte[0x06]=_z80_P6; z80->I1Byte[0x07]=_z80_P7;
  z80->I1Byte[0x08]=_z80_P8; z80->I1Byte[0x09]=_z80_P9; z80->I1Byte[0x0a]=_z80_PA; z80->I1Byte[0x0b]=_z80_PB;
  z80->I1Byte[0x0c]=_z80_PC; z80->I1Byte[0x0d]=_z80_PD; z80->I1Byte[0x0e]=_z80_PE; z80->I1Byte[0x0f]=_z80_PF;

  z80->I1Byte[0x10]=_z80_P10; z80->I1Byte[0x11]=_z80_P11; z80->I1Byte[0x12]=_z80_P12; z80->I1Byte[0x13]=_z80_P13;
  z80->I1Byte[0x14]=_z80_P14; z80->I1Byte[0x15]=_z80_P15; z80->I1Byte[0x16]=_z80_P16; z80->I1Byte[0x17]=_z80_P17;
  z80->I1Byte[0x18]=_z80_P18; z80->I1Byte[0x19]=_z80_P19; z80->I1Byte[0x1a]=_z80_P1A; z80->I1Byte[0x1b]=_z80_P1B;
  z80->I1Byte[0x1c]=_z80_P1C; z80->I1Byte[0x1d]=_z80_P1D; z80->I1Byte[0x1e]=_z80_P1E; z80->I1Byte[0x1f]=_z80_P1F;

  z80->I1Byte[0x20]=_z80_P20; z80->I1Byte[0x21]=_z80_P21; z80->I1Byte[0x22]=_z80_P22; z80->I1Byte[0x23]=_z80_P23;
  z80->I1Byte[0x24]=_z80_P24; z80->I1Byte[0x25]=_z80_P25; z80->I1Byte[0x26]=_z80_P26; z80->I1Byte[0x27]=_z80_P27;
  z80->I1Byte[0x28]=_z80_P28; z80->I1Byte[0x29]=_z80_P29; z80->I1Byte[0x2a]=_z80_P2A; z80->I1Byte[0x2b]=_z80_P2B;
  z80->I1Byte[0x2c]=_z80_P2C; z80->I1Byte[0x2d]=_z80_P2D; z80->I1Byte[0x2e]=_z80_P2E; z80->I1Byte[0x2f]=_z80_P2F;

  z80->I1Byte[0x30]=_z80_P30; z80->I1Byte[0x31]=_z80_P31; z80->I1Byte[0x32]=_z80_P32; z80->I1Byte[0x33]=_z80_P33;
  z80->I1Byte[0x34]=_z80_P34; z80->I1Byte[0x35]=_z80_P35; z80->I1Byte[0x36]=_z80_P36; z80->I1Byte[0x37]=_z80_P37;
  z80->I1Byte[0x38]=_z80_P38; z80->I1Byte[0x39]=_z80_P39; z80->I1Byte[0x3a]=_z80_P3A; z80->I1Byte[0x3b]=_z80_P3B;
  z80->I1Byte[0x3c]=_z80_P3C; z80->I1Byte[0x3d]=_z80_P3D; z80->I1Byte[0x3e]=_z80_P3E; z80->I1Byte[0x3f]=_z80_P3F;

  z80->I1Byte[0x40]=_z80_P40; z80->I1Byte[0x41]=_z80_P41; z80->I1Byte[0x42]=_z80_P42; z80->I1Byte[0x43]=_z80_P43;
  z80->I1Byte[0x44]=_z80_P44; z80->I1Byte[0x45]=_z80_P45; z80->I1Byte[0x46]=_z80_P46; z80->I1Byte[0x47]=_z80_P47;
  z80->I1Byte[0x48]=_z80_P48; z80->I1Byte[0x49]=_z80_P49; z80->I1Byte[0x4a]=_z80_P4A; z80->I1Byte[0x4b]=_z80_P4B;
  z80->I1Byte[0x4c]=_z80_P4C; z80->I1Byte[0x4d]=_z80_P4D; z80->I1Byte[0x4e]=_z80_P4E; z80->I1Byte[0x4f]=_z80_P4F;

  z80->I1Byte[0x50]=_z80_P50; z80->I1Byte[0x51]=_z80_P51; z80->I1Byte[0x52]=_z80_P52; z80->I1Byte[0x53]=_z80_P53;
  z80->I1Byte[0x54]=_z80_P54; z80->I1Byte[0x55]=_z80_P55; z80->I1Byte[0x56]=_z80_P56; z80->I1Byte[0x57]=_z80_P57;
  z80->I1Byte[0x58]=_z80_P58; z80->I1Byte[0x59]=_z80_P59; z80->I1Byte[0x5a]=_z80_P5A; z80->I1Byte[0x5b]=_z80_P5B;
  z80->I1Byte[0x5c]=_z80_P5C; z80->I1Byte[0x5d]=_z80_P5D; z80->I1Byte[0x5e]=_z80_P5E; z80->I1Byte[0x5f]=_z80_P5F;

  z80->I1Byte[0x60]=_z80_P60; z80->I1Byte[0x61]=_z80_P61; z80->I1Byte[0x62]=_z80_P62; z80->I1Byte[0x63]=_z80_P63;
  z80->I1Byte[0x64]=_z80_P64; z80->I1Byte[0x65]=_z80_P65; z80->I1Byte[0x66]=_z80_P66; z80->I1Byte[0x67]=_z80_P67;
  z80->I1Byte[0x68]=_z80_P68; z80->I1Byte[0x69]=_z80_P69; z80->I1Byte[0x6a]=_z80_P6A; z80->I1Byte[0x6b]=_z80_P6B;
  z80->I1Byte[0x6c]=_z80_P6C; z80->I1Byte[0x6d]=_z80_P6D; z80->I1Byte[0x6e]=_z80_P6E; z80->I1Byte[0x6f]=_z80_P6F;

  z80->I1Byte[0x70]=_z80_P70; z80->I1Byte[0x71]=_z80_P71; z80->I1Byte[0x72]=_z80_P72; z80->I1Byte[0x73]=_z80_P73;
  z80->I1Byte[0x74]=_z80_P74; z80->I1Byte[0x75]=_z80_P75; z80->I1Byte[0x76]=_z80_P76; z80->I1Byte[0x77]=_z80_P77;
  z80->I1Byte[0x78]=_z80_P78; z80->I1Byte[0x79]=_z80_P79; z80->I1Byte[0x7a]=_z80_P7A; z80->I1Byte[0x7b]=_z80_P7B;
  z80->I1Byte[0x7c]=_z80_P7C; z80->I1Byte[0x7d]=_z80_P7D; z80->I1Byte[0x7e]=_z80_P7E; z80->I1Byte[0x7f]=_z80_P7F;

  z80->I1Byte[0x80]=_z80_P80; z80->I1Byte[0x81]=_z80_P81; z80->I1Byte[0x82]=_z80_P82; z80->I1Byte[0x83]=_z80_P83;
  z80->I1Byte[0x84]=_z80_P84; z80->I1Byte[0x85]=_z80_P85; z80->I1Byte[0x86]=_z80_P86; z80->I1Byte[0x87]=_z80_P87;
  z80->I1Byte[0x88]=_z80_P88; z80->I1Byte[0x89]=_z80_P89; z80->I1Byte[0x8a]=_z80_P8A; z80->I1Byte[0x8b]=_z80_P8B;
  z80->I1Byte[0x8c]=_z80_P8C; z80->I1Byte[0x8d]=_z80_P8D; z80->I1Byte[0x8e]=_z80_P8E; z80->I1Byte[0x8f]=_z80_P8F;

  z80->I1Byte[0x90]=_z80_P90; z80->I1Byte[0x91]=_z80_P91; z80->I1Byte[0x92]=_z80_P92; z80->I1Byte[0x93]=_z80_P93;
  z80->I1Byte[0x94]=_z80_P94; z80->I1Byte[0x95]=_z80_P95; z80->I1Byte[0x96]=_z80_P96; z80->I1Byte[0x97]=_z80_P97;
  z80->I1Byte[0x98]=_z80_P98; z80->I1Byte[0x99]=_z80_P99; z80->I1Byte[0x9a]=_z80_P9A; z80->I1Byte[0x9b]=_z80_P9B;
  z80->I1Byte[0x9c]=_z80_P9C; z80->I1Byte[0x9d]=_z80_P9D; z80->I1Byte[0x9e]=_z80_P9E; z80->I1Byte[0x9f]=_z80_P9F;

  z80->I1Byte[0xa0]=_z80_PA0; z80->I1Byte[0xa1]=_z80_PA1; z80->I1Byte[0xa2]=_z80_PA2; z80->I1Byte[0xa3]=_z80_PA3;
  z80->I1Byte[0xa4]=_z80_PA4; z80->I1Byte[0xa5]=_z80_PA5; z80->I1Byte[0xa6]=_z80_PA6; z80->I1Byte[0xa7]=_z80_PA7;
  z80->I1Byte[0xa8]=_z80_PA8; z80->I1Byte[0xa9]=_z80_PA9; z80->I1Byte[0xaa]=_z80_PAA; z80->I1Byte[0xab]=_z80_PAB;
  z80->I1Byte[0xac]=_z80_PAC; z80->I1Byte[0xad]=_z80_PAD; z80->I1Byte[0xae]=_z80_PAE; z80->I1Byte[0xaf]=_z80_PAF;

  z80->I1Byte[0xb0]=_z80_PB0; z80->I1Byte[0xb1]=_z80_PB1; z80->I1Byte[0xb2]=_z80_PB2; z80->I1Byte[0xb3]=_z80_PB3;
  z80->I1Byte[0xb4]=_z80_PB4; z80->I1Byte[0xb5]=_z80_PB5; z80->I1Byte[0xb6]=_z80_PB6; z80->I1Byte[0xb7]=_z80_PB7;
  z80->I1Byte[0xb8]=_z80_PB8; z80->I1Byte[0xb9]=_z80_PB9; z80->I1Byte[0xba]=_z80_PBA; z80->I1Byte[0xbb]=_z80_PBB;
  z80->I1Byte[0xbc]=_z80_PBC; z80->I1Byte[0xbd]=_z80_PBD; z80->I1Byte[0xbe]=_z80_PBE; z80->I1Byte[0xbf]=_z80_PBF;

  z80->I1Byte[0xc0]=_z80_PC0; z80->I1Byte[0xc1]=_z80_PC1; z80->I1Byte[0xc2]=_z80_PC2; z80->I1Byte[0xc3]=_z80_PC3;
  z80->I1Byte[0xc4]=_z80_PC4; z80->I1Byte[0xc5]=_z80_PC5; z80->I1Byte[0xc6]=_z80_PC6; z80->I1Byte[0xc7]=_z80_PC7;
  z80->I1Byte[0xc8]=_z80_PC8; z80->I1Byte[0xc9]=_z80_PC9; z80->I1Byte[0xca]=_z80_PCA; z80->I1Byte[0xcb]=_z80_WPCB;
  z80->I1Byte[0xcc]=_z80_PCC; z80->I1Byte[0xcd]=_z80_PCD; z80->I1Byte[0xce]=_z80_PCE; z80->I1Byte[0xcf]=_z80_PCF;

  z80->I1Byte[0xd0]=_z80_PD0; z80->I1Byte[0xd1]=_z80_PD1; z80->I1Byte[0xd2]=_z80_PD2; z80->I1Byte[0xd3]=_z80_PD3;
  z80->I1Byte[0xd4]=_z80_PD4; z80->I1Byte[0xd5]=_z80_PD5; z80->I1Byte[0xd6]=_z80_PD6; z80->I1Byte[0xd7]=_z80_PD7;
  z80->I1Byte[0xd8]=_z80_PD8; z80->I1Byte[0xd9]=_z80_PD9; z80->I1Byte[0xda]=_z80_PDA; z80->I1Byte[0xdb]=_z80_PDB;
  z80->I1Byte[0xdc]=_z80_PDC; z80->I1Byte[0xdd]=_z80_WPDD; z80->I1Byte[0xde]=_z80_PDE; z80->I1Byte[0xdf]=_z80_PDF;

  z80->I1Byte[0xe0]=_z80_PE0; z80->I1Byte[0xe1]=_z80_PE1; z80->I1Byte[0xe2]=_z80_PE2; z80->I1Byte[0xe3]=_z80_PE3;
  z80->I1Byte[0xe4]=_z80_PE4; z80->I1Byte[0xe5]=_z80_PE5; z80->I1Byte[0xe6]=_z80_PE6; z80->I1Byte[0xe7]=_z80_PE7;
  z80->I1Byte[0xe8]=_z80_PE8; z80->I1Byte[0xe9]=_z80_PE9; z80->I1Byte[0xea]=_z80_PEA; z80->I1Byte[0xeb]=_z80_PEB;
  z80->I1Byte[0xec]=_z80_PEC; z80->I1Byte[0xed]=_z80_WPED; z80->I1Byte[0xee]=_z80_PEE; z80->I1Byte[0xef]=_z80_PEF;

  z80->I1Byte[0xf0]=_z80_PF0; z80->I1Byte[0xf1]=_z80_PF1; z80->I1Byte[0xf2]=_z80_PF2; z80->I1Byte[0xf3]=_z80_PF3;
  z80->I1Byte[0xf4]=_z80_PF4; z80->I1Byte[0xf5]=_z80_PF5; z80->I1Byte[0xf6]=_z80_PF6; z80->I1Byte[0xf7]=_z80_PF7;
  z80->I1Byte[0xf8]=_z80_PF8; z80->I1Byte[0xf9]=_z80_PF9; z80->I1Byte[0xfa]=_z80_PFA; z80->I1Byte[0xfb]=_z80_PFB;
  z80->I1Byte[0xfc]=_z80_PFC; z80->I1Byte[0xfd]=_z80_WPFD; z80->I1Byte[0xfe]=_z80_PFE; z80->I1Byte[0xff]=_z80_PFF;
  }

