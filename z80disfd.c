#include "header.h"

int disF00(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF01(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF02(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF03(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF04(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF05(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF06(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF07(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF08(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disF09(byte a,byte b,byte c,byte d,char *buffer)        /* ADD IY,BC */
  {
    sprintf(buffer,"%02x %02x       add iy,bc",a,b);
    return 2;
  }

int disF0A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF0B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF0C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF0D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF0E(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF0F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF10(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF11(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF12(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF13(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF14(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF15(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF16(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF17(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF18(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disF19(byte a,byte b,byte c,byte d,char *buffer)        /* ADD IY,DE */
  {
    sprintf(buffer,"%02x %02x       add iy,de",a,b);
    return 2;
  }

int disF1A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF1B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF1C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF1D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF1E(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF1F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF20(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disF21(byte a,byte b,byte c,byte d,char *buffer)        /* LD IY,nn */
  {
    sprintf(buffer,"%02x %02x %02x %02x ld iy,%04x",a,b,c,d,c+d*256);
    return 4;
  }

int disF22(byte a,byte b,byte c,byte d,char *buffer)        /* LD (nn),IY */
  {
    sprintf(buffer,"%02x %02x %02x %02x ld (%04x),iy",a,b,c,d,c+d*256);
    return 4;
  }

int disF23(byte a,byte b,byte c,byte d,char *buffer)        /* INC IY */
  {
    sprintf(buffer,"%02x %02x       inc iy",a,b);
    return 2;
  }

int disF24(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF25(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF26(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF27(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF28(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disF29(byte a,byte b,byte c,byte d,char *buffer)        /* ADD IY,IY */
  {
    sprintf(buffer,"%02x %02x       add iy,iy",a,b);
    return 2;
  }

int disF2A(byte a,byte b,byte c,byte d,char *buffer)        /* LD IY,(nn) */
  {
    sprintf(buffer,"%02x %02x %02x %02x ld iy,(%04x)",a,b,c,d,c+d*256);
    return 4;
  }

int disF2B(byte a,byte b,byte c,byte d,char *buffer)        /* DEC IY */
  {
    sprintf(buffer,"%02x %02x       dec iy",a,b);
    return 2;
  }

int disF2C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF2D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF2E(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF2F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF30(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF31(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF32(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF33(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disF34(byte a,byte b,byte c,byte d,char *buffer)        /* INC (IY+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    inc (iy-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    inc (iy+%02x)",a,b,c,o);
    return 3;
  }

int disF35(byte a,byte b,byte c,byte d,char *buffer)        /* DEC (IY+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    dec (iy-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    dec (iy+%02x)",a,b,c,o);
    return 3;
  }

int disF36(byte a,byte b,byte c,byte d,char *buffer)        /* LD (IY+d),n */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x %02x ld (iy-%02x),%02x",a,b,c,d,(0-o),d);
      else sprintf(buffer,"%02x %02x %02x %02x ld (iy+%02x),%02x",a,b,c,d,o,d);
    return 4;
  }

int disF37(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF38(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disF39(byte a,byte b,byte c,byte d,char *buffer)        /* ADD IY,SP */
  {
    sprintf(buffer,"%02x %02x       add iy,sp",a,b);
    return 2;
  }

int disF3A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF3B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF3C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF3D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF3E(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF3F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF40(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF41(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF42(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF43(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF44(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF45(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disF46(byte a,byte b,byte c,byte d,char *buffer)        /* LD B,(IY+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld b,(iy-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld b,(iy+%02x)",a,b,c,o);
    return 3;
  }

int disF47(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF48(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF49(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF4A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF4B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF4C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF4D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disF4E(byte a,byte b,byte c,byte d,char *buffer)        /* LD C,(IY+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld c,(iy-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld c,(iy+%02x)",a,b,c,o);
    return 3;
  }

int disF4F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF50(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF51(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF52(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF53(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF54(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF55(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disF56(byte a,byte b,byte c,byte d,char *buffer)        /* LD D,(IY+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld d,(iy-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld d,(iy+%02x)",a,b,c,o);
    return 3;
  }

int disF57(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF58(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF59(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF5A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF5B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF5C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF5D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disF5E(byte a,byte b,byte c,byte d,char *buffer)        /* LD E,(IY+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld e,(iy-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld e,(iy+%02x)",a,b,c,o);
    return 3;
  }

int disF5F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF60(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF61(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF62(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF63(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF64(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF65(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disF66(byte a,byte b,byte c,byte d,char *buffer)        /* LD H,(IY+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld h,(iy-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld h,(iy+%02x)",a,b,c,o);
    return 3;
  }

int disF67(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF68(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF69(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF6A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF6B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF6C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF6D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disF6E(byte a,byte b,byte c,byte d,char *buffer)        /* LD L,(IY+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld l,(iy-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld l,(iy+%02x)",a,b,c,o);
    return 3;
  }

int disF6F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disF70(byte a,byte b,byte c,byte d,char *buffer)        /* LD (IY+d),B */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld (iy-%02x),b",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld (iy+%02x),b",a,b,c,o);
    return 3;
  }

int disF71(byte a,byte b,byte c,byte d,char *buffer)        /* LD (IY+d),C */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld (iy-%02x),c",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld (iy+%02x),c",a,b,c,o);
    return 3;
  }

int disF72(byte a,byte b,byte c,byte d,char *buffer)        /* LD (IY+d),D */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld (iy-%02x),d",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld (iy+%02x),d",a,b,c,o);
    return 3;
  }

int disF73(byte a,byte b,byte c,byte d,char *buffer)        /* LD (IY+d),E */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld (iy-%02x),e",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld (iy+%02x),e",a,b,c,o);
    return 3;
  }

int disF74(byte a,byte b,byte c,byte d,char *buffer)        /* LD (IY+d),H */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld (iy-%02x),h",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld (iy+%02x),h",a,b,c,o);
    return 3;
  }

int disF75(byte a,byte b,byte c,byte d,char *buffer)        /* LD (IY+d),L */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld (iy-%02x),l",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld (iy+%02x),l",a,b,c,o);
    return 3;
  }

int disF76(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disF77(byte a,byte b,byte c,byte d,char *buffer)        /* LD (IY+d),A */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld (iy-%02x),a",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld (iy+%02x),a",a,b,c,o);
    return 3;
  }

int disF78(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF79(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF7A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF7B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF7C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF7D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disF7E(byte a,byte b,byte c,byte d,char *buffer)        /* LD A,(IY+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld a,(iy-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld a,(iy+%02x)",a,b,c,o);
    return 3;
  }

int disF7F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disF80(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF81(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF82(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF83(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF84(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF85(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disF86(byte a,byte b,byte c,byte d,char *buffer)        /* ADD A,(IY+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    add a,(iy-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    add a,(iy+%02x)",a,b,c,o);
    return 3;
  }

int disF87(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF88(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF89(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF8A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF8B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF8C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF8D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disF8E(byte a,byte b,byte c,byte d,char *buffer)        /* ADC A,(IY+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    adc a,(iy-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    adc a,(iy+%02x)",a,b,c,o);
    return 3;
  }

int disF8F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF90(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF91(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF92(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF93(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF94(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF95(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disF96(byte a,byte b,byte c,byte d,char *buffer)        /* SUB A,(IY+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    sub a,(iy-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    sub a,(iy+%02x)",a,b,c,o);
    return 3;
  }

int disF97(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF98(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF99(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF9A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF9B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF9C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disF9D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disF9E(byte a,byte b,byte c,byte d,char *buffer)        /* SBC A,(IY+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    sbc a,(iy-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    sbc a,(iy+%02x)",a,b,c,o);
    return 3;
  }

int disF9F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFA0(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFA1(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFA2(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFA3(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFA4(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFA5(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disFA6(byte a,byte b,byte c,byte d,char *buffer)        /* AND (IY+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    and (iy-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    and (iy+%02x)",a,b,c,o);
    return 3;
  }

int disFA7(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFA8(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFA9(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFAA(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFAB(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFAC(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFAD(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disFAE(byte a,byte b,byte c,byte d,char *buffer)        /* XOR (IY+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    xor (iy-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    xor (iy+%02x)",a,b,c,o);
    return 3;
  }

int disFAF(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFB0(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFB1(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFB2(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFB3(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFB4(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFB5(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disFB6(byte a,byte b,byte c,byte d,char *buffer)        /* OR (IY+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    or (iy-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    or (iy+%02x)",a,b,c,o);
    return 3;
  }

int disFB7(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFB8(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFB9(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFBA(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFBB(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFBC(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFBD(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disFBE(byte a,byte b,byte c,byte d,char *buffer)        /* CP (IY+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    cp (iy-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    cp (iy+%02x)",a,b,c,o);
    return 3;
  }

int disFBF(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disFC0(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFC1(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFC2(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFC3(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFC4(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFC5(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFC6(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFC7(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFC8(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFC9(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFCA(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disFCB(byte a,byte b,byte c,byte d,char *buffer)
  {
    word Adr;
    byte Cmd;
    byte Cy,Cy2;
    byte Wrk;
    int o;
    o=Offset(c);
    Cmd=d;
    if (Cmd<=0x07) {                   /* RLC */
      if (o<0) sprintf(buffer,"%02x %02x %02x %02x rlc (iy-%02x)",a,b,c,d,(0-o));
        else sprintf(buffer,"%02x %02x %02x %02x rlc (iy+%02x)",a,b,c,d,o);
      }
    else if (Cmd<=0x0f) {              /* RRC */
      if (o<0) sprintf(buffer,"%02x %02x %02x %02x rrc (iy-%02x)",a,b,c,d,(0-o));
        else sprintf(buffer,"%02x %02x %02x %02x rrc (iy+%02x)",a,b,c,d,o);
      }
    else if (Cmd<=0x17) {              /* RL */
      if (o<0) sprintf(buffer,"%02x %02x %02x %02x rl (iy-%02x)",a,b,c,d,(0-o));
        else sprintf(buffer,"%02x %02x %02x %02x rl (iy+%02x)",a,b,c,d,o);
      }
    else if (Cmd<=0x1f) {              /* RR */
      if (o<0) sprintf(buffer,"%02x %02x %02x %02x rr (iy-%02x)",a,b,c,d,(0-o));
        else sprintf(buffer,"%02x %02x %02x %02x rr (iy+%02x)",a,b,c,d,o);
      }
    else if (Cmd<=0x27) {              /* SLA */
      if (o<0) sprintf(buffer,"%02x %02x %02x %02x sla (iy-%02x)",a,b,c,d,(0-o));
        else sprintf(buffer,"%02x %02x %02x %02x sla (iy+%02x)",a,b,c,d,o);
      }
    else if (Cmd<=0x2f) {              /* SRA */
      if (o<0) sprintf(buffer,"%02x %02x %02x %02x sra (iy-%02x)",a,b,c,d,(0-o));
        else sprintf(buffer,"%02x %02x %02x %02x sra (iy+%02x)",a,b,c,d,o);
      }
    else if (Cmd<=0x3f) {              /* SRL */
      if (o<0) sprintf(buffer,"%02x %02x %02x %02x srl (iy-%02x)",a,b,c,d,(0-o));
        else sprintf(buffer,"%02x %02x %02x %02x srl (iy+%02x)",a,b,c,d,o);
      }
    else if (Cmd<=0x7f) {              /* BIT */
      if (o<0) sprintf(buffer,"%02x %02x %02x %02x bit %d,(iy-%02x)",a,b,c,d,(Cmd>>3)&7,(0-o));
        else sprintf(buffer,"%02x %02x %02x %02x bit %d,(iy+%02x)",a,b,c,d,(Cmd>>3)&7,o);
      }
    else if (Cmd<=0xbf) {              /* RES */
      if (o<0) sprintf(buffer,"%02x %02x %02x %02x res %d,(iy-%02x)",a,b,c,d,(Cmd>>3)&7,(0-o));
        else sprintf(buffer,"%02x %02x %02x %02x res %d,(iy+%02x)",a,b,c,d,(Cmd>>3)&7,o);
      }
    else {                             /* SET */
      if (o<0) sprintf(buffer,"%02x %02x %02x %02x set %d,(iy-%02x)",a,b,c,d,(Cmd>>3)&7,(0-o));
        else sprintf(buffer,"%02x %02x %02x %02x set %d,(iy+%02x)",a,b,c,d,(Cmd>>3)&7,o);
      }
    return 4;
  }
          
int disFCC(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFCD(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFCE(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFCF(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disFD0(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFD1(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFD2(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFD3(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFD4(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFD5(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFD6(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFD7(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFD8(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFD9(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFDA(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFDB(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFDC(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFDD(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFDE(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFDF(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFE0(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disFE1(byte a,byte b,byte c,byte d,char *buffer)        /* POP IY */
  {
    sprintf(buffer,"%02x %02x       pop iy",a,b);
    return 2;
  }

int disFE2(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disFE3(byte a,byte b,byte c,byte d,char *buffer)        /* EX (SP),IY */
  {
    sprintf(buffer,"%02x %02x       ex (sp),iy",a,b);
    return 2;
  }

int disFE4(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disFE5(byte a,byte b,byte c,byte d,char *buffer)        /* PUSH IY */
  {
    sprintf(buffer,"%02x %02x       push iy",a,b);
    return 2;
  }

int disFE6(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFE7(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFE8(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disFE9(byte a,byte b,byte c,byte d,char *buffer)        /* JP (IY) */
  {
    sprintf(buffer,"%02x %02x       jp (iy)",a,b);
    return 2;
  }

int disFEA(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFEB(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFEC(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFED(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFEE(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFEF(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFF0(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFF1(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFF2(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFF3(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFF4(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFF5(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFF6(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFF7(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFF8(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disFF9(byte a,byte b,byte c,byte d,char *buffer)        /* LD SP,IY */
  {
    sprintf(buffer,"%02x %02x       ld sp,iy",a,b);
    return 2;
  }

int disFFA(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFFB(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFFC(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFFD(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFFE(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disFFF(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disPFD(byte a,byte b,byte c,byte d,char *buffer)
  {
    byte bt;
    bt=b;
    switch (bt & 0xf0) {
      case 0x00:switch (bt & 15) {
         case  0:return disF00(a,b,c,d,buffer); break;
         case  1:return disF01(a,b,c,d,buffer); break;
         case  2:return disF02(a,b,c,d,buffer); break;
         case  3:return disF03(a,b,c,d,buffer); break;
         case  4:return disF04(a,b,c,d,buffer); break;
         case  5:return disF05(a,b,c,d,buffer); break;
         case  6:return disF06(a,b,c,d,buffer); break;
         case  7:return disF07(a,b,c,d,buffer); break;
         case  8:return disF08(a,b,c,d,buffer); break;
         case  9:return disF09(a,b,c,d,buffer); break;
         case 10:return disF0A(a,b,c,d,buffer); break;
         case 11:return disF0B(a,b,c,d,buffer); break;
         case 12:return disF0C(a,b,c,d,buffer); break;
         case 13:return disF0D(a,b,c,d,buffer); break;
         case 14:return disF0E(a,b,c,d,buffer); break;
         case 15:return disF0F(a,b,c,d,buffer); break;
         } break;

      case 0x10:switch (bt & 15) {
         case  0:return disF10(a,b,c,d,buffer); break;
         case  1:return disF11(a,b,c,d,buffer); break;
         case  2:return disF12(a,b,c,d,buffer); break;
         case  3:return disF13(a,b,c,d,buffer); break;
         case  4:return disF14(a,b,c,d,buffer); break;
         case  5:return disF15(a,b,c,d,buffer); break;
         case  6:return disF16(a,b,c,d,buffer); break;
         case  7:return disF17(a,b,c,d,buffer); break;
         case  8:return disF18(a,b,c,d,buffer); break;
         case  9:return disF19(a,b,c,d,buffer); break;
         case 10:return disF1A(a,b,c,d,buffer); break;
         case 11:return disF1B(a,b,c,d,buffer); break;
         case 12:return disF1C(a,b,c,d,buffer); break;
         case 13:return disF1D(a,b,c,d,buffer); break;
         case 14:return disF1E(a,b,c,d,buffer); break;
         case 15:return disF1F(a,b,c,d,buffer); break;
         } break;
      case 0x20:switch (bt & 15) {
         case  0:return disF20(a,b,c,d,buffer); break;
         case  1:return disF21(a,b,c,d,buffer); break;
         case  2:return disF22(a,b,c,d,buffer); break;
         case  3:return disF23(a,b,c,d,buffer); break;
         case  4:return disF24(a,b,c,d,buffer); break;
         case  5:return disF25(a,b,c,d,buffer); break;
         case  6:return disF26(a,b,c,d,buffer); break;
         case  7:return disF27(a,b,c,d,buffer); break;
         case  8:return disF28(a,b,c,d,buffer); break;
         case  9:return disF29(a,b,c,d,buffer); break;
         case 10:return disF2A(a,b,c,d,buffer); break;
         case 11:return disF2B(a,b,c,d,buffer); break;
         case 12:return disF2C(a,b,c,d,buffer); break;
         case 13:return disF2D(a,b,c,d,buffer); break;
         case 14:return disF2E(a,b,c,d,buffer); break;
         case 15:return disF2F(a,b,c,d,buffer); break;
         } break;
      case 0x30:switch (bt & 15) {
         case  0:return disF30(a,b,c,d,buffer); break;
         case  1:return disF31(a,b,c,d,buffer); break;
         case  2:return disF32(a,b,c,d,buffer); break;
         case  3:return disF33(a,b,c,d,buffer); break;
         case  4:return disF34(a,b,c,d,buffer); break;
         case  5:return disF35(a,b,c,d,buffer); break;
         case  6:return disF36(a,b,c,d,buffer); break;
         case  7:return disF37(a,b,c,d,buffer); break;
         case  8:return disF38(a,b,c,d,buffer); break;
         case  9:return disF39(a,b,c,d,buffer); break;
         case 10:return disF3A(a,b,c,d,buffer); break;
         case 11:return disF3B(a,b,c,d,buffer); break;
         case 12:return disF3C(a,b,c,d,buffer); break;
         case 13:return disF3D(a,b,c,d,buffer); break;
         case 14:return disF3E(a,b,c,d,buffer); break;
         case 15:return disF3F(a,b,c,d,buffer); break;
         } break;
      case 0x40:switch (bt & 15) {
         case  0:return disF40(a,b,c,d,buffer); break;
         case  1:return disF41(a,b,c,d,buffer); break;
         case  2:return disF42(a,b,c,d,buffer); break;
         case  3:return disF43(a,b,c,d,buffer); break;
         case  4:return disF44(a,b,c,d,buffer); break;
         case  5:return disF45(a,b,c,d,buffer); break;
         case  6:return disF46(a,b,c,d,buffer); break;
         case  7:return disF47(a,b,c,d,buffer); break;
         case  8:return disF48(a,b,c,d,buffer); break;
         case  9:return disF49(a,b,c,d,buffer); break;
         case 10:return disF4A(a,b,c,d,buffer); break;
         case 11:return disF4B(a,b,c,d,buffer); break;
         case 12:return disF4C(a,b,c,d,buffer); break;
         case 13:return disF4D(a,b,c,d,buffer); break;
         case 14:return disF4E(a,b,c,d,buffer); break;
         case 15:return disF4F(a,b,c,d,buffer); break;
         } break;
      case 0x50:switch (bt & 15) {
         case  0:return disF50(a,b,c,d,buffer); break;
         case  1:return disF51(a,b,c,d,buffer); break;
         case  2:return disF52(a,b,c,d,buffer); break;
         case  3:return disF53(a,b,c,d,buffer); break;
         case  4:return disF54(a,b,c,d,buffer); break;
         case  5:return disF55(a,b,c,d,buffer); break;
         case  6:return disF56(a,b,c,d,buffer); break;
         case  7:return disF57(a,b,c,d,buffer); break;
         case  8:return disF58(a,b,c,d,buffer); break;
         case  9:return disF59(a,b,c,d,buffer); break;
         case 10:return disF5A(a,b,c,d,buffer); break;
         case 11:return disF5B(a,b,c,d,buffer); break;
         case 12:return disF5C(a,b,c,d,buffer); break;
         case 13:return disF5D(a,b,c,d,buffer); break;
         case 14:return disF5E(a,b,c,d,buffer); break;
         case 15:return disF5F(a,b,c,d,buffer); break;
         } break;
      case 0x60:switch (bt & 15) {
         case  0:return disF60(a,b,c,d,buffer); break;
         case  1:return disF61(a,b,c,d,buffer); break;
         case  2:return disF62(a,b,c,d,buffer); break;
         case  3:return disF63(a,b,c,d,buffer); break;
         case  4:return disF64(a,b,c,d,buffer); break;
         case  5:return disF65(a,b,c,d,buffer); break;
         case  6:return disF66(a,b,c,d,buffer); break;
         case  7:return disF67(a,b,c,d,buffer); break;
         case  8:return disF68(a,b,c,d,buffer); break;
         case  9:return disF69(a,b,c,d,buffer); break;
         case 10:return disF6A(a,b,c,d,buffer); break;
         case 11:return disF6B(a,b,c,d,buffer); break;
         case 12:return disF6C(a,b,c,d,buffer); break;
         case 13:return disF6D(a,b,c,d,buffer); break;
         case 14:return disF6E(a,b,c,d,buffer); break;
         case 15:return disF6F(a,b,c,d,buffer); break;
         } break;
      case 0x70:switch (bt & 15) {
         case  0:return disF70(a,b,c,d,buffer); break;
         case  1:return disF71(a,b,c,d,buffer); break;
         case  2:return disF72(a,b,c,d,buffer); break;
         case  3:return disF73(a,b,c,d,buffer); break;
         case  4:return disF74(a,b,c,d,buffer); break;
         case  5:return disF75(a,b,c,d,buffer); break;
         case  6:return disF76(a,b,c,d,buffer); break;
         case  7:return disF77(a,b,c,d,buffer); break;
         case  8:return disF78(a,b,c,d,buffer); break;
         case  9:return disF79(a,b,c,d,buffer); break;
         case 10:return disF7A(a,b,c,d,buffer); break;
         case 11:return disF7B(a,b,c,d,buffer); break;
         case 12:return disF7C(a,b,c,d,buffer); break;
         case 13:return disF7D(a,b,c,d,buffer); break;
         case 14:return disF7E(a,b,c,d,buffer); break;
         case 15:return disF7F(a,b,c,d,buffer); break;
         } break;
      case 0x80:switch (bt & 15) {
         case  0:return disF80(a,b,c,d,buffer); break;
         case  1:return disF81(a,b,c,d,buffer); break;
         case  2:return disF82(a,b,c,d,buffer); break;
         case  3:return disF83(a,b,c,d,buffer); break;
         case  4:return disF84(a,b,c,d,buffer); break;
         case  5:return disF85(a,b,c,d,buffer); break;
         case  6:return disF86(a,b,c,d,buffer); break;
         case  7:return disF87(a,b,c,d,buffer); break;
         case  8:return disF88(a,b,c,d,buffer); break;
         case  9:return disF89(a,b,c,d,buffer); break;
         case 10:return disF8A(a,b,c,d,buffer); break;
         case 11:return disF8B(a,b,c,d,buffer); break;
         case 12:return disF8C(a,b,c,d,buffer); break;
         case 13:return disF8D(a,b,c,d,buffer); break;
         case 14:return disF8E(a,b,c,d,buffer); break;
         case 15:return disF8F(a,b,c,d,buffer); break;
         } break;

      case 0x90:switch (bt & 15) {
         case  0:return disF90(a,b,c,d,buffer); break;
         case  1:return disF91(a,b,c,d,buffer); break;
         case  2:return disF92(a,b,c,d,buffer); break;
         case  3:return disF93(a,b,c,d,buffer); break;
         case  4:return disF94(a,b,c,d,buffer); break;
         case  5:return disF95(a,b,c,d,buffer); break;
         case  6:return disF96(a,b,c,d,buffer); break;
         case  7:return disF97(a,b,c,d,buffer); break;
         case  8:return disF98(a,b,c,d,buffer); break;
         case  9:return disF99(a,b,c,d,buffer); break;
         case 10:return disF9A(a,b,c,d,buffer); break;
         case 11:return disF9B(a,b,c,d,buffer); break;
         case 12:return disF9C(a,b,c,d,buffer); break;
         case 13:return disF9D(a,b,c,d,buffer); break;
         case 14:return disF9E(a,b,c,d,buffer); break;
         case 15:return disF9F(a,b,c,d,buffer); break;
         } break;
      case 0xA0:switch (bt & 15) {
         case  0:return disFA0(a,b,c,d,buffer); break;
         case  1:return disFA1(a,b,c,d,buffer); break;
         case  2:return disFA2(a,b,c,d,buffer); break;
         case  3:return disFA3(a,b,c,d,buffer); break;
         case  4:return disFA4(a,b,c,d,buffer); break;
         case  5:return disFA5(a,b,c,d,buffer); break;
         case  6:return disFA6(a,b,c,d,buffer); break;
         case  7:return disFA7(a,b,c,d,buffer); break;
         case  8:return disFA8(a,b,c,d,buffer); break;
         case  9:return disFA9(a,b,c,d,buffer); break;
         case 10:return disFAA(a,b,c,d,buffer); break;
         case 11:return disFAB(a,b,c,d,buffer); break;
         case 12:return disFAC(a,b,c,d,buffer); break;
         case 13:return disFAD(a,b,c,d,buffer); break;
         case 14:return disFAE(a,b,c,d,buffer); break;
         case 15:return disFAF(a,b,c,d,buffer); break;
         } break;
      case 0xB0:switch (bt & 15) {
         case  0:return disFB0(a,b,c,d,buffer); break;
         case  1:return disFB1(a,b,c,d,buffer); break;
         case  2:return disFB2(a,b,c,d,buffer); break;
         case  3:return disFB3(a,b,c,d,buffer); break;
         case  4:return disFB4(a,b,c,d,buffer); break;
         case  5:return disFB5(a,b,c,d,buffer); break;
         case  6:return disFB6(a,b,c,d,buffer); break;
         case  7:return disFB7(a,b,c,d,buffer); break;
         case  8:return disFB8(a,b,c,d,buffer); break;
         case  9:return disFB9(a,b,c,d,buffer); break;
         case 10:return disFBA(a,b,c,d,buffer); break;
         case 11:return disFBB(a,b,c,d,buffer); break;
         case 12:return disFBC(a,b,c,d,buffer); break;
         case 13:return disFBD(a,b,c,d,buffer); break;
         case 14:return disFBE(a,b,c,d,buffer); break;
         case 15:return disFBF(a,b,c,d,buffer); break;
         } break;
      case 0xC0:switch (bt & 15) {
         case  0:return disFC0(a,b,c,d,buffer); break;
         case  1:return disFC1(a,b,c,d,buffer); break;
         case  2:return disFC2(a,b,c,d,buffer); break;
         case  3:return disFC3(a,b,c,d,buffer); break;
         case  4:return disFC4(a,b,c,d,buffer); break;
         case  5:return disFC5(a,b,c,d,buffer); break;
         case  6:return disFC6(a,b,c,d,buffer); break;
         case  7:return disFC7(a,b,c,d,buffer); break;
         case  8:return disFC8(a,b,c,d,buffer); break;
         case  9:return disFC9(a,b,c,d,buffer); break;
         case 10:return disFCA(a,b,c,d,buffer); break;
         case 11:return disFCB(a,b,c,d,buffer); break;
         case 12:return disFCC(a,b,c,d,buffer); break;
         case 13:return disFCD(a,b,c,d,buffer); break;
         case 14:return disFCE(a,b,c,d,buffer); break;
         case 15:return disFCF(a,b,c,d,buffer); break;
         } break;
      case 0xD0:switch (bt & 15) {
         case  0:return disFD0(a,b,c,d,buffer); break;
         case  1:return disFD1(a,b,c,d,buffer); break;
         case  2:return disFD2(a,b,c,d,buffer); break;
         case  3:return disFD3(a,b,c,d,buffer); break;
         case  4:return disFD4(a,b,c,d,buffer); break;
         case  5:return disFD5(a,b,c,d,buffer); break;
         case  6:return disFD6(a,b,c,d,buffer); break;
         case  7:return disFD7(a,b,c,d,buffer); break;
         case  8:return disFD8(a,b,c,d,buffer); break;
         case  9:return disFD9(a,b,c,d,buffer); break;
         case 10:return disFDA(a,b,c,d,buffer); break;
         case 11:return disFDB(a,b,c,d,buffer); break;
         case 12:return disFDC(a,b,c,d,buffer); break;
         case 13:return disFDD(a,b,c,d,buffer); break;
         case 14:return disFDE(a,b,c,d,buffer); break;
         case 15:return disFDF(a,b,c,d,buffer); break;
         } break;
      case 0xE0:switch (bt & 15) {
         case  0:return disFE0(a,b,c,d,buffer); break;
         case  1:return disFE1(a,b,c,d,buffer); break;
         case  2:return disFE2(a,b,c,d,buffer); break;
         case  3:return disFE3(a,b,c,d,buffer); break;
         case  4:return disFE4(a,b,c,d,buffer); break;
         case  5:return disFE5(a,b,c,d,buffer); break;
         case  6:return disFE6(a,b,c,d,buffer); break;
         case  7:return disFE7(a,b,c,d,buffer); break;
         case  8:return disFE8(a,b,c,d,buffer); break;
         case  9:return disFE9(a,b,c,d,buffer); break;
         case 10:return disFEA(a,b,c,d,buffer); break;
         case 11:return disFEB(a,b,c,d,buffer); break;
         case 12:return disFEC(a,b,c,d,buffer); break;
         case 13:return disFED(a,b,c,d,buffer); break;
         case 14:return disFEE(a,b,c,d,buffer); break;
         case 15:return disFEF(a,b,c,d,buffer); break;
         } break;
      case 0xF0:switch (bt & 15) {
         case  0:return disFF0(a,b,c,d,buffer); break;
         case  1:return disFF1(a,b,c,d,buffer); break;
         case  2:return disFF2(a,b,c,d,buffer); break;
         case  3:return disFF3(a,b,c,d,buffer); break;
         case  4:return disFF4(a,b,c,d,buffer); break;
         case  5:return disFF5(a,b,c,d,buffer); break;
         case  6:return disFF6(a,b,c,d,buffer); break;
         case  7:return disFF7(a,b,c,d,buffer); break;
         case  8:return disFF8(a,b,c,d,buffer); break;
         case  9:return disFF9(a,b,c,d,buffer); break;
         case 10:return disFFA(a,b,c,d,buffer); break;
         case 11:return disFFB(a,b,c,d,buffer); break;
         case 12:return disFFC(a,b,c,d,buffer); break;
         case 13:return disFFD(a,b,c,d,buffer); break;
         case 14:return disFFE(a,b,c,d,buffer); break;
         case 15:return disFFF(a,b,c,d,buffer); break;
         } break;

      }
  }

