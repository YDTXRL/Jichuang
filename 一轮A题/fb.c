//#include <REGX52.H>
//#include "DELAY.H"
//#include "KEY.H"
//#include "MATRIXKEY.H"
//#include "TIMER0.H"
//#include "Nixie.H"

//typedef unsigned int u16;
//typedef unsigned char u8;

//u16 i;		//for循环变量
//long int Num1=0,Num2=0,Num3=0;		//存储数据
//u16 Negative1=0,Negative2=0,Negative3=0,Negative4=0;		//储存第一位数符号，储存第二位数符号，数码管显示符号，最后计算符号
//u16 Point_Location=9,Point=0;		//小数点
//u16 Point_Location1=9,Point_Location2=9,Point_Location3=9;		//储存第一位数点的位置，储存第二位数点的位置，储存最终点的位置
//u16 flag=0;		//功能符号标识
//u16 Calculate=0;		//运算符号标识
//u16 Num_Location=0;		//被计算数据位置
//int b[8]={0,0,0,0,0,0,0,0};		//数码管显示的数
//int a[2]={0,10};		//数码管显示的负号
//int c[2]={12,11};		//数码管显示的小数点
//int T=0;
//int x,y;

//void Input()
//{
//	int KeyNum=MatrixKey();
//	int KeyNumber=Key();
//	
//		if(KeyNum==1||KeyNum==2||KeyNum==3||KeyNum==4||KeyNum==5||KeyNum==6||KeyNum==7||KeyNum==8||KeyNum==9||KeyNum==0)
//		{
//			T=KeyNum;
//			
//			for(i=7;i>0;i--)
//			{
//				b[i]=b[i-1];
//			}
//		
//			b[0]=T;
//			
//			if(Point_Location==9)
//			{
//				Point_Location=9;
//			}
//			else
//			{
//				Point_Location--;
//				
//			}
//			if(Num_Location==0)
//			{
//				Num1=(b[6]*1000000+b[5]*100000+b[4]*10000+b[3]*1000+b[2]*100+b[1]*10+b[0]);
//			}
//			else
//			{
//				Num2=(b[6]*1000000+b[5]*100000+b[4]*10000+b[3]*1000+b[2]*100+b[1]*10+b[0]);
//			}
//			
//		}
//		else if(KeyNum==10)	//加
//		{
//			
//			Negative4=1;
//			T=KeyNum;
//			Negative3=0;
//			Num_Location=1;
//			Calculate=1;
//			Point_Location1=Point_Location;
//			Point_Location=9;
//			Point=0;
//			for(i=0;i<7;i++)
//			{
//				b[i]=0;
//			}
//			
//		}
//		else if(KeyNum==11)	//减
//		{
//			
//			T=KeyNum;
//			if(Num1==0)
//			{
//				Negative1=1;		//标记第一位负号
//				Negative3=1;		//显示第一位负号
//			}
//			else if(Num2==0)
//			{
//				if(Negative4==1)
//				{
//					Negative2=1;		//标记第二位负号
//					Negative3=1;		//显示第二位负号
//				}
//				else
//				{
//					Num_Location=1;
//					Calculate=2;
//					Point_Location1=Point_Location;
//					Point_Location=9;
//					Point=0;
//					for(i=0;i<7;i++)
//					{
//						b[i]=0;
//					}
//					flag=100;
//				}
//			}
//			
//		}
//		else if(KeyNum==12)	//乘
//		{
//			
//			Negative4=1;
//			T=KeyNum;
//			Num_Location=1;
//			Calculate=3;
//			Point_Location1=Point_Location;
//			Point_Location=9;
//			Point=0;
//			for(i=0;i<7;i++)
//			{
//				b[i]=0;
//			}
//			flag=100;
//		}
//		else if(KeyNum==13)	//除
//		{
//			
//			Negative4=1;
//			T=KeyNum;
//			Num_Location=1;
//			Calculate=4;
//			Point_Location1=Point_Location;
//			Point_Location=9;
//			Point=0;
//			for(i=0;i<7;i++)
//			{
//				b[i]=0;
//			}
//			flag=100;
//		}
//		else if(KeyNum==16)	//等于
//		{
//			flag=6;
//			T=KeyNum;
//		}
//		else if(KeyNum==15)	//小数点
//		{
//			flag=7;
//			Point_Location=8;
//			T=KeyNum;
//			Point=1;
//		}
//		else if(KeyNumber==1)
//		{
//			flag=8;
//		}
//}

//void main()
//{
//	
//	while(1)
//	{
//		Input();
//	
//		Nixie(1,a[Negative3]);
//		Nixie(2,b[6]);
//		Nixie(3,b[5]);
//		Nixie(4,b[4]);
//		Nixie(5,b[3]);
//		Nixie(6,b[2]);
//		Nixie(7,b[1]);
//		Nixie(8,b[0]);
//		c[0]=12;
//		Nixie(Point_Location,c[Point]);
//			
//		if(flag==6)		//等于
//		{
//			Negative3=0;
//			Point_Location2=Point_Location;
//			Point_Location=9;
//			
//			if(Calculate==1)		//加法
//			{
//				if(Point_Location1<Point_Location2)
//				{
//					Point_Location=Point_Location1;
//					Point=1;
//					if(Point_Location2!=9)
//					{
//						Point_Location3=(Point_Location2-Point_Location1);
//						for(i=0;i<Point_Location3;i++)
//						{
//							Num2=Num2*10;
//						}
//					}
//					else if(Point_Location2==9)
//					{
//						Point_Location3=(8-Point_Location1);
//						for(i=0;i<Point_Location3;i++)
//						{
//							Num2=Num2*10;
//						}
//					}
//					
//				}
//				else if(Point_Location1==Point_Location2)
//				{
//					Point_Location=Point_Location2;
//					Point_Location3=Point_Location1;
//				}
//				else if(Point_Location1>Point_Location2)
//				{
//					if(Point_Location1!=9)
//					{
//						Point_Location=Point_Location2;

//						Point_Location3=(Point_Location1-Point_Location2);
//						for(i=0;i<Point_Location3;i++)
//						{
//							Num1=Num1*10;
//						}
//					}
//					else if(Point_Location1==9)
//					{
//						Point_Location=Point_Location2;
//						Point_Location3=(8-Point_Location2);
//						for(i=0;i<Point_Location3;i++)
//						{
//							Num1=Num1*10;
//						}
//					}
//					
//				}
//			
//				if(Negative1==1&&Negative2==1)
//				{
//					Negative3=1;
//					Num3=Num1+Num2;
//				}
//				else if(Negative1==1&&Negative2==0)
//				{
//					if(Num1>=Num2)
//					{
//						Num3=(Num1-Num2);
//						Negative3=1;
//					}
//					else if(Num1<=Num2)
//					{
//						Num3=(Num2-Num1);
//						Negative3=0;
//					}
//				}
//				else if(Negative1==0&&Negative2==1)
//				{
//					if(Num1>=Num2)
//					{
//						Num3=(Num1-Num2);
//						Negative3=0;
//					}
//					else if(Num1<=Num2)
//					{
//						Num3=(Num2-Num1);
//						Negative3=1;
//					}
//				}
//				else if(Negative1==0&&Negative2==0)
//				{
//					Num3=Num1+Num2;
//				}
//				
//				b[6]=((Num3/1000000)%10);
//				b[5]=((Num3/100000)%10);
//				b[4]=((Num3/10000)%10);
//				b[3]=((Num3/1000)%10);
//				b[2]=((Num3/100)%10);
//				b[1]=((Num3/10)%10);
//				b[0]=(Num3%10);
//			}
//			
//			if(Calculate==2)		//减法
//			{
//				if(Point_Location1<Point_Location2)
//				{
//					Point_Location=Point_Location1;
//					Point=1;
//					if(Point_Location2!=9)
//					{
//						Point_Location3=(Point_Location2-Point_Location1);
//						for(i=0;i<Point_Location3;i++)
//						{
//							Num2=Num2*10;
//						}
//					}
//					else if(Point_Location2==9)
//					{
//						Point_Location3=(8-Point_Location1);
//						for(i=0;i<Point_Location3;i++)
//						{
//							Num2=Num2*10;
//						}
//					}
//				}
//				else if(Point_Location1==Point_Location2)
//				{
//					Point_Location=Point_Location2;
//					Point_Location3=Point_Location1;
//				}
//				else if(Point_Location1>Point_Location2)
//				{
//					Point_Location=Point_Location2;
//					Point_Location3=(Point_Location1-Point_Location2);
//					for(i=0;i<Point_Location3;i++)
//					{
//						Num1=Num1*10;
//					}
//				}
//				
//				if(Negative1==1&&Negative2==1)
//				{
//					if(Num1>=Num2)
//					{
//						Num3=(Num1-Num2);
//						Negative3=1;
//					}
//					else if(Num1<=Num2)
//					{
//						Num3=(Num2-Num1);
//						Negative3=0;
//					}
//						
//				}
//				else if(Negative1==1&&Negative2==0)
//				{
//					Num3=Num1+Num2;
//					Negative3=1;
//					
//				}
//				else if(Negative1==0&&Negative2==1)
//				{
//					Num3=Num1+Num2;
//					Negative3=0;
//				}
//				else if(Negative1==0&&Negative2==0)
//				{
//					if(Num1>=Num2)
//					{
//						Num3=(Num1-Num2);
//						Negative3=0;
//					}
//					else if(Num1<=Num2)
//					{
//						Num3=(Num2-Num1);
//						Negative3=1;
//					}
//				}
//			
//				b[6]=((Num3/1000000)%10);
//				b[5]=((Num3/100000)%10);
//				b[4]=((Num3/10000)%10);
//				b[3]=((Num3/1000)%10);
//				b[2]=((Num3/100)%10);
//				b[1]=((Num3/10)%10);
//				b[0]=(Num3%10);
//			}
//		
//			if(Calculate==3)		//乘法
//			{
//				Point=1;
//				if(Point_Location1!=9&&Point_Location2!=9)
//				{
//					Point_Location=(Point_Location1+Point_Location2-8);
//				}
//				else if(Point_Location1==9&&Point_Location2!=9)
//				{
//					Point_Location=Point_Location2;
//				}
//				else if(Point_Location1!=9&&Point_Location2==9)
//				{
//					Point_Location=Point_Location1;
//				}
//				else Point=0;
//				
//				if(Negative1==1&&Negative2==1)
//				{
//					
//					Num3=Num1*Num2;
//					Negative3=0;
//					
//				}
//				else if(Negative1==1&&Negative2==0)
//				{
//					Num3=Num1*Num2;
//					Negative3=1;
//					
//				}
//				else if(Negative1==0&&Negative2==1)
//				{
//					Num3=Num1*Num2;
//					Negative3=1;
//				}
//				else if(Negative1==0&&Negative2==0)
//				{
//					Num3=Num1*Num2;
//				}
//			
//				b[6]=((Num3/1000000)%10);
//				b[5]=((Num3/100000)%10);
//				b[4]=((Num3/10000)%10);
//				b[3]=((Num3/1000)%10);
//				b[2]=((Num3/100)%10);
//				b[1]=((Num3/10)%10);
//				b[0]=(Num3%10);
//			}
//			
//			if(Calculate==4)		//除法
//			{
//				if(Point_Location1>Point_Location2)
//				{
//					Point_Location=9;
//					Point=0;
//					if(Point_Location1!=9)
//					{
//						Point_Location3=Point_Location1-Point_Location2;
//						for(i=0;i<Point_Location3-1;i++)
//						{
//							Num1=Num1*10;
//						}
//					}
//					else if(Point_Location1==9)
//					{
//						Point_Location3=(8-Point_Location2);
//						for(i=0;i<Point_Location3;i++)
//						{
//							Num1=Num1*10;
//						}
//					}
//				}
//				else if(Point_Location1==Point_Location2)
//				{
//					Point_Location=9;
//					Point=0;
//				}
//				else if(Point_Location1<Point_Location2)
//				{
//					if(Point_Location2!=9)
//					{
//						Point_Location3=8-Point_Location2;
//						Point_Location=Point_Location1+Point_Location3;
//						Point=1;
//					}
//					else if(Point_Location2==9)
//					{
//						Point_Location=Point_Location1;
//						Point=1;
//					}
//				}
//				
//				Num1=Num1*100;
//				
//				if(Negative1==1&&Negative2==1)
//				{
//					Num3=Num1/Num2;
//					Negative3=0;
//				}
//				else if(Negative1==1&&Negative2==0)
//				{
//					Num3=Num1/Num2;
//					Negative3=1;
//				}
//				else if(Negative1==0&&Negative2==1)
//				{
//					Num3=Num1/Num2;
//					Negative3=1;
//				}
//				else if(Negative1==0&&Negative2==0)
//				{
//					Num3=Num1/Num2;
//				}
//				
//				x=(Num3%10);		//检测后两位是否为0
//				y=(Num3%100);
//				if(x==0&&y==0)
//				{
//					Point_Location=Point_Location;
//					Num3/=100;
//				}
//				else
//				{
//					Point=1;
//					if(Point_Location!=9)
//					{
//						Point_Location-=2;
//					}
//					else if(Point_Location==9)
//					{
//						Point_Location=6;
//					}
//					
//				}
//			
//				b[6]=((Num3/1000000)%10);
//				b[5]=((Num3/100000)%10);
//				b[4]=((Num3/10000)%10);
//				b[3]=((Num3/1000)%10);
//				b[2]=((Num3/100)%10);
//				b[1]=((Num3/10)%10);
//				b[0]=(Num3%10);
//			}
//			flag=100;
//		}
//		
//		if(flag==8)		//初始化
//		{
//			Num_Location=0;
//			Num1=0;
//			Num2=0;
//			Num3=0;
//			Negative1=0;
//			Negative2=0;
//			Negative3=0;
//			Negative4=0;
//			Point_Location=9;
//			Point_Location1=9;
//			Point_Location2=9;
//			Point_Location3=9;
//			Point=0;
//			Calculate=0;
//			T=0;
//			for(i=0;i<7;i++)
//			{
//				b[i]=0;
//			}
//			flag=0;
//		}
//	}
//}