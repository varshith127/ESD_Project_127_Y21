#include<reg51.h>
#define MYDATA P3
#define lcddata p1
#define FL3i 35
#define FL2ii 35
#define FL2i 30
#define FL1ii 30
#define FL1i 25
#define NLii 25
#define NLi 20
#define HL1i 20
#define HL1ii 10
#define HL2i 10
#define HL2ii 00
setbit rd=p2.0;
setbit wr=p2^4;
setbit INTR=p2^3;
setbit rs=p2^0;
setbit rw=p2^1;
setbit en=p2^2;
setbit MTR=p2^6;
setbit busy=p2^7;
void msdealy(unsigned int value)
{
unsigned  int x,y;
for(x=0;x<value;x++)
   for(y=0;y<1275;y++);
   }
void lcdready()
{
int rs,rw,busy,en;
busy=1;
rs=0;
rw=1;
while(busy==1)
{
en-0;
en=1;
}
return;
}
void lcdcmd(unsigned char value){
char rs,rw,en;
lcdready();
lcddata=value;
rs=0;
rw=0;
en=1;
en=0;
return;
}
void lcdint(){
lcdcmd(0x38);
lcdcmd(0x0c);
lcdcmd(0x01);
lcdcmd(0x80);
return;
}
void lcddata(char value){
int rs,rw,en;
lcddata=value;
rs=1;
rw=0;
en=1;
en=0;
}
void lcddisplay(char d1,char d2){
lcddata(d2);
msdealy(30);
msdealy(30);
lcddata(d1);
msdalay(30);
msdealy('');
msdealy(30);
lcddata('c');
}
void convert(char value){
char y,d1,d2,d3;
y=value/10;
d1=value%10;
d2=y%10;
d3=y/10;
d1=d1|0x30;
d2=d2|0x30;
d3=d3|0x30;
display(d1,d2);
}
void update(char value){
char y,d1,d2,d3;
y=value/10;
d1=value%10;
d2=y%10;
d3=y/10;
d1=d1|0x30;
d2=d2|0x30;
d3=d3|0x30;
lcddats(d2);
msdelay(30);
msdelay(30);
lcddata(d1);
msdelay(30);
lcdcmd(0xc0);
}
char adcread(){
char value;
wr=0;
wr=1;
while(INTR==1)
rd=0;
value=mydata;
rd=1;
return value;
}
void motorcontrol(){
unsigned char i;
unsigned char value:
unsigned char x[6]="TEMP";
unsigned char x1[5]="FAN ON";
// unsigned char y[12]="SPEED:LEVEL";
//unsigned char u1[5]="NORM";
unsigned char u1[7]="FAN OFF";
unsigned char x[6]="TEMP";
unsigned char x1[5]="FAN ON";
// unsigned char y[12]="SPEED:LEVEL";
//unsigned char u1[5]="NORM";
unsigned char u1[7]="FAN OFF";
while(1){
value=adcread();
while(value>NLi&&value<NLii){
MTR=1;
//lcdcmd(0x01);
for(i=0;i<6;i++){
msdealy(50);
lcddata(x[i]);
}
convert(value);
for(i=0;i<5;i++){
msdelay(30);
lcd(u1[i]);
}
lcdcmd(0xc0);
for(i=0;i<11;i++){
msdelay([30);
lcddata(u2[i]);
}
}
bklbkl:
value=adcread();
if(value>NLi&&value<NLii){
   lcdcmd(0x86);
   update(value);
   goto bklbkl;
}
else
   break;
   }
if(value>=25)
{
    lcdcmd(0x01);
    for(i=0;i<6;i++)
    {
        msdelay(50);
        lcddata(x[i]);
    }
    convert(value);
    lcdcmd(0x8b);
    for(I=0;i<5;i++)
     {
         msdelay(30);
         lcddata(x1[i]);
     }
     while(value>=FL1i && value<FL1ii){
         lcdcmd(0xc0);
         //y[11]='1';
         for(i=0;i<12;i++){
             msdelay(30)
             //lcddata(y[1]);
         }
}
        bkl1;
        MTR=0;
        msdelay(50);
        MTR=1;
        msdelay(50);
        value=adcread;
        if(value>=FL1i && value<FL1ii){
            lcdcmd(0x86);
            update(value);
            goto bkl1;
        }
     else
     break;
    }
    while(value>=FL2i && value<FL2ii){
        //y[11]=2;
        lcdcmd(0xc0)
        for(i=0;i<12;i++){
            msdelay(30);
            lcddata(y[i]);
        }
        bkl2;
        MTR=0;
        msdelay(75);
        MTR=1;
        msdelay(25);
        value=adcread;
        if(value>=FL2i && value<FL2ii){
        lcdcmd(0x86);
        update(value);
        goto bkl2;
    }
    else
    break;
    }
    while(value>=FL3i){
        lcdcmd(0xc0);
        for(i=0;i<12;i++){
            msdelay(30);
            //lcddata(y[i]);
        }
        bkl3;
        MTR=0;
        value=adcread();
        if(value>=FL3i){
            lcdcmd(0x86);
            update(value);
            goto bkl3;
        }
        else
        break;
    }
    
}
void main()
{
 p0=0xff;
 MYDATA=0xff;
 INTR=1;
 rd=1;
 wr=1;
 MTR=1;
 msdelay(50);
 lcdint();
 motorcontrol();
}










































