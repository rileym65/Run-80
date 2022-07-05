#include "header.h"

int disE0(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE1(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE2(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE3(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE4(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE5(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE6(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE7(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE8(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE9(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEA(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEB(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEC(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disED(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEE(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEF(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE10(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE11(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE12(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE13(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE14(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE15(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE16(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE17(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE18(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE19(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE1A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE1B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE1C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE1D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE1E(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE1F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE20(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE21(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE22(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE23(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE24(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE25(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE26(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE27(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE28(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE29(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE2A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE2B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE2C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE2D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE2E(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE2F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE30(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE31(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE32(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE33(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE34(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE35(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE36(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE37(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE38(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE39(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE3A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE3B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE3C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE3D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE3E(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE3F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disE40(byte a,byte b,byte c,byte d,char *buffer)        /* IN B,(C) */
  {
    sprintf(buffer,"%02x %02x       in b,(c)",a,b);
    return 2;
  }

int disE41(byte a,byte b,byte c,byte d,char *buffer)        /* OUT (C),B */
  {
    sprintf(buffer,"%02x %02x      out (c),b",a,b);
    return 2;
  }

int disE42(byte a,byte b,byte c,byte d,char *buffer)        /* SBC HL,BC */
  {
    sprintf(buffer,"%02x %02x      sbc hl,bc",a,b);
    return 2;
  }

int disE43(byte a,byte b,byte c,byte d,char *buffer)        /* LD (nn),BC */
  {
    sprintf(buffer,"%02x %02x %02x %02x ld (%04x),bc",a,b,c,d,c+d*256);
    return 4;
  }

int disE44(byte a,byte b,byte c,byte d,char *buffer)        /* NEG */
  {
    sprintf(buffer,"%02x %02x       neg",a,b);
    return 2;
  }

int disE45(byte a,byte b,byte c,byte d,char *buffer)        /* RETN */
  {
    sprintf(buffer,"%02x %02x       retn",a,b);
    return 2;
  }

int disE46(byte a,byte b,byte c,byte d,char *buffer)        /* IM 0 */
  {
    sprintf(buffer,"%02x %02x       im 0",a,b);
    return 2;
  }

int disE47(byte a,byte b,byte c,byte d,char *buffer)        /* LD I,A */
  {
    sprintf(buffer,"%02x %02x       ld i,a",a,b);
    return 2;
  }

int disE48(byte a,byte b,byte c,byte d,char *buffer)        /* IN C,(C) */
  {
    sprintf(buffer,"%02x %02x       in c,(c)",a,b);
    return 2;
  }

int disE49(byte a,byte b,byte c,byte d,char *buffer)        /* OUT (C),C */
  {
    sprintf(buffer,"%02x %02x       out (c),c",a,b);
    return 2;
  }

int disE4A(byte a,byte b,byte c,byte d,char *buffer)        /* ADC HL,BC */
  {
    sprintf(buffer,"%02x %02x       adc hl,bc",a,b);
    return 2;
  }

int disE4B(byte a,byte b,byte c,byte d,char *buffer)        /* LD BC,(nn) */
  {
    sprintf(buffer,"%02x %02x %02x %02x ld bc,(%04x)",a,b,c,d,c+d*256);
    return 4;
  }

int disE4C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disE4D(byte a,byte b,byte c,byte d,char *buffer)        /* RETI */
  {
    sprintf(buffer,"%02x %02x       reti",a,b);
    return 2;
  }

int disE4E(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disE4F(byte a,byte b,byte c,byte d,char *buffer)        /* LD R,A */
  {
    sprintf(buffer,"%02x %02x       ld r,a",a,b);
    return 2;
  }

int disE50(byte a,byte b,byte c,byte d,char *buffer)        /* IN D,(C) */
  {
    sprintf(buffer,"%02x %02x       in d,(c)",a,b);
    return 2;
  }

int disE51(byte a,byte b,byte c,byte d,char *buffer)        /* OUT (C),D */
  {
    sprintf(buffer,"%02x %02x       out (c),d",a,b);
    return 2;
  }

int disE52(byte a,byte b,byte c,byte d,char *buffer)        /* SBC HL,DE */
  {
    sprintf(buffer,"%02x %02x       sbc hl,de",a,b);
    return 2;
  }

int disE53(byte a,byte b,byte c,byte d,char *buffer)        /* LD (nn),DE */
  {
    sprintf(buffer,"%02x %02x %02x %02x ld (%04x),de",a,b,c,d,c+d*256);
    return 4;
  }

int disE54(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE55(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disE56(byte a,byte b,byte c,byte d,char *buffer)        /* IM 1 */
  {
    sprintf(buffer,"%02x %02x       im 1",a,b);
    return 2;
  }

int disE57(byte a,byte b,byte c,byte d,char *buffer)        /* LD A,I */
  {
    sprintf(buffer,"%02x %02x       ld a,i",a,b);
    return 2;
  }

int disE58(byte a,byte b,byte c,byte d,char *buffer)        /* IN E,(C) */
  {
    sprintf(buffer,"%02x %02x       in e,(c)",a,b);
    return 2;
  }

int disE59(byte a,byte b,byte c,byte d,char *buffer)        /* OUT (C),E */
  {
    sprintf(buffer,"%02x %02x       out (c),e",a,b);
    return 2;
  }

int disE5A(byte a,byte b,byte c,byte d,char *buffer)        /* ADC HL,DE */
  {
    sprintf(buffer,"%02x %02x       adc hl,de",a,b);
    return 2;
  }

int disE5B(byte a,byte b,byte c,byte d,char *buffer)        /* LD DE,(nn) */
  {
    sprintf(buffer,"%02x %02x %02x %02x ld de,(%04x)",a,b,c,d,c+d*256);
    return 4;
  }

int disE5C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE5D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disE5E(byte a,byte b,byte c,byte d,char *buffer)        /* IM 2 */
  {
    sprintf(buffer,"%02x          im 2",a);
    return 2;
  }

int disE5F(byte a,byte b,byte c,byte d,char *buffer)        /* LD A,R */
  {
    sprintf(buffer,"%02x %02x       ld a,r",a,b);
    return 2;
  }

int disE60(byte a,byte b,byte c,byte d,char *buffer)        /* IN H,(C) */
  {
    sprintf(buffer,"%02x %02x       in h,(c)",a,b);
    return 2;
  }

int disE61(byte a,byte b,byte c,byte d,char *buffer)        /* OUT (C),H */
  {
    sprintf(buffer,"%02x %02x       out (c),h",a,b);
    return 2;
  }

int disE62(byte a,byte b,byte c,byte d,char *buffer)        /* SBC HL,HL */
  {
    sprintf(buffer,"%02x %02x       sbc hl,hl",a,b);
    return 2;
  }

int disE63(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE64(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE65(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE66(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disE67(byte a,byte b,byte c,byte d,char *buffer)        /* RRD */
  {
    sprintf(buffer,"%02x %02x       rrd",a,b);
    return 2;
  }

int disE68(byte a,byte b,byte c,byte d,char *buffer)        /* IN L,(C) */
  {
    sprintf(buffer,"%02x %02x       in l,(c)",a,b);
    return 2;
  }

int disE69(byte a,byte b,byte c,byte d,char *buffer)        /* OUT (C),L */
  {
    sprintf(buffer,"%02x %02x       out (c),l",a,b);
    return 2;
  }

int disE6A(byte a,byte b,byte c,byte d,char *buffer)        /* ADC HL,HL */
  {
    sprintf(buffer,"%02x %02x       adc hl,hl",a,b);
    return 2;
  }

int disE6B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE6C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE6D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE6E(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disE6F(byte a,byte b,byte c,byte d,char *buffer)        /* RLD */
  {
    sprintf(buffer,"%02x %02x       rld",a,b);
    return 2;
  }

int disE70(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE71(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disE72(byte a,byte b,byte c,byte d,char *buffer)        /* SBC HL,SP */
  {
    sprintf(buffer,"%02x %02x       sbc hl,sp",a,b);
    return 2;
  }

int disE73(byte a,byte b,byte c,byte d,char *buffer)        /* LD (nn),SP */
  {
    sprintf(buffer,"%02x %02x %02x %02x ld (%04x),sp",a,b,c,d,c+d*256);
    return 4;
  }

int disE74(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE75(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE76(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE77(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disE78(byte a,byte b,byte c,byte d,char *buffer)        /* IN A,(C) */
  {
    sprintf(buffer,"%02x %02x       in a,(c)",a,b);
    return 2;
  }

int disE79(byte a,byte b,byte c,byte d,char *buffer)        /* OUT (C),A */
  {
    sprintf(buffer,"%02x %02x       out (c),a",a,b);
    return 2;
  }

int disE7A(byte a,byte b,byte c,byte d,char *buffer)        /* ADC HL,SP */
  {
    sprintf(buffer,"%02x %02x       adc hl,sp",a,b);
    return 2;
  }

int disE7B(byte a,byte b,byte c,byte d,char *buffer)        /* LD SP,(nn) */
  {
    sprintf(buffer,"%02x %02x %02x %02x ld sp,(%04x)",a,b,c,d,c+d*256);
    return 4;
  }

int disE7C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE7D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE7E(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE7F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disE80(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE81(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE82(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE83(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE84(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE85(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE86(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE87(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE88(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE89(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE8A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE8B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE8C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE8D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE8E(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE8F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disE90(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE91(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE92(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE93(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE94(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE95(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE96(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE97(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE98(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE99(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE9A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE9B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE9C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE9D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE9E(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disE9F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disEA0(byte a,byte b,byte c,byte d,char *buffer)        /* LDI */
  {
    sprintf(buffer,"%02x %02x       ldi",a,b);
    return 2;
  }

int disEA1(byte a,byte b,byte c,byte d,char *buffer)        /* CPI */
  {
    sprintf(buffer,"%02x %02x       cpi",a,b);
    return 2;
  }

int disEA2(byte a,byte b,byte c,byte d,char *buffer)        /* INI */
  {
    sprintf(buffer,"%02x %02x       ini",a,b);
    return 2;
  }

int disEA3(byte a,byte b,byte c,byte d,char *buffer)        /* OUTI */
  {
    sprintf(buffer,"%02x %02x       outi",a,b);
    return 2;
  }

int disEA4(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEA5(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEA6(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEA7(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disEA8(byte a,byte b,byte c,byte d,char *buffer)        /* LDD */
  {
    sprintf(buffer,"%02x %02x       ldd",a,b);
    return 2;
  }

int disEA9(byte a,byte b,byte c,byte d,char *buffer)        /* CPD */
  {
    sprintf(buffer,"%02x %02x       cpd",a,b);
    return 2;
  }

int disEAA(byte a,byte b,byte c,byte d,char *buffer)        /* IND */
  {
    sprintf(buffer,"%02x %02x       ind",a,b);
    return 2;
  }

int disEAB(byte a,byte b,byte c,byte d,char *buffer)        /* OUTD */
  {
    sprintf(buffer,"%02x %02x       outd",a,b);
    return 2;
  }

int disEAC(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEAD(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEAE(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEAF(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disEB0(byte a,byte b,byte c,byte d,char *buffer)        /* LDIR */
  {
    sprintf(buffer,"%02x %02x       ldir",a,b);
    return 2;
  }

int disEB1(byte a,byte b,byte c,byte d,char *buffer)        /* CPIR */
  {
    sprintf(buffer,"%02x %02x       cpir",a,b);
    return 2;
  }

int disEB2(byte a,byte b,byte c,byte d,char *buffer)        /* INIR */
  {
    sprintf(buffer,"%02x %02x       inir",a,b);
    return 2;
  }

int disEB3(byte a,byte b,byte c,byte d,char *buffer)        /* OTIR */
  {
    sprintf(buffer,"%02x %02x       otir",a,b);
    return 2;
  }

int disEB4(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEB5(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEB6(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEB7(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disEB8(byte a,byte b,byte c,byte d,char *buffer)        /* LDDR */
  {
    sprintf(buffer,"%02x %02x       lddr",a,b);
    return 2;
  }

int disEB9(byte a,byte b,byte c,byte d,char *buffer)        /* CPDR */
  {
    sprintf(buffer,"%02x %02x       cpdr",a,b);
    return 2;
  }

int disEBA(byte a,byte b,byte c,byte d,char *buffer)        /* INDR */
  {
    sprintf(buffer,"%02x %02x       indr",a,b);
    return 2;
  }

int disEBB(byte a,byte b,byte c,byte d,char *buffer)        /* OTDR */
  {
    sprintf(buffer,"%02x %02x       otdr",a,b);
    return 2;
  }

int disEBC(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEBD(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEBE(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEBF(byte a,byte b,byte c,byte d,char *buffer) { return 2; }


int disEC0(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEC1(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEC2(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEC3(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEC4(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEC5(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEC6(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEC7(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEC8(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEC9(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disECA(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disECB(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disECC(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disECD(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disECE(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disECF(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disED0(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disED1(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disED2(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disED3(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disED4(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disED5(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disED6(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disED7(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disED8(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disED9(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEDA(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEDB(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEDC(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEDD(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEDE(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEDF(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disEE0(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEE1(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEE2(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEE3(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEE4(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEE5(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEE6(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEE7(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEE8(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEE9(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEEA(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEEB(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEEC(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEED(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEEE(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEEF(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disEF0(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEF1(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEF2(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEF3(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEF4(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEF5(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEF6(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEF7(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEF8(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEF9(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEFA(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEFB(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEFC(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEFD(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEFE(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disEFF(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disPED(byte a,byte b,byte c,byte d,char *buffer)
  {
    byte bt;
    bt=b;
    switch (bt & 0xf0) {
      case 0x00:switch (bt & 15) {
         case  0:return disE0(a,b,c,d,buffer); break;
         case  1:return disE1(a,b,c,d,buffer); break;
         case  2:return disE2(a,b,c,d,buffer); break;
         case  3:return disE3(a,b,c,d,buffer); break;
         case  4:return disE4(a,b,c,d,buffer); break;
         case  5:return disE5(a,b,c,d,buffer); break;
         case  6:return disE6(a,b,c,d,buffer); break;
         case  7:return disE7(a,b,c,d,buffer); break;
         case  8:return disE8(a,b,c,d,buffer); break;
         case  9:return disE9(a,b,c,d,buffer); break;
         case 10:return disEA(a,b,c,d,buffer); break;
         case 11:return disEB(a,b,c,d,buffer); break;
         case 12:return disEC(a,b,c,d,buffer); break;
         case 13:return disED(a,b,c,d,buffer); break;
         case 14:return disEE(a,b,c,d,buffer); break;
         case 15:return disEF(a,b,c,d,buffer); break;
         } break;

      case 0x10:switch (bt & 15) {
         case  0:return disE10(a,b,c,d,buffer); break;
         case  1:return disE11(a,b,c,d,buffer); break;
         case  2:return disE12(a,b,c,d,buffer); break;
         case  3:return disE13(a,b,c,d,buffer); break;
         case  4:return disE14(a,b,c,d,buffer); break;
         case  5:return disE15(a,b,c,d,buffer); break;
         case  6:return disE16(a,b,c,d,buffer); break;
         case  7:return disE17(a,b,c,d,buffer); break;
         case  8:return disE18(a,b,c,d,buffer); break;
         case  9:return disE19(a,b,c,d,buffer); break;
         case 10:return disE1A(a,b,c,d,buffer); break;
         case 11:return disE1B(a,b,c,d,buffer); break;
         case 12:return disE1C(a,b,c,d,buffer); break;
         case 13:return disE1D(a,b,c,d,buffer); break;
         case 14:return disE1E(a,b,c,d,buffer); break;
         case 15:return disE1F(a,b,c,d,buffer); break;
         } break;
      case 0x20:switch (bt & 15) {
         case  0:return disE20(a,b,c,d,buffer); break;
         case  1:return disE21(a,b,c,d,buffer); break;
         case  2:return disE22(a,b,c,d,buffer); break;
         case  3:return disE23(a,b,c,d,buffer); break;
         case  4:return disE24(a,b,c,d,buffer); break;
         case  5:return disE25(a,b,c,d,buffer); break;
         case  6:return disE26(a,b,c,d,buffer); break;
         case  7:return disE27(a,b,c,d,buffer); break;
         case  8:return disE28(a,b,c,d,buffer); break;
         case  9:return disE29(a,b,c,d,buffer); break;
         case 10:return disE2A(a,b,c,d,buffer); break;
         case 11:return disE2B(a,b,c,d,buffer); break;
         case 12:return disE2C(a,b,c,d,buffer); break;
         case 13:return disE2D(a,b,c,d,buffer); break;
         case 14:return disE2E(a,b,c,d,buffer); break;
         case 15:return disE2F(a,b,c,d,buffer); break;
         } break;
      case 0x30:switch (bt & 15) {
         case  0:return disE30(a,b,c,d,buffer); break;
         case  1:return disE31(a,b,c,d,buffer); break;
         case  2:return disE32(a,b,c,d,buffer); break;
         case  3:return disE33(a,b,c,d,buffer); break;
         case  4:return disE34(a,b,c,d,buffer); break;
         case  5:return disE35(a,b,c,d,buffer); break;
         case  6:return disE36(a,b,c,d,buffer); break;
         case  7:return disE37(a,b,c,d,buffer); break;
         case  8:return disE38(a,b,c,d,buffer); break;
         case  9:return disE39(a,b,c,d,buffer); break;
         case 10:return disE3A(a,b,c,d,buffer); break;
         case 11:return disE3B(a,b,c,d,buffer); break;
         case 12:return disE3C(a,b,c,d,buffer); break;
         case 13:return disE3D(a,b,c,d,buffer); break;
         case 14:return disE3E(a,b,c,d,buffer); break;
         case 15:return disE3F(a,b,c,d,buffer); break;
         } break;
      case 0x40:switch (bt & 15) {
         case  0:return disE40(a,b,c,d,buffer); break;
         case  1:return disE41(a,b,c,d,buffer); break;
         case  2:return disE42(a,b,c,d,buffer); break;
         case  3:return disE43(a,b,c,d,buffer); break;
         case  4:return disE44(a,b,c,d,buffer); break;
         case  5:return disE45(a,b,c,d,buffer); break;
         case  6:return disE46(a,b,c,d,buffer); break;
         case  7:return disE47(a,b,c,d,buffer); break;
         case  8:return disE48(a,b,c,d,buffer); break;
         case  9:return disE49(a,b,c,d,buffer); break;
         case 10:return disE4A(a,b,c,d,buffer); break;
         case 11:return disE4B(a,b,c,d,buffer); break;
         case 12:return disE4C(a,b,c,d,buffer); break;
         case 13:return disE4D(a,b,c,d,buffer); break;
         case 14:return disE4E(a,b,c,d,buffer); break;
         case 15:return disE4F(a,b,c,d,buffer); break;
         } break;
      case 0x50:switch (bt & 15) {
         case  0:return disE50(a,b,c,d,buffer); break;
         case  1:return disE51(a,b,c,d,buffer); break;
         case  2:return disE52(a,b,c,d,buffer); break;
         case  3:return disE53(a,b,c,d,buffer); break;
         case  4:return disE54(a,b,c,d,buffer); break;
         case  5:return disE55(a,b,c,d,buffer); break;
         case  6:return disE56(a,b,c,d,buffer); break;
         case  7:return disE57(a,b,c,d,buffer); break;
         case  8:return disE58(a,b,c,d,buffer); break;
         case  9:return disE59(a,b,c,d,buffer); break;
         case 10:return disE5A(a,b,c,d,buffer); break;
         case 11:return disE5B(a,b,c,d,buffer); break;
         case 12:return disE5C(a,b,c,d,buffer); break;
         case 13:return disE5D(a,b,c,d,buffer); break;
         case 14:return disE5E(a,b,c,d,buffer); break;
         case 15:return disE5F(a,b,c,d,buffer); break;
         } break;
      case 0x60:switch (bt & 15) {
         case  0:return disE60(a,b,c,d,buffer); break;
         case  1:return disE61(a,b,c,d,buffer); break;
         case  2:return disE62(a,b,c,d,buffer); break;
         case  3:return disE63(a,b,c,d,buffer); break;
         case  4:return disE64(a,b,c,d,buffer); break;
         case  5:return disE65(a,b,c,d,buffer); break;
         case  6:return disE66(a,b,c,d,buffer); break;
         case  7:return disE67(a,b,c,d,buffer); break;
         case  8:return disE68(a,b,c,d,buffer); break;
         case  9:return disE69(a,b,c,d,buffer); break;
         case 10:return disE6A(a,b,c,d,buffer); break;
         case 11:return disE6B(a,b,c,d,buffer); break;
         case 12:return disE6C(a,b,c,d,buffer); break;
         case 13:return disE6D(a,b,c,d,buffer); break;
         case 14:return disE6E(a,b,c,d,buffer); break;
         case 15:return disE6F(a,b,c,d,buffer); break;
         } break;
      case 0x70:switch (bt & 15) {
         case  0:return disE70(a,b,c,d,buffer); break;
         case  1:return disE71(a,b,c,d,buffer); break;
         case  2:return disE72(a,b,c,d,buffer); break;
         case  3:return disE73(a,b,c,d,buffer); break;
         case  4:return disE74(a,b,c,d,buffer); break;
         case  5:return disE75(a,b,c,d,buffer); break;
         case  6:return disE76(a,b,c,d,buffer); break;
         case  7:return disE77(a,b,c,d,buffer); break;
         case  8:return disE78(a,b,c,d,buffer); break;
         case  9:return disE79(a,b,c,d,buffer); break;
         case 10:return disE7A(a,b,c,d,buffer); break;
         case 11:return disE7B(a,b,c,d,buffer); break;
         case 12:return disE7C(a,b,c,d,buffer); break;
         case 13:return disE7D(a,b,c,d,buffer); break;
         case 14:return disE7E(a,b,c,d,buffer); break;
         case 15:return disE7F(a,b,c,d,buffer); break;
         } break;
      case 0x80:switch (bt & 15) {
         case  0:return disE80(a,b,c,d,buffer); break;
         case  1:return disE81(a,b,c,d,buffer); break;
         case  2:return disE82(a,b,c,d,buffer); break;
         case  3:return disE83(a,b,c,d,buffer); break;
         case  4:return disE84(a,b,c,d,buffer); break;
         case  5:return disE85(a,b,c,d,buffer); break;
         case  6:return disE86(a,b,c,d,buffer); break;
         case  7:return disE87(a,b,c,d,buffer); break;
         case  8:return disE88(a,b,c,d,buffer); break;
         case  9:return disE89(a,b,c,d,buffer); break;
         case 10:return disE8A(a,b,c,d,buffer); break;
         case 11:return disE8B(a,b,c,d,buffer); break;
         case 12:return disE8C(a,b,c,d,buffer); break;
         case 13:return disE8D(a,b,c,d,buffer); break;
         case 14:return disE8E(a,b,c,d,buffer); break;
         case 15:return disE8F(a,b,c,d,buffer); break;
         } break;

      case 0x90:switch (bt & 15) {
         case  0:return disE90(a,b,c,d,buffer); break;
         case  1:return disE91(a,b,c,d,buffer); break;
         case  2:return disE92(a,b,c,d,buffer); break;
         case  3:return disE93(a,b,c,d,buffer); break;
         case  4:return disE94(a,b,c,d,buffer); break;
         case  5:return disE95(a,b,c,d,buffer); break;
         case  6:return disE96(a,b,c,d,buffer); break;
         case  7:return disE97(a,b,c,d,buffer); break;
         case  8:return disE98(a,b,c,d,buffer); break;
         case  9:return disE99(a,b,c,d,buffer); break;
         case 10:return disE9A(a,b,c,d,buffer); break;
         case 11:return disE9B(a,b,c,d,buffer); break;
         case 12:return disE9C(a,b,c,d,buffer); break;
         case 13:return disE9D(a,b,c,d,buffer); break;
         case 14:return disE9E(a,b,c,d,buffer); break;
         case 15:return disE9F(a,b,c,d,buffer); break;
         } break;
      case 0xA0:switch (bt & 15) {
         case  0:return disEA0(a,b,c,d,buffer); break;
         case  1:return disEA1(a,b,c,d,buffer); break;
         case  2:return disEA2(a,b,c,d,buffer); break;
         case  3:return disEA3(a,b,c,d,buffer); break;
         case  4:return disEA4(a,b,c,d,buffer); break;
         case  5:return disEA5(a,b,c,d,buffer); break;
         case  6:return disEA6(a,b,c,d,buffer); break;
         case  7:return disEA7(a,b,c,d,buffer); break;
         case  8:return disEA8(a,b,c,d,buffer); break;
         case  9:return disEA9(a,b,c,d,buffer); break;
         case 10:return disEAA(a,b,c,d,buffer); break;
         case 11:return disEAB(a,b,c,d,buffer); break;
         case 12:return disEAC(a,b,c,d,buffer); break;
         case 13:return disEAD(a,b,c,d,buffer); break;
         case 14:return disEAE(a,b,c,d,buffer); break;
         case 15:return disEAF(a,b,c,d,buffer); break;
         } break;
      case 0xB0:switch (bt & 15) {
         case  0:return disEB0(a,b,c,d,buffer); break;
         case  1:return disEB1(a,b,c,d,buffer); break;
         case  2:return disEB2(a,b,c,d,buffer); break;
         case  3:return disEB3(a,b,c,d,buffer); break;
         case  4:return disEB4(a,b,c,d,buffer); break;
         case  5:return disEB5(a,b,c,d,buffer); break;
         case  6:return disEB6(a,b,c,d,buffer); break;
         case  7:return disEB7(a,b,c,d,buffer); break;
         case  8:return disEB8(a,b,c,d,buffer); break;
         case  9:return disEB9(a,b,c,d,buffer); break;
         case 10:return disEBA(a,b,c,d,buffer); break;
         case 11:return disEBB(a,b,c,d,buffer); break;
         case 12:return disEBC(a,b,c,d,buffer); break;
         case 13:return disEBD(a,b,c,d,buffer); break;
         case 14:return disEBE(a,b,c,d,buffer); break;
         case 15:return disEBF(a,b,c,d,buffer); break;
         } break;
      case 0xC0:switch (bt & 15) {
         case  0:return disEC0(a,b,c,d,buffer); break;
         case  1:return disEC1(a,b,c,d,buffer); break;
         case  2:return disEC2(a,b,c,d,buffer); break;
         case  3:return disEC3(a,b,c,d,buffer); break;
         case  4:return disEC4(a,b,c,d,buffer); break;
         case  5:return disEC5(a,b,c,d,buffer); break;
         case  6:return disEC6(a,b,c,d,buffer); break;
         case  7:return disEC7(a,b,c,d,buffer); break;
         case  8:return disEC8(a,b,c,d,buffer); break;
         case  9:return disEC9(a,b,c,d,buffer); break;
         case 10:return disECA(a,b,c,d,buffer); break;
         case 11:return disECB(a,b,c,d,buffer); break;
         case 12:return disECC(a,b,c,d,buffer); break;
         case 13:return disECD(a,b,c,d,buffer); break;
         case 14:return disECE(a,b,c,d,buffer); break;
         case 15:return disECF(a,b,c,d,buffer); break;
         } break;
      case 0xD0:switch (bt & 15) {
         case  0:return disED0(a,b,c,d,buffer); break;
         case  1:return disED1(a,b,c,d,buffer); break;
         case  2:return disED2(a,b,c,d,buffer); break;
         case  3:return disED3(a,b,c,d,buffer); break;
         case  4:return disED4(a,b,c,d,buffer); break;
         case  5:return disED5(a,b,c,d,buffer); break;
         case  6:return disED6(a,b,c,d,buffer); break;
         case  7:return disED7(a,b,c,d,buffer); break;
         case  8:return disED8(a,b,c,d,buffer); break;
         case  9:return disED9(a,b,c,d,buffer); break;
         case 10:return disEDA(a,b,c,d,buffer); break;
         case 11:return disEDB(a,b,c,d,buffer); break;
         case 12:return disEDC(a,b,c,d,buffer); break;
         case 13:return disEDD(a,b,c,d,buffer); break;
         case 14:return disEDE(a,b,c,d,buffer); break;
         case 15:return disEDF(a,b,c,d,buffer); break;
         } break;
      case 0xE0:switch (bt & 15) {
         case  0:return disEE0(a,b,c,d,buffer); break;
         case  1:return disEE1(a,b,c,d,buffer); break;
         case  2:return disEE2(a,b,c,d,buffer); break;
         case  3:return disEE3(a,b,c,d,buffer); break;
         case  4:return disEE4(a,b,c,d,buffer); break;
         case  5:return disEE5(a,b,c,d,buffer); break;
         case  6:return disEE6(a,b,c,d,buffer); break;
         case  7:return disEE7(a,b,c,d,buffer); break;
         case  8:return disEE8(a,b,c,d,buffer); break;
         case  9:return disEE9(a,b,c,d,buffer); break;
         case 10:return disEEA(a,b,c,d,buffer); break;
         case 11:return disEEB(a,b,c,d,buffer); break;
         case 12:return disEEC(a,b,c,d,buffer); break;
         case 13:return disEED(a,b,c,d,buffer); break;
         case 14:return disEEE(a,b,c,d,buffer); break;
         case 15:return disEEF(a,b,c,d,buffer); break;
         } break;
      case 0xF0:switch (bt & 15) {
         case  0:return disEF0(a,b,c,d,buffer); break;
         case  1:return disEF1(a,b,c,d,buffer); break;
         case  2:return disEF2(a,b,c,d,buffer); break;
         case  3:return disEF3(a,b,c,d,buffer); break;
         case  4:return disEF4(a,b,c,d,buffer); break;
         case  5:return disEF5(a,b,c,d,buffer); break;
         case  6:return disEF6(a,b,c,d,buffer); break;
         case  7:return disEF7(a,b,c,d,buffer); break;
         case  8:return disEF8(a,b,c,d,buffer); break;
         case  9:return disEF9(a,b,c,d,buffer); break;
         case 10:return disEFA(a,b,c,d,buffer); break;
         case 11:return disEFB(a,b,c,d,buffer); break;
         case 12:return disEFC(a,b,c,d,buffer); break;
         case 13:return disEFD(a,b,c,d,buffer); break;
         case 14:return disEFE(a,b,c,d,buffer); break;
         case 15:return disEFF(a,b,c,d,buffer); break;
         } break;

      }
  }

