#include "header.h"

int disPCB(byte a,byte b,byte c,byte d,char *buffer)
  {
  int  ret;
  byte Cy,Cy2;
  byte Cmd;
  byte *Ptr;
  char reg[10];
  ret = 2;
  Cmd=b;
  switch (Cmd&7) {
    case 0:strcpy(reg,"b"); break;
    case 1:strcpy(reg,"c"); break;
    case 2:strcpy(reg,"d"); break;
    case 3:strcpy(reg,"e"); break;
    case 4:strcpy(reg,"h"); break;
    case 5:strcpy(reg,"l"); break;
    case 6:strcpy(reg,"(hl)"); break;
    case 7:strcpy(reg,"a"); break;
    }
  if (Cmd<=7) {                  /* RLC */
    sprintf(buffer,"%02x %02x       rlc %s",a,b,reg);
    }
  else if (Cmd<=0x0f) {          /* RRC */
    sprintf(buffer,"%02x %02x       rrc %s",a,b,reg);
    }
  else if (Cmd<=0x17) {          /* RL */
    sprintf(buffer,"%02x %02x       rl %s",a,b,reg);
    }
  else if (Cmd<=0x1f) {          /* RR */
    sprintf(buffer,"%02x %02x       rr %s",a,b,reg);
    }
  else if (Cmd<=0x27) {          /* SLA */
    sprintf(buffer,"%02x %02x       sla %s",a,b,reg);
    }
  else if (Cmd<=0x2f) {          /* SRA */
    sprintf(buffer,"%02x %02x       sra %s",a,b,reg);
    }
  else if (Cmd<=0x3f) {          /* SRL */
    sprintf(buffer,"%02x %02x       srl %s",a,b,reg);
    }
  else if (Cmd<=0x7f) {          /* BIT */
    sprintf(buffer,"%02x %02x       bit %d,%s",a,b,(Cmd>>3)&7,reg);
    }
  else if (Cmd<=0xbf) {          /* RES */
    sprintf(buffer,"%02x %02x       res %d,%s",a,b,(Cmd>>3)&7,reg);
    }
  else {                         /* SET */
    sprintf(buffer,"%02x %02x       set %d,%s",a,b,(Cmd>>3)&7,reg);
    }
  return ret;
  }      
