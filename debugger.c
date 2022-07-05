#include <stdio.h>
#include <string.h>
#include "header.h"

char didDump;

char debugLines[16][80];

char* getHex(char *buffer, word *ret) {
  int  flag;
  word value;
  value=0;
  flag=0;
  while (flag==0) {
    switch (*buffer) {
      case '0':value=value*16+0; break;
      case '1':value=value*16+1; break;
      case '2':value=value*16+2; break;
      case '3':value=value*16+3; break;
      case '4':value=value*16+4; break;
      case '5':value=value*16+5; break;
      case '6':value=value*16+6; break;
      case '7':value=value*16+7; break;
      case '8':value=value*16+8; break;
      case '9':value=value*16+9; break;
      case 'a':value=value*16+10; break;
      case 'b':value=value*16+11; break;
      case 'c':value=value*16+12; break;
      case 'd':value=value*16+13; break;
      case 'e':value=value*16+14; break;
      case 'f':value=value*16+15; break;
      case 'A':value=value*16+10; break;
      case 'B':value=value*16+11; break;
      case 'C':value=value*16+12; break;
      case 'D':value=value*16+13; break;
      case 'E':value=value*16+14; break;
      case 'F':value=value*16+15; break;
      default:flag=1; break;
      }
    if (flag == 0) buffer++;
    }
  *ret = value;
  return buffer;
  }

void clearDBInfo() {
  int i;
  for (i=0;i<16;i++) {
    strcpy(debugLines[i],"");
    }
  }

void clearBreakpoint(word addr) {
  int i,j;
  for (i=0;i<bpCount;i++) {
    if (breakpoints[i]==addr) {
      for (j=i;j<bpCount-1;j++)
        breakpoints[j]=breakpoints[j+1];
      bpCount--;
      i--;
      }
    }
  }

void drawDebugScreen() {
  ClrScr();
  GotoXY(1,1);
  printf("+AF---+ +AF'--+ +-------------------------------------------------------------+\n");
  printf("|     | |     | |                                                             |\n");
  printf("+-----+ +-----+ |                                                             |\n");
  printf("+BC---+ +BC'--+ |                                                             |\n");
  printf("|     | |     | |                                                             |\n");
  printf("+-----+ +-----+ |                                                             |\n");
  printf("+DE---+ +DE'--+ |                                                             |\n");
  printf("|     | |     | |                                                             |\n");
  printf("+-----+ +-----+ |                                                             |\n");
  printf("+HL---+ +HL'--+ |                                                             |\n");
  printf("|     | |     | |                                                             |\n");
  printf("+-----+ +-----+ |                                                             |\n");
  printf("+IX---+ +IY---+ |                                                             |\n");
  printf("|     | |     | |                                                             |\n");
  printf("+-----+ +-----+ |                                                             |\n");
  printf("+PC---+ +SP---+ |                                                             |\n");
  printf("|     | |     | |                                                             |\n");
  printf("+-----+ +-----+ +-------------------------------------------------------------+\n");
  printf("+R----+ +I----+\n");
  printf("|     | |     |\n");
  printf("+-----+ +-----+\n");
  }

void debugOutput(char* line) {
  int i;
  for (i=0; i<15; i++) strcpy(debugLines[i], debugLines[i+1]);
  strcpy(debugLines[15], line);
  for (i=0; i<16; i++) {
    while (strlen(debugLines[i]) < 60) strcat(debugLines[i]," ");
    GotoXY(18,i+2); printf("%s",debugLines[i]);
    }
  }

void debugB(struct Z80CPU *z80, char* buffer) {
  char msg[256];
  char tmp[16];
  int count;
  int i,j;
  word bp;
  if (strcmp(buffer,"++") == 0) {
    enableBreakpoints = -1;
    debugOutput("Breakpoints enabled");
    return;
    }
  if (strcmp(buffer,"--") == 0) {
    enableBreakpoints = 0;
    debugOutput("Breakpoints disabled");
    return;
    }
  if (*buffer == '?') {
    debugOutput("Breakpoints:");
    count = 0;
    strcpy(msg,"  ");
    for (i=0;i<bpCount;i++) {
      sprintf(tmp,"%04x ",breakpoints[i]);
      strcat(msg,tmp);
      count++;
      if (count == 10) {
        debugOutput(msg);
        strcpy(msg,"  ");
        count = 0;
        }
      }
    if (count != 0) debugOutput(msg);
    }
  else if (*buffer == 'c' || *buffer == 'C') {
    bpCount = 0;
    debugOutput("All breakpoints cleared");
    }
  else if (*buffer == '+') {
    buffer++;
    getHex(buffer, &bp);
    for (i=0; i<bpCount; i++)
      if (breakpoints[i] == bp) return;
    breakpoints[bpCount++] = bp;
    sprintf(msg,"Set breakpoint at %04x",bp);
    debugOutput(msg);
    }
  else if (*buffer == '-') {
    buffer++;
    getHex(buffer, &bp);
    for (i=0; i<bpCount; i++)
      if (breakpoints[i] == bp) {
        for (j=i; j<bpCount-1; j++)
          breakpoints[j] = breakpoints[j+1];
        bpCount--;
        sprintf(msg, "Breakpoint at %04x removed", bp);
        debugOutput(msg);
        return;
        }
    sprintf(msg,"No breakpoint at %04x",bp);
    debugOutput(msg);
    }
  }

void debugT(struct Z80CPU *z80, char* buffer) {
  int i,j;
  byte b[4];
  int count;
  word v;
  char msg[128];
  char tmp[64];
  char da[64];
  char func;
  int flag;
  if (strcmp(buffer,"++") == 0) {
    enableTraps = -1;
    debugOutput("Traps enabled");
    return;
    }
  if (strcmp(buffer,"--") == 0) {
    enableTraps = 0;
    debugOutput("Traps disabled");
    return;
    }
  if (*buffer == '?') {
    debugOutput("Traps:");
    for (i=0; i<trapCount; i++) {
      strcpy(msg," ");
      for (j=0; j<traps[i][0]; j++) {
        sprintf(tmp," %02x",traps[i][j+1]);
        strcat(msg,tmp);
        }
      disassem(traps[i][1],traps[i][2],traps[i][3],traps[i][4],da);
      while (strlen(msg) < 15) strcat(msg," ");
      strcat(msg,da);
      debugOutput(msg);
      }
    return;
    }
  if (*buffer == 'c' || *buffer == 'C') {
    trapCount = 0;
    debugOutput("All traps cleared");
    return;
    }
  func = *buffer++;
  while (*buffer == ' ') buffer++;
  count = 0;
  while (count <4 && *buffer != 0) {
    buffer = getHex(buffer, &v);
    b[count++] = v & 0xff;
    while (*buffer == ' ') buffer++;
    }
  if (func == '+' && count > 0) {
    traps[trapCount][0] = count;
    for (i=0; i<count; i++) traps[trapCount][1+i] = b[i];
    trapCount++;
    }
  else if (func == '-' && count > 0) {
    for (i=0; i<trapCount; i++) {
      if (count == traps[i][0]) {
        flag = -1;
        for (j=0; j<count; j++) if (traps[i][j+1] != b[j]) flag = 0;
        if (flag != 0) {
          for (j=i; j<trapCount-1; j++) {
            traps[j][0] = traps[j+1][0];
            traps[j][1] = traps[j+1][1];
            traps[j][2] = traps[j+1][2];
            traps[j][3] = traps[j+1][3];
            traps[j][4] = traps[j+1][4];
            }
          trapCount--;
          return;
          }
        }
      }
    }
  }


void debugDL(struct Z80CPU *z80, char* buffer) {
  int i,j;
  byte a,b,c,d;
  char tmp[256];
  char da[64];
  if (strcasecmp(buffer,"pc") == 0) debugAddress = z80->PC;
  else if (strcasecmp(buffer,"sp") == 0) debugAddress = z80->SP;
  else if (strcasecmp(buffer,"ix") == 0) debugAddress = z80->IX;
  else if (strcasecmp(buffer,"iy") == 0) debugAddress = z80->IY;
  else if (strcasecmp(buffer,"bc") == 0) debugAddress = z80->BC.BC;
  else if (strcasecmp(buffer,"de") == 0) debugAddress = z80->DE.DE;
  else if (strcasecmp(buffer,"hl") == 0) debugAddress = z80->HL.HL;
  else if (*buffer != 0) {
    getHex(buffer, &debugAddress);
    }
  for (i=0; i<16; i++) {
    sprintf(tmp,"%04x: ",debugAddress);
    a=TFetch(z80,debugAddress);
    b=TFetch(z80,debugAddress+1);
    c=TFetch(z80,debugAddress+2);
    d=TFetch(z80,debugAddress+3);
    debugAddress += disassem(a,b,c,d,da);
    strcat(tmp, da);
    debugOutput(tmp);
    }
  }

void debugEX(struct Z80CPU *z80, char* buffer) {
  int i,j;
  byte a,b,c,d;
  char tmp[256];
  char da[64];
  word address;
  word value;
  if (strcasecmp(buffer,"pc") == 0) { address = z80->PC; buffer += 2; }
  else if (strcasecmp(buffer,"sp") == 0) { address = z80->SP; buffer += 2; }
  else if (strcasecmp(buffer,"ix") == 0) { address = z80->IX; buffer += 2; }
  else if (strcasecmp(buffer,"iy") == 0) { address = z80->IY; buffer += 2; }
  else if (strcasecmp(buffer,"bc") == 0) { address = z80->BC.BC; buffer += 2; }
  else if (strcasecmp(buffer,"de") == 0) { address = z80->DE.DE; buffer += 2; }
  else if (strcasecmp(buffer,"hl") == 0) { address = z80->HL.HL; buffer += 2; }
  else if (*buffer != 0) {
    buffer = getHex(buffer, &address);
    }
  while (*buffer == ' ') buffer++;
  while (*buffer != 0) {
    buffer = getHex(buffer, &value);
    while (*buffer == ' ') buffer++;
    TStore(z80, address++, value & 0xff);
    }
  }

void debugQM(struct Z80CPU *z80, char* buffer) {
  int i,j;
  char tmp[256];
  char tmp2[8];
  if (strcasecmp(buffer,"pc") == 0) debugAddress = z80->PC;
  else if (strcasecmp(buffer,"sp") == 0) debugAddress = z80->SP;
  else if (strcasecmp(buffer,"ix") == 0) debugAddress = z80->IX;
  else if (strcasecmp(buffer,"iy") == 0) debugAddress = z80->IY;
  else if (strcasecmp(buffer,"bc") == 0) debugAddress = z80->BC.BC;
  else if (strcasecmp(buffer,"de") == 0) debugAddress = z80->DE.DE;
  else if (strcasecmp(buffer,"hl") == 0) debugAddress = z80->HL.HL;
  else if (*buffer != 0) {
    getHex(buffer, &debugAddress);
    }
  for (i=0; i<16; i++) {
    sprintf(tmp,"%04x: ",debugAddress);
    for (j=0; j<16; j++) {
      sprintf(tmp2," %02x",TFetch(z80,debugAddress+j));
      strcat(tmp, tmp2);
      }
    debugAddress += 16;
    debugOutput(tmp);
    }
  }

void updateDebugScreen(struct Z80CPU *z80) {
  int i;
  char da[80];
  char buffer[256];
  byte a,b,c,d;
  GotoXY(2,2); printf("%02x",z80->AF.AFu.A);
  GotoXY(5,2); printf("%02x",z80->AF.AFu.F);
  GotoXY(3,5); printf("%04x",z80->BC.BC);
  GotoXY(3,8); printf("%04x",z80->DE.DE);
  GotoXY(3,11); printf("%04x",z80->HL.HL);
  GotoXY(10,2); printf("%02x",((z80->AFa) >> 4 & 0xff));
  GotoXY(13,2); printf("%02x",(z80->AFa & 0xff));
  GotoXY(11,5); printf("%04x",z80->BCa);
  GotoXY(11,8); printf("%04x",z80->DEa);
  GotoXY(11,11); printf("%04x",z80->HLa);
  GotoXY(3,14); printf("%04x",z80->IX);
  GotoXY(11,14); printf("%04x",z80->IY);
  GotoXY(3,17); printf("%04x",z80->PC);
  GotoXY(11,17); printf("%04x",z80->SP);
  GotoXY(4,20); printf("%02x",z80->R);
  GotoXY(12,20); printf("%02x",z80->I);
  for (i=0; i<16; i++) {
    while (strlen(debugLines[i]) < 60) strcat(debugLines[i]," ");
    GotoXY(18,i+2); printf("%s",debugLines[i]);
    }
  GotoXY(1,22);
  if ((z80->AF.AFu.F & SIGN_FLAG)==SIGN_FLAG) printf("S "); else printf("- ");
  if ((z80->AF.AFu.F & ZERO_FLAG)==ZERO_FLAG) printf("Z "); else printf("- ");
  if ((z80->AF.AFu.F & HALF_CARRY_FLAG)==HALF_CARRY_FLAG) printf("H "); else printf("- ");
  if ((z80->AF.AFu.F & OVERFLOW_FLAG)==OVERFLOW_FLAG) printf("P/V "); else printf("--- ");
  if ((z80->AF.AFu.F & ADD_SUB_FLAG)==ADD_SUB_FLAG) printf("N "); else printf("- ");
  if ((z80->AF.AFu.F & CARRY_FLAG)==CARRY_FLAG) printf("C "); else printf("- ");
  a=TFetch(z80,z80->PC);
  b=TFetch(z80,z80->PC+1);
  c=TFetch(z80,z80->PC+2);
  d=TFetch(z80,z80->PC+3);
  disassem(a,b,c,d,da);
  sprintf(buffer,"%04x: %s",z80->PC,da);
  GotoXY(18,21); printf("%s",buffer);
  GotoXY(18,22);
  }

void debugger(struct Z80CPU *cpu) {
    word i,j,addr;
    byte b[4];
    char buffer[1024];
    char buffer2[100];
    char *bptr;
    byte i1,i2,i3,i4;
    char da[80];
    byte flag;
    word value;
    if (debugMode == 3) debugMode = 1;
    if (debugMode==2) {
      if (trapCount > 0 && enableTraps != 0) {
        b[0]=TFetch(cpu,cpu->PC);
        b[1]=TFetch(cpu,cpu->PC+1);
        b[2]=TFetch(cpu,cpu->PC+2);
        b[3]=TFetch(cpu,cpu->PC+3);
        for (i=0; i<trapCount; i++) {
          flag = 1;
          for (j=0; j<traps[i][0]; j++)
            if (traps[i][j+1] != b[j]) flag = 0;
          if (flag != 0) {
            debugOutput("Break at trap");
            debugMode = 1;
            }
          }
     
        }
      if (enableBreakpoints != 0) {
        for (i=0;i<bpCount;i++)
          if (cpu->PC == breakpoints[i]) {
            sprintf(buffer,"Break at %04x",breakpoints[i]);
            debugOutput(buffer);
            debugMode=1;
            }
        }
      }
    if (debugMode==1) {
      didDump=' ';
      drawDebugScreen();
      updateDebugScreen(cpu);
      printf(">");
      while (debugMode == 1) {
        GotoXY(18,22);
        printf(">                                                                          ");
        GotoXY(18,22);
        printf(">");
        fgets(buffer, 1023, stdin);
        while (buffer[0] != 0 && buffer[strlen(buffer)-1] <' ')
          buffer[strlen(buffer)-1] = 0;
        if (strlen(buffer) == 0) {
          if (traceMode != 0) {
            i1=TFetch(cpu,cpu->PC);
            i2=TFetch(cpu,cpu->PC+1);
            i3=TFetch(cpu,cpu->PC+2);
            i4=TFetch(cpu,cpu->PC+3);
            disassem(i1,i2,i3,i4,da);
            sprintf(buffer2,"%04x: %s",cpu->PC, da);
            debugOutput(buffer2);
            }
          debugMode = 3;
          }
        else if (strncasecmp(buffer,"pc=",3) == 0) {
          getHex(buffer+3, &cpu->PC);
          updateDebugScreen(cpu);
          }
        else if (strncasecmp(buffer,"sp=",3) == 0) {
          getHex(buffer+3, &cpu->SP);
          updateDebugScreen(cpu);
          }
        else if (strncasecmp(buffer,"bc=",3) == 0) {
          getHex(buffer+3, &cpu->BC.BC);
          updateDebugScreen(cpu);
          }
        else if (strncasecmp(buffer,"de=",3) == 0) {
          getHex(buffer+3, &cpu->DE.DE);
          updateDebugScreen(cpu);
          }
        else if (strncasecmp(buffer,"hl=",3) == 0) {
          getHex(buffer+3, &cpu->HL.HL);
          updateDebugScreen(cpu);
          }
        else if (strncasecmp(buffer,"ix=",3) == 0) {
          getHex(buffer+3, &cpu->IX);
          updateDebugScreen(cpu);
          }
        else if (strncasecmp(buffer,"iy=",3) == 0) {
          getHex(buffer+3, &cpu->IY);
          updateDebugScreen(cpu);
          }
        else if (strncasecmp(buffer,"a=",2) == 0) {
          getHex(buffer+2, &value);
          cpu->AF.AFu.A = value & 0xff;
          updateDebugScreen(cpu);
          }
        else if (strncasecmp(buffer,"b=",2) == 0) {
          getHex(buffer+2, &value);
          cpu->BC.BCu.B = value & 0xff;
          updateDebugScreen(cpu);
          }
        else if (strncasecmp(buffer,"c=",2) == 0) {
          getHex(buffer+2, &value);
          cpu->BC.BCu.C = value & 0xff;
          updateDebugScreen(cpu);
          }
        else if (strncasecmp(buffer,"d=",2) == 0) {
          getHex(buffer+2, &value);
          cpu->DE.DEu.D = value & 0xff;
          updateDebugScreen(cpu);
          }
        else if (strncasecmp(buffer,"e=",2) == 0) {
          getHex(buffer+2, &value);
          cpu->DE.DEu.E = value & 0xff;
          updateDebugScreen(cpu);
          }
        else if (strncasecmp(buffer,"h=",2) == 0) {
          getHex(buffer+2, &value);
          cpu->HL.HLu.H = value & 0xff;
          updateDebugScreen(cpu);
          }
        else if (strncasecmp(buffer,"l=",2) == 0) {
          getHex(buffer+2, &value);
          cpu->HL.HLu.L = value & 0xff;
          updateDebugScreen(cpu);
          }
        else if (strncasecmp(buffer,"i=",2) == 0) {
          getHex(buffer+2, &value);
          cpu->I = value & 0xff;
          updateDebugScreen(cpu);
          }
        else if (strncasecmp(buffer,"im=",3) == 0) {
          getHex(buffer+3, &value);
          value = value & 0xff;
          if (value >= 0 && value <= 2) cpu->IM = value & 0xff;
          updateDebugScreen(cpu);
          }
        else if (buffer[0] == '?') debugQM(cpu,buffer+1);
        else if (buffer[0] == '$') debugDL(cpu,buffer+1);
        else if (buffer[0] == '!') debugEX(cpu,buffer+1);
        else if (buffer[0] == '@') debugMode = 2;
        else if (buffer[0] == 'b' || buffer[0] == 'B') debugB(cpu,buffer+1);
        else if (buffer[0] == '/') { debugMode = 0; simExit = 0xff; }
        else if (strncasecmp(buffer,"tr+",3) == 0) traceMode = 1;
        else if (strncasecmp(buffer,"tr-",3) == 0) traceMode = 0;
        else if (buffer[0] == 't' || buffer[0] == 'T') debugT(cpu,buffer+1);
        else if (buffer[0] == 'r' || buffer[0] == 'R') {
          z80_reset(cpu);
          updateDebugScreen(cpu);
          }
        else if (buffer[0] == 'i' || buffer[0] == 'I') {
          getHex(buffer+2, &value);
          z80_irq(cpu, value & 0xff);
          updateDebugScreen(cpu);
          }
        else if (buffer[0] == 'n' || buffer[0] == 'N') {
          z80_nmi(cpu);
          updateDebugScreen(cpu);
          }
        }
      }
  }
