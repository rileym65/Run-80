#include <stdio.h>
#define global

#include "z80.h"

struct Z80CPU trs80;

FILE *errfile;

void errlog(char *buffer) {
  errfile=fopen("trs.log","a");
  fprintf(errfile,"%s",buffer);
  fclose(errfile);
  }

void TStore(struct Z80CPU *z80,word Address,byte Value) {
  z80->Memory[Address]=Value;
  }

byte TFetch(struct Z80CPU *z80,word Address) {
  byte retval;
  retval= z80->Memory[Address];
  return retval;
  }

void TOut(struct Z80CPU *z80,word Address,byte Value) {
  }

byte TIn(struct Z80CPU *z80,word Address) {
  return 0;
  }

void z80reset(struct Z80CPU *z80) {
  z80->IE=0;
  z80->PC=0;
  z80->R=0;
  z80->Halt=0;
  z80->Intrpt=0;
  }

void test(word af,word bc,word de,word hl,word ix,word iy,word sp,
          word pc,byte p1,byte p2,byte p3,byte p4,
          word eaf,word ebc,word ede,word ehl,word eix,word eiy,word esp,
          word epc,word addr,byte m1,byte m2,byte m3,byte m4) {
  char f;
  trs80.AF.AF=af; trs80.BC.BC=bc; trs80.DE.DE=de; trs80.HL.HL=hl;
  trs80.IX=ix; trs80.IY=iy; trs80.SP=sp,trs80.PC=pc;
  trs80.Memory[pc]=p1; trs80.Memory[pc+1]=p2;
  trs80.Memory[pc+2]=p3; trs80.Memory[pc+3]=p4;
  f=' ';
  cycle(&trs80);
  if (trs80.AF.AF!=eaf || trs80.BC.BC!=ebc || trs80.DE.DE!=ede || trs80.HL.HL!=ehl) f='*';
  if (trs80.IX!=eix || trs80.IY!=eiy || trs80.SP!=esp || trs80.PC!=epc) f='*';
  if (addr!=0) {
    if (trs80.Memory[addr]!=m1) f='*';
    if (trs80.Memory[addr+1]!=m2) f='*';
    if (trs80.Memory[addr+2]!=m3) f='*';
    if (trs80.Memory[addr+3]!=m4) f='*';
    }
  if (f!=' ') {
    printf("inst=%02x %02x %02x %02x\n",p1,p2,p3,p4);
    printf("af=%04x (%04x)  bc=%04x (%04x)  de=%04x (%04x)  hl=%04x (%04x)\n",
            trs80.AF.AF,eaf,trs80.BC.BC,ebc,trs80.DE.DE,ede,trs80.HL.HL,ehl);
    printf("ix=%04x (%04x)  iy=%04x (%04x)  sp=%04x (%04x)  pc=%04x (%04x)\n",
            trs80.IX,eix,trs80.IY,eiy,trs80.SP,esp,trs80.PC,epc);
    if (addr!=0) {
      printf("mem=%04x %02x %02x %02x %02x (%02x %02x %02x %02x)\n",
        addr,trs80.Memory[addr],trs80.Memory[addr+1],trs80.Memory[addr+2],
        trs80.Memory[addr+3],m1,m2,m3,m4);
      }
    printf("\n");
    }
  }

void performtest() {
/*       AF     BC     DE     HL     IX     IY     SP     PC           I1   I2   I3   I4 */
/*  00            NOP  */
  test(0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,       0x00,0x00,0x00,0x00,
       0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0001,0x0000,0x00,0x00,0x00,0x00);
/*  01            LD BC,nn  */
  test(0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,       0x01,0xfe,0xbc,0x00,
       0x0000,0xbcfe,0x0000,0x0000,0x0000,0x0000,0x0000,0x0003,0x0000,0x00,0x00,0x00,0x00);
  test(0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0000,       0x01,0xfe,0xbc,0x00,
       0xffff,0xbcfe,0xffff,0xffff,0xffff,0xffff,0xffff,0x0003,0x0000,0x00,0x00,0x00,0x00);
/*  02            LD (BC),A  */
/*  03            INC BC  */
/*  04            INC B  */
/*  05            DEC B  */
/*  06            LD B,n  */
/*  07            RLCA  */
/*  08            EX AF,AF'  */
/*  09            ADD HL,BC  */
/*  0A            LD A,(BC)  */
/*  0B            DEC BC  */
/*  0C            INC C  */
/*  0D            DEC C  */
/*  0E            LD C,n  */
/*  0F            RRCA  */
/*  10            DJNZ  */
/*  11            LD DE,nn  */
/*  12            LD (DE),A  */
/*  13            INC DE  */
/*  14            INC D  */
/*  15            DEC D  */
/*  16            LD D,n  */
/*  17            RLA  */
/*  18            JR e  */
/*  19            ADD HL,DE  */
/*  1A            LD A,(DE)  */
/*  1B            DEC DE  */
/*  1C            INC E  */
/*  1D            DEC E  */
/*  1E            LD E,n  */
/*  1F            RRA  */
/*  20            JR NZ,e  */
/*  21            LD HL,nn  */
/*  22            LD (nn),HL  */
/*  23            INC HL  */
/*  24            INC H  */
/*  25            DEC H  */
/*  26            LD H,n  */
/*  27            DAA  */
/*  28            JR Z,e  */
/*  29            ADD HL,HL  */
/*  2A            LD HL,(nn)  */
/*  2B            DEC HL  */
/*  2C            INC L  */
/*  2D            DEC L  */
/*  2E            LD L,n  */
/*  2F            CPL  */
  test(0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,       0x2f,0x00,0x00,0x00,
       0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0001,0x0000,0x00,0x00,0x00,0x00);
  test(0xffff,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,       0x2f,0x00,0x00,0x00,
       0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0001,0x0000,0x00,0x00,0x00,0x00);
/*  30            JR NC,e  */
/*  31            LD SP,nn  */
/*  32            LD (nn),A  */
/*  33            INC SP  */
/*  34            INC (HL)  */
/*  35            DEC (HL)  */
/*  36            LD (HL),n  */
/*  37            SCF  */
/*  38            JR C,e  */
/*  39            ADD HL,SP  */
/*  3A            LD A,(nn)  */
/*  3B            DEC SP  */
/*  3C            INC A  */
/*  3D            DEC A  */
/*  3E            LD A,n  */
/*  3F            CCF  */
/*  40            LD B,B  */
/*  41            LD B,C  */
/*  42            LD B,D  */
/*  43            LD B,E  */
/*  44            LD B,H  */
/*  45            LD B,L  */
/*  46            LD B,(HL)  */
/*  47            LD B,A  */
/*  48            LD C,B  */
/*  49            LD C,C  */
/*  4A            LD C,D  */
/*  4B            LD C,E  */
/*  4C            LD C,H  */
/*  4D            LD C,L  */
/*  4E            LD C,(HL)  */
/*  4F            LD C,A  */
/*  50            LD D,B  */
/*  51            LD D,C  */
/*  52            LD D,D  */
/*  53            LD D,E  */
/*  54            LD D,H  */
/*  55            LD D,L  */
/*  56            LD D,(HL)  */
/*  57            LD D,A  */
/*  58            LD E,B  */
/*  59            LD E,C  */
/*  5A            LD E,D  */
/*  5B            LD E,E  */
/*  5C            LD E,H  */
/*  5D            LD E,L  */
/*  5E            LD E,(HL)  */
/*  5F            LD E,A  */
/*  60            LD H,B  */
/*  61            LD H,C  */
/*  62            LD H,D  */
/*  63            LD H,E  */
/*  64            LD H,H  */
/*  65            LD H,L  */
/*  66            LD H,(HL)  */
/*  67            LD H,A  */
/*  68            LD L,B  */
/*  69            LD L,C  */
/*  6A            LD L,D  */
/*  6B            LD L,E  */
/*  6C            LD L,H  */
/*  6D            LD L,L  */
/*  6E            LD L,(HL)  */
/*  6F            LD L,A  */
/*  70            LD (HL),B  */
/*  71            LD (HL),C  */
/*  72            LD (HL),D  */
/*  73            LD (HL),E  */
/*  74            LD (HL),H  */
/*  75            LD (HL),L  */
/*  76            HALT  */
/*  77            LD (HL),A  */
/*  78            LD A,B  */
/*  79            LD A,C  */
/*  7A            LD A,D  */
/*  7B            LD A,E  */
/*  7C            LD A,H  */
/*  7D            LD A,L  */
/*  7E            LD A,(HL)  */
/*  7F            LD A,A  */
/*  80            ADD A,B  */
/*  81            ADD A,C  */
/*  82            ADD A,D  */
/*  83            ADD A,E  */
/*  84            ADD A,H  */
/*  85            ADD A,L  */
/*  86            ADD A,(HL)  */
/*  87            ADD A,A  */
/*  88            ADC A,B  */
/*  89            ADC A,C  */
/*  8A            ADC A,D  */
/*  8B            ADC A,E  */
/*  8C            ADC A,H  */
/*  8D            ADC A,L  */
/*  8E            ADC A,(HL)  */
/*  8F            ADC A,A  */
/*  90            SUB B  */
/*  91            SUB C  */
/*  92            SUB D  */
/*  93            SUB E  */
/*  94            SUB H  */
/*  95            SUB L  */
/*  96            SUB (HL)  */
/*  97            SUB A  */
/*  98            SBC B  */
/*  99            SBC C  */
/*  9A            SBC D  */
/*  9B            SBC E  */
/*  9C            SBC H  */
/*  9D            SBC L  */
/*  9E            SBC (HL)  */
/*  9F            SBC A  */
/*  A0            AND B  */
/*  A1            AND C  */
/*  A2            AND D  */
/*  A3            AND E  */
/*  A4            AND H  */
/*  A5            AND L  */
/*  A6            AND (HL)  */
/*  A7            AND A  */
/*  A8            XOR B  */
/*  A9            XOR C  */
/*  AA            XOR D  */
/*  AB            XOR E  */
/*  AC            XOR H  */
/*  AD            XOR L  */
/*  AE            XOR (HL)  */
/*  AF            XOR A  */
/*  B0            OR B  */
/*  B1            OR C  */
/*  B2            OR D  */
/*  B3            OR E  */
/*  B4            OR H  */
/*  B5            OR L  */
/*  B6            OR (HL)  */
/*  B7            OR A  */
/*  B8            CP B  */
/*  B9            CP C  */
/*  BA            CP D  */
/*  BB            CP E  */
/*  BC            CP H  */
/*  BD            CP L  */
/*  BE            CP (HL)  */
/*  BF            CP A  */
/*  C0            RET NZ  */
/*  C1            POP BC  */
/*  C2            JP NZ,nn  */
/*  C3            JP nn  */
/*  C4            CALL NZ,nn  */
/*  C5            PUSH BC  */
/*  C6            ADD A,n  */
/*  C7            RST 00H  */
/*  C8            RET Z  */
/*  C9            RET  */
/*  CA            JP Z,nn  */
/*  CC            CALL Z,nn  */
/*  CD            CALL nn  */
/*  CE            ADC A,n  */
/*  CF            RST 08H  */
/*  D0            RET NC  */
/*  D1            POP DE  */
/*  D2            JP NC,nn  */
/*  D3            OUT (n),A  */
/*  D4            CALL NC,nn  */
/*  D5            PUSH DE  */
/*  D6            SUB n  */
/*  D7            RST 10H  */
/*  D8            RET C  */
/*  D9            EXX  */
/*  DA            JP C,nn  */
/*  DB            IN A,(n)  */
/*  DC            CALL C,nn  */
/*  DE            SBC A,n  */
/*  DF            RST 18H  */
/*  E0            RET PE  */
/*  E1            POP HL  */
/*  E2            JP PE,nn  */
/*  E3            EX (SP),HL  */
/*  E4            CALL PE,nn  */
/*  E5            PUSH HL  */
/*  E6            AND n  */
/*  E7            RST 20H  */
/*  E8            RET PO  */
/*  E9            JP (HL)  */
/*  EA            JP PO,nn  */
/*  EB            EX DE,HL  */
/*  EC            CALL PO,nn  */
/*  EE            XOR n  */
/*  EF            RST 28H  */
/*  F0            RET P  */
/*  F1            POP AF  */
/*  F2            JP P,nn  */
/*  F3            DI  */
/*  F4            CALL P,nn  */
/*  F5            PUSH AF  */
/*  F6            OR a  */
/*  F7            RST 30H  */
/*  F8            RET M  */
/*  F9            LD SP,HL  */
/*  FA            JP M,nn  */
/*  FB            EI  */
/*  FC            CALL M,nn  */
/*  FE            CP n  */
/*  FF            RST 38H  */
/*    */
/*  CB 00         RLC B  */
/*  CB 01         RLC C  */
/*  CB 02         RLC D  */
/*  CB 03         RLC E  */
/*  CB 04         RLC H  */
/*  CB 05         RLC L  */
/*  CB 06         RLC (HL)  */
/*  CB 07         RLC A  */
/*  CB 08         RRC B  */
/*  CB 09         RRC C  */
/*  CB 0A         RRC D  */
/*  CB 0B         RRC E  */
/*  CB 0C         RRC H  */
/*  CB 0D         RRC L  */
/*  CB 0E         RRC (HL)  */
/*  CB 0F         RRC A  */
/*  CB 10         RL B  */
/*  CB 11         RL C  */
/*  CB 12         RL D  */
/*  CB 13         RL E  */
/*  CB 14         RL H  */
/*  CB 15         RL L  */
/*  CB 16         RL (HL)  */
/*  CB 17         RL A  */
/*  CB 18         RR B  */
/*  CB 19         RR C  */
/*  CB 1A         RR D  */
/*  CB 1B         RR E  */
/*  CB 1C         RR H  */
/*  CB 1D         RR L  */
/*  CB 1E         RR (HL)  */
/*  CB 1F         RR A  */
/*  CB 20         SLA B  */
/*  CB 21         SLA C  */
/*  CB 22         SLA D  */
/*  CB 23         SLA E  */
/*  CB 24         SLA H  */
/*  CB 25         SLA L  */
/*  CB 26         SLA (HL)  */
/*  CB 27         SLA A  */
/*  CB 28         SRA B  */
/*  CB 29         SRA C  */
/*  CB 2A         SRA D  */
/*  CB 2B         SRA E  */
/*  CB 2C         SRA H  */
/*  CB 2D         SRA L  */
/*  CB 2E         SRA (HL)  */
/*  CB 2F         SRA A  */
/*  CB 38         SRL B  */
/*  CB 39         SRL C  */
/*  CB 3A         SRL D  */
/*  CB 3B         SRL E  */
/*  CB 3C         SRL H  */
/*  CB 3D         SRL L  */
/*  CB 3E         SRL (HL)  */
/*  CB 3F         SRL A  */
/*  CB 40         BIT 0,B  */
/*  CB 41         BIT 0,C  */
/*  CB 42         BIT 0,D  */
/*  CB 43         BIT 0,E  */
/*  CB 44         BIT 0,H  */
/*  CB 45         BIT 0,L  */
/*  CB 46         BIT 0,(HL)  */
/*  CB 47         BIT 0,A  */
/*  CB 48         BIT 1,B  */
/*  CB 49         BIT 1,C  */
/*  CB 4A         BIT 1,D  */
/*  CB 4B         BIT 1,E  */
/*  CB 4C         BIT 1,H  */
/*  CB 4D         BIT 1,L  */
/*  CB 4E         BIT 1,(HL)  */
/*  CB 4F         BIT 1,A  */
/*  CB 50         BIT 2,B  */
/*  CB 51         BIT 2,C  */
/*  CB 52         BIT 2,D  */
/*  CB 53         BIT 2,E  */
/*  CB 54         BIT 2,H  */
/*  CB 55         BIT 2,L  */
/*  CB 56         BIT 2,(HL)  */
/*  CB 57         BIT 2,A  */
/*  CB 58         BIT 3,B  */
/*  CB 59         BIT 3,C  */
/*  CB 5A         BIT 3,D  */
/*  CB 5B         BIT 3,E  */
/*  CB 5C         BIT 3,H  */
/*  CB 5D         BIT 3,L  */
/*  CB 5E         BIT 3,(HL)  */
/*  CB 5F         BIT 3,A  */
/*  CB 60         BIT 4,B  */
/*  CB 61         BIT 4,C  */
/*  CB 62         BIT 4,D  */
/*  CB 63         BIT 4,E  */
/*  CB 64         BIT 4,H  */
/*  CB 65         BIT 4,L  */
/*  CB 66         BIT 4,(HL)  */
/*  CB 67         BIT 4,A  */
/*  CB 68         BIT 5,B  */
/*  CB 69         BIT 5,C  */
/*  CB 6A         BIT 5,D  */
/*  CB 6B         BIT 5,E  */
/*  CB 6C         BIT 5,H  */
/*  CB 6D         BIT 5,L  */
/*  CB 6E         BIT 5,(HL)  */
/*  CB 6F         BIT 5,A  */
/*  CB 70         BIT 6,B  */
/*  CB 71         BIT 6,C  */
/*  CB 72         BIT 6,D  */
/*  CB 73         BIT 6,E  */
/*  CB 74         BIT 6,H  */
/*  CB 75         BIT 6,L  */
/*  CB 76         BIT 6,(HL)  */
/*  CB 77         BIT 6,A  */
/*  CB 78         BIT 7,B  */
/*  CB 79         BIT 7,C  */
/*  CB 7A         BIT 7,D  */
/*  CB 7B         BIT 7,E  */
/*  CB 7C         BIT 7,H  */
/*  CB 7D         BIT 7,L  */
/*  CB 7E         BIT 7,(HL)  */
/*  CB 7F         BIT 7,A  */
/*  CB 80         RES 0,B  */
/*  CB 81         RES 0,C  */
/*  CB 82         RES 0,D  */
/*  CB 83         RES 0,E  */
/*  CB 84         RES 0,H  */
/*  CB 85         RES 0,L  */
/*  CB 86         RES 0,(HL)  */
/*  CB 87         RES 0,A  */
/*  CB 88         RES 1,B  */
/*  CB 89         RES 1,C  */
/*  CB 8A         RES 1,D  */
/*  CB 8B         RES 1,E  */
/*  CB 8C         RES 1,H  */
/*  CB 8D         RES 1,L  */
/*  CB 8E         RES 1,(HL)  */
/*  CB 8F         RES 1,A  */
/*  CB 90         RES 2,B  */
/*  CB 91         RES 2,C  */
/*  CB 92         RES 2,D  */
/*  CB 93         RES 2,E  */
/*  CB 94         RES 2,H  */
/*  CB 95         RES 2,L  */
/*  CB 96         RES 2,(HL)  */
/*  CB 97         RES 2,A  */
/*  CB 98         RES 3,B  */
/*  CB 99         RES 3,C  */
/*  CB 9A         RES 3,D  */
/*  CB 9B         RES 3,E  */
/*  CB 9C         RES 3,H  */
/*  CB 9D         RES 3,L  */
/*  CB 9E         RES 3,(HL)  */
/*  CB 9F         RES 3,A  */
/*  CB A0         RES 4,B  */
/*  CB A1         RES 4,C  */
/*  CB A2         RES 4,D  */
/*  CB A3         RES 4,E  */
/*  CB A4         RES 4,H  */
/*  CB A5         RES 4,L  */
/*  CB A6         RES 4,(HL)  */
/*  CB A7         RES 4,A  */
/*  CB A8         RES 5,B  */
/*  CB A9         RES 5,C  */
/*  CB AA         RES 5,D  */
/*  CB AB         RES 5,E  */
/*  CB AC         RES 5,H  */
/*  CB AD         RES 5,L  */
/*  CB AE         RES 5,(HL)  */
/*  CB AF         RES 5,A  */
/*  CB B0         RES 6,B  */
/*  CB B1         RES 6,C  */
/*  CB B2         RES 6,D  */
/*  CB B3         RES 6,E  */
/*  CB B4         RES 6,H  */
/*  CB B5         RES 6,L  */
/*  CB B6         RES 6,(HL)  */
/*  CB B7         RES 6,A  */
/*  CB B8         RES 7,B  */
/*  CB B9         RES 7,C  */
/*  CB BA         RES 7,D  */
/*  CB BB         RES 7,E  */
/*  CB BC         RES 7,H  */
/*  CB BD         RES 7,L  */
/*  CB BE         RES 7,(HL)  */
/*  CB BF         RES 7,A  */
/*  CB C0         SET 0,B  */
/*  CB C1         SET 0,C  */
/*  CB C2         SET 0,D  */
/*  CB C3         SET 0,E  */
/*  CB C4         SET 0,H  */
/*  CB C5         SET 0,L  */
/*  CB C6         SET 0,(HL)  */
/*  CB C7         SET 0,A  */
/*  CB C8         SET 1,B  */
/*  CB C9         SET 1,C  */
/*  CB CA         SET 1,D  */
/*  CB CB         SET 1,E  */
/*  CB CC         SET 1,H  */
/*  CB CD         SET 1,L  */
/*  CB CE         SET 1,(HL)  */
/*  CB CF         SET 1,A  */
/*  CB D0         SET 2,B  */
/*  CB D1         SET 2,C  */
/*  CB D2         SET 2,D  */
/*  CB D3         SET 2,E  */
/*  CB D4         SET 2,H  */
/*  CB D5         SET 2,L  */
/*  CB D6         SET 2,(HL)  */
/*  CB D7         SET 2,A  */
/*  CB D8         SET 3,B  */
/*  CB D9         SET 3,C  */
/*  CB DA         SET 3,D  */
/*  CB DB         SET 3,E  */
/*  CB DC         SET 3,H  */
/*  CB DD         SET 3,L  */
/*  CB DE         SET 3,(HL)  */
/*  CB DF         SET 3,A  */
/*  CB E0         SET 4,B  */
/*  CB E1         SET 4,C  */
/*  CB E2         SET 4,D  */
/*  CB E3         SET 4,E  */
/*  CB E4         SET 4,H  */
/*  CB E5         SET 4,L  */
/*  CB E6         SET 4,(HL)  */
/*  CB E7         SET 4,A  */
/*  CB E8         SET 5,B  */
/*  CB E9         SET 5,C  */
/*  CB EA         SET 5,D  */
/*  CB EB         SET 5,E  */
/*  CB EC         SET 5,H  */
/*  CB ED         SET 5,L  */
/*  CB EE         SET 5,(HL)  */
/*  CB EF         SET 5,A  */
/*  CB F0         SET 6,B  */
/*  CB F1         SET 6,C  */
/*  CB F2         SET 6,D  */
/*  CB F3         SET 6,E  */
/*  CB F4         SET 6,H  */
/*  CB F5         SET 6,L  */
/*  CB F6         SET 6,(HL)  */
/*  CB F7         SET 6,A  */
/*  CB F8         SET 7,B  */
/*  CB F9         SET 7,C  */
/*  CB FA         SET 7,D  */
/*  CB FB         SET 7,E  */
/*  CB FC         SET 7,H  */
/*  CB FD         SET 7,L  */
/*  CB FE         SET 7,(HL)  */
/*  CB FF         SET 7,A  */
/*    */
/*  DD 09         ADD IX,BC  */
/*  DD 19         ADD IX,DE  */
/*  DD 21         LD IX,nn  */
/*  DD 22         LD (nn),IX  */
/*  DD 23         INC IX  */
/*  DD 29         ADD IX,IX  */
/*  DD 2A         LD IX,(nn)  */
/*  DD 2B         DEC IX  */
/*  DD 34         INC (IX+d)  */
/*  DD 35         DEC (IX+d)  */
/*  DD 36         LD (IX+d),n  */
/*  DD 39         ADD IX,SP  */
/*  DD 46         LD B,(IX+d)  */
/*  DD 4E         LD C,(IX+d)  */
/*  DD 56         LD D,(IX+d)  */
/*  DD 5E         LD E,(IX+d)  */
/*  DD 66         LD H,(IX+d)  */
/*  DD 6E         LD L,(IX+d)  */
/*  DD 70         LD (IX+d),B  */
/*  DD 71         LD (IX+d),C  */
/*  DD 72         LD (IX+d),D  */
/*  DD 73         LD (IX+d),E  */
/*  DD 74         LD (IX+d),H  */
/*  DD 75         LD (IX+d),L  */
/*  DD 77         LD (IX+d),A  */
/*  DD 7E         LD A,(IX+d)  */
/*  DD 86         ADD A,(IX+d)  */
/*  DD 8E         ADC A,(IX+d)  */
/*  DD 96         SUB A,(IX+d)  */
/*  DD 9E         SBC A,(IX+d)  */
/*  DD A6         AND (IX+d)  */
/*  DD AE         XOR (IX+d)  */
/*  DD B6         OR (IX+d)  */
/*  DD BE         CP (IX+d)  */
/*  DD CB dd 06   RLC (IX+d)  */
/*  DD CB dd 0E   RRC (IX+d)  */
/*  DD CB dd 16   RL (IX+d)  */
/*  DD CB dd 1E   RR (IX+d)  */
/*  DD CB dd 26   SLA (IX+d)  */
/*  DD CB dd 2E   SRA (IX+d)  */
/*  DD CB dd 3E   SRL (IX+d)  */
/*  DD CB dd 46   BIT 0,(IX+d)  */
/*  DD CB dd 4E   BIT 1,(IX+d)  */
/*  DD CB dd 56   BIT 2,(IX+d)  */
/*  DD CB dd 5E   BIT 3,(IX+d)  */
/*  DD CB dd 66   BIT 4,(IX+d)  */
/*  DD CB dd 6E   BIT 5,(IX+d)  */
/*  DD CB dd 76   BIT 6,(IX+d)  */
/*  DD CB dd 7E   BIT 7,(IX+d)  */
/*  DD CB dd 86   RES 0,(IX+d)  */
/*  DD CB dd 8E   RES 1,(IX+d)  */
/*  DD CB dd 96   RES 2,(IX+d)  */
/*  DD CB dd 9E   RES 3,(IX+d)  */
/*  DD CB dd A6   RES 4,(IX+d)  */
/*  DD CB dd AE   RES 5,(IX+d)  */
/*  DD CB dd B6   RES 6,(IX+d)  */
/*  DD CB dd BE   RES 7,(IX+d)  */
/*  DD CB dd C6   SET 0,(IX+d)  */
/*  DD CB dd CE   SET 1,(IX+d)  */
/*  DD CB dd D6   SET 2,(IX+d)  */
/*  DD CB dd DE   SET 3,(IX+d)  */
/*  DD CB dd E6   SET 4,(IX+d)  */
/*  DD CB dd EE   SET 5,(IX+d)  */
/*  DD CB dd F6   SET 6,(IX+d)  */
/*  DD CB dd FE   SET 7,(IX+d)  */
/*  DD E1         POP IX  */
/*  DD E3         EX (SP),IX  */
/*  DD E5         PUSH IX  */
/*  DD E9         JP (IX)  */
/*  DD F9         LD SP,IX  */
/*    */
/*  ED 40         IN B,(C)  */
/*  ED 41         OUT (C),B  */
/*  ED 42         SBC HL,BC  */
/*  ED 43         LD (nn),BC  */
/*  ED 44         NEG  */
  test(0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,       0xed,0x44,0x00,0x00,
       0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0001,0x0000,0x00,0x00,0x00,0x00);
  test(0x0100,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,       0xed,0x44,0x00,0x00,
       0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0001,0x0000,0x00,0x00,0x00,0x00);
  test(0xffff,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,       0xed,0x44,0x00,0x00,
       0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0001,0x0000,0x00,0x00,0x00,0x00);
/*  ED 45         RETN  */
/*  ED 46         IM 0  */
/*  ED 47         LD I,A  */
/*  ED 48         IN C,(C)  */
/*  ED 49         OUT (C),C  */
/*  ED 4A         ADC HL,BC  */
/*  ED 4B         LD BC,(nn)  */
/*  ED 4D         RETI  */
/*  ED 4F         LD R,A  */
/*  ED 50         IN D,(C)  */
/*  ED 51         OUT (C),D  */
/*  ED 52         SBC HL,DE  */
/*  ED 53         LD (nn),DE  */
/*  ED 56         IM 1  */
/*  ED 57         LD A,I  */
/*  ED 58         IN E,(C)  */
/*  ED 59         OUT (C),E  */
/*  ED 5A         ADC HL,DE  */
/*  ED 5B         LD DE,(nn)  */
/*  ED 5F         LD A,R  */
/*  ED 60         IN H,(C)  */
/*  ED 61         OUT (C),H  */
/*  ED 62         SBC HL,HL  */
/*  ED 67         RRD  */
/*  ED 68         IN L,(C)  */
/*  ED 69         OUT (C),L  */
/*  ED 6A         ADC HL,HL  */
/*  ED 6F         RLD  */
/*  ED 72         SBC HL,SP  */
/*  ED 73         LD (nn),SP  */
/*  ED 78         IN A,(C)  */
/*  ED 79         OUT (C),A  */
/*  ED 7A         ADC HL,SP  */
/*  ED 7B         LD SP,(nn)  */
/*  ED A0         LDI  */
/*  ED A1         CPI  */
/*  ED A2         INI  */
/*  ED A3         OUTI  */
/*  ED A8         LDD  */
/*  ED A9         CPD  */
/*  ED AA         IND  */
/*  ED AB         OUTD  */
/*  ED B0         LDIR  */
/*  ED B1         CPIR  */
/*  ED B2         INIR  */
/*  ED B3         OTIR  */
/*  ED B8         LDDR  */
/*  ED B9         CPDR  */
/*  ED BA         INDR  */
/*  ED BB         OTDR  */
/*    */
/*  FD 09         ADD IY,BC  */
/*  FD 19         ADD IY,DE  */
/*  FD 21         LD IY,nn  */
/*  FD 22         LD (nn),IY  */
/*  FD 23         INC IY  */
/*  FD 29         ADD IY,IX  */
/*  FD 2A         LD IY,(nn)  */
/*  FD 2B         DEC IY  */
/*  FD 34         INC (IY+d)  */
/*  FD 35         DEC (IY+d)  */
/*  FD 36         LD (IY+d),n  */
/*  FD 39         ADD IY,SP  */
/*  FD 46         LD B,(IY+d)  */
/*  FD 4E         LD C,(IY+d)  */
/*  FD 56         LD D,(IY+d)  */
/*  FD 5E         LD E,(IY+d)  */
/*  FD 66         LD H,(IY+d)  */
/*  FD 6E         LD L,(IY+d)  */
/*  FD 70         LD (IY+d),B  */
/*  FD 71         LD (IY+d),C  */
/*  FD 72         LD (IY+d),D  */
/*  FD 73         LD (IY+d),E  */
/*  FD 74         LD (IY+d),H  */
/*  FD 75         LD (IY+d),L  */
/*  FD 77         LD (IY+d),A  */
/*  FD 7E         LD A,(IY+d)  */
/*  FD 86         ADD A,(IY+d)  */
/*  FD 8E         ADC A,(IY+d)  */
/*  FD 96         SUB A,(IY+d)  */
/*  FD 9E         SBC A,(IY+d)  */
/*  FD A6         AND (IY+d)  */
/*  FD AE         XOR (IY+d)  */
/*  FD B6         OR (IY+d)  */
/*  FD BE         CP (IY+d)  */
/*  FD CB dd 06   RLC (IY+d)  */
/*  FD CB dd 0E   RRC (IY+d)  */
/*  FD CB dd 16   RL (IY+d)  */
/*  FD CB dd 1E   RR (IY+d)  */
/*  FD CB dd 26   SLA (IY+d)  */
/*  FD CB dd 2E   SRA (IY+d)  */
/*  FD CB dd 3E   SRL (IY+d)  */
/*  FD CB dd 46   BIT 0,(IY+d)  */
/*  FD CB dd 4E   BIT 1,(IY+d)  */
/*  FD CB dd 56   BIT 2,(IY+d)  */
/*  FD CB dd 5E   BIT 3,(IY+d)  */
/*  FD CB dd 66   BIT 4,(IY+d)  */
/*  FD CB dd 6E   BIT 5,(IY+d)  */
/*  FD CB dd 76   BIT 6,(IY+d)  */
/*  FD CB dd 7E   BIT 7,(IY+d)  */
/*  FD CB dd 86   RES 0,(IY+d)  */
/*  FD CB dd 8E   RES 1,(IY+d)  */
/*  FD CB dd 96   RES 2,(IY+d)  */
/*  FD CB dd 9E   RES 3,(IY+d)  */
/*  FD CB dd A6   RES 4,(IY+d)  */
/*  FD CB dd AE   RES 5,(IY+d)  */
/*  FD CB dd B6   RES 6,(IY+d)  */
/*  FD CB dd BE   RES 7,(IY+d)  */
/*  FD CB dd C6   SET 0,(IY+d)  */
/*  FD CB dd CE   SET 1,(IY+d)  */
/*  FD CB dd D6   SET 2,(IY+d)  */
/*  FD CB dd DE   SET 3,(IY+d)  */
/*  FD CB dd E6   SET 4,(IY+d)  */
/*  FD CB dd EE   SET 5,(IY+d)  */
/*  FD CB dd F6   SET 6,(IY+d)  */
/*  FD CB dd FE   SET 7,(IY+d)  */
/*  FD E1         POP IY  */
/*  FD E3         EX (SP),IY  */
/*  FD E5         PUSH IY  */
/*  FD E9         JP (IY)  */
/*  FD F9         LD SP,IY  */
  }

main(int argc,char *argv[]) {
  int i;
  char buffer[100];
  prepareZ80();
  z80reset(&trs80);
  trs80.Memory=(byte *)calloc(65536,1);
  trs80.Store=TStore;
  trs80.Fetch=TFetch;
  trs80.Out=TOut;
  trs80.In=TIn;
  performtest();
  }
