#define Z80_VERSION     1.4
#define LINK extern

#ifndef _BYTE
typedef unsigned char byte;
typedef unsigned short word;
#define _BYTE
#endif

#define SIGN_FLAG       128
#define ZERO_FLAG       64
#define FLAG5           32
#define HALF_CARRY_FLAG 16
#define FLAG3           8
#define OVERFLOW_FLAG   4
#define ADD_SUB_FLAG    2
#define CARRY_FLAG      1

#define SIGN_OFF        0x7f
#define ZERO_OFF        0xbf
#define HALF_CARRY_OFF  0xef
#define OVERFLOW_OFF    0xfb
#define ADD_SUB_OFF     0xfd
#define CARRY_OFF       0xfe

#ifdef GLOBALS
#define ZPREFIX
#else
#define ZPREFIX extern
#endif

struct Z80CPU {
#ifdef BIG_END
  union {
    struct {
      byte A;
      byte F;
      } AFu;
     word AF;
     } AF;
  union {
    struct {
      byte B;
      byte C;
      } BCu;
    word BC;
    } BC;
  union {
    struct {
      byte D;
      byte E;
      } DEu;
    word DE;
    } DE;
  union {
    struct {
      byte H;
      byte L;
      } HLu;
    word HL;
    } HL;
#else
  union {
    struct {
      byte F;
      byte A;
      } AFu;
     word AF;
     } AF;
  union {
    struct {
      byte C;
      byte B;
      } BCu;
    word BC;
    } BC;
  union {
    struct {
      byte E;
      byte D;
      } DEu;
    word DE;
    } DE;
  union {
    struct {
      byte L;
      byte H;
      } HLu;
    word HL;
    } HL;
#endif
  word AFa;
  word BCa;
  word DEa;
  word HLa;
  byte IE;
  byte IE2;
  byte Halt;
  byte Intrpt;
  byte I;
  byte R;
  byte IM;
  word IX;
  word IY;
  word PC;
  word SP;
  byte *Memory;
  void (*Store)(struct Z80CPU *z80,word Address,byte Value);
  byte (*Fetch)(struct Z80CPU *z80,word Address);
  void (*Out)(struct Z80CPU *z80,word Address,byte Value);
  byte (*In)(struct Z80CPU *z80,word Address);
  void (*I1Byte[257])(struct Z80CPU *z80);
  void (*IDD[257])(struct Z80CPU *z80);
  void (*IED[257])(struct Z80CPU *z80);
  void (*IFD[257])(struct Z80CPU *z80);
  long ts;
  };

char hist[5][256];

extern void   _z80_Adc_8(struct Z80CPU *z80,byte *Register,byte Value);
extern void   _z80_Adc_16(struct Z80CPU *z80,word *Register,word Value);
extern void   _z80_Add_8(struct Z80CPU *z80,byte *Register,byte Value);
extern void   _z80_Add_16(struct Z80CPU *z80,word *Register,word Value);
extern void   _z80_And_8(struct Z80CPU *z80,byte *Register,byte Value);
extern void   _z80_Cmp_8(struct Z80CPU *z80,byte *Register,byte Value);
extern void   _z80_Dec_8(struct Z80CPU *z80,byte *Register);
extern void   _z80_Dec_16(word *value);
extern void   _z80_Dec_Mem_8(struct Z80CPU *z80,word Address);
extern void   _z80_Exch_16(word *value1,word *value2);
extern byte   _z80_Fetch(struct Z80CPU *z80,word Address);
extern word   _z80_Fetch2(struct Z80CPU *z80,word Address);
extern byte   _z80_Get_PC(struct Z80CPU *z80);
extern word   _z80_Get_PC2(struct Z80CPU *z80);
extern void   _z80_Inc_16(word *value);
extern void   _z80_Inc_8(struct Z80CPU *z80,byte *Register);
extern void   _z80_Inc_Mem_8(struct Z80CPU *z80,word Address);
extern void   _z80_InFlags(struct Z80CPU *z80,byte value);
extern byte   _z80_InPort(struct Z80CPU *z80,byte Port);
extern void   _z80_Logic_Flags(struct Z80CPU *z80,byte Value);
extern void   _z80_Neg_8(struct Z80CPU *z80,byte *Register);
extern word   _z80_Offset(word address,byte ofs);
extern void   _z80_Or_8(struct Z80CPU *z80,byte *Register,byte Value);
extern void   _z80_OutPort(struct Z80CPU *z80,byte Port,byte Value);
extern word   _z80_Pop2(struct Z80CPU *z80);
extern void   _z80_Push2(struct Z80CPU *z80,word Value);
extern void   _z80_Store(struct Z80CPU *z80,word Address,byte Value);
extern void   _z80_Store2(struct Z80CPU *z80,word Address,word Value);
extern void   _z80_Sbc_8(struct Z80CPU *z80,byte *Register,byte Value);
extern void   _z80_Sbc_16(struct Z80CPU *z80,word *Register,word Value);
extern void   _z80_Sub_8(struct Z80CPU *z80,byte *Register,byte Value);
extern void   _z80_XOr_8(struct Z80CPU *z80,byte *Register,byte Value);
extern byte   _z80_Parity(byte Value);
extern void   _z80_prepare1Byte(struct Z80CPU *z80);
extern void   _z80_prepareDD(struct Z80CPU *z80);
extern void   _z80_prepareED(struct Z80CPU *z80);
extern void   _z80_prepareFD(struct Z80CPU *z80);
extern void   _z80_PCB(struct Z80CPU *z80);
extern void   _z80_PDD(struct Z80CPU *z80);
extern void   _z80_PED(struct Z80CPU *z80);
extern void   _z80_PFD(struct Z80CPU *z80);
extern byte _z80_rlc_byte(struct Z80CPU *z80,byte value);
extern byte _z80_rrc_byte(struct Z80CPU *z80,byte value);
extern byte _z80_rl_byte(struct Z80CPU *z80,byte value);
extern byte _z80_rr_byte(struct Z80CPU *z80,byte value);
extern byte _z80_sla_byte(struct Z80CPU *z80,byte value);
extern byte _z80_sra_byte(struct Z80CPU *z80,byte value);
extern byte _z80_srl_byte(struct Z80CPU *z80,byte value);
extern void _z80_bit_byte(struct Z80CPU *z80,byte op,byte value,byte bit);
extern byte _z80_sub_Flags(int a,int b,int result);

LINK void z80_nmi(struct Z80CPU *z80);
LINK void z80_irq(struct Z80CPU *z80, byte b1);
LINK void z80_cycle(struct Z80CPU *z80);
LINK void z80_reset(struct Z80CPU *z80);
LINK void z80_prepareZ80(struct Z80CPU *z80);
LINK void z80_printHist();

