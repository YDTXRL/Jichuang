#include <REGX52.H>
#include "DELAY.H"

unsigned int Key()
{
	unsigned char KeyNumber;
	
	if(P3_1==0){Delay(20);while(P3_1==0);Delay(20);KeyNumber=1;}
	if(P3_0==0){Delay(20);while(P3_0==0);Delay(20);KeyNumber=2;}
	if(P3_2==0){Delay(20);while(P3_2==0);Delay(20);KeyNumber=3;}
	if(P3_3==0){Delay(20);while(P3_3==0);Delay(20);KeyNumber=4;}
	
	return KeyNumber;
	
}