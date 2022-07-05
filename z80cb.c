#include "z80.h"

void _z80_PCB(struct Z80CPU *z80) {
    byte Cmd;
    byte *Ptr;
    byte temp;
    word addr;
    byte mem;
    mem=0;
    z80->ts++;
    Cmd=_z80_Get_PC(z80);
#ifdef HIST
    hist[1][Cmd]='*';
#endif
    switch (Cmd&7) {
      case 0:Ptr=&(z80->BC.BCu.B); break;
      case 1:Ptr=&(z80->BC.BCu.C); break;
      case 2:Ptr=&(z80->DE.DEu.D); break;
      case 3:Ptr=&(z80->DE.DEu.E); break;
      case 4:Ptr=&(z80->HL.HLu.H); break;
      case 5:Ptr=&(z80->HL.HLu.L); break;
      case 6:Ptr=&temp; addr=z80->HL.HL; mem=1; temp=_z80_Fetch(z80,addr); z80->ts++;
             break;
      case 7:Ptr=&(z80->AF.AFu.A); break;
      }
    if (Cmd<=7) {                  /* RLC */
      *Ptr=_z80_rlc_byte(z80,*Ptr);
      if (mem==1) _z80_Store(z80,addr,temp);
      }
    else if (Cmd<=0x0f) {          /* RRC */
      *Ptr=_z80_rrc_byte(z80,*Ptr);
      if (mem==1) _z80_Store(z80,addr,temp);
      }
    else if (Cmd<=0x17) {          /* RL */
      *Ptr=_z80_rl_byte(z80,*Ptr);
      if (mem==1) _z80_Store(z80,addr,temp);
      }
    else if (Cmd<=0x1f) {          /* RR */
      *Ptr=_z80_rr_byte(z80,*Ptr);
      if (mem==1) _z80_Store(z80,addr,temp);
      }
    else if (Cmd<=0x27) {          /* SLA */
      *Ptr=_z80_sla_byte(z80,*Ptr);
      if (mem==1) _z80_Store(z80,addr,temp);
      }
    else if (Cmd<=0x2f) {          /* SRA */
      *Ptr=_z80_sra_byte(z80,*Ptr);
      if (mem==1) _z80_Store(z80,addr,temp);
      }
    else if (Cmd<=0x3f) {          /* SRL */
      *Ptr=_z80_srl_byte(z80,*Ptr);
      if (mem==1) _z80_Store(z80,addr,temp);
      }
    else if (Cmd<=0x7f) {          /* BIT */
      _z80_bit_byte(z80,Cmd,*Ptr,(Cmd>>3)&7);
      }
    else if (Cmd<=0xbf) {          /* RES */
      Cmd=(Cmd>>3)&7;
      Cmd=(1<<Cmd);
      *Ptr=*Ptr&(~Cmd);
      if (mem==1) _z80_Store(z80,addr,temp);
      }
    else {                         /* SET */
      Cmd=(Cmd>>3)&7;
      Cmd=(1<<Cmd);
      *Ptr=*Ptr|Cmd;
      if (mem==1) _z80_Store(z80,addr,temp);
      }
  }      
