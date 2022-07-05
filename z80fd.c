#include "z80.h"

void _z80_F00(struct Z80CPU *z80) { }
void _z80_F01(struct Z80CPU *z80) { }
void _z80_F02(struct Z80CPU *z80) { }
void _z80_F03(struct Z80CPU *z80) { }
void _z80_F04(struct Z80CPU *z80) { }
void _z80_F05(struct Z80CPU *z80) { }
void _z80_F06(struct Z80CPU *z80) { }
void _z80_F07(struct Z80CPU *z80) { }
void _z80_F08(struct Z80CPU *z80) { }

void _z80_F09(struct Z80CPU *z80)                         /* ADD IY,BC */
  {
    _z80_Add_16(z80,&z80->IY,z80->BC.BC);
    z80->ts+=7;
  }

void _z80_F0A(struct Z80CPU *z80) { }
void _z80_F0B(struct Z80CPU *z80) { }
void _z80_F0C(struct Z80CPU *z80) { }
void _z80_F0D(struct Z80CPU *z80) { }
void _z80_F0E(struct Z80CPU *z80) { }
void _z80_F0F(struct Z80CPU *z80) { }
void _z80_F10(struct Z80CPU *z80) { }
void _z80_F11(struct Z80CPU *z80) { }
void _z80_F12(struct Z80CPU *z80) { }
void _z80_F13(struct Z80CPU *z80) { }
void _z80_F14(struct Z80CPU *z80) { }
void _z80_F15(struct Z80CPU *z80) { }
void _z80_F16(struct Z80CPU *z80) { }
void _z80_F17(struct Z80CPU *z80) { }
void _z80_F18(struct Z80CPU *z80) { }

void _z80_F19(struct Z80CPU *z80)                         /* ADD IY,DE */
  {
    _z80_Add_16(z80,&z80->IY,z80->DE.DE);
    z80->ts+=7;
  }

void _z80_F1A(struct Z80CPU *z80) { }
void _z80_F1B(struct Z80CPU *z80) { }
void _z80_F1C(struct Z80CPU *z80) { }
void _z80_F1D(struct Z80CPU *z80) { }
void _z80_F1E(struct Z80CPU *z80) { }
void _z80_F1F(struct Z80CPU *z80) { }
void _z80_F20(struct Z80CPU *z80) { }

void _z80_F21(struct Z80CPU *z80)                         /* LD IY,nn */
  {
    z80->IY=_z80_Get_PC2(z80);
  }

void _z80_F22(struct Z80CPU *z80)                         /* LD (nn),IY */
  {
    _z80_Store2(z80,_z80_Get_PC2(z80),z80->IY);
  }

void _z80_F23(struct Z80CPU *z80)                         /* INC IY */
  {
    z80->IY++;
    z80->ts+=2;
  }

void _z80_F24(struct Z80CPU *z80) { }
void _z80_F25(struct Z80CPU *z80) { }
void _z80_F26(struct Z80CPU *z80) { }
void _z80_F27(struct Z80CPU *z80) { }
void _z80_F28(struct Z80CPU *z80) { }

void _z80_F29(struct Z80CPU *z80)                         /* ADD IY,IY */
  {
    _z80_Add_16(z80,&z80->IY,z80->IY);
    z80->ts+=7;
  }

void _z80_F2A(struct Z80CPU *z80)                         /* LD IY,(nn) */
  {
    z80->IY=_z80_Fetch2(z80,_z80_Get_PC2(z80));
  }

void _z80_F2B(struct Z80CPU *z80)                         /* DEC IY */
  {
    z80->IY--;
    z80->ts+=2;
  }

void _z80_F2C(struct Z80CPU *z80) { }
void _z80_F2D(struct Z80CPU *z80) { }
void _z80_F2E(struct Z80CPU *z80) { }
void _z80_F2F(struct Z80CPU *z80) { }
void _z80_F30(struct Z80CPU *z80) { }
void _z80_F31(struct Z80CPU *z80) { }
void _z80_F32(struct Z80CPU *z80) { }
void _z80_F33(struct Z80CPU *z80) { }

void _z80_F34(struct Z80CPU *z80)                         /* INC (IY+d) */
  {
    _z80_Inc_Mem_8(z80,_z80_Offset(z80->IY,_z80_Get_PC(z80)));
    z80->ts+=6;
  }

void _z80_F35(struct Z80CPU *z80)                         /* DEC (IY+d) */
  {
    _z80_Dec_Mem_8(z80,_z80_Offset(z80->IY,_z80_Get_PC(z80)));
    z80->ts+=6;
  }

void _z80_F36(struct Z80CPU *z80)                         /* LD (IY+d),n */
  {
    byte d,n;
    d=_z80_Get_PC(z80);
    n=_z80_Get_PC(z80);
    _z80_Store(z80,_z80_Offset(z80->IY,d),n);
    z80->ts+=2;
  }

void _z80_F37(struct Z80CPU *z80) { }
void _z80_F38(struct Z80CPU *z80) { }

void _z80_F39(struct Z80CPU *z80)                         /* ADD IY,SP */
  {
    _z80_Add_16(z80,&z80->IY,z80->SP);
    z80->ts+=7;
  }

void _z80_F3A(struct Z80CPU *z80) { }
void _z80_F3B(struct Z80CPU *z80) { }
void _z80_F3C(struct Z80CPU *z80) { }
void _z80_F3D(struct Z80CPU *z80) { }
void _z80_F3E(struct Z80CPU *z80) { }
void _z80_F3F(struct Z80CPU *z80) { }
void _z80_F40(struct Z80CPU *z80) { }
void _z80_F41(struct Z80CPU *z80) { }
void _z80_F42(struct Z80CPU *z80) { }
void _z80_F43(struct Z80CPU *z80) { }
void _z80_F44(struct Z80CPU *z80) { }
void _z80_F45(struct Z80CPU *z80) { }

void _z80_F46(struct Z80CPU *z80)                         /* LD B,(IY+d) */
  {
    z80->BC.BCu.B=_z80_Fetch(z80,_z80_Offset(z80->IY,_z80_Get_PC(z80)));
    z80->ts+=5;
  }

void _z80_F47(struct Z80CPU *z80) { }
void _z80_F48(struct Z80CPU *z80) { }
void _z80_F49(struct Z80CPU *z80) { }
void _z80_F4A(struct Z80CPU *z80) { }
void _z80_F4B(struct Z80CPU *z80) { }
void _z80_F4C(struct Z80CPU *z80) { }
void _z80_F4D(struct Z80CPU *z80) { }

void _z80_F4E(struct Z80CPU *z80)                         /* LD C,(IY+d) */
  {
    byte d;
    d=_z80_Get_PC(z80);
    z80->BC.BCu.C=_z80_Fetch(z80,_z80_Offset(z80->IY,d));
    z80->ts+=5;
  }

void _z80_F4F(struct Z80CPU *z80) { }
void _z80_F50(struct Z80CPU *z80) { }
void _z80_F51(struct Z80CPU *z80) { }
void _z80_F52(struct Z80CPU *z80) { }
void _z80_F53(struct Z80CPU *z80) { }
void _z80_F54(struct Z80CPU *z80) { }
void _z80_F55(struct Z80CPU *z80) { }

void _z80_F56(struct Z80CPU *z80)                         /* LD D,(IY+d) */
  {
    z80->DE.DEu.D=_z80_Fetch(z80,_z80_Offset(z80->IY,_z80_Get_PC(z80)));
    z80->ts+=5;
  }

void _z80_F57(struct Z80CPU *z80) { }
void _z80_F58(struct Z80CPU *z80) { }
void _z80_F59(struct Z80CPU *z80) { }
void _z80_F5A(struct Z80CPU *z80) { }
void _z80_F5B(struct Z80CPU *z80) { }
void _z80_F5C(struct Z80CPU *z80) { }
void _z80_F5D(struct Z80CPU *z80) { }

void _z80_F5E(struct Z80CPU *z80)                         /* LD E,(IY+d) */
  {
    byte d;
    d=_z80_Get_PC(z80);
    z80->DE.DEu.E=_z80_Fetch(z80,_z80_Offset(z80->IY,d));
    z80->ts+=5;
  }

void _z80_F5F(struct Z80CPU *z80) { }
void _z80_F60(struct Z80CPU *z80) { }
void _z80_F61(struct Z80CPU *z80) { }
void _z80_F62(struct Z80CPU *z80) { }
void _z80_F63(struct Z80CPU *z80) { }
void _z80_F64(struct Z80CPU *z80) { }
void _z80_F65(struct Z80CPU *z80) { }

void _z80_F66(struct Z80CPU *z80)                         /* LD H,(IY+d) */
  {
    z80->HL.HLu.H=_z80_Fetch(z80,_z80_Offset(z80->IY,_z80_Get_PC(z80)));
    z80->ts+=5;
  }

void _z80_F67(struct Z80CPU *z80) { }
void _z80_F68(struct Z80CPU *z80) { }
void _z80_F69(struct Z80CPU *z80) { }
void _z80_F6A(struct Z80CPU *z80) { }
void _z80_F6B(struct Z80CPU *z80) { }
void _z80_F6C(struct Z80CPU *z80) { }
void _z80_F6D(struct Z80CPU *z80) { }

void _z80_F6E(struct Z80CPU *z80)                         /* LD L,(IY+d) */
  {
    z80->HL.HLu.L=_z80_Fetch(z80,_z80_Offset(z80->IY,_z80_Get_PC(z80)));
    z80->ts+=5;
  }

void _z80_F6F(struct Z80CPU *z80) { }

void _z80_F70(struct Z80CPU *z80)                         /* LD (IY+d),B */
  {
    byte d;
    d=_z80_Get_PC(z80);
    _z80_Store(z80,_z80_Offset(z80->IY,d),z80->BC.BCu.B);
    z80->ts+=5;
  }

void _z80_F71(struct Z80CPU *z80)                         /* LD (IY+d),C */
  {
    byte d;
    d=_z80_Get_PC(z80);
    _z80_Store(z80,_z80_Offset(z80->IY,d),z80->BC.BCu.C);
    z80->ts+=5;
  }

void _z80_F72(struct Z80CPU *z80)                         /* LD (IY+d),D */
  {
    _z80_Store(z80,_z80_Offset(z80->IY,_z80_Get_PC(z80)),z80->DE.DEu.D);
    z80->ts+=5;
  }

void _z80_F73(struct Z80CPU *z80)                         /* LD (IY+d),E */
  {
    _z80_Store(z80,_z80_Offset(z80->IY,_z80_Get_PC(z80)),z80->DE.DEu.E);
    z80->ts+=5;
  }

void _z80_F74(struct Z80CPU *z80)                         /* LD (IY+d),H */
  {
    _z80_Store(z80,_z80_Offset(z80->IY,_z80_Get_PC(z80)),z80->HL.HLu.H);
    z80->ts+=5;
  }

void _z80_F75(struct Z80CPU *z80)                         /* LD (IY+d),L */
  {
    _z80_Store(z80,_z80_Offset(z80->IY,_z80_Get_PC(z80)),z80->HL.HLu.L);
    z80->ts+=5;
  }

void _z80_F76(struct Z80CPU *z80) { }

void _z80_F77(struct Z80CPU *z80)                         /* LD (IY+d),A */
  {
    byte d;
    d=_z80_Get_PC(z80);
    _z80_Store(z80,_z80_Offset(z80->IY,d),z80->AF.AFu.A);
    z80->ts+=5;
  }

void _z80_F78(struct Z80CPU *z80) { }
void _z80_F79(struct Z80CPU *z80) { }
void _z80_F7A(struct Z80CPU *z80) { }
void _z80_F7B(struct Z80CPU *z80) { }
void _z80_F7C(struct Z80CPU *z80) { }
void _z80_F7D(struct Z80CPU *z80) { }

void _z80_F7E(struct Z80CPU *z80)                         /* LD A,(IY+d) */
  {
    byte d;
    d=_z80_Get_PC(z80);
    z80->AF.AFu.A=_z80_Fetch(z80,_z80_Offset(z80->IY,d));
    z80->ts+=5;
  }

void _z80_F7F(struct Z80CPU *z80) { }

void _z80_F80(struct Z80CPU *z80) { }
void _z80_F81(struct Z80CPU *z80) { }
void _z80_F82(struct Z80CPU *z80) { }
void _z80_F83(struct Z80CPU *z80) { }
void _z80_F84(struct Z80CPU *z80) { }
void _z80_F85(struct Z80CPU *z80) { }

void _z80_F86(struct Z80CPU *z80)                         /* ADD A,(IY+d) */
  {
    _z80_Add_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,_z80_Offset(z80->IY,_z80_Get_PC(z80))));
    z80->ts+=5;
  }

void _z80_F87(struct Z80CPU *z80) { }
void _z80_F88(struct Z80CPU *z80) { }
void _z80_F89(struct Z80CPU *z80) { }
void _z80_F8A(struct Z80CPU *z80) { }
void _z80_F8B(struct Z80CPU *z80) { }
void _z80_F8C(struct Z80CPU *z80) { }
void _z80_F8D(struct Z80CPU *z80) { }

void _z80_F8E(struct Z80CPU *z80)                         /* ADC A,(IY+d) */
  {
    _z80_Adc_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,_z80_Offset(z80->IY,_z80_Get_PC(z80))));
    z80->ts+=5;
  }

void _z80_F8F(struct Z80CPU *z80) { }
void _z80_F90(struct Z80CPU *z80) { }
void _z80_F91(struct Z80CPU *z80) { }
void _z80_F92(struct Z80CPU *z80) { }
void _z80_F93(struct Z80CPU *z80) { }
void _z80_F94(struct Z80CPU *z80) { }
void _z80_F95(struct Z80CPU *z80) { }

void _z80_F96(struct Z80CPU *z80)                         /* SUB A,(IY+d) */
  {
    _z80_Sub_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,_z80_Offset(z80->IY,_z80_Get_PC(z80))));
    z80->ts+=5;
  }

void _z80_F97(struct Z80CPU *z80) { }
void _z80_F98(struct Z80CPU *z80) { }
void _z80_F99(struct Z80CPU *z80) { }
void _z80_F9A(struct Z80CPU *z80) { }
void _z80_F9B(struct Z80CPU *z80) { }
void _z80_F9C(struct Z80CPU *z80) { }
void _z80_F9D(struct Z80CPU *z80) { }

void _z80_F9E(struct Z80CPU *z80)                         /* SBC A,(IY+d) */
  {
    _z80_Sbc_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,_z80_Offset(z80->IY,_z80_Get_PC(z80))));
    z80->ts+=5;
  }

void _z80_F9F(struct Z80CPU *z80) { }
void _z80_FA0(struct Z80CPU *z80) { }
void _z80_FA1(struct Z80CPU *z80) { }
void _z80_FA2(struct Z80CPU *z80) { }
void _z80_FA3(struct Z80CPU *z80) { }
void _z80_FA4(struct Z80CPU *z80) { }
void _z80_FA5(struct Z80CPU *z80) { }

void _z80_FA6(struct Z80CPU *z80)                         /* AND (IY+d) */
  {
    _z80_And_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,_z80_Offset(z80->IY,_z80_Get_PC(z80))));
    z80->ts+=5;
  }

void _z80_FA7(struct Z80CPU *z80) { }
void _z80_FA8(struct Z80CPU *z80) { }
void _z80_FA9(struct Z80CPU *z80) { }
void _z80_FAA(struct Z80CPU *z80) { }
void _z80_FAB(struct Z80CPU *z80) { }
void _z80_FAC(struct Z80CPU *z80) { }
void _z80_FAD(struct Z80CPU *z80) { }

void _z80_FAE(struct Z80CPU *z80)                         /* XOR (IY+d) */
  {
    _z80_XOr_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,_z80_Offset(z80->IY,_z80_Get_PC(z80))));
    z80->ts+=5;
  }

void _z80_FAF(struct Z80CPU *z80) { }
void _z80_FB0(struct Z80CPU *z80) { }
void _z80_FB1(struct Z80CPU *z80) { }
void _z80_FB2(struct Z80CPU *z80) { }
void _z80_FB3(struct Z80CPU *z80) { }
void _z80_FB4(struct Z80CPU *z80) { }
void _z80_FB5(struct Z80CPU *z80) { }

void _z80_FB6(struct Z80CPU *z80)                         /* OR (IY+d) */
  {
    _z80_Or_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,_z80_Offset(z80->IY,_z80_Get_PC(z80))));
    z80->ts+=5;
  }

void _z80_FB7(struct Z80CPU *z80) { }
void _z80_FB8(struct Z80CPU *z80) { }
void _z80_FB9(struct Z80CPU *z80) { }
void _z80_FBA(struct Z80CPU *z80) { }
void _z80_FBB(struct Z80CPU *z80) { }
void _z80_FBC(struct Z80CPU *z80) { }
void _z80_FBD(struct Z80CPU *z80) { }

void _z80_FBE(struct Z80CPU *z80)                         /* CP (IY+d) */
  {
    byte d;
    d=_z80_Get_PC(z80);
    _z80_Cmp_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,_z80_Offset(z80->IY,d)));
    z80->ts+=5;
  }

void _z80_FBF(struct Z80CPU *z80) { }

void _z80_FC0(struct Z80CPU *z80) { }
void _z80_FC1(struct Z80CPU *z80) { }
void _z80_FC2(struct Z80CPU *z80) { }
void _z80_FC3(struct Z80CPU *z80) { }
void _z80_FC4(struct Z80CPU *z80) { }
void _z80_FC5(struct Z80CPU *z80) { }
void _z80_FC6(struct Z80CPU *z80) { }
void _z80_FC7(struct Z80CPU *z80) { }
void _z80_FC8(struct Z80CPU *z80) { }
void _z80_FC9(struct Z80CPU *z80) { }
void _z80_FCA(struct Z80CPU *z80) { }

void _z80_FCB(struct Z80CPU *z80)
  {
    word Adr;
    byte Cmd;
    byte Wrk;
    Adr=_z80_Offset(z80->IY,_z80_Get_PC(z80));
    Cmd=_z80_Get_PC(z80);
    z80->ts+=3;
    if (Cmd<=0x07) {                   /* RLC */
      Wrk=_z80_rlc_byte(z80,_z80_Fetch(z80,Adr));
      _z80_Store(z80,Adr,Wrk);
      }
    else if (Cmd<=0x0f) {              /* RRC */
      Wrk=_z80_rrc_byte(z80,_z80_Fetch(z80,Adr));
      _z80_Store(z80,Adr,Wrk);
      }
    else if (Cmd<=0x17) {              /* RL */
      Wrk=_z80_rl_byte(z80,_z80_Fetch(z80,Adr));
      _z80_Store(z80,Adr,Wrk);
      }
    else if (Cmd<=0x1f) {              /* RR */
      Wrk=_z80_rr_byte(z80,_z80_Fetch(z80,Adr));
      _z80_Store(z80,Adr,Wrk);
      }
    else if (Cmd<=0x27) {              /* SLA */
      Wrk=_z80_sla_byte(z80,_z80_Fetch(z80,Adr));
      _z80_Store(z80,Adr,Wrk);
      }
    else if (Cmd<=0x2f) {              /* SRA */
      Wrk=_z80_sra_byte(z80,_z80_Fetch(z80,Adr));
      _z80_Store(z80,Adr,Wrk);
      }
    else if (Cmd<=0x3f) {              /* SRL */
      Wrk=_z80_srl_byte(z80,_z80_Fetch(z80,Adr));
      _z80_Store(z80,Adr,Wrk);
      }
    else if (Cmd<=0x7f) {              /* BIT */
      _z80_bit_byte(z80,Cmd,_z80_Fetch(z80,Adr),(Cmd>>3)&7);
      }
    else if (Cmd<=0xbf) {              /* RES */
      Wrk=_z80_Fetch(z80,Adr);
      Cmd=(Cmd>>3)&7;
      Cmd=1<<Cmd;
      Wrk=Wrk&(~Cmd);
      _z80_Store(z80,Adr,Wrk);
      }
    else {                             /* SET */
      Wrk=_z80_Fetch(z80,Adr);
      Cmd=(Cmd>>3)&7;
      Cmd=1<<Cmd;
      Wrk=Wrk|Cmd;
      _z80_Store(z80,Adr,Wrk);
      }
  }
          
void _z80_FCC(struct Z80CPU *z80) { }
void _z80_FCD(struct Z80CPU *z80) { }
void _z80_FCE(struct Z80CPU *z80) { }
void _z80_FCF(struct Z80CPU *z80) { }

void _z80_FD0(struct Z80CPU *z80) { }
void _z80_FD1(struct Z80CPU *z80) { }
void _z80_FD2(struct Z80CPU *z80) { }
void _z80_FD3(struct Z80CPU *z80) { }
void _z80_FD4(struct Z80CPU *z80) { }
void _z80_FD5(struct Z80CPU *z80) { }
void _z80_FD6(struct Z80CPU *z80) { }
void _z80_FD7(struct Z80CPU *z80) { }
void _z80_FD8(struct Z80CPU *z80) { }
void _z80_FD9(struct Z80CPU *z80) { }
void _z80_FDA(struct Z80CPU *z80) { }
void _z80_FDB(struct Z80CPU *z80) { }
void _z80_FDC(struct Z80CPU *z80) { }
void _z80_FDD(struct Z80CPU *z80) { }
void _z80_FDE(struct Z80CPU *z80) { }
void _z80_FDF(struct Z80CPU *z80) { }
void _z80_FE0(struct Z80CPU *z80) { }

void _z80_FE1(struct Z80CPU *z80)                         /* POP IY */
  {
    z80->IY=_z80_Pop2(z80);
  }

void _z80_FE2(struct Z80CPU *z80) { }

void _z80_FE3(struct Z80CPU *z80)                         /* EX (SP),IY */
  {
    word tmp;
    tmp=_z80_Fetch2(z80,z80->SP);
    _z80_Store2(z80,z80->SP,z80->IY);
    z80->IY=tmp;
    z80->ts+=3;
  }

void _z80_FE4(struct Z80CPU *z80) { }

void _z80_FE5(struct Z80CPU *z80)                         /* PUSH IY */
  {
    _z80_Push2(z80,z80->IY);
    z80->ts++;
  }

void _z80_FE6(struct Z80CPU *z80) { }
void _z80_FE7(struct Z80CPU *z80) { }
void _z80_FE8(struct Z80CPU *z80) { }

void _z80_FE9(struct Z80CPU *z80)                         /* JP (IY) */
  {
    z80->PC=z80->IY;
  }

void _z80_FEA(struct Z80CPU *z80) { }
void _z80_FEB(struct Z80CPU *z80) { }
void _z80_FEC(struct Z80CPU *z80) { }
void _z80_FED(struct Z80CPU *z80) { }
void _z80_FEE(struct Z80CPU *z80) { }
void _z80_FEF(struct Z80CPU *z80) { }
void _z80_FF0(struct Z80CPU *z80) { }
void _z80_FF1(struct Z80CPU *z80) { }
void _z80_FF2(struct Z80CPU *z80) { }
void _z80_FF3(struct Z80CPU *z80) { }
void _z80_FF4(struct Z80CPU *z80) { }
void _z80_FF5(struct Z80CPU *z80) { }
void _z80_FF6(struct Z80CPU *z80) { }
void _z80_FF7(struct Z80CPU *z80) { }
void _z80_FF8(struct Z80CPU *z80) { }

void _z80_FF9(struct Z80CPU *z80)                         /* LD SP,IY */
  {
    z80->SP=z80->IY;
    z80->ts+=2;
  }

void _z80_FFA(struct Z80CPU *z80) { }
void _z80_FFB(struct Z80CPU *z80) { }
void _z80_FFC(struct Z80CPU *z80) { }
void _z80_FFD(struct Z80CPU *z80) { }
void _z80_FFE(struct Z80CPU *z80) { }
void _z80_FFF(struct Z80CPU *z80) { }

void _z80_PFD(struct Z80CPU *z80)
  {
    byte bt;
    bt=_z80_Get_PC(z80);
    z80->ts++;
#ifdef HIST
    hist[4][bt]='*';
#endif
    z80->IFD[bt](z80);
  }


void _z80_prepareFD(struct Z80CPU *z80) {
  z80->IFD[0x00]=_z80_F00; z80->IFD[0x01]=_z80_F01; z80->IFD[0x02]=_z80_F02; z80->IFD[0x03]=_z80_F03;
  z80->IFD[0x04]=_z80_F04; z80->IFD[0x05]=_z80_F05; z80->IFD[0x06]=_z80_F06; z80->IFD[0x07]=_z80_F07;
  z80->IFD[0x08]=_z80_F08; z80->IFD[0x09]=_z80_F09; z80->IFD[0x0a]=_z80_F0A; z80->IFD[0x0b]=_z80_F0B;
  z80->IFD[0x0c]=_z80_F0C; z80->IFD[0x0d]=_z80_F0D; z80->IFD[0x0e]=_z80_F0E; z80->IFD[0x0f]=_z80_F0F;

  z80->IFD[0x10]=_z80_F10; z80->IFD[0x11]=_z80_F11; z80->IFD[0x12]=_z80_F12; z80->IFD[0x13]=_z80_F13;
  z80->IFD[0x14]=_z80_F14; z80->IFD[0x15]=_z80_F15; z80->IFD[0x16]=_z80_F16; z80->IFD[0x17]=_z80_F17;
  z80->IFD[0x18]=_z80_F18; z80->IFD[0x19]=_z80_F19; z80->IFD[0x1a]=_z80_F1A; z80->IFD[0x1b]=_z80_F1B;
  z80->IFD[0x1c]=_z80_F1C; z80->IFD[0x1d]=_z80_F1D; z80->IFD[0x1e]=_z80_F1E; z80->IFD[0x1f]=_z80_F1F;

  z80->IFD[0x20]=_z80_F20; z80->IFD[0x21]=_z80_F21; z80->IFD[0x22]=_z80_F22; z80->IFD[0x23]=_z80_F23;
  z80->IFD[0x24]=_z80_F24; z80->IFD[0x25]=_z80_F25; z80->IFD[0x26]=_z80_F26; z80->IFD[0x27]=_z80_F27;
  z80->IFD[0x28]=_z80_F28; z80->IFD[0x29]=_z80_F29; z80->IFD[0x2a]=_z80_F2A; z80->IFD[0x2b]=_z80_F2B;
  z80->IFD[0x2c]=_z80_F2C; z80->IFD[0x2d]=_z80_F2D; z80->IFD[0x2e]=_z80_F2E; z80->IFD[0x2f]=_z80_F2F;

  z80->IFD[0x30]=_z80_F30; z80->IFD[0x31]=_z80_F31; z80->IFD[0x32]=_z80_F32; z80->IFD[0x33]=_z80_F33;
  z80->IFD[0x34]=_z80_F34; z80->IFD[0x35]=_z80_F35; z80->IFD[0x36]=_z80_F36; z80->IFD[0x37]=_z80_F37;
  z80->IFD[0x38]=_z80_F38; z80->IFD[0x39]=_z80_F39; z80->IFD[0x3a]=_z80_F3A; z80->IFD[0x3b]=_z80_F3B;
  z80->IFD[0x3c]=_z80_F3C; z80->IFD[0x3d]=_z80_F3D; z80->IFD[0x3e]=_z80_F3E; z80->IFD[0x3f]=_z80_F3F;

  z80->IFD[0x40]=_z80_F40; z80->IFD[0x41]=_z80_F41; z80->IFD[0x42]=_z80_F42; z80->IFD[0x43]=_z80_F43;
  z80->IFD[0x44]=_z80_F44; z80->IFD[0x45]=_z80_F45; z80->IFD[0x46]=_z80_F46; z80->IFD[0x47]=_z80_F47;
  z80->IFD[0x48]=_z80_F48; z80->IFD[0x49]=_z80_F49; z80->IFD[0x4a]=_z80_F4A; z80->IFD[0x4b]=_z80_F4B;
  z80->IFD[0x4c]=_z80_F4C; z80->IFD[0x4d]=_z80_F4D; z80->IFD[0x4e]=_z80_F4E; z80->IFD[0x4f]=_z80_F4F;

  z80->IFD[0x50]=_z80_F50; z80->IFD[0x51]=_z80_F51; z80->IFD[0x52]=_z80_F52; z80->IFD[0x53]=_z80_F53;
  z80->IFD[0x54]=_z80_F54; z80->IFD[0x55]=_z80_F55; z80->IFD[0x56]=_z80_F56; z80->IFD[0x57]=_z80_F57;
  z80->IFD[0x58]=_z80_F58; z80->IFD[0x59]=_z80_F59; z80->IFD[0x5a]=_z80_F5A; z80->IFD[0x5b]=_z80_F5B;
  z80->IFD[0x5c]=_z80_F5C; z80->IFD[0x5d]=_z80_F5D; z80->IFD[0x5e]=_z80_F5E; z80->IFD[0x5f]=_z80_F5F;

  z80->IFD[0x60]=_z80_F60; z80->IFD[0x61]=_z80_F61; z80->IFD[0x62]=_z80_F62; z80->IFD[0x63]=_z80_F63;
  z80->IFD[0x64]=_z80_F64; z80->IFD[0x65]=_z80_F65; z80->IFD[0x66]=_z80_F66; z80->IFD[0x67]=_z80_F67;
  z80->IFD[0x68]=_z80_F68; z80->IFD[0x69]=_z80_F69; z80->IFD[0x6a]=_z80_F6A; z80->IFD[0x6b]=_z80_F6B;
  z80->IFD[0x6c]=_z80_F6C; z80->IFD[0x6d]=_z80_F6D; z80->IFD[0x6e]=_z80_F6E; z80->IFD[0x6f]=_z80_F6F;

  z80->IFD[0x70]=_z80_F70; z80->IFD[0x71]=_z80_F71; z80->IFD[0x72]=_z80_F72; z80->IFD[0x73]=_z80_F73;
  z80->IFD[0x74]=_z80_F74; z80->IFD[0x75]=_z80_F75; z80->IFD[0x76]=_z80_F76; z80->IFD[0x77]=_z80_F77;
  z80->IFD[0x78]=_z80_F78; z80->IFD[0x79]=_z80_F79; z80->IFD[0x7a]=_z80_F7A; z80->IFD[0x7b]=_z80_F7B;
  z80->IFD[0x7c]=_z80_F7C; z80->IFD[0x7d]=_z80_F7D; z80->IFD[0x7e]=_z80_F7E; z80->IFD[0x7f]=_z80_F7F;

  z80->IFD[0x80]=_z80_F80; z80->IFD[0x81]=_z80_F81; z80->IFD[0x82]=_z80_F82; z80->IFD[0x83]=_z80_F83;
  z80->IFD[0x84]=_z80_F84; z80->IFD[0x85]=_z80_F85; z80->IFD[0x86]=_z80_F86; z80->IFD[0x87]=_z80_F87;
  z80->IFD[0x88]=_z80_F88; z80->IFD[0x89]=_z80_F89; z80->IFD[0x8a]=_z80_F8A; z80->IFD[0x8b]=_z80_F8B;
  z80->IFD[0x8c]=_z80_F8C; z80->IFD[0x8d]=_z80_F8D; z80->IFD[0x8e]=_z80_F8E; z80->IFD[0x8f]=_z80_F8F;

  z80->IFD[0x90]=_z80_F90; z80->IFD[0x91]=_z80_F91; z80->IFD[0x92]=_z80_F92; z80->IFD[0x93]=_z80_F93;
  z80->IFD[0x94]=_z80_F94; z80->IFD[0x95]=_z80_F95; z80->IFD[0x96]=_z80_F96; z80->IFD[0x97]=_z80_F97;
  z80->IFD[0x98]=_z80_F98; z80->IFD[0x99]=_z80_F99; z80->IFD[0x9a]=_z80_F9A; z80->IFD[0x9b]=_z80_F9B;
  z80->IFD[0x9c]=_z80_F9C; z80->IFD[0x9d]=_z80_F9D; z80->IFD[0x9e]=_z80_F9E; z80->IFD[0x9f]=_z80_F9F;

  z80->IFD[0xa0]=_z80_FA0; z80->IFD[0xa1]=_z80_FA1; z80->IFD[0xa2]=_z80_FA2; z80->IFD[0xa3]=_z80_FA3;
  z80->IFD[0xa4]=_z80_FA4; z80->IFD[0xa5]=_z80_FA5; z80->IFD[0xa6]=_z80_FA6; z80->IFD[0xa7]=_z80_FA7;
  z80->IFD[0xa8]=_z80_FA8; z80->IFD[0xa9]=_z80_FA9; z80->IFD[0xaa]=_z80_FAA; z80->IFD[0xab]=_z80_FAB;
  z80->IFD[0xac]=_z80_FAC; z80->IFD[0xad]=_z80_FAD; z80->IFD[0xae]=_z80_FAE; z80->IFD[0xaf]=_z80_FAF;

  z80->IFD[0xb0]=_z80_FB0; z80->IFD[0xb1]=_z80_FB1; z80->IFD[0xb2]=_z80_FB2; z80->IFD[0xb3]=_z80_FB3;
  z80->IFD[0xb4]=_z80_FB4; z80->IFD[0xb5]=_z80_FB5; z80->IFD[0xb6]=_z80_FB6; z80->IFD[0xb7]=_z80_FB7;
  z80->IFD[0xb8]=_z80_FB8; z80->IFD[0xb9]=_z80_FB9; z80->IFD[0xba]=_z80_FBA; z80->IFD[0xbb]=_z80_FBB;
  z80->IFD[0xbc]=_z80_FBC; z80->IFD[0xbd]=_z80_FBD; z80->IFD[0xbe]=_z80_FBE; z80->IFD[0xbf]=_z80_FBF;

  z80->IFD[0xc0]=_z80_FC0; z80->IFD[0xc1]=_z80_FC1; z80->IFD[0xc2]=_z80_FC2; z80->IFD[0xc3]=_z80_FC3;
  z80->IFD[0xc4]=_z80_FC4; z80->IFD[0xc5]=_z80_FC5; z80->IFD[0xc6]=_z80_FC6; z80->IFD[0xc7]=_z80_FC7;
  z80->IFD[0xc8]=_z80_FC8; z80->IFD[0xc9]=_z80_FC9; z80->IFD[0xca]=_z80_FCA; z80->IFD[0xcb]=_z80_FCB;
  z80->IFD[0xcc]=_z80_FCC; z80->IFD[0xcd]=_z80_FCD; z80->IFD[0xce]=_z80_FCE; z80->IFD[0xcf]=_z80_FCF;

  z80->IFD[0xd0]=_z80_FD0; z80->IFD[0xd1]=_z80_FD1; z80->IFD[0xd2]=_z80_FD2; z80->IFD[0xd3]=_z80_FD3;
  z80->IFD[0xd4]=_z80_FD4; z80->IFD[0xd5]=_z80_FD5; z80->IFD[0xd6]=_z80_FD6; z80->IFD[0xd7]=_z80_FD7;
  z80->IFD[0xd8]=_z80_FD8; z80->IFD[0xd9]=_z80_FD9; z80->IFD[0xda]=_z80_FDA; z80->IFD[0xdb]=_z80_FDB;
  z80->IFD[0xdc]=_z80_FDC; z80->IFD[0xdd]=_z80_FDD; z80->IFD[0xde]=_z80_FDE; z80->IFD[0xdf]=_z80_FDF;

  z80->IFD[0xe0]=_z80_FE0; z80->IFD[0xe1]=_z80_FE1; z80->IFD[0xe2]=_z80_FE2; z80->IFD[0xe3]=_z80_FE3;
  z80->IFD[0xe4]=_z80_FE4; z80->IFD[0xe5]=_z80_FE5; z80->IFD[0xe6]=_z80_FE6; z80->IFD[0xe7]=_z80_FE7;
  z80->IFD[0xe8]=_z80_FE8; z80->IFD[0xe9]=_z80_FE9; z80->IFD[0xea]=_z80_FEA; z80->IFD[0xeb]=_z80_FEB;
  z80->IFD[0xec]=_z80_FEC; z80->IFD[0xed]=_z80_FED; z80->IFD[0xee]=_z80_FEE; z80->IFD[0xef]=_z80_FEF;

  z80->IFD[0xf0]=_z80_FF0; z80->IFD[0xf1]=_z80_FF1; z80->IFD[0xf2]=_z80_FF2; z80->IFD[0xf3]=_z80_FF3;
  z80->IFD[0xf4]=_z80_FF4; z80->IFD[0xf5]=_z80_FF5; z80->IFD[0xf6]=_z80_FF6; z80->IFD[0xf7]=_z80_FF7;
  z80->IFD[0xf8]=_z80_FF8; z80->IFD[0xf9]=_z80_FF9; z80->IFD[0xfa]=_z80_FFA; z80->IFD[0xfb]=_z80_FFB;
  z80->IFD[0xfc]=_z80_FFC; z80->IFD[0xfd]=_z80_FFD; z80->IFD[0xfe]=_z80_FFE; z80->IFD[0xff]=_z80_FFF;
  }

