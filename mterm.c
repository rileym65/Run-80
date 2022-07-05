#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <termios.h>
#include "mterm.h"

struct termios term,old;

unsigned char keyBuffer[10];
int keyCount;

void openterm() {
  if (tcgetattr(0,&term)!=0) printf("Error getting term data\n");
  old=term;
  keyCount=0;
  }

void closeterm() {
  if (tcsetattr(0,TCSANOW,&old)!=0) printf("Could not set term\n");
  }

void echoon() {
  term.c_lflag|=ECHO;
  if (tcsetattr(0,TCSANOW,&term)!=0) printf("Could not set term\n");
  }

void echooff() {
  term.c_lflag&=~ECHO;
  if (tcsetattr(0,TCSANOW,&term)!=0) printf("Could not set term\n");
  }

void unbuffered() {
  term.c_lflag&=~ICANON;
  term.c_cc[VMIN]=0;
  term.c_cc[VTIME]=0;
  if (tcsetattr(0,TCSANOW,&term)!=0) printf("Could not set term\n");
  }

void buffered() {
  term.c_lflag|=ICANON;
  if (tcsetattr(0,TCSANOW,&term)!=0) printf("Could not set term\n");
  }


int inkey() {
  unsigned char           c;
  fd_set         rfds;
  struct timeval tv;
  int            i;
  char           flag;
  if (keyCount>0 && keyBuffer[0]!=27) {
    c=keyBuffer[0];
    for (i=0;i<9;i++) keyBuffer[i]=keyBuffer[i+1];
    keyCount--;
    } else {
    flag=0;
    while (flag==0) {
      c=fgetc(stdin);
      if (c!=2551) {
        if (keyCount>0 && keyBuffer[0]==27) {
          keyBuffer[keyCount++]=c;
          if (c>63 && c!='[') {
            keyBuffer[keyCount]='\0';
            if (strcmp("[A",keyBuffer)==0) { c=MKEY_UP; flag=1; keyCount=0; }
            else if (strcmp("[B",keyBuffer)==0) { c=MKEY_DOWN; flag=1; keyCount=0; }
            else if (strcmp("[C",keyBuffer)==0) { c=MKEY_RIGHT; flag=1; keyCount=0; }
            else if (strcmp("[D",keyBuffer)==0) { c=MKEY_LEFT; flag=1; keyCount=0; }
            else if (strcmp("[11~",keyBuffer)==0) { c=MKEY_F1; flag=1; keyCount=0; }
            else if (strcmp("[12~",keyBuffer)==0) { c=MKEY_F2; flag=1; keyCount=0; }
            else if (strcmp("[13~",keyBuffer)==0) { c=MKEY_F3; flag=1; keyCount=0; }
            else if (strcmp("[14~",keyBuffer)==0) { c=MKEY_F4; flag=1; keyCount=0; }
            else if (strcmp("[15~",keyBuffer)==0) { c=MKEY_F5; flag=1; keyCount=0; }
            else if (strcmp("[17~",keyBuffer)==0) { c=MKEY_F6; flag=1; keyCount=0; }
            else if (strcmp("[18~",keyBuffer)==0) { c=MKEY_F7; flag=1; keyCount=0; }
            else if (strcmp("[19~",keyBuffer)==0) { c=MKEY_F8; flag=1; keyCount=0; }
            else if (strcmp("[20~",keyBuffer)==0) { c=MKEY_F9; flag=1; keyCount=0; }
            else if (strcmp("[21~",keyBuffer)==0) { c=MKEY_F10; flag=1; keyCount=0; }
            else if (strcmp("[34~",keyBuffer)==0) { c=MKEY_SF10; flag=1; keyCount=0; }
              else {
                c=keyBuffer[0];
                for (i=0;i<9;i++) keyBuffer[i]=keyBuffer[i+1];
                keyCount--;
                flag=1;
                }
            }
          } else {
          if (c!=27) flag=1; else { keyBuffer[0]=c; keyCount=1; c=0; }
          }
        }
      }
    }
  if (c==255) c=0;
  return c;
  }

/*
main() {
  char c;
  int  flag;
  char buffer[100];

  setbuf(stdout,NULL);
  openterm();
  echooff();
  unbuffered();
  flag=0;
  while (flag==0) {
    c=fgetc(stdin);
    if (c>0) printf("%d\n",c);
    if (c==27) flag=1;
    }
  closeterm();
  }
*/

void Output(char* Buffer)
{
  printf("%s",Buffer);
}

void Input(char* Buffer)
{
  Buffer[0]='\0';
  fgets(Buffer, 1023, stdin);
  while (Buffer[0] != 0 && Buffer[strlen(Buffer)-1] <' ')
    Buffer[strlen(Buffer)-1] = 0;
}

void ClrScr()
{
  Output("\E[H\E[2J");
}

void ClrEos()
{
  Output("\E[J");
}

void ClrEol()
{
  Output("\E[K");
}

void Delay(int sec)
{
  sleep(sec);
}

void GotoXY(int x,int y)
{
  char XBuffer[10];
  char YBuffer[10];
  char Buffer[20];
  sprintf(XBuffer,"%d",x);
  sprintf(YBuffer,"%d",y);
  strcpy(Buffer,"\E["); strcat(Buffer,YBuffer); strcat(Buffer,";");
  strcat(Buffer,XBuffer); strcat(Buffer,"H");
  Output(Buffer);
}

void CursorDown(int num)
{
  int i;
  for (i=0;i<num;i++) Output("\E[B");
}

void CursorUp(int num)
{
  int i;
  for (i=0;i<num;i++) Output("\E[A");
}
