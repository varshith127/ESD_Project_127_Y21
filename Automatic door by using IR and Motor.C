
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
      x=1;
      y=0;
      delay();
      x=0;
      y=1;
      delay();
    }
    else
    {
      x=0;
			y=0;
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
