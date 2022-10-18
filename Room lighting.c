#include <reg51.h>
sbit ir=P2^4; //ir sensor is connected to pin 4 of port 2
sbit led=P2^1; //led is connected to pin 1 of port 2
void main()
{
	int i;
	while(1)
	{
		if(ir==0) //pir sensor senses the presence of human
			led=1;
		else
			led=0;
		for(i=0;i<20000;i++)
	}
}
