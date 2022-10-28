#include<reg51.h>
sbit input=P1^4;
sbit a=P1^5;
sbit b=P1^6;
void delay(void);
int main(void)
{
  while(1)
  {
    if(input==1)
    {
      a=1;
      b=0;
      delay();
      a=0;
      b=1;
      delay();
    }
    else
    {
      a=b=0;
    }
}
}

void delay(void)
{
  int i,j;
  for(i=0;i<1000;i++)
  {
    for(j=0;j<1000;j++);
  }
}
