#include "z80.h"

#include <stdio.h>
#include <string.h>

#ifndef _BYTE
typedef unsigned char byte;
typedef unsigned short word;
#define _BYTE
#endif

#ifdef LINK
#undef LINK
#endif

#ifdef global
#define LINK
#else
#define LINK extern
#endif

#define RUN80_VERSION     1.0

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

#define MAX_BREAKPOINTS   100
#define MAX_TRAPS         100

#define INDXON    8000
#define INDXOFF   500
#define HTIMER    10000

LINK int debugMode;
LINK int traceMode;
LINK word breakpoints[MAX_BREAKPOINTS];
LINK word bpCount;
LINK byte traps[MAX_TRAPS][5];
LINK word trapCount;
LINK byte intPort;
LINK long heartBeat;
LINK byte simExit;
LINK byte ports[256];
LINK word memac;
LINK char allowInterrupts;
LINK word debugAddress;
LINK byte noDisk;
LINK int  enableBreakpoints;
LINK int  enableTraps;

LINK char errbuffer[100];

extern void openterm();
extern void closeterm();
extern void echoon();
extern void echooff();
extern void unbuffered();
extern void buffered();
extern int inkey();
extern void keyboard(struct Z80CPU *z80,byte chr,int pressed);
extern short Offset(byte value);
extern void checkKey(struct Z80CPU *z80);
extern void prepareMemory(struct Z80CPU *z80);
extern void getFilename(char *mask,char *prompt,char *filename);
extern void mountDisk(byte drive,char *filename);
extern void ClrScr();
extern void Output(char* Buffer);
extern void Input(char* Buffer);
extern void updateScreen(struct Z80CPU *z80);
extern int  disassem(byte a,byte b,byte c,byte d,char *buffer);
extern void resetKeyboard(struct Z80CPU *z80);
extern byte TFetch(struct Z80CPU *z80,word Address);
extern void GotoXY(int x,int y);
extern void errlog(char *buffer);
extern void debugger(struct Z80CPU *trs80);
extern int  disPCB(byte a,byte b,byte c,byte d,char *buffer);
extern int  disPDD(byte a,byte b,byte c,byte d,char *buffer);
extern int  disPED(byte a,byte b,byte c,byte d,char *buffer);
extern int  disPFD(byte a,byte b,byte c,byte d,char *buffer);
extern void setProcedures(struct Z80CPU *z80);
extern void reverseZ80(struct Z80CPU *z80);
extern word loadcmd(struct Z80CPU *z80,char *filename);
extern void printerWrite(byte character);
extern byte printerRead();
extern void resetNoDisk(struct Z80CPU *z80);
extern void newDisk(struct Z80CPU *z80,byte drive);
extern void trsMenu(struct Z80CPU *z80);
extern void reset(struct Z80CPU *z80);
extern void fdcCmd(struct Z80CPU *z80,byte command);
extern void writeScreen(word Address,byte Value);

