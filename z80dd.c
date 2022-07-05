#include "z80.h"

void _z80_D00(struct Z80CPU *z80) { }
void _z80_D01(struct Z80CPU *z80) { }
void _z80_D02(struct Z80CPU *z80) { }
void _z80_D03(struct Z80CPU *z80) { }
void _z80_D04(struct Z80CPU *z80) { }
void _z80_D05(struct Z80CPU *z80) { }
void _z80_D06(struct Z80CPU *z80) { }
void _z80_D07(struct Z80CPU *z80) { }
void _z80_D08(struct Z80CPU *z80) { }

void _z80_D09(struct Z80CPU *z80)                         /* ADD IX,BC */
  {
    _z80_Add_16(z80,&z80->IX,z80->BC.BC);
    z80->ts+=7;
  }

void _z80_D0A(struct Z80CPU *z80) { }
void _z80_D0B(struct Z80CPU *z80) { }
void _z80_D0C(struct Z80CPU *z80) { }
void _z80_D0D(struct Z80CPU *z80) { }
void _z80_D0E(struct Z80CPU *z80) { }
void _z80_D0F(struct Z80CPU *z80) { }
void _z80_D10(struct Z80CPU *z80) { }
void _z80_D11(struct Z80CPU *z80) { }
void _z80_D12(struct Z80CPU *z80) { }
void _z80_D13(struct Z80CPU *z80) { }
void _z80_D14(struct Z80CPU *z80) { }
void _z80_D15(struct Z80CPU *z80) { }
void _z80_D16(struct Z80CPU *z80) { }
void _z80_D17(struct Z80CPU *z80) { }
void _z80_D18(struct Z80CPU *z80) { }

void _z80_D19(struct Z80CPU *z80)                         /* ADD IX,DE */
  {
    _z80_Add_16(z80,&z80->IX,z80->DE.DE);
    z80->ts+=7;
  }

void _z80_D1A(struct Z80CPU *z80) { }
void _z80_D1B(struct Z80CPU *z80) { }
void _z80_D1C(struct Z80CPU *z80) { }
void _z80_D1D(struct Z80CPU *z80) { }
void _z80_D1E(struct Z80CPU *z80) { }
void _z80_D1F(struct Z80CPU *z80) { }
void _z80_D20(struct Z80CPU *z80) { }

void _z80_D21(struct Z80CPU *z80)                         /* LD IX,nn */
  {
    z80->IX=_z80_Get_PC2(z80);
  }

void _z80_D22(struct Z80CPU *z80)                         /* LD (nn),IX */
  {
    _z80_Store2(z80,_z80_Get_PC2(z80),z80->IX);
  }

void _z80_D23(struct Z80CPU *z80)                         /* INC IX */
  {
    z80->IX++;
    z80->ts+=2;
  }

void _z80_D24(struct Z80CPU *z80) { }
void _z80_D25(struct Z80CPU *z80) { }
void _z80_D26(struct Z80CPU *z80) { }
void _z80_D27(struct Z80CPU *z80) { }
void _z80_D28(struct Z80CPU *z80) { }

void _z80_D29(struct Z80CPU *z80)                         /* ADD IX,IX */
  {
    _z80_Add_16(z80,&z80->IX,z80->IX);
    z80->ts+=7;
  }

void _z80_D2A(struct Z80CPU *z80)                         /* LD IX,(nn) */
  {
    z80->IX=_z80_Fetch2(z80,_z80_Get_PC2(z80));
  }

void _z80_D2B(struct Z80CPU *z80)                         /* DEC IX */
  {
    z80->IX--;
    z80->ts+=2;
  }

void _z80_D2C(struct Z80CPU *z80) { }
void _z80_D2D(struct Z80CPU *z80) { }
void _z80_D2E(struct Z80CPU *z80) { }
void _z80_D2F(struct Z80CPU *z80) { }
void _z80_D30(struct Z80CPU *z80) { }
void _z80_D31(struct Z80CPU *z80) { }
void _z80_D32(struct Z80CPU *z80) { }
void _z80_D33(struct Z80CPU *z80) { }

void _z80_D34(struct Z80CPU *z80)                         /* INC (IX+d) */
  {
    _z80_Inc_Mem_8(z80,_z80_Offset(z80->IX,_z80_Get_PC(z80)));
    z80->ts+=6;
  }

void _z80_D35(struct Z80CPU *z80)                         /* DEC (IX+d) */
  {
    _z80_Dec_Mem_8(z80,_z80_Offset(z80->IX,_z80_Get_PC(z80)));
    z80->ts+=6;
  }

void _z80_D36(struct Z80CPU *z80)                         /* LD (IX+d),n */
  {
    byte d,n;
    d=_z80_Get_PC(z80);
    n=_z80_Get_PC(z80);
    _z80_Store(z80,_z80_Offset(z80->IX,d),n);
    z80->ts+=2;
  }

void _z80_D37(struct Z80CPU *z80) { }
void _z80_D38(struct Z80CPU *z80) { }

void _z80_D39(struct Z80CPU *z80)                         /* ADD IX,SP */
  {
    _z80_Add_16(z80,&z80->IX,z80->SP);
    z80->ts+=7;
  }

void _z80_D3A(struct Z80CPU *z80) { }
void _z80_D3B(struct Z80CPU *z80) { }
void _z80_D3C(struct Z80CPU *z80) { }
void _z80_D3D(struct Z80CPU *z80) { }
void _z80_D3E(struct Z80CPU *z80) { }
void _z80_D3F(struct Z80CPU *z80) { }
void _z80_D40(struct Z80CPU *z80) { }
void _z80_D41(struct Z80CPU *z80) { }
void _z80_D42(struct Z80CPU *z80) { }
void _z80_D43(struct Z80CPU *z80) { }
void _z80_D44(struct Z80CPU *z80) { }
void _z80_D45(struct Z80CPU *z80) { }

void _z80_D46(struct Z80CPU *z80)                         /* LD B,(IX+d) */
  {
    z80->BC.BCu.B=_z80_Fetch(z80,_z80_Offset(z80->IX,_z80_Get_PC(z80)));
    z80->ts+=5;
  }

void _z80_D47(struct Z80CPU *z80) { }
void _z80_D48(struct Z80CPU *z80) { }
void _z80_D49(struct Z80CPU *z80) { }
void _z80_D4A(struct Z80CPU *z80) { }
void _z80_D4B(struct Z80CPU *z80) { }
void _z80_D4C(struct Z80CPU *z80) { }
void _z80_D4D(struct Z80CPU *z80) { }

void _z80_D4E(struct Z80CPU *z80)                         /* LD C,(IX+d) */
  {
    byte d;
    d=_z80_Get_PC(z80);
    z80->BC.BCu.C=_z80_Fetch(z80,_z80_Offset(z80->IX,d));
    z80->ts+=5;
  }

void _z80_D4F(struct Z80CPU *z80) { }
void _z80_D50(struct Z80CPU *z80) { }
void _z80_D51(struct Z80CPU *z80) { }
void _z80_D52(struct Z80CPU *z80) { }
void _z80_D53(struct Z80CPU *z80) { }
void _z80_D54(struct Z80CPU *z80) { }
void _z80_D55(struct Z80CPU *z80) { }

void _z80_D56(struct Z80CPU *z80)                         /* LD D,(IX+d) */
  {
    z80->DE.DEu.D=_z80_Fetch(z80,_z80_Offset(z80->IX,_z80_Get_PC(z80)));
    z80->ts+=5;
  }

void _z80_D57(struct Z80CPU *z80) { }
void _z80_D58(struct Z80CPU *z80) { }
void _z80_D59(struct Z80CPU *z80) { }
void _z80_D5A(struct Z80CPU *z80) { }
void _z80_D5B(struct Z80CPU *z80) { }
void _z80_D5C(struct Z80CPU *z80) { }
void _z80_D5D(struct Z80CPU *z80) { }

void _z80_D5E(struct Z80CPU *z80)                         /* LD E,(IX+d) */
  {
    byte d;
    d=_z80_Get_PC(z80);
    z80->DE.DEu.E=_z80_Fetch(z80,_z80_Offset(z80->IX,d));
    z80->ts+=5;
  }

void _z80_D5F(struct Z80CPU *z80) { }
void _z80_D60(struct Z80CPU *z80) { }
void _z80_D61(struct Z80CPU *z80) { }
void _z80_D62(struct Z80CPU *z80) { }
void _z80_D63(struct Z80CPU *z80) { }
void _z80_D64(struct Z80CPU *z80) { }
void _z80_D65(struct Z80CPU *z80) { }

void _z80_D66(struct Z80CPU *z80)                         /* LD H,(IX+d) */
  {
    z80->HL.HLu.H=_z80_Fetch(z80,_z80_Offset(z80->IX,_z80_Get_PC(z80)));
    z80->ts+=5;
  }

void _z80_D67(struct Z80CPU *z80) { }
void _z80_D68(struct Z80CPU *z80) { }
void _z80_D69(struct Z80CPU *z80) { }
void _z80_D6A(struct Z80CPU *z80) { }
void _z80_D6B(struct Z80CPU *z80) { }
void _z80_D6C(struct Z80CPU *z80) { }
void _z80_D6D(struct Z80CPU *z80) { }

void _z80_D6E(struct Z80CPU *z80)                         /* LD L,(IX+d) */
  {
    z80->HL.HLu.L=_z80_Fetch(z80,_z80_Offset(z80->IX,_z80_Get_PC(z80)));
    z80->ts+=5;
  }

void _z80_D6F(struct Z80CPU *z80) { }

void _z80_D70(struct Z80CPU *z80)                         /* LD (IX+d),B */
  {
    byte d;
    d=_z80_Get_PC(z80);
    _z80_Store(z80,_z80_Offset(z80->IX,d),z80->BC.BCu.B);
    z80->ts+=5;
  }

void _z80_D71(struct Z80CPU *z80)                         /* LD (IX+d),C */
  {
    byte d;
    d=_z80_Get_PC(z80);
    _z80_Store(z80,_z80_Offset(z80->IX,d),z80->BC.BCu.C);
    z80->ts+=5;
  }

void _z80_D72(struct Z80CPU *z80)                         /* LD (IX+d),D */
  {
    _z80_Store(z80,_z80_Offset(z80->IX,_z80_Get_PC(z80)),z80->DE.DEu.D);
    z80->ts+=5;
  }

void _z80_D73(struct Z80CPU *z80)                         /* LD (IX+d),E */
  {
    _z80_Store(z80,_z80_Offset(z80->IX,_z80_Get_PC(z80)),z80->DE.DEu.E);
    z80->ts+=5;
  }

void _z80_D74(struct Z80CPU *z80)                         /* LD (IX+d),H */
  {
    _z80_Store(z80,_z80_Offset(z80->IX,_z80_Get_PC(z80)),z80->HL.HLu.H);
    z80->ts+=5;
  }

void _z80_D75(struct Z80CPU *z80)                         /* LD (IX+d),L */
  {
    _z80_Store(z80,_z80_Offset(z80->IX,_z80_Get_PC(z80)),z80->HL.HLu.L);
    z80->ts+=5;
  }

void _z80_D76(struct Z80CPU *z80) { }

void _z80_D77(struct Z80CPU *z80)                         /* LD (IX+d),A */
  {
    byte d;
    d=_z80_Get_PC(z80);
    _z80_Store(z80,_z80_Offset(z80->IX,d),z80->AF.AFu.A);
    z80->ts+=5;
  }

void _z80_D78(struct Z80CPU *z80) { }
void _z80_D79(struct Z80CPU *z80) { }
void _z80_D7A(struct Z80CPU *z80) { }
void _z80_D7B(struct Z80CPU *z80) { }
void _z80_D7C(struct Z80CPU *z80) { }
void _z80_D7D(struct Z80CPU *z80) { }

void _z80_D7E(struct Z80CPU *z80)                         /* LD A,(IX+d) */
  {
    byte d;
    d=_z80_Get_PC(z80);
    z80->AF.AFu.A=_z80_Fetch(z80,_z80_Offset(z80->IX,d));
    z80->ts+=5;
  }

void _z80_D7F(struct Z80CPU *z80) { }

void _z80_D80(struct Z80CPU *z80) { }
void _z80_D81(struct Z80CPU *z80) { }
void _z80_D82(struct Z80CPU *z80) { }
void _z80_D83(struct Z80CPU *z80) { }
void _z80_D84(struct Z80CPU *z80) { }
void _z80_D85(struct Z80CPU *z80) { }

void _z80_D86(struct Z80CPU *z80)                         /* ADD A,(IX+d) */
  {
    _z80_Add_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,_z80_Offset(z80->IX,_z80_Get_PC(z80))));
    z80->ts+=5;
  }

void _z80_D87(struct Z80CPU *z80) { }
void _z80_D88(struct Z80CPU *z80) { }
void _z80_D89(struct Z80CPU *z80) { }
void _z80_D8A(struct Z80CPU *z80) { }
void _z80_D8B(struct Z80CPU *z80) { }
void _z80_D8C(struct Z80CPU *z80) { }
void _z80_D8D(struct Z80CPU *z80) { }

void _z80_D8E(struct Z80CPU *z80)                         /* ADC A,(IX+d) */
  {
    _z80_Adc_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,_z80_Offset(z80->IX,_z80_Get_PC(z80))));
    z80->ts+=5;
  }

void _z80_D8F(struct Z80CPU *z80) { }
void _z80_D90(struct Z80CPU *z80) { }
void _z80_D91(struct Z80CPU *z80) { }
void _z80_D92(struct Z80CPU *z80) { }
void _z80_D93(struct Z80CPU *z80) { }
void _z80_D94(struct Z80CPU *z80) { }
void _z80_D95(struct Z80CPU *z80) { }

void _z80_D96(struct Z80CPU *z80)                         /* SUB A,(IX+d) */
  {
    _z80_Sub_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,_z80_Offset(z80->IX,_z80_Get_PC(z80))));
    z80->ts+=5;
  }

void _z80_D97(struct Z80CPU *z80) { }
void _z80_D98(struct Z80CPU *z80) { }
void _z80_D99(struct Z80CPU *z80) { }
void _z80_D9A(struct Z80CPU *z80) { }
void _z80_D9B(struct Z80CPU *z80) { }
void _z80_D9C(struct Z80CPU *z80) { }
void _z80_D9D(struct Z80CPU *z80) { }

void _z80_D9E(struct Z80CPU *z80)                         /* SBC A,(IX+d) */
  {
    _z80_Sbc_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,_z80_Offset(z80->IX,_z80_Get_PC(z80))));
    z80->ts+=5;
  }

void _z80_D9F(struct Z80CPU *z80) { }
void _z80_DA0(struct Z80CPU *z80) { }
void _z80_DA1(struct Z80CPU *z80) { }
void _z80_DA2(struct Z80CPU *z80) { }
void _z80_DA3(struct Z80CPU *z80) { }
void _z80_DA4(struct Z80CPU *z80) { }
void _z80_DA5(struct Z80CPU *z80) { }

void _z80_DA6(struct Z80CPU *z80)                         /* AND (IX+d) */
  {
    _z80_And_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,_z80_Offset(z80->IX,_z80_Get_PC(z80))));
    z80->ts+=5;
  }

void _z80_DA7(struct Z80CPU *z80) { }
void _z80_DA8(struct Z80CPU *z80) { }
void _z80_DA9(struct Z80CPU *z80) { }
void _z80_DAA(struct Z80CPU *z80) { }
void _z80_DAB(struct Z80CPU *z80) { }
void _z80_DAC(struct Z80CPU *z80) { }
void _z80_DAD(struct Z80CPU *z80) { }

void _z80_DAE(struct Z80CPU *z80)                         /* XOR (IX+d) */
  {
    _z80_XOr_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,_z80_Offset(z80->IX,_z80_Get_PC(z80))));
    z80->ts+=5;
  }

void _z80_DAF(struct Z80CPU *z80) { }
void _z80_DB0(struct Z80CPU *z80) { }
void _z80_DB1(struct Z80CPU *z80) { }
void _z80_DB2(struct Z80CPU *z80) { }
void _z80_DB3(struct Z80CPU *z80) { }
void _z80_DB4(struct Z80CPU *z80) { }
void _z80_DB5(struct Z80CPU *z80) { }

void _z80_DB6(struct Z80CPU *z80)                         /* OR (IX+d) */
  {
    _z80_Or_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,_z80_Offset(z80->IX,_z80_Get_PC(z80))));
    z80->ts+=5;
  }

void _z80_DB7(struct Z80CPU *z80) { }
void _z80_DB8(struct Z80CPU *z80) { }
void _z80_DB9(struct Z80CPU *z80) { }
void _z80_DBA(struct Z80CPU *z80) { }
void _z80_DBB(struct Z80CPU *z80) { }
void _z80_DBC(struct Z80CPU *z80) { }
void _z80_DBD(struct Z80CPU *z80) { }

void _z80_DBE(struct Z80CPU *z80)                         /* CP (IX+d) */
  {
    byte d;
    d=_z80_Get_PC(z80);
    _z80_Cmp_8(z80,&z80->AF.AFu.A,_z80_Fetch(z80,_z80_Offset(z80->IX,d)));
    z80->ts+=5;
  }

void _z80_DBF(struct Z80CPU *z80) { }

void _z80_DC0(struct Z80CPU *z80) { }
void _z80_DC1(struct Z80CPU *z80) { }
void _z80_DC2(struct Z80CPU *z80) { }
void _z80_DC3(struct Z80CPU *z80) { }
void _z80_DC4(struct Z80CPU *z80) { }
void _z80_DC5(struct Z80CPU *z80) { }
void _z80_DC6(struct Z80CPU *z80) { }
void _z80_DC7(struct Z80CPU *z80) { }
void _z80_DC8(struct Z80CPU *z80) { }
void _z80_DC9(struct Z80CPU *z80) { }
void _z80_DCA(struct Z80CPU *z80) { }

void _z80_DCB(struct Z80CPU *z80)
  {
    word Adr;
    byte Cmd;
    byte Wrk;
    Adr=_z80_Offset(z80->IX,_z80_Get_PC(z80));
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
          
void _z80_DCC(struct Z80CPU *z80) { }
void _z80_DCD(struct Z80CPU *z80) { }
void _z80_DCE(struct Z80CPU *z80) { }
void _z80_DCF(struct Z80CPU *z80) { }

void _z80_DD0(struct Z80CPU *z80) { }
void _z80_DD1(struct Z80CPU *z80) { }
void _z80_DD2(struct Z80CPU *z80) { }
void _z80_DD3(struct Z80CPU *z80) { }
void _z80_DD4(struct Z80CPU *z80) { }
void _z80_DD5(struct Z80CPU *z80) { }
void _z80_DD6(struct Z80CPU *z80) { }
void _z80_DD7(struct Z80CPU *z80) { }
void _z80_DD8(struct Z80CPU *z80) { }
void _z80_DD9(struct Z80CPU *z80) { }
void _z80_DDA(struct Z80CPU *z80) { }
void _z80_DDB(struct Z80CPU *z80) { }
void _z80_DDC(struct Z80CPU *z80) { }
void _z80_DDD(struct Z80CPU *z80) { }
void _z80_DDE(struct Z80CPU *z80) { }
void _z80_DDF(struct Z80CPU *z80) { }
void _z80_DE0(struct Z80CPU *z80) { }

void _z80_DE1(struct Z80CPU *z80)                         /* POP IX */
  {
    z80->IX=_z80_Pop2(z80);
  }

void _z80_DE2(struct Z80CPU *z80) { }

void _z80_DE3(struct Z80CPU *z80)                         /* EX (SP),IX */
  {
    word tmp;
    tmp=_z80_Fetch2(z80,z80->SP);
    _z80_Store2(z80,z80->SP,z80->IX);
    z80->IX=tmp;
    z80->ts+=3;
  }

void _z80_DE4(struct Z80CPU *z80) { }

void _z80_DE5(struct Z80CPU *z80)                         /* PUSH IX */
  {
    _z80_Push2(z80,z80->IX);
    z80->ts++;
  }

void _z80_DE6(struct Z80CPU *z80) { }
void _z80_DE7(struct Z80CPU *z80) { }
void _z80_DE8(struct Z80CPU *z80) { }

void _z80_DE9(struct Z80CPU *z80)                         /* JP (IX) */
  {
    z80->PC=z80->IX;
  }

void _z80_DEA(struct Z80CPU *z80) { }
void _z80_DEB(struct Z80CPU *z80) { }
void _z80_DEC(struct Z80CPU *z80) { }
void _z80_DED(struct Z80CPU *z80) { }
void _z80_DEE(struct Z80CPU *z80) { }
void _z80_DEF(struct Z80CPU *z80) { }
void _z80_DF0(struct Z80CPU *z80) { }
void _z80_DF1(struct Z80CPU *z80) { }
void _z80_DF2(struct Z80CPU *z80) { }
void _z80_DF3(struct Z80CPU *z80) { }
void _z80_DF4(struct Z80CPU *z80) { }
void _z80_DF5(struct Z80CPU *z80) { }
void _z80_DF6(struct Z80CPU *z80) { }
void _z80_DF7(struct Z80CPU *z80) { }
void _z80_DF8(struct Z80CPU *z80) { }

void _z80_DF9(struct Z80CPU *z80)                         /* LD SP,IX */
  {
    z80->SP=z80->IX;
    z80->ts+=2;
  }

void _z80_DFA(struct Z80CPU *z80) { }
void _z80_DFB(struct Z80CPU *z80) { }
void _z80_DFC(struct Z80CPU *z80) { }
void _z80_DFD(struct Z80CPU *z80) { }
void _z80_DFE(struct Z80CPU *z80) { }
void _z80_DFF(struct Z80CPU *z80) { }

void _z80_PDD(struct Z80CPU *z80)
  {
    byte bt;
    bt=_z80_Get_PC(z80);
    z80->ts++;
#ifdef HIST
    hist[2][bt]='*';
#endif
    z80->IDD[bt](z80);
  }


void _z80_prepareDD(struct Z80CPU *z80) {
  z80->IDD[0x00]=_z80_D00; z80->IDD[0x01]=_z80_D01; z80->IDD[0x02]=_z80_D02; z80->IDD[0x03]=_z80_D03;
  z80->IDD[0x04]=_z80_D04; z80->IDD[0x05]=_z80_D05; z80->IDD[0x06]=_z80_D06; z80->IDD[0x07]=_z80_D07;
  z80->IDD[0x08]=_z80_D08; z80->IDD[0x09]=_z80_D09; z80->IDD[0x0a]=_z80_D0A; z80->IDD[0x0b]=_z80_D0B;
  z80->IDD[0x0c]=_z80_D0C; z80->IDD[0x0d]=_z80_D0D; z80->IDD[0x0e]=_z80_D0E; z80->IDD[0x0f]=_z80_D0F;

  z80->IDD[0x10]=_z80_D10; z80->IDD[0x11]=_z80_D11; z80->IDD[0x12]=_z80_D12; z80->IDD[0x13]=_z80_D13;
  z80->IDD[0x14]=_z80_D14; z80->IDD[0x15]=_z80_D15; z80->IDD[0x16]=_z80_D16; z80->IDD[0x17]=_z80_D17;
  z80->IDD[0x18]=_z80_D18; z80->IDD[0x19]=_z80_D19; z80->IDD[0x1a]=_z80_D1A; z80->IDD[0x1b]=_z80_D1B;
  z80->IDD[0x1c]=_z80_D1C; z80->IDD[0x1d]=_z80_D1D; z80->IDD[0x1e]=_z80_D1E; z80->IDD[0x1f]=_z80_D1F;

  z80->IDD[0x20]=_z80_D20; z80->IDD[0x21]=_z80_D21; z80->IDD[0x22]=_z80_D22; z80->IDD[0x23]=_z80_D23;
  z80->IDD[0x24]=_z80_D24; z80->IDD[0x25]=_z80_D25; z80->IDD[0x26]=_z80_D26; z80->IDD[0x27]=_z80_D27;
  z80->IDD[0x28]=_z80_D28; z80->IDD[0x29]=_z80_D29; z80->IDD[0x2a]=_z80_D2A; z80->IDD[0x2b]=_z80_D2B;
  z80->IDD[0x2c]=_z80_D2C; z80->IDD[0x2d]=_z80_D2D; z80->IDD[0x2e]=_z80_D2E; z80->IDD[0x2f]=_z80_D2F;

  z80->IDD[0x30]=_z80_D30; z80->IDD[0x31]=_z80_D31; z80->IDD[0x32]=_z80_D32; z80->IDD[0x33]=_z80_D33;
  z80->IDD[0x34]=_z80_D34; z80->IDD[0x35]=_z80_D35; z80->IDD[0x36]=_z80_D36; z80->IDD[0x37]=_z80_D37;
  z80->IDD[0x38]=_z80_D38; z80->IDD[0x39]=_z80_D39; z80->IDD[0x3a]=_z80_D3A; z80->IDD[0x3b]=_z80_D3B;
  z80->IDD[0x3c]=_z80_D3C; z80->IDD[0x3d]=_z80_D3D; z80->IDD[0x3e]=_z80_D3E; z80->IDD[0x3f]=_z80_D3F;

  z80->IDD[0x40]=_z80_D40; z80->IDD[0x41]=_z80_D41; z80->IDD[0x42]=_z80_D42; z80->IDD[0x43]=_z80_D43;
  z80->IDD[0x44]=_z80_D44; z80->IDD[0x45]=_z80_D45; z80->IDD[0x46]=_z80_D46; z80->IDD[0x47]=_z80_D47;
  z80->IDD[0x48]=_z80_D48; z80->IDD[0x49]=_z80_D49; z80->IDD[0x4a]=_z80_D4A; z80->IDD[0x4b]=_z80_D4B;
  z80->IDD[0x4c]=_z80_D4C; z80->IDD[0x4d]=_z80_D4D; z80->IDD[0x4e]=_z80_D4E; z80->IDD[0x4f]=_z80_D4F;

  z80->IDD[0x50]=_z80_D50; z80->IDD[0x51]=_z80_D51; z80->IDD[0x52]=_z80_D52; z80->IDD[0x53]=_z80_D53;
  z80->IDD[0x54]=_z80_D54; z80->IDD[0x55]=_z80_D55; z80->IDD[0x56]=_z80_D56; z80->IDD[0x57]=_z80_D57;
  z80->IDD[0x58]=_z80_D58; z80->IDD[0x59]=_z80_D59; z80->IDD[0x5a]=_z80_D5A; z80->IDD[0x5b]=_z80_D5B;
  z80->IDD[0x5c]=_z80_D5C; z80->IDD[0x5d]=_z80_D5D; z80->IDD[0x5e]=_z80_D5E; z80->IDD[0x5f]=_z80_D5F;

  z80->IDD[0x60]=_z80_D60; z80->IDD[0x61]=_z80_D61; z80->IDD[0x62]=_z80_D62; z80->IDD[0x63]=_z80_D63;
  z80->IDD[0x64]=_z80_D64; z80->IDD[0x65]=_z80_D65; z80->IDD[0x66]=_z80_D66; z80->IDD[0x67]=_z80_D67;
  z80->IDD[0x68]=_z80_D68; z80->IDD[0x69]=_z80_D69; z80->IDD[0x6a]=_z80_D6A; z80->IDD[0x6b]=_z80_D6B;
  z80->IDD[0x6c]=_z80_D6C; z80->IDD[0x6d]=_z80_D6D; z80->IDD[0x6e]=_z80_D6E; z80->IDD[0x6f]=_z80_D6F;

  z80->IDD[0x70]=_z80_D70; z80->IDD[0x71]=_z80_D71; z80->IDD[0x72]=_z80_D72; z80->IDD[0x73]=_z80_D73;
  z80->IDD[0x74]=_z80_D74; z80->IDD[0x75]=_z80_D75; z80->IDD[0x76]=_z80_D76; z80->IDD[0x77]=_z80_D77;
  z80->IDD[0x78]=_z80_D78; z80->IDD[0x79]=_z80_D79; z80->IDD[0x7a]=_z80_D7A; z80->IDD[0x7b]=_z80_D7B;
  z80->IDD[0x7c]=_z80_D7C; z80->IDD[0x7d]=_z80_D7D; z80->IDD[0x7e]=_z80_D7E; z80->IDD[0x7f]=_z80_D7F;

  z80->IDD[0x80]=_z80_D80; z80->IDD[0x81]=_z80_D81; z80->IDD[0x82]=_z80_D82; z80->IDD[0x83]=_z80_D83;
  z80->IDD[0x84]=_z80_D84; z80->IDD[0x85]=_z80_D85; z80->IDD[0x86]=_z80_D86; z80->IDD[0x87]=_z80_D87;
  z80->IDD[0x88]=_z80_D88; z80->IDD[0x89]=_z80_D89; z80->IDD[0x8a]=_z80_D8A; z80->IDD[0x8b]=_z80_D8B;
  z80->IDD[0x8c]=_z80_D8C; z80->IDD[0x8d]=_z80_D8D; z80->IDD[0x8e]=_z80_D8E; z80->IDD[0x8f]=_z80_D8F;

  z80->IDD[0x90]=_z80_D90; z80->IDD[0x91]=_z80_D91; z80->IDD[0x92]=_z80_D92; z80->IDD[0x93]=_z80_D93;
  z80->IDD[0x94]=_z80_D94; z80->IDD[0x95]=_z80_D95; z80->IDD[0x96]=_z80_D96; z80->IDD[0x97]=_z80_D97;
  z80->IDD[0x98]=_z80_D98; z80->IDD[0x99]=_z80_D99; z80->IDD[0x9a]=_z80_D9A; z80->IDD[0x9b]=_z80_D9B;
  z80->IDD[0x9c]=_z80_D9C; z80->IDD[0x9d]=_z80_D9D; z80->IDD[0x9e]=_z80_D9E; z80->IDD[0x9f]=_z80_D9F;

  z80->IDD[0xa0]=_z80_DA0; z80->IDD[0xa1]=_z80_DA1; z80->IDD[0xa2]=_z80_DA2; z80->IDD[0xa3]=_z80_DA3;
  z80->IDD[0xa4]=_z80_DA4; z80->IDD[0xa5]=_z80_DA5; z80->IDD[0xa6]=_z80_DA6; z80->IDD[0xa7]=_z80_DA7;
  z80->IDD[0xa8]=_z80_DA8; z80->IDD[0xa9]=_z80_DA9; z80->IDD[0xaa]=_z80_DAA; z80->IDD[0xab]=_z80_DAB;
  z80->IDD[0xac]=_z80_DAC; z80->IDD[0xad]=_z80_DAD; z80->IDD[0xae]=_z80_DAE; z80->IDD[0xaf]=_z80_DAF;

  z80->IDD[0xb0]=_z80_DB0; z80->IDD[0xb1]=_z80_DB1; z80->IDD[0xb2]=_z80_DB2; z80->IDD[0xb3]=_z80_DB3;
  z80->IDD[0xb4]=_z80_DB4; z80->IDD[0xb5]=_z80_DB5; z80->IDD[0xb6]=_z80_DB6; z80->IDD[0xb7]=_z80_DB7;
  z80->IDD[0xb8]=_z80_DB8; z80->IDD[0xb9]=_z80_DB9; z80->IDD[0xba]=_z80_DBA; z80->IDD[0xbb]=_z80_DBB;
  z80->IDD[0xbc]=_z80_DBC; z80->IDD[0xbd]=_z80_DBD; z80->IDD[0xbe]=_z80_DBE; z80->IDD[0xbf]=_z80_DBF;

  z80->IDD[0xc0]=_z80_DC0; z80->IDD[0xc1]=_z80_DC1; z80->IDD[0xc2]=_z80_DC2; z80->IDD[0xc3]=_z80_DC3;
  z80->IDD[0xc4]=_z80_DC4; z80->IDD[0xc5]=_z80_DC5; z80->IDD[0xc6]=_z80_DC6; z80->IDD[0xc7]=_z80_DC7;
  z80->IDD[0xc8]=_z80_DC8; z80->IDD[0xc9]=_z80_DC9; z80->IDD[0xca]=_z80_DCA; z80->IDD[0xcb]=_z80_DCB;
  z80->IDD[0xcc]=_z80_DCC; z80->IDD[0xcd]=_z80_DCD; z80->IDD[0xce]=_z80_DCE; z80->IDD[0xcf]=_z80_DCF;

  z80->IDD[0xd0]=_z80_DD0; z80->IDD[0xd1]=_z80_DD1; z80->IDD[0xd2]=_z80_DD2; z80->IDD[0xd3]=_z80_DD3;
  z80->IDD[0xd4]=_z80_DD4; z80->IDD[0xd5]=_z80_DD5; z80->IDD[0xd6]=_z80_DD6; z80->IDD[0xd7]=_z80_DD7;
  z80->IDD[0xd8]=_z80_DD8; z80->IDD[0xd9]=_z80_DD9; z80->IDD[0xda]=_z80_DDA; z80->IDD[0xdb]=_z80_DDB;
  z80->IDD[0xdc]=_z80_DDC; z80->IDD[0xdd]=_z80_DDD; z80->IDD[0xde]=_z80_DDE; z80->IDD[0xdf]=_z80_DDF;

  z80->IDD[0xe0]=_z80_DE0; z80->IDD[0xe1]=_z80_DE1; z80->IDD[0xe2]=_z80_DE2; z80->IDD[0xe3]=_z80_DE3;
  z80->IDD[0xe4]=_z80_DE4; z80->IDD[0xe5]=_z80_DE5; z80->IDD[0xe6]=_z80_DE6; z80->IDD[0xe7]=_z80_DE7;
  z80->IDD[0xe8]=_z80_DE8; z80->IDD[0xe9]=_z80_DE9; z80->IDD[0xea]=_z80_DEA; z80->IDD[0xeb]=_z80_DEB;
  z80->IDD[0xec]=_z80_DEC; z80->IDD[0xed]=_z80_DED; z80->IDD[0xee]=_z80_DEE; z80->IDD[0xef]=_z80_DEF;

  z80->IDD[0xf0]=_z80_DF0; z80->IDD[0xf1]=_z80_DF1; z80->IDD[0xf2]=_z80_DF2; z80->IDD[0xf3]=_z80_DF3;
  z80->IDD[0xf4]=_z80_DF4; z80->IDD[0xf5]=_z80_DF5; z80->IDD[0xf6]=_z80_DF6; z80->IDD[0xf7]=_z80_DF7;
  z80->IDD[0xf8]=_z80_DF8; z80->IDD[0xf9]=_z80_DF9; z80->IDD[0xfa]=_z80_DFA; z80->IDD[0xfb]=_z80_DFB;
  z80->IDD[0xfc]=_z80_DFC; z80->IDD[0xfd]=_z80_DFD; z80->IDD[0xfe]=_z80_DFE; z80->IDD[0xff]=_z80_DFF;
  }

