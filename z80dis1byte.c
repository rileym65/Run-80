#include "header.h"

int disP0(byte a,byte b,byte c,byte d,char *buffer)         /* NOP */
  {
    sprintf(buffer,"%02x          nop",a);
    return 1;
  }

int disP1(byte a,byte b,byte c,byte d,char *buffer)         /* LD BC,nn */
  {
    sprintf(buffer,"%02x %02x %02x    ld bc,%04x",a,b,c,b+c*256);
    return 2;
  }

int disP2(byte a,byte b,byte c,byte d,char *buffer)         /* LD (BC),A */
  {
    sprintf(buffer,"%02x          ld (bc),a",a);
    return 1;
  }

int disP3(byte a,byte b,byte c,byte d,char *buffer)         /* INC BC */
  {
    sprintf(buffer,"%02x          inc bc",a);
    return 1;
  }

int disP4(byte a,byte b,byte c,byte d,char *buffer)         /* INC B */
  {
    sprintf(buffer,"%02x          inc b",a);
    return 1;
  }

int disP5(byte a,byte b,byte c,byte d,char *buffer)         /* DEC B */
  {
    sprintf(buffer,"%02x          dec b",a);
    return 1;
  }

int disP6(byte a,byte b,byte c,byte d,char *buffer)         /* LD B,n */
  {
    sprintf(buffer,"%02x %02x       ld b,%02x",a,b,b);
    return 2;
  }

int disP7(byte a,byte b,byte c,byte d,char *buffer)         /* RLCA */
  {
    sprintf(buffer,"%02x          rlca",a);
    return 1;
  }

int disP8(byte a,byte b,byte c,byte d,char *buffer)         /* EX AF,AF' */
  {
    sprintf(buffer,"%02x          ex af,af'",a);
    return 1;
  }

int disP9(byte a,byte b,byte c,byte d,char *buffer)         /* ADD HL,BC */
  {
    sprintf(buffer,"%02x          add hl,bc",a);
    return 1;
  }

int disPA(byte a,byte b,byte c,byte d,char *buffer)         /* LD A,(BC) */
  {
    sprintf(buffer,"%02x          ld a,(bc)",a);
    return 1;
  }

int disPB(byte a,byte b,byte c,byte d,char *buffer)         /* DEC BC */
  {
    sprintf(buffer,"%02x          dec bc",a);
    return 1;
  }

int disPC(byte a,byte b,byte c,byte d,char *buffer)         /* INC C */
  {
    sprintf(buffer,"%02x          inc c",a);
    return 1;
  }
    
int disPD(byte a,byte b,byte c,byte d,char *buffer)         /* DEC C */
  {
    sprintf(buffer,"%02x          dec c",a);
    return 1;
  }

int disPE(byte a,byte b,byte c,byte d,char *buffer)         /* LD C,n */
  {
    sprintf(buffer,"%02x %02x       ld c,%02x",a,b,b);
    return 2;
  }

int disPF(byte a,byte b,byte c,byte d,char *buffer)         /* RRCA */
  {
    sprintf(buffer,"%02x          rrca",a);
    return 1;
  }

int disP10(byte a,byte b,byte c,byte d,char *buffer)        /* DJNZ */
  {
    sprintf(buffer,"%02x %02x       djnz %d",a,b,Offset(b));
    return 2;
  }

int disP11(byte a,byte b,byte c,byte d,char *buffer)        /* LD DE,nn */
  {
    sprintf(buffer,"%02x %02x %02x    ld de,%04x",a,b,c,b+c*256);
    return 3;
  }

int disP12(byte a,byte b,byte c,byte d,char *buffer)        /* LD (DE),A */
  {
    sprintf(buffer,"%02x          ld (de),a",a);
    return 1;
  }

int disP13(byte a,byte b,byte c,byte d,char *buffer)        /* INC DE */
  {
    sprintf(buffer,"%02x          inc de",a);
    return 1;
  }

int disP14(byte a,byte b,byte c,byte d,char *buffer)        /* INC D */
  {
    sprintf(buffer,"%02x          inc d",a);
    return 1;
  }

int disP15(byte a,byte b,byte c,byte d,char *buffer)        /* DEC D */
  {
    sprintf(buffer,"%02x          dec d",a);
    return 1;
  }

int disP16(byte a,byte b,byte c,byte d,char *buffer)        /* LD D,n */
  {
    sprintf(buffer,"%02x %02x       ld d,%02x",a,b,b);
    return 2;
  }

int disP17(byte a,byte b,byte c,byte d,char *buffer)        /* RLA */
  {
    sprintf(buffer,"%02x          rla",a);
    return 1;
  }

int disP18(byte a,byte b,byte c,byte d,char *buffer)        /* JR e */
  {
    sprintf(buffer,"%02x %02x       jr %02x",a,b,Offset(b));
    return 2;
  }

int disP19(byte a,byte b,byte c,byte d,char *buffer)        /* ADD HL,DE */
  {
    sprintf(buffer,"%02x          add hl,de",a);
    return 1;
  }

int disP1A(byte a,byte b,byte c,byte d,char *buffer)        /* LD A,(DE) */
  {
    sprintf(buffer,"%02x          ld a,(de)",a);
    return 1;
  }

int disP1B(byte a,byte b,byte c,byte d,char *buffer)        /* DEC DE */
  {
    sprintf(buffer,"%02x          dec de",a);
    return 1;
  }

int disP1C(byte a,byte b,byte c,byte d,char *buffer)        /* INC E */
  {
    sprintf(buffer,"%02x          inc e",a);
    return 1;
  }

int disP1D(byte a,byte b,byte c,byte d,char *buffer)        /* DEC E */
  {
    sprintf(buffer,"%02x          dec e",a);
    return 1;
  }


int disP1E(byte a,byte b,byte c,byte d,char *buffer)        /* LD E,n */
  {
    sprintf(buffer,"%02x %02x       ld e,%02x",a,b,b);
    return 2;
  }

int disP1F(byte a,byte b,byte c,byte d,char *buffer)        /* RRA */
  {
    sprintf(buffer,"%02x          rra",a);
    return 1;
  }

int disP20(byte a,byte b,byte c,byte d,char *buffer)        /* JR NZ,e */
  {
    sprintf(buffer,"%02x %02x       jr nz,%d",a,b,Offset(b));
    return 2;
  }

int disP21(byte a,byte b,byte c,byte d,char *buffer)        /* LD HL,nn */
  {
    sprintf(buffer,"%02x %02x %02x    ld hl,%04x",a,b,c,b+c*256);
    return 3;
  }

int disP22(byte a,byte b,byte c,byte d,char *buffer)        /* LD (nn),HL */
  {
    sprintf(buffer,"%02x %02x %02x    ld (%04x),hl",a,b,c,b+c*256);
    return 3;
  }

int disP23(byte a,byte b,byte c,byte d,char *buffer)        /* INC HL */
  {
    sprintf(buffer,"%02x          inc hl",a);
    return 1;
  }

int disP24(byte a,byte b,byte c,byte d,char *buffer)        /* INC H */
  {
    sprintf(buffer,"%02x          inc h",a);
    return 1;
  }

int disP25(byte a,byte b,byte c,byte d,char *buffer)        /* DEC H */
  {
    sprintf(buffer,"%02x          dec h",a);
    return 1;
  }

int disP26(byte a,byte b,byte c,byte d,char *buffer)        /* LD H,n */
  {
    sprintf(buffer,"%02x %02x       ld h,%02x",a,b,b);
    return 2;
  }

int disP27(byte a,byte b,byte c,byte d,char *buffer)        /* DAA */
  {
    sprintf(buffer,"%02x          daa",a);
    return 1;
  }

int disP28(byte a,byte b,byte c,byte d,char *buffer)        /* JR Z,e */
  {
    sprintf(buffer,"%02x %02x       jr z,%02x",a,b,Offset(b));
    return 2;
  }

int disP29(byte a,byte b,byte c,byte d,char *buffer)        /* ADD HL,HL */
  {
    sprintf(buffer,"%02x          add hl,hl",a);
    return 1;
  }

int disP2A(byte a,byte b,byte c,byte d,char *buffer)        /* LD HL,(nn) */
  {
    sprintf(buffer,"%02x %02x %02x    ld hl,(%04x)",a,b,c,b+c*256);
    return 3;
  }

int disP2B(byte a,byte b,byte c,byte d,char *buffer)        /* DEC HL */
  {
    sprintf(buffer,"%02x          dec hl",a);
    return 1;
  }

int disP2C(byte a,byte b,byte c,byte d,char *buffer)        /* INC L */
  {
    sprintf(buffer,"%02x          inc l",a);
    return 1;
  }

int disP2D(byte a,byte b,byte c,byte d,char *buffer)        /* DEC L */
  {
    sprintf(buffer,"%02x          dec l",a);
    return 1;
  }

int disP2E(byte a,byte b,byte c,byte d,char *buffer)        /* LD L,n */
  {
    sprintf(buffer,"%02x %02x       ld l,%02x",a,b,b);
    return 2;
  }


int disP2F(byte a,byte b,byte c,byte d,char *buffer)        /* CPL */
  {
    sprintf(buffer,"%02x          cpl",a);
    return 1;
  }

int disP30(byte a,byte b,byte c,byte d,char *buffer)        /* JR NC,e */
  {
    sprintf(buffer,"%02x %02x       jr NC,%02x",a,b,Offset(b));
    return 2;
  }

int disP31(byte a,byte b,byte c,byte d,char *buffer)        /* LD SP,nn */
  {
    sprintf(buffer,"%02x %02x %02x    ld sp,%04x",a,b,c,b+c*256);
    return 3;
  }

int disP32(byte a,byte b,byte c,byte d,char *buffer)        /* LD (nn),A */
  {
    sprintf(buffer,"%02x %02x %02x    ld (%04x),a",a,b,c,b+c*256);
    return 3;
  }

int disP33(byte a,byte b,byte c,byte d,char *buffer)        /* INC SP */
  {
    sprintf(buffer,"%02x          inc sp",a);
    return 1;
  }

int disP34(byte a,byte b,byte c,byte d,char *buffer)        /* INC (HL) */
  {
    sprintf(buffer,"%02x          inc (hl)",a);
    return 1;
  }

int disP35(byte a,byte b,byte c,byte d,char *buffer)        /* DEC (HL) */
  {
    sprintf(buffer,"%02x          dec (hl)",a);
    return 1;
  }

int disP36(byte a,byte b,byte c,byte d,char *buffer)        /* LD (HL),n */
  {
    sprintf(buffer,"%02x %02x       ld (hl),%02x",a,b,b);
    return 2;
  }

int disP37(byte a,byte b,byte c,byte d,char *buffer)        /* SCF */
  {
    sprintf(buffer,"%02x          scf",a);
    return 1;
  }

int disP38(byte a,byte b,byte c,byte d,char *buffer)        /* JR C,e */
  {
    sprintf(buffer,"%02x %02x       jr C,%02x",a,b,Offset(b));
    return 2;
  }

int disP39(byte a,byte b,byte c,byte d,char *buffer)        /* ADD HL,SP */
  {
    sprintf(buffer,"%02x          add hl,sp",a);
    return 1;
  }

int disP3A(byte a,byte b,byte c,byte d,char *buffer)        /* LD A,(nn) */
  {
    sprintf(buffer,"%02x %02x %02x    ld a,(%04x)",a,b,c,b+c*256);
    return 3;
  }

int disP3B(byte a,byte b,byte c,byte d,char *buffer)        /* DEC SP */
  {
    sprintf(buffer,"%02x          dec sp",a);
    return 1;
  }

int disP3C(byte a,byte b,byte c,byte d,char *buffer)        /* INC A */
  {
    sprintf(buffer,"%02x          inc a",a);
    return 1;
  }

int disP3D(byte a,byte b,byte c,byte d,char *buffer)        /* DEC A */
  {
    sprintf(buffer,"%02x          dec a",a);
    return 1;
  }

int disP3E(byte a,byte b,byte c,byte d,char *buffer)        /* LD A,n */
  {
    sprintf(buffer,"%02x %02x       ld a,%02x",a,b,b);
    return 2;
  }

int disP3F(byte a,byte b,byte c,byte d,char *buffer)        /* CCF */
  {
    sprintf(buffer,"%02x          ccf",a);
    return 1;
  }

int disP40(byte a,byte b,byte c,byte d,char *buffer)        /* LD B,B */
  {
    sprintf(buffer,"%02x          ld b,b",a);
    return 1;
  }

int disP41(byte a,byte b,byte c,byte d,char *buffer)        /* LD B,C */
  {
    sprintf(buffer,"%02x          ld b,c",a);
    return 1;
  }

int disP42(byte a,byte b,byte c,byte d,char *buffer)        /* LD B,D */
  {
    sprintf(buffer,"%02x          ld b,d",a);
    return 1;
  }

int disP43(byte a,byte b,byte c,byte d,char *buffer)        /* LD B,E */
  {
    sprintf(buffer,"%02x          ld b,e",a);
    return 1;
  }

int disP44(byte a,byte b,byte c,byte d,char *buffer)        /* LD B,H */
  {
    sprintf(buffer,"%02x          ld b,h",a);
    return 1;
  }

int disP45(byte a,byte b,byte c,byte d,char *buffer)        /* LD B,L */
  {
    sprintf(buffer,"%02x          ld b,l",a);
    return 1;
  }

int disP46(byte a,byte b,byte c,byte d,char *buffer)        /* LD B,(HL) */
  {
    sprintf(buffer,"%02x          ld b,(hl)",a);
    return 1;
  }

int disP47(byte a,byte b,byte c,byte d,char *buffer)        /* LD B,A */
  {
    sprintf(buffer,"%02x          ld b,a",a);
    return 1;
  }

int disP48(byte a,byte b,byte c,byte d,char *buffer)        /* LD C,B */
  {
    sprintf(buffer,"%02x          ld c,b",a);
    return 1;
  }

int disP49(byte a,byte b,byte c,byte d,char *buffer)        /* LD C,C */
  {
    sprintf(buffer,"%02x          ld c,c",a);
    return 1;
  }

int disP4A(byte a,byte b,byte c,byte d,char *buffer)        /* LD C,D */
  {
    sprintf(buffer,"%02x          ld c,d",a);
    return 1;
  }

int disP4B(byte a,byte b,byte c,byte d,char *buffer)        /* LD C,E */
  {
    sprintf(buffer,"%02x          ld c,e",a);
    return 1;
  }

int disP4C(byte a,byte b,byte c,byte d,char *buffer)        /* LD C,H */
  {
    sprintf(buffer,"%02x          ld c,h",a);
    return 1;
  }

int disP4D(byte a,byte b,byte c,byte d,char *buffer)        /* LD C,L */
  {
    sprintf(buffer,"%02x          ld c,l",a);
    return 1;
  }

int disP4E(byte a,byte b,byte c,byte d,char *buffer)        /* LD C,(HL) */
  {
    sprintf(buffer,"%02x          ld c,(hl)",a);
    return 1;
  }

int disP4F(byte a,byte b,byte c,byte d,char *buffer)        /* LD C,A */
  {
    sprintf(buffer,"%02x          ld c,a",a);
    return 1;
  }

int disP50(byte a,byte b,byte c,byte d,char *buffer)        /* LD D,B */
  {
    sprintf(buffer,"%02x          ld d,b",a);
    return 1;
  }

int disP51(byte a,byte b,byte c,byte d,char *buffer)        /* LD D,C */
  {
    sprintf(buffer,"%02x          ld d,c",a);
    return 1;
  }

int disP52(byte a,byte b,byte c,byte d,char *buffer)        /* LD D,D */
  {
    sprintf(buffer,"%02x          ld d,d",a);
    return 1;
  }

int disP53(byte a,byte b,byte c,byte d,char *buffer)        /* LD D,E */
  {
    sprintf(buffer,"%02x          ld d,e",a);
    return 1;
  }

int disP54(byte a,byte b,byte c,byte d,char *buffer)        /* LD D,H */
  {
    sprintf(buffer,"%02x          ld d,h",a);
    return 1;
  }

int disP55(byte a,byte b,byte c,byte d,char *buffer)        /* LD D,L */
  {
    sprintf(buffer,"%02x          ld d,l",a);
    return 1;
  }

int disP56(byte a,byte b,byte c,byte d,char *buffer)        /* LD D,(HL) */
  {
    sprintf(buffer,"%02x          ld d,(hl)",a);
    return 1;
  }

int disP57(byte a,byte b,byte c,byte d,char *buffer)        /* LD D,A */
  {
    sprintf(buffer,"%02x          ld d,a",a);
    return 1;
  }

int disP58(byte a,byte b,byte c,byte d,char *buffer)        /* LD E,B */
  {
    sprintf(buffer,"%02x          ld e,b",a);
    return 1;
  }

int disP59(byte a,byte b,byte c,byte d,char *buffer)        /* LD E,C */
  {
    sprintf(buffer,"%02x          ld e,c",a);
    return 1;
  }

int disP5A(byte a,byte b,byte c,byte d,char *buffer)        /* LD E,D */
  {
    sprintf(buffer,"%02x          ld e,d",a);
    return 1;
  }

int disP5B(byte a,byte b,byte c,byte d,char *buffer)        /* LD E,E */
  {
    sprintf(buffer,"%02x          ld e,e",a);
    return 1;
  }

int disP5C(byte a,byte b,byte c,byte d,char *buffer)        /* LD E,H */
  {
    sprintf(buffer,"%02x          ld e,h",a);
    return 1;
  }

int disP5D(byte a,byte b,byte c,byte d,char *buffer)        /* LD E,L */
  {
    sprintf(buffer,"%02x          ld e,l",a);
    return 1;
  }

int disP5E(byte a,byte b,byte c,byte d,char *buffer)        /* LD E,(HL) */
  {
    sprintf(buffer,"%02x          ld e,(hl)",a);
    return 1;
  }

int disP5F(byte a,byte b,byte c,byte d,char *buffer)        /* LD E,A */
  {
    sprintf(buffer,"%02x          ld e,a",a);
    return 1;
  }

int disP60(byte a,byte b,byte c,byte d,char *buffer)        /* LD H,B */
  {
    sprintf(buffer,"%02x          ld h,b",a);
    return 1;
  }

int disP61(byte a,byte b,byte c,byte d,char *buffer)        /* LD H,C */
  {
    sprintf(buffer,"%02x          ld h,c",a);
    return 1;
  }

int disP62(byte a,byte b,byte c,byte d,char *buffer)        /* LD H,D */
  {
    sprintf(buffer,"%02x          ld h,d",a);
    return 1;
  }

int disP63(byte a,byte b,byte c,byte d,char *buffer)        /* LD H,E */
  {
    sprintf(buffer,"%02x          ld h,e",a);
    return 1;
  }

int disP64(byte a,byte b,byte c,byte d,char *buffer)        /* LD H,H */
  {
    sprintf(buffer,"%02x          ld h,h",a);
    return 1;
  }

int disP65(byte a,byte b,byte c,byte d,char *buffer)        /* LD H,L */
  {
    sprintf(buffer,"%02x          ld h,l",a);
    return 1;
  }

int disP66(byte a,byte b,byte c,byte d,char *buffer)        /* LD H,(HL) */
  {
    sprintf(buffer,"%02x          ld h,(hl)",a);
    return 1;
  }

int disP67(byte a,byte b,byte c,byte d,char *buffer)        /* LD H,A */
  {
    sprintf(buffer,"%02x          ld h,a",a);
    return 1;
  }

int disP68(byte a,byte b,byte c,byte d,char *buffer)        /* LD L,B */
  {
    sprintf(buffer,"%02x          ld l,b",a);
    return 1;
  }

int disP69(byte a,byte b,byte c,byte d,char *buffer)        /* LD L,C */
  {
    sprintf(buffer,"%02x          ld l,c",a);
    return 1;
  }

int disP6A(byte a,byte b,byte c,byte d,char *buffer)        /* LD L,D */
  {
    sprintf(buffer,"%02x          ld l,d",a);
    return 1;
  }

int disP6B(byte a,byte b,byte c,byte d,char *buffer)        /* LD L,E */
  {
    sprintf(buffer,"%02x          ld l,e",a);
    return 1;
  }

int disP6C(byte a,byte b,byte c,byte d,char *buffer)        /* LD L,H */
  {
    sprintf(buffer,"%02x          ld l,h",a);
    return 1;
  }

int disP6D(byte a,byte b,byte c,byte d,char *buffer)        /* LD L,L */
  {
    sprintf(buffer,"%02x          ld l,l",a);
    return 1;
  }

int disP6E(byte a,byte b,byte c,byte d,char *buffer)        /* LD L,(HL) */
  {
    sprintf(buffer,"%02x          ld l,(hl)",a);
    return 1;
  }

int disP6F(byte a,byte b,byte c,byte d,char *buffer)        /* LD L,A */
  {
    sprintf(buffer,"%02x          ld l,a",a);
    return 1;
  }

int disP70(byte a,byte b,byte c,byte d,char *buffer)        /* LD (HL),B */
  {
    sprintf(buffer,"%02x          ld (hl),b",a);
    return 1;
  }

int disP71(byte a,byte b,byte c,byte d,char *buffer)        /* LD (HL),C */
  {
    sprintf(buffer,"%02x          ld (hl),c",a);
    return 1;
  }

int disP72(byte a,byte b,byte c,byte d,char *buffer)        /* LD (HL),D */
  {
    sprintf(buffer,"%02x          ld (hl),d",a);
    return 1;
  }

int disP73(byte a,byte b,byte c,byte d,char *buffer)        /* LD (HL),E */
  {
    sprintf(buffer,"%02x          ld (hl),e",a);
    return 1;
  }

int disP74(byte a,byte b,byte c,byte d,char *buffer)        /* LD (HL),H */
  {
    sprintf(buffer,"%02x          ld (hl),h",a);
    return 1;
  }

int disP75(byte a,byte b,byte c,byte d,char *buffer)        /* LD (HL),L */
  {
    sprintf(buffer,"%02x          ld (hl),l",a);
    return 1;
  }

int disP76(byte a,byte b,byte c,byte d,char *buffer)        /* HALT */
  {
    sprintf(buffer,"%02x          halt",a);
    return 1;
  }

int disP77(byte a,byte b,byte c,byte d,char *buffer)        /* LD (HL),A */
  {
    sprintf(buffer,"%02x          ld (hl),a",a);
    return 1;
  }

int disP78(byte a,byte b,byte c,byte d,char *buffer)        /* LD A,B */
  {
    sprintf(buffer,"%02x          ld a,b",a);
    return 1;
  }

int disP79(byte a,byte b,byte c,byte d,char *buffer)        /* LD A,C */
  {
    sprintf(buffer,"%02x          ld a,c",a);
    return 1;
  }

int disP7A(byte a,byte b,byte c,byte d,char *buffer)        /* LD A,D */
  {
    sprintf(buffer,"%02x          ld a,d",a);
    return 1;
  }

int disP7B(byte a,byte b,byte c,byte d,char *buffer)        /* LD A,E */
  {
    sprintf(buffer,"%02x          ld a,e",a);
    return 1;
  }

int disP7C(byte a,byte b,byte c,byte d,char *buffer)        /* LD A,H */
  {
    sprintf(buffer,"%02x          ld a,h",a);
    return 1;
  }

int disP7D(byte a,byte b,byte c,byte d,char *buffer)        /* LD A,L */
  {
    sprintf(buffer,"%02x          ld a,l",a);
    return 1;
  }

int disP7E(byte a,byte b,byte c,byte d,char *buffer)        /* LD A,(HL) */
  {
    sprintf(buffer,"%02x          ld a,(hl)",a);
    return 1;
  }

int disP7F(byte a,byte b,byte c,byte d,char *buffer)        /* LD A,A */
  {
    sprintf(buffer,"%02x          ld a,a",a);
    return 1;
  }

int disP80(byte a,byte b,byte c,byte d,char *buffer)        /* ADD A,B */
  {
    sprintf(buffer,"%02x          add a,b",a);
    return 1;
  }

int disP81(byte a,byte b,byte c,byte d,char *buffer)        /* ADD A,C */
  {
    sprintf(buffer,"%02x          add a,c",a);
    return 1;
  }

int disP82(byte a,byte b,byte c,byte d,char *buffer)        /* ADD A,D */
  {
    sprintf(buffer,"%02x          add a,d",a);
    return 1;
  }

int disP83(byte a,byte b,byte c,byte d,char *buffer)        /* ADD A,E */
  {
    sprintf(buffer,"%02x          add a,e",a);
    return 1;
  }

int disP84(byte a,byte b,byte c,byte d,char *buffer)        /* ADD A,H */
  {
    sprintf(buffer,"%02x          add a,h",a);
    return 1;
  }

int disP85(byte a,byte b,byte c,byte d,char *buffer)        /* ADD A,L */
  {
    sprintf(buffer,"%02x          add a,l",a);
    return 1;
  }

int disP86(byte a,byte b,byte c,byte d,char *buffer)        /* ADD A,(HL) */
  {
    sprintf(buffer,"%02x          add a,(hl)",a);
    return 1;
  }

int disP87(byte a,byte b,byte c,byte d,char *buffer)        /* ADD A,A */
  {
    sprintf(buffer,"%02x          add a,a",a);
    return 1;
  }

int disP88(byte a,byte b,byte c,byte d,char *buffer)        /* ADC A,B */
  {
    sprintf(buffer,"%02x          adc a,b",a);
    return 1;
  }

int disP89(byte a,byte b,byte c,byte d,char *buffer)        /* ADC A,C */
  {
    sprintf(buffer,"%02x          adc a,c",a);
    return 1;
  }

int disP8A(byte a,byte b,byte c,byte d,char *buffer)        /* ADC A,D */
  {
    sprintf(buffer,"%02x          adc a,d",a);
    return 1;
  }

int disP8B(byte a,byte b,byte c,byte d,char *buffer)        /* ADC A,E */
  {
    sprintf(buffer,"%02x          adc a,e",a);
    return 1;
  }

int disP8C(byte a,byte b,byte c,byte d,char *buffer)        /* ADC A,H */
  {
    sprintf(buffer,"%02x          adc a,h",a);
    return 1;
  }

int disP8D(byte a,byte b,byte c,byte d,char *buffer)        /* ADC A,L */
  {
    sprintf(buffer,"%02x          adc a,l",a);
    return 1;
  }

int disP8E(byte a,byte b,byte c,byte d,char *buffer)        /* ADC A,(HL) */
  {
    sprintf(buffer,"%02x          adc a,(hl)",a);
    return 1;
  }

int disP8F(byte a,byte b,byte c,byte d,char *buffer)        /* ADC A,A */
  {
    sprintf(buffer,"%02x          adc a,a",a);
    return 1;
  }

int disP90(byte a,byte b,byte c,byte d,char *buffer)        /* SUB B */
  {
    sprintf(buffer,"%02x          sub b",a);
    return 1;
  }

int disP91(byte a,byte b,byte c,byte d,char *buffer)        /* SUB C */
  {
    sprintf(buffer,"%02x          sub c",a);
    return 1;
  }

int disP92(byte a,byte b,byte c,byte d,char *buffer)        /* SUB D */
  {
    sprintf(buffer,"%02x          sub d",a);
    return 1;
  }

int disP93(byte a,byte b,byte c,byte d,char *buffer)        /* SUB E */
  {
    sprintf(buffer,"%02x          sub e",a);
    return 1;
  }

int disP94(byte a,byte b,byte c,byte d,char *buffer)        /* SUB H */
  {
    sprintf(buffer,"%02x          sub h",a);
    return 1;
  }

int disP95(byte a,byte b,byte c,byte d,char *buffer)        /* SUB L */
  {
    sprintf(buffer,"%02x          sub l",a);
    return 1;
  }

int disP96(byte a,byte b,byte c,byte d,char *buffer)        /* SUB (HL) */
  {
    sprintf(buffer,"%02x          sub (hl)",a);
    return 1;
  }

int disP97(byte a,byte b,byte c,byte d,char *buffer)        /* SUB A */
  {
    sprintf(buffer,"%02x          sub a",a);
    return 1;
  }

int disP98(byte a,byte b,byte c,byte d,char *buffer)        /* SBC B */
  {
    sprintf(buffer,"%02x          sbc b",a);
    return 1;
  }

int disP99(byte a,byte b,byte c,byte d,char *buffer)        /* SBC C */
  {
    sprintf(buffer,"%02x          sbc c",a);
    return 1;
  }

int disP9A(byte a,byte b,byte c,byte d,char *buffer)        /* SBC D */
  {
    sprintf(buffer,"%02x          sbc d",a);
    return 1;
  }

int disP9B(byte a,byte b,byte c,byte d,char *buffer)        /* SBC E */
  {
    sprintf(buffer,"%02x          sbc e",a);
    return 1;
  }

int disP9C(byte a,byte b,byte c,byte d,char *buffer)        /* SBC H */
  {
    sprintf(buffer,"%02x          sbc h",a);
    return 1;
  }

int disP9D(byte a,byte b,byte c,byte d,char *buffer)        /* SBC L */
  {
    sprintf(buffer,"%02x          sbc l",a);
    return 1;
  }

int disP9E(byte a,byte b,byte c,byte d,char *buffer)        /* SBC (HL) */
  {
    sprintf(buffer,"%02x          sbc (hl)",a);
    return 1;
  }

int disP9F(byte a,byte b,byte c,byte d,char *buffer)        /* SBC A */
  {
    sprintf(buffer,"%02x          sbc a",a);
    return 1;
  }

int disPA0(byte a,byte b,byte c,byte d,char *buffer)        /* AND B */
  {
    sprintf(buffer,"%02x          and b",a);
    return 1;
  }

int disPA1(byte a,byte b,byte c,byte d,char *buffer)        /* AND C */
  {
    sprintf(buffer,"%02x          and c",a);
    return 1;
  }

int disPA2(byte a,byte b,byte c,byte d,char *buffer)        /* AND D */
  {
    sprintf(buffer,"%02x          and d",a);
    return 1;
  }

int disPA3(byte a,byte b,byte c,byte d,char *buffer)        /* AND E */
  {
    sprintf(buffer,"%02x          and e",a);
    return 1;
  }

int disPA4(byte a,byte b,byte c,byte d,char *buffer)        /* AND H */
  {
    sprintf(buffer,"%02x          and h",a);
    return 1;
  }

int disPA5(byte a,byte b,byte c,byte d,char *buffer)        /* AND L */
  {
    sprintf(buffer,"%02x          and l",a);
    return 1;
  }

int disPA6(byte a,byte b,byte c,byte d,char *buffer)        /* AND (HL) */
  {
    sprintf(buffer,"%02x          and (hl)",a);
    return 1;
  }

int disPA7(byte a,byte b,byte c,byte d,char *buffer)        /* AND A */
  {
    sprintf(buffer,"%02x          and a",a);
    return 1;
  }

int disPA8(byte a,byte b,byte c,byte d,char *buffer)        /* XOR B */
  {
    sprintf(buffer,"%02x          xor b",a);
    return 1;
  }

int disPA9(byte a,byte b,byte c,byte d,char *buffer)        /* XOR C */
  {
    sprintf(buffer,"%02x          xor c",a);
    return 1;
  }

int disPAA(byte a,byte b,byte c,byte d,char *buffer)        /* XOR D */
  {
    sprintf(buffer,"%02x          xor d",a);
    return 1;
  }

int disPAB(byte a,byte b,byte c,byte d,char *buffer)        /* XOR E */
  {
    sprintf(buffer,"%02x          xor e",a);
    return 1;
  }

int disPAC(byte a,byte b,byte c,byte d,char *buffer)        /* XOR H */
  {
    sprintf(buffer,"%02x          xor h",a);
    return 1;
  }

int disPAD(byte a,byte b,byte c,byte d,char *buffer)        /* XOR L */
  {
    sprintf(buffer,"%02x          xor l",a);
    return 1;
  }

int disPAE(byte a,byte b,byte c,byte d,char *buffer)        /* XOR (HL) */
  {
    sprintf(buffer,"%02x          xor (hl)",a);
    return 1;
  }

int disPAF(byte a,byte b,byte c,byte d,char *buffer)        /* XOR A */
  {
    sprintf(buffer,"%02x          xor a",a);
    return 1;
  }

int disPB0(byte a,byte b,byte c,byte d,char *buffer)        /* OR B */
  {
    sprintf(buffer,"%02x          or b",a);
    return 1;
  }

int disPB1(byte a,byte b,byte c,byte d,char *buffer)        /* OR C */
  {
    sprintf(buffer,"%02x          or c",a);
    return 1;
  }

int disPB2(byte a,byte b,byte c,byte d,char *buffer)        /* OR D */
  {
    sprintf(buffer,"%02x          or d",a);
    return 1;
  }

int disPB3(byte a,byte b,byte c,byte d,char *buffer)        /* OR E */
  {
    sprintf(buffer,"%02x          or e",a);
    return 1;
  }

int disPB4(byte a,byte b,byte c,byte d,char *buffer)        /* OR H */
  {
    sprintf(buffer,"%02x          or h",a);
    return 1;
  }

int disPB5(byte a,byte b,byte c,byte d,char *buffer)        /* OR L */
  {
    sprintf(buffer,"%02x          or l",a);
    return 1;
  }

int disPB6(byte a,byte b,byte c,byte d,char *buffer)        /* OR (HL) */
  {
    sprintf(buffer,"%02x          or (hl)",a);
    return 1;
  }

int disPB7(byte a,byte b,byte c,byte d,char *buffer)        /* OR A */
  {
    sprintf(buffer,"%02x          or a",a);
    return 1;
  }

int disPB8(byte a,byte b,byte c,byte d,char *buffer)        /* CP B */
  {
    sprintf(buffer,"%02x          cp b",a);
    return 1;
  }

int disPB9(byte a,byte b,byte c,byte d,char *buffer)        /* CP C */
  {
    sprintf(buffer,"%02x          cp c",a);
    return 1;
  }

int disPBA(byte a,byte b,byte c,byte d,char *buffer)        /* CP D */
  {
    sprintf(buffer,"%02x          cp d",a);
    return 1;
  }

int disPBB(byte a,byte b,byte c,byte d,char *buffer)        /* CP E */
  {
    sprintf(buffer,"%02x          cp e",a);
    return 1;
  }

int disPBC(byte a,byte b,byte c,byte d,char *buffer)        /* CP H */
  {
    sprintf(buffer,"%02x          cp h",a);
    return 1;
  }

int disPBD(byte a,byte b,byte c,byte d,char *buffer)        /* CP L */
  {
    sprintf(buffer,"%02x          cp l",a);
    return 1;
  }

int disPBE(byte a,byte b,byte c,byte d,char *buffer)        /* CP (HL) */
  {
    sprintf(buffer,"%02x          cp (hl)",a);
    return 1;
  }

int disPBF(byte a,byte b,byte c,byte d,char *buffer)        /* CP A */
  {
    sprintf(buffer,"%02x          cp a",a);
    return 1;
  }

int disPC0(byte a,byte b,byte c,byte d,char *buffer)        /* RET NZ */
  {
    sprintf(buffer,"%02x          ret nz",a);
    return 1;
  }

int disPC1(byte a,byte b,byte c,byte d,char *buffer)        /* POP BC */
  {
    sprintf(buffer,"%02x          pop bc",a);
    return 1;
  }

int disPC2(byte a,byte b,byte c,byte d,char *buffer)        /* JP NZ,nn */
  {
    sprintf(buffer,"%02x %02x %02x    jp nz,%04x",a,b,c,b+c*256);
    return 3;
  }

int disPC3(byte a,byte b,byte c,byte d,char *buffer)        /* JP nn */
  {
    sprintf(buffer,"%02x %02x %02x    jp %04x",a,b,c,b+c*256);
    return 3;
  }

int disPC4(byte a,byte b,byte c,byte d,char *buffer)        /* CALL NZ,nn */
  {
    sprintf(buffer,"%02x %02x %02x    call nz,%04x",a,b,c,b+c*256);
    return 3;
  }

int disPC5(byte a,byte b,byte c,byte d,char *buffer)        /* PUSH BC */
  {
    sprintf(buffer,"%02x          push bc",a);
    return 1;
  }

int disPC6(byte a,byte b,byte c,byte d,char *buffer)        /* ADD A,n */
  {
    sprintf(buffer,"%02x %02x       add a,%02x",a,b,b);
    return 2;
  }

int disPC7(byte a,byte b,byte c,byte d,char *buffer)        /* RST 00H */
  {
    sprintf(buffer,"%02x          rst 00",a);
    return 1;
  }

int disPC8(byte a,byte b,byte c,byte d,char *buffer)        /* RET Z */
  {
    sprintf(buffer,"%02x          ret z",a);
    return 1;
  }

int disPC9(byte a,byte b,byte c,byte d,char *buffer)        /* RET */
  {
    sprintf(buffer,"%02x          ret",a);
    return 1;
  }

int disPCA(byte a,byte b,byte c,byte d,char *buffer)        /* JP Z,nn */
  {
    sprintf(buffer,"%02x %02x %02x    jp z,%04x",a,b,c,b+c*256);
    return 3;
  }

int disPCC(byte a,byte b,byte c,byte d,char *buffer)        /* CALL Z,nn */
  {
    sprintf(buffer,"%02x %02x %02x    call z,%04x",a,b,c,b+c*256);
    return 3;
  }

int disPCD(byte a,byte b,byte c,byte d,char *buffer)        /* CALL nn */
  {
    sprintf(buffer,"%02x %02x %02x    call %04x",a,b,c,b+c*256);
    return 3;
  }

int disPCE(byte a,byte b,byte c,byte d,char *buffer)        /* ADC A,n */
  {
    sprintf(buffer,"%02x %02x       adc a,%02x",a,b,b);
    return 2;
  }

int disPCF(byte a,byte b,byte c,byte d,char *buffer)        /* RST 08H */
  {
    sprintf(buffer,"%02x          rst 08",a);
    return 1;
  }

int disPD0(byte a,byte b,byte c,byte d,char *buffer)        /* RET NC */
  {
    sprintf(buffer,"%02x          ret nc",a);
    return 1;
  }

int disPD1(byte a,byte b,byte c,byte d,char *buffer)        /* POP DE */
  {
    sprintf(buffer,"%02x          pop de",a);
    return 1;
  }

int disPD2(byte a,byte b,byte c,byte d,char *buffer)        /* JP NC,nn */
  {
    sprintf(buffer,"%02x %02x %02x    jp nc,%04x",a,b,c,b+c*256);
    return 3;
  }

int disPD3(byte a,byte b,byte c,byte d,char *buffer)        /* OUT (n),A */
  {
    sprintf(buffer,"%02x %02x       out (%02x),a",a,b,b);
    return 2;
  }

int disPD4(byte a,byte b,byte c,byte d,char *buffer)        /* CALL NC,nn */
  {
    sprintf(buffer,"%02x %02x %02x    call nc,%04x",a,b,c,b+c*256);
    return 3;
  }

int disPD5(byte a,byte b,byte c,byte d,char *buffer)        /* PUSH DE */
  {
    sprintf(buffer,"%02x          push de",a);
    return 1;
  }

int disPD6(byte a,byte b,byte c,byte d,char *buffer)        /* SUB n */
  {
    sprintf(buffer,"%02x %02x       sub %02x",a,b,b);
    return 2;
  }

int disPD7(byte a,byte b,byte c,byte d,char *buffer)        /* RST 10H */
  {
    sprintf(buffer,"%02x          rst 10",a);
    return 1;
  }

int disPD8(byte a,byte b,byte c,byte d,char *buffer)        /* RET C */
  {
    sprintf(buffer,"%02x          ret c",a);
    return 1;
  }

int disPD9(byte a,byte b,byte c,byte d,char *buffer)        /* EXX */
  {
    sprintf(buffer,"%02x          exx",a);
    return 1;
  }

int disPDA(byte a,byte b,byte c,byte d,char *buffer)        /* JP C,nn */
  {
    sprintf(buffer,"%02x %02x %02x    jp c,%04x",a,b,c,b+c*256);
    return 3;
  }

int disPDB(byte a,byte b,byte c,byte d,char *buffer)        /* IN A,(n) */
  {
    sprintf(buffer,"%02x %02x       in a,(%02x)",a,b,b);
    return 2;
  }

int disPDC(byte a,byte b,byte c,byte d,char *buffer)        /* CALL C,nn */
  {
    sprintf(buffer,"%02x %02x %02x    call c,%04x",a,b,c,b+c*256);
    return 3;
  }

int disPDE(byte a,byte b,byte c,byte d,char *buffer)        /* SBC A,n */
  {
    sprintf(buffer,"%02x %02x       sbc a,%02x",a,b,b);
    return 2;
  }

int disPDF(byte a,byte b,byte c,byte d,char *buffer)        /* RST 18H */
  {
    sprintf(buffer,"%02x          rst 18",a);
    return 1;
  }

int disPE0(byte a,byte b,byte c,byte d,char *buffer)        /* RET PE */
  {
    sprintf(buffer,"%02x          ret pe",a);
    return 1;
  }

int disPE1(byte a,byte b,byte c,byte d,char *buffer)        /* POP HL */
  {
    sprintf(buffer,"%02x          pop hl",a);
    return 1;
  }

int disPE2(byte a,byte b,byte c,byte d,char *buffer)        /* JP PO,nn */
  {
    sprintf(buffer,"%02x %02x %02x    jp po,%04x",a,b,c,b+c*256);
    return 3;
  }

int disPE3(byte a,byte b,byte c,byte d,char *buffer)        /* EX (SP),HL */
  {
    sprintf(buffer,"%02x          ex (sp),hl",a);
    return 1;
  }

int disPE4(byte a,byte b,byte c,byte d,char *buffer)        /* CALL PE,nn */
  {
    sprintf(buffer,"%02x %02x %02x    call pe,%04x",a,b,c,b+c*256);
    return 3;
  }

int disPE5(byte a,byte b,byte c,byte d,char *buffer)        /* PUSH HL */
  {
    sprintf(buffer,"%02x          push hl",a);
    return 1;
  }

int disPE6(byte a,byte b,byte c,byte d,char *buffer)        /* AND n */
  {
    sprintf(buffer,"%02x %02x       and %02x",a,b,b);
    return 2;
  }

int disPE7(byte a,byte b,byte c,byte d,char *buffer)        /* RST 20H */
  {
    sprintf(buffer,"%02x          rst 20",a);
    return 1;
  }

int disPE8(byte a,byte b,byte c,byte d,char *buffer)        /* RET PO */
  {
    sprintf(buffer,"%02x          ret po",a);
    return 1;
  }

int disPE9(byte a,byte b,byte c,byte d,char *buffer)        /* JP (HL) */
  {
    sprintf(buffer,"%02x          jp (hl)",a);
    return 1;
  }

int disPEA(byte a,byte b,byte c,byte d,char *buffer)        /* JP PE,nn */
 {
    sprintf(buffer,"%02x %02x %02x    jp pe,%04x",a,b,c,b+c*256);
    return 3;
 }

int disPEB(byte a,byte b,byte c,byte d,char *buffer)        /* EX DE,HL */
  {
    sprintf(buffer,"%02x          ex de,hl",a);
    return 1;
  }

int disPEC(byte a,byte b,byte c,byte d,char *buffer)        /* CALL PO,nn */
  {
    sprintf(buffer,"%02x %02x %02x    call po,%04x",a,b,c,b+c*256);
    return 3;
  }

int disPEE(byte a,byte b,byte c,byte d,char *buffer)        /* XOR n */
  {
    sprintf(buffer,"%02x %02x       xor %02x",a,b,b);
    return 2;
  }

int disPEF(byte a,byte b,byte c,byte d,char *buffer)        /* RST 28H */
  {
    sprintf(buffer,"%02x          rst 28",a);
    return 1;
  }

int disPF0(byte a,byte b,byte c,byte d,char *buffer)        /* RET P */
  {
    sprintf(buffer,"%02x          ret p",a);
    return 1;
  }

int disPF1(byte a,byte b,byte c,byte d,char *buffer)        /* POP AF */
  {
    sprintf(buffer,"%02x          pop af",a);
    return 1;
  }

int disPF2(byte a,byte b,byte c,byte d,char *buffer)        /* JP P,nn */
  {
    sprintf(buffer,"%02x %02x %02x    jp p,%04x",a,b,c,b+c*256);
    return 3;
  }

int disPF3(byte a,byte b,byte c,byte d,char *buffer)        /* DI */
  {
    sprintf(buffer,"%02x          di",a);
    return 1;
  }

int disPF4(byte a,byte b,byte c,byte d,char *buffer)        /* CALL P,nn */
  {
    sprintf(buffer,"%02x %02x %02x    call p,%04x",a,b,c,b+c*256);
    return 3;
  }

int disPF5(byte a,byte b,byte c,byte d,char *buffer)        /* PUSH AF */
  {
    sprintf(buffer,"%02x          push af",a);
    return 1;
  }

int disPF6(byte a,byte b,byte c,byte d,char *buffer)        /* OR n */
  {
    sprintf(buffer,"%02x %02x       or %02x",a,b,b);
    return 2;
  }

int disPF7(byte a,byte b,byte c,byte d,char *buffer)        /* RST 30H */
  {
    sprintf(buffer,"%02x          rst 30",a);
    return 1;
  }

int disPF8(byte a,byte b,byte c,byte d,char *buffer)        /* RET M */
  {
    sprintf(buffer,"%02x          ret m",a);
    return 1;
  }

int disPF9(byte a,byte b,byte c,byte d,char *buffer)        /* LD SP,HL */
  {
    sprintf(buffer,"%02x          ld sp,hl",a);
    return 1;
  }

int disPFA(byte a,byte b,byte c,byte d,char *buffer)        /* JP M,nn */
  {
    sprintf(buffer,"%02x %02x %02x    jp m,%04x",a,b,c,b+c*256);
    return 3;
  }

int disPFB(byte a,byte b,byte c,byte d,char *buffer)        /* EI */
  {
    sprintf(buffer,"%02x          ei",a);
    return 1;
  }

int disPFC(byte a,byte b,byte c,byte d,char *buffer)        /* CALL M,nn */
  {
    sprintf(buffer,"%02x %02x %02x    call m,%04x",a,b,c,b+c*256);
    return 3;
  }

int disPFE(byte a,byte b,byte c,byte d,char *buffer)        /* CP n */
  {
    sprintf(buffer,"%02x %02x       cp %02x",a,b,b);
    return 2;
  }

int disPFF(byte a,byte b,byte c,byte d,char *buffer)        /* RST 38H */
  {
    sprintf(buffer,"%02x          rst 38",a);
    return 1;
  }

int disassem(byte a,byte b,byte c,byte d,char *buffer)
  {
    byte bt;
    bt=a;
    strcpy(buffer,"***");
    switch (bt & 0xf0) {
      case 0x00:switch (bt & 15) {
         case  0:return disP0(a,b,c,d,buffer); break;
         case  1:return disP1(a,b,c,d,buffer); break;
         case  2:return disP2(a,b,c,d,buffer); break;
         case  3:return disP3(a,b,c,d,buffer); break;
         case  4:return disP4(a,b,c,d,buffer); break;
         case  5:return disP5(a,b,c,d,buffer); break;
         case  6:return disP6(a,b,c,d,buffer); break;
         case  7:return disP7(a,b,c,d,buffer); break;
         case  8:return disP8(a,b,c,d,buffer); break;
         case  9:return disP9(a,b,c,d,buffer); break;
         case 10:return disPA(a,b,c,d,buffer); break;
         case 11:return disPB(a,b,c,d,buffer); break;
         case 12:return disPC(a,b,c,d,buffer); break;
         case 13:return disPD(a,b,c,d,buffer); break;
         case 14:return disPE(a,b,c,d,buffer); break;
         case 15:return disPF(a,b,c,d,buffer); break;
         } break;

      case 0x10:switch (bt & 15) {
         case  0:return disP10(a,b,c,d,buffer); break;
         case  1:return disP11(a,b,c,d,buffer); break;
         case  2:return disP12(a,b,c,d,buffer); break;
         case  3:return disP13(a,b,c,d,buffer); break;
         case  4:return disP14(a,b,c,d,buffer); break;
         case  5:return disP15(a,b,c,d,buffer); break;
         case  6:return disP16(a,b,c,d,buffer); break;
         case  7:return disP17(a,b,c,d,buffer); break;
         case  8:return disP18(a,b,c,d,buffer); break;
         case  9:return disP19(a,b,c,d,buffer); break;
         case 10:return disP1A(a,b,c,d,buffer); break;
         case 11:return disP1B(a,b,c,d,buffer); break;
         case 12:return disP1C(a,b,c,d,buffer); break;
         case 13:return disP1D(a,b,c,d,buffer); break;
         case 14:return disP1E(a,b,c,d,buffer); break;
         case 15:return disP1F(a,b,c,d,buffer); break;
         } break;
      case 0x20:switch (bt & 15) {
         case  0:return disP20(a,b,c,d,buffer); break;
         case  1:return disP21(a,b,c,d,buffer); break;
         case  2:return disP22(a,b,c,d,buffer); break;
         case  3:return disP23(a,b,c,d,buffer); break;
         case  4:return disP24(a,b,c,d,buffer); break;
         case  5:return disP25(a,b,c,d,buffer); break;
         case  6:return disP26(a,b,c,d,buffer); break;
         case  7:return disP27(a,b,c,d,buffer); break;
         case  8:return disP28(a,b,c,d,buffer); break;
         case  9:return disP29(a,b,c,d,buffer); break;
         case 10:return disP2A(a,b,c,d,buffer); break;
         case 11:return disP2B(a,b,c,d,buffer); break;
         case 12:return disP2C(a,b,c,d,buffer); break;
         case 13:return disP2D(a,b,c,d,buffer); break;
         case 14:return disP2E(a,b,c,d,buffer); break;
         case 15:return disP2F(a,b,c,d,buffer); break;
         } break;
      case 0x30:switch (bt & 15) {
         case  0:return disP30(a,b,c,d,buffer); break;
         case  1:return disP31(a,b,c,d,buffer); break;
         case  2:return disP32(a,b,c,d,buffer); break;
         case  3:return disP33(a,b,c,d,buffer); break;
         case  4:return disP34(a,b,c,d,buffer); break;
         case  5:return disP35(a,b,c,d,buffer); break;
         case  6:return disP36(a,b,c,d,buffer); break;
         case  7:return disP37(a,b,c,d,buffer); break;
         case  8:return disP38(a,b,c,d,buffer); break;
         case  9:return disP39(a,b,c,d,buffer); break;
         case 10:return disP3A(a,b,c,d,buffer); break;
         case 11:return disP3B(a,b,c,d,buffer); break;
         case 12:return disP3C(a,b,c,d,buffer); break;
         case 13:return disP3D(a,b,c,d,buffer); break;
         case 14:return disP3E(a,b,c,d,buffer); break;
         case 15:return disP3F(a,b,c,d,buffer); break;
         } break;
      case 0x40:switch (bt & 15) {
         case  0:return disP40(a,b,c,d,buffer); break;
         case  1:return disP41(a,b,c,d,buffer); break;
         case  2:return disP42(a,b,c,d,buffer); break;
         case  3:return disP43(a,b,c,d,buffer); break;
         case  4:return disP44(a,b,c,d,buffer); break;
         case  5:return disP45(a,b,c,d,buffer); break;
         case  6:return disP46(a,b,c,d,buffer); break;
         case  7:return disP47(a,b,c,d,buffer); break;
         case  8:return disP48(a,b,c,d,buffer); break;
         case  9:return disP49(a,b,c,d,buffer); break;
         case 10:return disP4A(a,b,c,d,buffer); break;
         case 11:return disP4B(a,b,c,d,buffer); break;
         case 12:return disP4C(a,b,c,d,buffer); break;
         case 13:return disP4D(a,b,c,d,buffer); break;
         case 14:return disP4E(a,b,c,d,buffer); break;
         case 15:return disP4F(a,b,c,d,buffer); break;
         } break;
      case 0x50:switch (bt & 15) {
         case  0:return disP50(a,b,c,d,buffer); break;
         case  1:return disP51(a,b,c,d,buffer); break;
         case  2:return disP52(a,b,c,d,buffer); break;
         case  3:return disP53(a,b,c,d,buffer); break;
         case  4:return disP54(a,b,c,d,buffer); break;
         case  5:return disP55(a,b,c,d,buffer); break;
         case  6:return disP56(a,b,c,d,buffer); break;
         case  7:return disP57(a,b,c,d,buffer); break;
         case  8:return disP58(a,b,c,d,buffer); break;
         case  9:return disP59(a,b,c,d,buffer); break;
         case 10:return disP5A(a,b,c,d,buffer); break;
         case 11:return disP5B(a,b,c,d,buffer); break;
         case 12:return disP5C(a,b,c,d,buffer); break;
         case 13:return disP5D(a,b,c,d,buffer); break;
         case 14:return disP5E(a,b,c,d,buffer); break;
         case 15:return disP5F(a,b,c,d,buffer); break;
         } break;
      case 0x60:switch (bt & 15) {
         case  0:return disP60(a,b,c,d,buffer); break;
         case  1:return disP61(a,b,c,d,buffer); break;
         case  2:return disP62(a,b,c,d,buffer); break;
         case  3:return disP63(a,b,c,d,buffer); break;
         case  4:return disP64(a,b,c,d,buffer); break;
         case  5:return disP65(a,b,c,d,buffer); break;
         case  6:return disP66(a,b,c,d,buffer); break;
         case  7:return disP67(a,b,c,d,buffer); break;
         case  8:return disP68(a,b,c,d,buffer); break;
         case  9:return disP69(a,b,c,d,buffer); break;
         case 10:return disP6A(a,b,c,d,buffer); break;
         case 11:return disP6B(a,b,c,d,buffer); break;
         case 12:return disP6C(a,b,c,d,buffer); break;
         case 13:return disP6D(a,b,c,d,buffer); break;
         case 14:return disP6E(a,b,c,d,buffer); break;
         case 15:return disP6F(a,b,c,d,buffer); break;
         } break;
      case 0x70:switch (bt & 15) {
         case  0:return disP70(a,b,c,d,buffer); break;
         case  1:return disP71(a,b,c,d,buffer); break;
         case  2:return disP72(a,b,c,d,buffer); break;
         case  3:return disP73(a,b,c,d,buffer); break;
         case  4:return disP74(a,b,c,d,buffer); break;
         case  5:return disP75(a,b,c,d,buffer); break;
         case  6:return disP76(a,b,c,d,buffer); break;
         case  7:return disP77(a,b,c,d,buffer); break;
         case  8:return disP78(a,b,c,d,buffer); break;
         case  9:return disP79(a,b,c,d,buffer); break;
         case 10:return disP7A(a,b,c,d,buffer); break;
         case 11:return disP7B(a,b,c,d,buffer); break;
         case 12:return disP7C(a,b,c,d,buffer); break;
         case 13:return disP7D(a,b,c,d,buffer); break;
         case 14:return disP7E(a,b,c,d,buffer); break;
         case 15:return disP7F(a,b,c,d,buffer); break;
         } break;
      case 0x80:switch (bt & 15) {
         case  0:return disP80(a,b,c,d,buffer); break;
         case  1:return disP81(a,b,c,d,buffer); break;
         case  2:return disP82(a,b,c,d,buffer); break;
         case  3:return disP83(a,b,c,d,buffer); break;
         case  4:return disP84(a,b,c,d,buffer); break;
         case  5:return disP85(a,b,c,d,buffer); break;
         case  6:return disP86(a,b,c,d,buffer); break;
         case  7:return disP87(a,b,c,d,buffer); break;
         case  8:return disP88(a,b,c,d,buffer); break;
         case  9:return disP89(a,b,c,d,buffer); break;
         case 10:return disP8A(a,b,c,d,buffer); break;
         case 11:return disP8B(a,b,c,d,buffer); break;
         case 12:return disP8C(a,b,c,d,buffer); break;
         case 13:return disP8D(a,b,c,d,buffer); break;
         case 14:return disP8E(a,b,c,d,buffer); break;
         case 15:return disP8F(a,b,c,d,buffer); break;
         } break;

      case 0x90:switch (bt & 15) {
         case  0:return disP90(a,b,c,d,buffer); break;
         case  1:return disP91(a,b,c,d,buffer); break;
         case  2:return disP92(a,b,c,d,buffer); break;
         case  3:return disP93(a,b,c,d,buffer); break;
         case  4:return disP94(a,b,c,d,buffer); break;
         case  5:return disP95(a,b,c,d,buffer); break;
         case  6:return disP96(a,b,c,d,buffer); break;
         case  7:return disP97(a,b,c,d,buffer); break;
         case  8:return disP98(a,b,c,d,buffer); break;
         case  9:return disP99(a,b,c,d,buffer); break;
         case 10:return disP9A(a,b,c,d,buffer); break;
         case 11:return disP9B(a,b,c,d,buffer); break;
         case 12:return disP9C(a,b,c,d,buffer); break;
         case 13:return disP9D(a,b,c,d,buffer); break;
         case 14:return disP9E(a,b,c,d,buffer); break;
         case 15:return disP9F(a,b,c,d,buffer); break;
         } break;
      case 0xA0:switch (bt & 15) {
         case  0:return disPA0(a,b,c,d,buffer); break;
         case  1:return disPA1(a,b,c,d,buffer); break;
         case  2:return disPA2(a,b,c,d,buffer); break;
         case  3:return disPA3(a,b,c,d,buffer); break;
         case  4:return disPA4(a,b,c,d,buffer); break;
         case  5:return disPA5(a,b,c,d,buffer); break;
         case  6:return disPA6(a,b,c,d,buffer); break;
         case  7:return disPA7(a,b,c,d,buffer); break;
         case  8:return disPA8(a,b,c,d,buffer); break;
         case  9:return disPA9(a,b,c,d,buffer); break;
         case 10:return disPAA(a,b,c,d,buffer); break;
         case 11:return disPAB(a,b,c,d,buffer); break;
         case 12:return disPAC(a,b,c,d,buffer); break;
         case 13:return disPAD(a,b,c,d,buffer); break;
         case 14:return disPAE(a,b,c,d,buffer); break;
         case 15:return disPAF(a,b,c,d,buffer); break;
         } break;
      case 0xB0:switch (bt & 15) {
         case  0:return disPB0(a,b,c,d,buffer); break;
         case  1:return disPB1(a,b,c,d,buffer); break;
         case  2:return disPB2(a,b,c,d,buffer); break;
         case  3:return disPB3(a,b,c,d,buffer); break;
         case  4:return disPB4(a,b,c,d,buffer); break;
         case  5:return disPB5(a,b,c,d,buffer); break;
         case  6:return disPB6(a,b,c,d,buffer); break;
         case  7:return disPB7(a,b,c,d,buffer); break;
         case  8:return disPB8(a,b,c,d,buffer); break;
         case  9:return disPB9(a,b,c,d,buffer); break;
         case 10:return disPBA(a,b,c,d,buffer); break;
         case 11:return disPBB(a,b,c,d,buffer); break;
         case 12:return disPBC(a,b,c,d,buffer); break;
         case 13:return disPBD(a,b,c,d,buffer); break;
         case 14:return disPBE(a,b,c,d,buffer); break;
         case 15:return disPBF(a,b,c,d,buffer); break;
         } break;
      case 0xC0:switch (bt & 15) {
         case  0:return disPC0(a,b,c,d,buffer); break;
         case  1:return disPC1(a,b,c,d,buffer); break;
         case  2:return disPC2(a,b,c,d,buffer); break;
         case  3:return disPC3(a,b,c,d,buffer); break;
         case  4:return disPC4(a,b,c,d,buffer); break;
         case  5:return disPC5(a,b,c,d,buffer); break;
         case  6:return disPC6(a,b,c,d,buffer); break;
         case  7:return disPC7(a,b,c,d,buffer); break;
         case  8:return disPC8(a,b,c,d,buffer); break;
         case  9:return disPC9(a,b,c,d,buffer); break;
         case 10:return disPCA(a,b,c,d,buffer); break;
         case 11:return disPCB(a,b,c,d,buffer); break;
         case 12:return disPCC(a,b,c,d,buffer); break;
         case 13:return disPCD(a,b,c,d,buffer); break;
         case 14:return disPCE(a,b,c,d,buffer); break;
         case 15:return disPCF(a,b,c,d,buffer); break;
         } break;
      case 0xD0:switch (bt & 15) {
         case  0:return disPD0(a,b,c,d,buffer); break;
         case  1:return disPD1(a,b,c,d,buffer); break;
         case  2:return disPD2(a,b,c,d,buffer); break;
         case  3:return disPD3(a,b,c,d,buffer); break;
         case  4:return disPD4(a,b,c,d,buffer); break;
         case  5:return disPD5(a,b,c,d,buffer); break;
         case  6:return disPD6(a,b,c,d,buffer); break;
         case  7:return disPD7(a,b,c,d,buffer); break;
         case  8:return disPD8(a,b,c,d,buffer); break;
         case  9:return disPD9(a,b,c,d,buffer); break;
         case 10:return disPDA(a,b,c,d,buffer); break;
         case 11:return disPDB(a,b,c,d,buffer); break;
         case 12:return disPDC(a,b,c,d,buffer); break;
         case 13:return disPDD(a,b,c,d,buffer); break;
         case 14:return disPDE(a,b,c,d,buffer); break;
         case 15:return disPDF(a,b,c,d,buffer); break;
         } break;
      case 0xE0:switch (bt & 15) {
         case  0:return disPE0(a,b,c,d,buffer); break;
         case  1:return disPE1(a,b,c,d,buffer); break;
         case  2:return disPE2(a,b,c,d,buffer); break;
         case  3:return disPE3(a,b,c,d,buffer); break;
         case  4:return disPE4(a,b,c,d,buffer); break;
         case  5:return disPE5(a,b,c,d,buffer); break;
         case  6:return disPE6(a,b,c,d,buffer); break;
         case  7:return disPE7(a,b,c,d,buffer); break;
         case  8:return disPE8(a,b,c,d,buffer); break;
         case  9:return disPE9(a,b,c,d,buffer); break;
         case 10:return disPEA(a,b,c,d,buffer); break;
         case 11:return disPEB(a,b,c,d,buffer); break;
         case 12:return disPEC(a,b,c,d,buffer); break;
         case 13:return disPED(a,b,c,d,buffer); break;
         case 14:return disPEE(a,b,c,d,buffer); break;
         case 15:return disPEF(a,b,c,d,buffer); break;
         } break;
      case 0xF0:switch (bt & 15) {
         case  0:return disPF0(a,b,c,d,buffer); break;
         case  1:return disPF1(a,b,c,d,buffer); break;
         case  2:return disPF2(a,b,c,d,buffer); break;
         case  3:return disPF3(a,b,c,d,buffer); break;
         case  4:return disPF4(a,b,c,d,buffer); break;
         case  5:return disPF5(a,b,c,d,buffer); break;
         case  6:return disPF6(a,b,c,d,buffer); break;
         case  7:return disPF7(a,b,c,d,buffer); break;
         case  8:return disPF8(a,b,c,d,buffer); break;
         case  9:return disPF9(a,b,c,d,buffer); break;
         case 10:return disPFA(a,b,c,d,buffer); break;
         case 11:return disPFB(a,b,c,d,buffer); break;
         case 12:return disPFC(a,b,c,d,buffer); break;
         case 13:return disPFD(a,b,c,d,buffer); break;
         case 14:return disPFE(a,b,c,d,buffer); break;
         case 15:return disPFF(a,b,c,d,buffer); break;
         } break;

      }
  }

