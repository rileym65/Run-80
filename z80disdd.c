#include "header.h"

int disD00(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD01(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD02(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD03(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD04(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD05(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD06(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD07(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD08(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disD09(byte a,byte b,byte c,byte d,char *buffer)        /* ADD IX,BC */
  {
    sprintf(buffer,"%02x %02x       add ix,bc",a,b);
    return 2;
  }

int disD0A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD0B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD0C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD0D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD0E(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD0F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD10(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD11(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD12(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD13(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD14(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD15(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD16(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD17(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD18(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disD19(byte a,byte b,byte c,byte d,char *buffer)        /* ADD IX,DE */
  {
    sprintf(buffer,"%02x %02x       add ix,de",a,b);
    return 2;
  }

int disD1A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD1B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD1C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD1D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD1E(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD1F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD20(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disD21(byte a,byte b,byte c,byte d,char *buffer)        /* LD IX,nn */
  {
    sprintf(buffer,"%02x %02x %02x %02x ld ix,%04x",a,b,c,d,c+d*256);
    return 4;
  }

int disD22(byte a,byte b,byte c,byte d,char *buffer)        /* LD (nn),IX */
  {
    sprintf(buffer,"%02x %02x %02x %02x ld (%04x),ix",a,b,c,d,c+d*256);
    return 4;
  }

int disD23(byte a,byte b,byte c,byte d,char *buffer)        /* INC IX */
  {
    sprintf(buffer,"%02x %02x       inc ix",a,b);
    return 2;
  }

int disD24(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD25(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD26(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD27(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD28(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disD29(byte a,byte b,byte c,byte d,char *buffer)        /* ADD IX,IX */
  {
    sprintf(buffer,"%02x %02x       add ix,ix",a,b);
    return 2;
  }

int disD2A(byte a,byte b,byte c,byte d,char *buffer)        /* LD IX,(nn) */
  {
    sprintf(buffer,"%02x %02x %02x %02x ld ix,(%04x)",a,b,c,d,c+d*256);
    return 4;
  }

int disD2B(byte a,byte b,byte c,byte d,char *buffer)        /* DEC IX */
  {
    sprintf(buffer,"%02x %02x       dec ix",a,b);
    return 2;
  }

int disD2C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD2D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD2E(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD2F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD30(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD31(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD32(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD33(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disD34(byte a,byte b,byte c,byte d,char *buffer)        /* INC (IX+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    inc (ix-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    inc (ix+%02x)",a,b,c,o);
    return 3;
  }

int disD35(byte a,byte b,byte c,byte d,char *buffer)        /* DEC (IX+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    dec (ix-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    dec (ix+%02x)",a,b,c,o);
    return 3;
  }

int disD36(byte a,byte b,byte c,byte d,char *buffer)        /* LD (IX+d),n */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x %02x ld (ix-%02x),%02x",a,b,c,d,(0-o),d);
      else sprintf(buffer,"%02x %02x %02x %02x ld (ix+%02x),%02x",a,b,c,d,o,d);
    return 4;
  }

int disD37(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD38(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disD39(byte a,byte b,byte c,byte d,char *buffer)        /* ADD IX,SP */
  {
    sprintf(buffer,"%02x %02x       add ix,sp",a,b);
    return 2;
  }

int disD3A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD3B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD3C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD3D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD3E(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD3F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD40(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD41(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD42(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD43(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD44(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD45(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disD46(byte a,byte b,byte c,byte d,char *buffer)        /* LD B,(IX+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld b,(ix-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld b,(ix+%02x)",a,b,c,o);
    return 3;
  }

int disD47(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD48(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD49(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD4A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD4B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD4C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD4D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disD4E(byte a,byte b,byte c,byte d,char *buffer)        /* LD C,(IX+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld c,(ix-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld c,(ix+%02x)",a,b,c,o);
    return 3;
  }

int disD4F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD50(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD51(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD52(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD53(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD54(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD55(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disD56(byte a,byte b,byte c,byte d,char *buffer)        /* LD D,(IX+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld d,(ix-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld d,(ix+%02x)",a,b,c,o);
    return 3;
  }

int disD57(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD58(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD59(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD5A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD5B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD5C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD5D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disD5E(byte a,byte b,byte c,byte d,char *buffer)        /* LD E,(IX+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld e,(ix-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld e,(ix+%02x)",a,b,c,o);
    return 3;
  }

int disD5F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD60(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD61(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD62(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD63(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD64(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD65(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disD66(byte a,byte b,byte c,byte d,char *buffer)        /* LD H,(IX+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld h,(ix-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld h,(ix+%02x)",a,b,c,o);
    return 3;
  }

int disD67(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD68(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD69(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD6A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD6B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD6C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD6D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disD6E(byte a,byte b,byte c,byte d,char *buffer)        /* LD L,(IX+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld l,(ix-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld l,(ix+%02x)",a,b,c,o);
    return 3;
  }

int disD6F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disD70(byte a,byte b,byte c,byte d,char *buffer)        /* LD (IX+d),B */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld (ix-%02x),b",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld (ix+%02x),b",a,b,c,o);
    return 3;
  }

int disD71(byte a,byte b,byte c,byte d,char *buffer)        /* LD (IX+d),C */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld (ix-%02x),c",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld (ix+%02x),c",a,b,c,o);
    return 3;
  }

int disD72(byte a,byte b,byte c,byte d,char *buffer)        /* LD (IX+d),D */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld (ix-%02x),d",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld (ix+%02x),d",a,b,c,o);
    return 3;
  }

int disD73(byte a,byte b,byte c,byte d,char *buffer)        /* LD (IX+d),E */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld (ix-%02x),e",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld (ix+%02x),e",a,b,c,o);
    return 3;
  }

int disD74(byte a,byte b,byte c,byte d,char *buffer)        /* LD (IX+d),H */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld (ix-%02x),h",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld (ix+%02x),h",a,b,c,o);
    return 3;
  }

int disD75(byte a,byte b,byte c,byte d,char *buffer)        /* LD (IX+d),L */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld (ix-%02x),l",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld (ix+%02x),l",a,b,c,o);
    return 3;
  }

int disD76(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disD77(byte a,byte b,byte c,byte d,char *buffer)        /* LD (IX+d),A */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld (ix-%02x),a",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld (ix+%02x),a",a,b,c,o);
    return 3;
  }

int disD78(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD79(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD7A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD7B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD7C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD7D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disD7E(byte a,byte b,byte c,byte d,char *buffer)        /* LD A,(IX+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    ld a,(ix-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    ld a,(ix+%02x)",a,b,c,o);
    return 3;
  }

int disD7F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disD80(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD81(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD82(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD83(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD84(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD85(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disD86(byte a,byte b,byte c,byte d,char *buffer)        /* ADD A,(IX+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    add a,(ix-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    add a,(ix+%02x)",a,b,c,o);
    return 3;
  }

int disD87(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD88(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD89(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD8A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD8B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD8C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD8D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disD8E(byte a,byte b,byte c,byte d,char *buffer)        /* ADC A,(IX+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    adc a,(ix-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    adc a,(ix+%02x)",a,b,c,o);
    return 3;
  }

int disD8F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD90(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD91(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD92(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD93(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD94(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD95(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disD96(byte a,byte b,byte c,byte d,char *buffer)        /* SUB A,(IX+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    sub a,(ix-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    sub a,(ix+%02x)",a,b,c,o);
    return 3;
  }

int disD97(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD98(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD99(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD9A(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD9B(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD9C(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disD9D(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disD9E(byte a,byte b,byte c,byte d,char *buffer)        /* SBC A,(IX+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    sbc a,(ix-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    sbc a,(ix+%02x)",a,b,c,o);
    return 3;
  }

int disD9F(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDA0(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDA1(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDA2(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDA3(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDA4(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDA5(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disDA6(byte a,byte b,byte c,byte d,char *buffer)        /* AND (IX+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    and (ix-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    and (ix+%02x)",a,b,c,o);
    return 3;
  }

int disDA7(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDA8(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDA9(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDAA(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDAB(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDAC(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDAD(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disDAE(byte a,byte b,byte c,byte d,char *buffer)        /* XOR (IX+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    xor (ix-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    xor (ix+%02x)",a,b,c,o);
    return 3;
  }

int disDAF(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDB0(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDB1(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDB2(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDB3(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDB4(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDB5(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disDB6(byte a,byte b,byte c,byte d,char *buffer)        /* OR (IX+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    or (ix-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    or (ix+%02x)",a,b,c,o);
    return 3;
  }

int disDB7(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDB8(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDB9(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDBA(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDBB(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDBC(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDBD(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disDBE(byte a,byte b,byte c,byte d,char *buffer)        /* CP (IX+d) */
  {
    int o;
    o=Offset(c);
    if (o<0) sprintf(buffer,"%02x %02x %02x    cp (ix-%02x)",a,b,c,(0-o));
      else sprintf(buffer,"%02x %02x %02x    cp (ix+%02x)",a,b,c,o);
    return 3;
  }

int disDBF(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disDC0(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDC1(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDC2(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDC3(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDC4(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDC5(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDC6(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDC7(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDC8(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDC9(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDCA(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disDCB(byte a,byte b,byte c,byte d,char *buffer)
  {
    word Adr;
    byte Cmd;
    byte Cy,Cy2;
    byte Wrk;
    int o;
    o=Offset(c);
    Cmd=d;
    if (Cmd<=0x07) {                   /* RLC */
      if (o<0) sprintf(buffer,"%02x %02x %02x %02x rlc (ix-%02x)",a,b,c,d,(0-o));
        else sprintf(buffer,"%02x %02x %02x %02x rlc (ix+%02x)",a,b,c,d,o);
      }
    else if (Cmd<=0x0f) {              /* RRC */
      if (o<0) sprintf(buffer,"%02x %02x %02x %02x rrc (ix-%02x)",a,b,c,d,(0-o));
        else sprintf(buffer,"%02x %02x %02x %02x rrc (ix+%02x)",a,b,c,d,o);
      }
    else if (Cmd<=0x17) {              /* RL */
      if (o<0) sprintf(buffer,"%02x %02x %02x %02x rl (ix-%02x)",a,b,c,d,(0-o));
        else sprintf(buffer,"%02x %02x %02x %02x rl (ix+%02x)",a,b,c,d,o);
      }
    else if (Cmd<=0x1f) {              /* RR */
      if (o<0) sprintf(buffer,"%02x %02x %02x %02x rr (ix-%02x)",a,b,c,d,(0-o));
        else sprintf(buffer,"%02x %02x %02x %02x rr (ix+%02x)",a,b,c,d,o);
      }
    else if (Cmd<=0x27) {              /* SLA */
      if (o<0) sprintf(buffer,"%02x %02x %02x %02x sla (ix-%02x)",a,b,c,d,(0-o));
        else sprintf(buffer,"%02x %02x %02x %02x sla (ix+%02x)",a,b,c,d,o);
      }
    else if (Cmd<=0x2f) {              /* SRA */
      if (o<0) sprintf(buffer,"%02x %02x %02x %02x sra (ix-%02x)",a,b,c,d,(0-o));
        else sprintf(buffer,"%02x %02x %02x %02x sra (ix+%02x)",a,b,c,d,o);
      }
    else if (Cmd<=0x3f) {              /* SRL */
      if (o<0) sprintf(buffer,"%02x %02x %02x %02x srl (ix-%02x)",a,b,c,d,(0-o));
        else sprintf(buffer,"%02x %02x %02x %02x srl (ix+%02x)",a,b,c,d,o);
      }
    else if (Cmd<=0x7f) {              /* BIT */
      if (o<0) sprintf(buffer,"%02x %02x %02x %02x bit %d,(ix-%02x)",a,b,c,d,(Cmd>>3)&7,(0-o));
        else sprintf(buffer,"%02x %02x %02x %02x bit %d,(ix+%02x)",a,b,c,d,(Cmd>>3)&7,o);
      }
    else if (Cmd<=0xbf) {              /* RES */
      if (o<0) sprintf(buffer,"%02x %02x %02x %02x res %d,(ix-%02x)",a,b,c,d,(Cmd>>3)&7,(0-o));
        else sprintf(buffer,"%02x %02x %02x %02x res %d,(ix+%02x)",a,b,c,d,(Cmd>>3)&7,o);
      }
    else {                             /* SET */
      if (o<0) sprintf(buffer,"%02x %02x %02x %02x set %d,(ix-%02x)",a,b,c,d,(Cmd>>3)&7,(0-o));
        else sprintf(buffer,"%02x %02x %02x %02x set %d,(ix+%02x)",a,b,c,d,(Cmd>>3)&7,o);
      }
    return 4;
  }
          
int disDCC(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDCD(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDCE(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDCF(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disDD0(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDD1(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDD2(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDD3(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDD4(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDD5(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDD6(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDD7(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDD8(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDD9(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDDA(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDDB(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDDC(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDDD(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDDE(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDDF(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDE0(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disDE1(byte a,byte b,byte c,byte d,char *buffer)        /* POP IX */
  {
    sprintf(buffer,"%02x %02x       pop ix",a,b);
    return 2;
  }

int disDE2(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disDE3(byte a,byte b,byte c,byte d,char *buffer)        /* EX (SP),IX */
  {
    sprintf(buffer,"%02x %02x       ex (sp),ix",a,b);
    return 2;
  }

int disDE4(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disDE5(byte a,byte b,byte c,byte d,char *buffer)        /* PUSH IX */
  {
    sprintf(buffer,"%02x %02x       push ix",a,b);
    return 2;
  }

int disDE6(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDE7(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDE8(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disDE9(byte a,byte b,byte c,byte d,char *buffer)        /* JP (IX) */
  {
    sprintf(buffer,"%02x %02x       jp (ix)",a,b);
    return 2;
  }

int disDEA(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDEB(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDEC(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDED(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDEE(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDEF(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDF0(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDF1(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDF2(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDF3(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDF4(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDF5(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDF6(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDF7(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDF8(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disDF9(byte a,byte b,byte c,byte d,char *buffer)        /* LD SP,IX */
  {
    sprintf(buffer,"%02x %02x       ld sp,ix",a,b);
    return 2;
  }

int disDFA(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDFB(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDFC(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDFD(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDFE(byte a,byte b,byte c,byte d,char *buffer) { return 2; }
int disDFF(byte a,byte b,byte c,byte d,char *buffer) { return 2; }

int disPDD(byte a,byte b,byte c,byte d,char *buffer)
  {
    byte bt;
    bt=b;
    switch (bt & 0xf0) {
      case 0x00:switch (bt & 15) {
         case  0:return disD00(a,b,c,d,buffer); break;
         case  1:return disD01(a,b,c,d,buffer); break;
         case  2:return disD02(a,b,c,d,buffer); break;
         case  3:return disD03(a,b,c,d,buffer); break;
         case  4:return disD04(a,b,c,d,buffer); break;
         case  5:return disD05(a,b,c,d,buffer); break;
         case  6:return disD06(a,b,c,d,buffer); break;
         case  7:return disD07(a,b,c,d,buffer); break;
         case  8:return disD08(a,b,c,d,buffer); break;
         case  9:return disD09(a,b,c,d,buffer); break;
         case 10:return disD0A(a,b,c,d,buffer); break;
         case 11:return disD0B(a,b,c,d,buffer); break;
         case 12:return disD0C(a,b,c,d,buffer); break;
         case 13:return disD0D(a,b,c,d,buffer); break;
         case 14:return disD0E(a,b,c,d,buffer); break;
         case 15:return disD0F(a,b,c,d,buffer); break;
         } break;

      case 0x10:switch (bt & 15) {
         case  0:return disD10(a,b,c,d,buffer); break;
         case  1:return disD11(a,b,c,d,buffer); break;
         case  2:return disD12(a,b,c,d,buffer); break;
         case  3:return disD13(a,b,c,d,buffer); break;
         case  4:return disD14(a,b,c,d,buffer); break;
         case  5:return disD15(a,b,c,d,buffer); break;
         case  6:return disD16(a,b,c,d,buffer); break;
         case  7:return disD17(a,b,c,d,buffer); break;
         case  8:return disD18(a,b,c,d,buffer); break;
         case  9:return disD19(a,b,c,d,buffer); break;
         case 10:return disD1A(a,b,c,d,buffer); break;
         case 11:return disD1B(a,b,c,d,buffer); break;
         case 12:return disD1C(a,b,c,d,buffer); break;
         case 13:return disD1D(a,b,c,d,buffer); break;
         case 14:return disD1E(a,b,c,d,buffer); break;
         case 15:return disD1F(a,b,c,d,buffer); break;
         } break;
      case 0x20:switch (bt & 15) {
         case  0:return disD20(a,b,c,d,buffer); break;
         case  1:return disD21(a,b,c,d,buffer); break;
         case  2:return disD22(a,b,c,d,buffer); break;
         case  3:return disD23(a,b,c,d,buffer); break;
         case  4:return disD24(a,b,c,d,buffer); break;
         case  5:return disD25(a,b,c,d,buffer); break;
         case  6:return disD26(a,b,c,d,buffer); break;
         case  7:return disD27(a,b,c,d,buffer); break;
         case  8:return disD28(a,b,c,d,buffer); break;
         case  9:return disD29(a,b,c,d,buffer); break;
         case 10:return disD2A(a,b,c,d,buffer); break;
         case 11:return disD2B(a,b,c,d,buffer); break;
         case 12:return disD2C(a,b,c,d,buffer); break;
         case 13:return disD2D(a,b,c,d,buffer); break;
         case 14:return disD2E(a,b,c,d,buffer); break;
         case 15:return disD2F(a,b,c,d,buffer); break;
         } break;
      case 0x30:switch (bt & 15) {
         case  0:return disD30(a,b,c,d,buffer); break;
         case  1:return disD31(a,b,c,d,buffer); break;
         case  2:return disD32(a,b,c,d,buffer); break;
         case  3:return disD33(a,b,c,d,buffer); break;
         case  4:return disD34(a,b,c,d,buffer); break;
         case  5:return disD35(a,b,c,d,buffer); break;
         case  6:return disD36(a,b,c,d,buffer); break;
         case  7:return disD37(a,b,c,d,buffer); break;
         case  8:return disD38(a,b,c,d,buffer); break;
         case  9:return disD39(a,b,c,d,buffer); break;
         case 10:return disD3A(a,b,c,d,buffer); break;
         case 11:return disD3B(a,b,c,d,buffer); break;
         case 12:return disD3C(a,b,c,d,buffer); break;
         case 13:return disD3D(a,b,c,d,buffer); break;
         case 14:return disD3E(a,b,c,d,buffer); break;
         case 15:return disD3F(a,b,c,d,buffer); break;
         } break;
      case 0x40:switch (bt & 15) {
         case  0:return disD40(a,b,c,d,buffer); break;
         case  1:return disD41(a,b,c,d,buffer); break;
         case  2:return disD42(a,b,c,d,buffer); break;
         case  3:return disD43(a,b,c,d,buffer); break;
         case  4:return disD44(a,b,c,d,buffer); break;
         case  5:return disD45(a,b,c,d,buffer); break;
         case  6:return disD46(a,b,c,d,buffer); break;
         case  7:return disD47(a,b,c,d,buffer); break;
         case  8:return disD48(a,b,c,d,buffer); break;
         case  9:return disD49(a,b,c,d,buffer); break;
         case 10:return disD4A(a,b,c,d,buffer); break;
         case 11:return disD4B(a,b,c,d,buffer); break;
         case 12:return disD4C(a,b,c,d,buffer); break;
         case 13:return disD4D(a,b,c,d,buffer); break;
         case 14:return disD4E(a,b,c,d,buffer); break;
         case 15:return disD4F(a,b,c,d,buffer); break;
         } break;
      case 0x50:switch (bt & 15) {
         case  0:return disD50(a,b,c,d,buffer); break;
         case  1:return disD51(a,b,c,d,buffer); break;
         case  2:return disD52(a,b,c,d,buffer); break;
         case  3:return disD53(a,b,c,d,buffer); break;
         case  4:return disD54(a,b,c,d,buffer); break;
         case  5:return disD55(a,b,c,d,buffer); break;
         case  6:return disD56(a,b,c,d,buffer); break;
         case  7:return disD57(a,b,c,d,buffer); break;
         case  8:return disD58(a,b,c,d,buffer); break;
         case  9:return disD59(a,b,c,d,buffer); break;
         case 10:return disD5A(a,b,c,d,buffer); break;
         case 11:return disD5B(a,b,c,d,buffer); break;
         case 12:return disD5C(a,b,c,d,buffer); break;
         case 13:return disD5D(a,b,c,d,buffer); break;
         case 14:return disD5E(a,b,c,d,buffer); break;
         case 15:return disD5F(a,b,c,d,buffer); break;
         } break;
      case 0x60:switch (bt & 15) {
         case  0:return disD60(a,b,c,d,buffer); break;
         case  1:return disD61(a,b,c,d,buffer); break;
         case  2:return disD62(a,b,c,d,buffer); break;
         case  3:return disD63(a,b,c,d,buffer); break;
         case  4:return disD64(a,b,c,d,buffer); break;
         case  5:return disD65(a,b,c,d,buffer); break;
         case  6:return disD66(a,b,c,d,buffer); break;
         case  7:return disD67(a,b,c,d,buffer); break;
         case  8:return disD68(a,b,c,d,buffer); break;
         case  9:return disD69(a,b,c,d,buffer); break;
         case 10:return disD6A(a,b,c,d,buffer); break;
         case 11:return disD6B(a,b,c,d,buffer); break;
         case 12:return disD6C(a,b,c,d,buffer); break;
         case 13:return disD6D(a,b,c,d,buffer); break;
         case 14:return disD6E(a,b,c,d,buffer); break;
         case 15:return disD6F(a,b,c,d,buffer); break;
         } break;
      case 0x70:switch (bt & 15) {
         case  0:return disD70(a,b,c,d,buffer); break;
         case  1:return disD71(a,b,c,d,buffer); break;
         case  2:return disD72(a,b,c,d,buffer); break;
         case  3:return disD73(a,b,c,d,buffer); break;
         case  4:return disD74(a,b,c,d,buffer); break;
         case  5:return disD75(a,b,c,d,buffer); break;
         case  6:return disD76(a,b,c,d,buffer); break;
         case  7:return disD77(a,b,c,d,buffer); break;
         case  8:return disD78(a,b,c,d,buffer); break;
         case  9:return disD79(a,b,c,d,buffer); break;
         case 10:return disD7A(a,b,c,d,buffer); break;
         case 11:return disD7B(a,b,c,d,buffer); break;
         case 12:return disD7C(a,b,c,d,buffer); break;
         case 13:return disD7D(a,b,c,d,buffer); break;
         case 14:return disD7E(a,b,c,d,buffer); break;
         case 15:return disD7F(a,b,c,d,buffer); break;
         } break;
      case 0x80:switch (bt & 15) {
         case  0:return disD80(a,b,c,d,buffer); break;
         case  1:return disD81(a,b,c,d,buffer); break;
         case  2:return disD82(a,b,c,d,buffer); break;
         case  3:return disD83(a,b,c,d,buffer); break;
         case  4:return disD84(a,b,c,d,buffer); break;
         case  5:return disD85(a,b,c,d,buffer); break;
         case  6:return disD86(a,b,c,d,buffer); break;
         case  7:return disD87(a,b,c,d,buffer); break;
         case  8:return disD88(a,b,c,d,buffer); break;
         case  9:return disD89(a,b,c,d,buffer); break;
         case 10:return disD8A(a,b,c,d,buffer); break;
         case 11:return disD8B(a,b,c,d,buffer); break;
         case 12:return disD8C(a,b,c,d,buffer); break;
         case 13:return disD8D(a,b,c,d,buffer); break;
         case 14:return disD8E(a,b,c,d,buffer); break;
         case 15:return disD8F(a,b,c,d,buffer); break;
         } break;

      case 0x90:switch (bt & 15) {
         case  0:return disD90(a,b,c,d,buffer); break;
         case  1:return disD91(a,b,c,d,buffer); break;
         case  2:return disD92(a,b,c,d,buffer); break;
         case  3:return disD93(a,b,c,d,buffer); break;
         case  4:return disD94(a,b,c,d,buffer); break;
         case  5:return disD95(a,b,c,d,buffer); break;
         case  6:return disD96(a,b,c,d,buffer); break;
         case  7:return disD97(a,b,c,d,buffer); break;
         case  8:return disD98(a,b,c,d,buffer); break;
         case  9:return disD99(a,b,c,d,buffer); break;
         case 10:return disD9A(a,b,c,d,buffer); break;
         case 11:return disD9B(a,b,c,d,buffer); break;
         case 12:return disD9C(a,b,c,d,buffer); break;
         case 13:return disD9D(a,b,c,d,buffer); break;
         case 14:return disD9E(a,b,c,d,buffer); break;
         case 15:return disD9F(a,b,c,d,buffer); break;
         } break;
      case 0xA0:switch (bt & 15) {
         case  0:return disDA0(a,b,c,d,buffer); break;
         case  1:return disDA1(a,b,c,d,buffer); break;
         case  2:return disDA2(a,b,c,d,buffer); break;
         case  3:return disDA3(a,b,c,d,buffer); break;
         case  4:return disDA4(a,b,c,d,buffer); break;
         case  5:return disDA5(a,b,c,d,buffer); break;
         case  6:return disDA6(a,b,c,d,buffer); break;
         case  7:return disDA7(a,b,c,d,buffer); break;
         case  8:return disDA8(a,b,c,d,buffer); break;
         case  9:return disDA9(a,b,c,d,buffer); break;
         case 10:return disDAA(a,b,c,d,buffer); break;
         case 11:return disDAB(a,b,c,d,buffer); break;
         case 12:return disDAC(a,b,c,d,buffer); break;
         case 13:return disDAD(a,b,c,d,buffer); break;
         case 14:return disDAE(a,b,c,d,buffer); break;
         case 15:return disDAF(a,b,c,d,buffer); break;
         } break;
      case 0xB0:switch (bt & 15) {
         case  0:return disDB0(a,b,c,d,buffer); break;
         case  1:return disDB1(a,b,c,d,buffer); break;
         case  2:return disDB2(a,b,c,d,buffer); break;
         case  3:return disDB3(a,b,c,d,buffer); break;
         case  4:return disDB4(a,b,c,d,buffer); break;
         case  5:return disDB5(a,b,c,d,buffer); break;
         case  6:return disDB6(a,b,c,d,buffer); break;
         case  7:return disDB7(a,b,c,d,buffer); break;
         case  8:return disDB8(a,b,c,d,buffer); break;
         case  9:return disDB9(a,b,c,d,buffer); break;
         case 10:return disDBA(a,b,c,d,buffer); break;
         case 11:return disDBB(a,b,c,d,buffer); break;
         case 12:return disDBC(a,b,c,d,buffer); break;
         case 13:return disDBD(a,b,c,d,buffer); break;
         case 14:return disDBE(a,b,c,d,buffer); break;
         case 15:return disDBF(a,b,c,d,buffer); break;
         } break;
      case 0xC0:switch (bt & 15) {
         case  0:return disDC0(a,b,c,d,buffer); break;
         case  1:return disDC1(a,b,c,d,buffer); break;
         case  2:return disDC2(a,b,c,d,buffer); break;
         case  3:return disDC3(a,b,c,d,buffer); break;
         case  4:return disDC4(a,b,c,d,buffer); break;
         case  5:return disDC5(a,b,c,d,buffer); break;
         case  6:return disDC6(a,b,c,d,buffer); break;
         case  7:return disDC7(a,b,c,d,buffer); break;
         case  8:return disDC8(a,b,c,d,buffer); break;
         case  9:return disDC9(a,b,c,d,buffer); break;
         case 10:return disDCA(a,b,c,d,buffer); break;
         case 11:return disDCB(a,b,c,d,buffer); break;
         case 12:return disDCC(a,b,c,d,buffer); break;
         case 13:return disDCD(a,b,c,d,buffer); break;
         case 14:return disDCE(a,b,c,d,buffer); break;
         case 15:return disDCF(a,b,c,d,buffer); break;
         } break;
      case 0xD0:switch (bt & 15) {
         case  0:return disDD0(a,b,c,d,buffer); break;
         case  1:return disDD1(a,b,c,d,buffer); break;
         case  2:return disDD2(a,b,c,d,buffer); break;
         case  3:return disDD3(a,b,c,d,buffer); break;
         case  4:return disDD4(a,b,c,d,buffer); break;
         case  5:return disDD5(a,b,c,d,buffer); break;
         case  6:return disDD6(a,b,c,d,buffer); break;
         case  7:return disDD7(a,b,c,d,buffer); break;
         case  8:return disDD8(a,b,c,d,buffer); break;
         case  9:return disDD9(a,b,c,d,buffer); break;
         case 10:return disDDA(a,b,c,d,buffer); break;
         case 11:return disDDB(a,b,c,d,buffer); break;
         case 12:return disDDC(a,b,c,d,buffer); break;
         case 13:return disDDD(a,b,c,d,buffer); break;
         case 14:return disDDE(a,b,c,d,buffer); break;
         case 15:return disDDF(a,b,c,d,buffer); break;
         } break;
      case 0xE0:switch (bt & 15) {
         case  0:return disDE0(a,b,c,d,buffer); break;
         case  1:return disDE1(a,b,c,d,buffer); break;
         case  2:return disDE2(a,b,c,d,buffer); break;
         case  3:return disDE3(a,b,c,d,buffer); break;
         case  4:return disDE4(a,b,c,d,buffer); break;
         case  5:return disDE5(a,b,c,d,buffer); break;
         case  6:return disDE6(a,b,c,d,buffer); break;
         case  7:return disDE7(a,b,c,d,buffer); break;
         case  8:return disDE8(a,b,c,d,buffer); break;
         case  9:return disDE9(a,b,c,d,buffer); break;
         case 10:return disDEA(a,b,c,d,buffer); break;
         case 11:return disDEB(a,b,c,d,buffer); break;
         case 12:return disDEC(a,b,c,d,buffer); break;
         case 13:return disDED(a,b,c,d,buffer); break;
         case 14:return disDEE(a,b,c,d,buffer); break;
         case 15:return disDEF(a,b,c,d,buffer); break;
         } break;
      case 0xF0:switch (bt & 15) {
         case  0:return disDF0(a,b,c,d,buffer); break;
         case  1:return disDF1(a,b,c,d,buffer); break;
         case  2:return disDF2(a,b,c,d,buffer); break;
         case  3:return disDF3(a,b,c,d,buffer); break;
         case  4:return disDF4(a,b,c,d,buffer); break;
         case  5:return disDF5(a,b,c,d,buffer); break;
         case  6:return disDF6(a,b,c,d,buffer); break;
         case  7:return disDF7(a,b,c,d,buffer); break;
         case  8:return disDF8(a,b,c,d,buffer); break;
         case  9:return disDF9(a,b,c,d,buffer); break;
         case 10:return disDFA(a,b,c,d,buffer); break;
         case 11:return disDFB(a,b,c,d,buffer); break;
         case 12:return disDFC(a,b,c,d,buffer); break;
         case 13:return disDFD(a,b,c,d,buffer); break;
         case 14:return disDFE(a,b,c,d,buffer); break;
         case 15:return disDFF(a,b,c,d,buffer); break;
         } break;

      }
  }

