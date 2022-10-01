#include<reg51.h>
sbit f=P1^0;
sbit m=P1^1;
sbit e=P1^2;
sbit t2=P1^3;
sbit rs=P0^0;
sbit rw=P0^1;
sbit en=P0^2;
sbit r=P3^0;

void ldata(unsigned char[],unsigned char);
void cmd(unsigned char);
void delay(unsigned int);
void main(void){
    r=0;
    P0=00;
    P2=00;
    f=1;
    m=1;
    e=1;
    t2=1;

    cmd(0x38);
    cmd(0x0c);
    cmd(0x06);
    cmd(0x01);
        while(1){
            if(t2==0){
           

                if(e==1 && m==1 && f==1){
                    r=1;
                    cmd(0x01);
                    cmd(0x80);
                    ldata("tank is empty",15);
                    cmd(0xc0);
                    ldata("motor on",8);
                }else if(e==0 && m==1 && f==1){
                    r=1;
                    cmd(0x01);
                    cmd(0x80);
                    ldata("tank filling",12);
                    cmd(0xc0);
                    ldata("motor on",8);
                }else if(e==0 && m==0 && f==1){
                    r=1;
                    cmd(0x01);
                    cmd(0x80);
                    ldata("tank middle",13);
                    cmd(0xc0);
                    ldata("motor on",8);
                }else if(f==0 && m==0 && e==0){
                    r=0;
                    cmd(0x01);
                    cmd(0x80);
                    ldata("tank is full",15);
                    cmd(0xc0);
                    ldata("motor off",8);
                }
        else{
        }

        }else{
    r=0;
            cmd(0x01);
            cmd(0x80);
            ldata("tank 2 ety",12);
            cmd(0xc0);
            ldata("fill tank 2",11);
        }
    } 
}

void cmd(unsigned char cmd){
    P2=cmd;
    rs=0;
    rw=0;
    en=1;
    delay(5);
    en=0;
}

void ldata(unsigned char a[],unsigned char len){
    unsigned char x;

    for(x=0;x<len;x++){
        P2=a[x];
        rs=1; //data
        rw=0;
        en=1;
        delay(5);
        en=0;
    }
}

void delay(unsigned int a)
{
    unsigned int x,y;

    for(x=0;x<a;x++)
        for(y=0;y<1275;y++);
}
