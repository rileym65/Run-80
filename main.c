#include <stdio.h>
#include <stdlib.h>
#include "mterm.h"
#define global

#include "header.h"

void TStore(struct Z80CPU *z80,word Address,byte Value) {
  z80->Memory[Address]=Value;
  }

byte TFetch(struct Z80CPU *z80,word Address) {
  return z80->Memory[Address];
  }

void TOut(struct Z80CPU *z80,word Address,byte Value) {
  }

byte TIn(struct Z80CPU *z80,word Address) {
  return 0xff;
  }

short Offset(byte value) {
  short retval;
  signed char byt;
  byt=value;
  if (byt>=0) retval=byt;
    else retval=0-abs(byt);
  return retval;
  }


FILE *errfile;

void errlog(char *buffer) {
  errfile=fopen("trs.log","a");
  fprintf(errfile,"%s",buffer);
  fclose(errfile);
  }

word loadcmd(struct Z80CPU *z80,char *filename) {
  int i;
  word count;
  char endfile;
  byte header[4];
  word addr,start;
  FILE *infile;
  infile=fopen(filename,"rb");
  endfile=' ';
  start=0;
  while (endfile==' ') {
    if ((fread(header,1,4,infile))!=0) {
      addr=header[2]+header[3]*256;
      if (header[0]==2) { start=addr; endfile='*'; }
      if (header[0]==1) {                 /* block to load */
        addr=header[2]+header[3]*256;
        header[1]-=2;
        if (header[1]==0) count=256; else count=header[1];
        for (i=0;i<count;i++) {
          fread(header,1,1,infile);
          z80->Memory[addr++]=header[0];
          }
        }
      } else endfile='*';
    }
  fclose(infile);
  return start;
  }

int loader(struct Z80CPU *cpu, char* filename) {
  FILE* infile;
  char  buffer[1024];
  word  address;
  byte  value;
  byte  valid;
  char  mode;
  int   pos;
  infile = fopen(filename,"r");
  if (infile == NULL) {
    printf("Could not open input file: %s\n",filename);
    exit(1);
    }
  address = 0;
  value = 0;
  valid = 0;
  mode = 'B';
  while (fgets(buffer, 1023, infile) != NULL) {
    pos = 0;
    while (buffer[pos] != 0) {
      if (buffer[pos] == '@') {
        if (valid)
          cpu->Memory[address++] = value;
        valid = 0;
        mode = 'E';
        cpu->PC = 0;
        }
      else if (buffer[pos] == ':') {
        if (valid)
          cpu->Memory[address++] = value;
        valid = 0;
        mode = 'A';
        address = 0;
        }
      else if (buffer[pos] == ' ') {
        if (valid)
          if (mode == 'B') cpu->Memory[address++] = value;
        valid = 0;
        mode = 'B';
        value = 0;
        }
      else if (buffer[pos] >= '0' && buffer[pos] <= '9') {
        if (mode == 'A')
          address = (address << 4) | (buffer[pos] - '0');
        else if (mode == 'E')
          cpu->PC = (cpu->PC << 4) | (buffer[pos] - '0');
        else
          value = (value << 4) | (buffer[pos] - '0');
        valid = 0xff;
        }
      else if (buffer[pos] >= 'a' && buffer[pos] <= 'f') {
        if (mode == 'A')
          address = (address << 4) | (10 + buffer[pos] - 'a');
        else if (mode == 'E')
          cpu->PC = (cpu->PC << 4) | (10 + buffer[pos] - 'a');
        else
          value = (value << 4) | (10 + buffer[pos] - 'a');
        valid = 0xff;
        }
      else if (buffer[pos] >= 'A' && buffer[pos] <= 'F') {
        if (mode == 'A')
          address = (address << 4) | (10 + buffer[pos] - 'A');
        else if (mode == 'E')
          cpu->PC = (cpu->PC << 4) | (10 + buffer[pos] - 'A');
        else
          value = (value << 4) | (10 + buffer[pos] - 'A');
        valid = 0xff;
        }
      pos++;
      }
    if (valid) cpu->Memory[address++] = value;
    }
  return 0;
  }

void reset(struct Z80CPU *z80) {
  z80_reset(z80);
  }

void resetNoDisk(struct Z80CPU *z80) {
  reset(z80);
  }

int main(int argc,char *argv[]) {
  int i;
  char buffer[100];
  struct Z80CPU cpu;
  z80_prepareZ80(&cpu);
  cpu.Memory=(byte *)malloc(65536);
  for (i=0; i<65536; i++) cpu.Memory[i] = 0;
  cpu.Store=TStore;
  cpu.Fetch=TFetch;
  cpu.Out=TOut;
  cpu.In=TIn;
  debugMode=1;
  traceMode=0;
  bpCount=0;
  allowInterrupts='Y';
  debugAddress = 0;
  trapCount = 0;
  enableBreakpoints = -1;
  enableTraps = -1;
  for (i=0;i<256;i++) ports[i]=255;
  for (i=1;i<argc;i++) {
  reset(&cpu);
    if (strcmp(argv[i],"-d")==0) debugMode=1;
    else loader(&cpu, argv[i]);
    }
  printf("Z80 Emulator v%.2f (%.2f)\n",RUN80_VERSION,Z80_VERSION);
  simExit=0;
  while (simExit==0) {
    if (debugMode!=0) debugger(&cpu);
    z80_cycle(&cpu);
    ++cpu.R;
    }
  }
