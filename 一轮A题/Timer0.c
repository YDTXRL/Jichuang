#include <REGX52.H>

void Timer0Init(void)		//1毫秒@11.0592MHz
{

	TMOD &= 0xF0;			//设置定时器模式//把TMOD的低四位清零，高四位不变
	TMOD |= 0x01;			//设置定时器模式//把TMOD的最低位1，高四位不变
	TL0 = 0x18;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	ET0=1;
	EA=1;
	PT0=0;
}




//定时器中断模板
//void Timer0_Routime() interrupt 1
//{
//	static unsigned int T0Count;
//	TH0=0xFC;
//	TL0=0x18;	
//	T0Count++;
//	if (T0Count>=1000)
//	{
//		T0Count=0;
//		
//	}
//}