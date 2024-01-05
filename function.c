#include <REGX52.H>
#include <INTRINS.H>
//延迟函数
unsigned int Delay(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms--){
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
	return 1;
}
//数码管显示
void Nixie(unsigned int loc,unsigned int num){
	int numList[]= {0x3f , 0x06 , 0x5b ,0x4f , 0x66 , 0x6d ,0x7d ,0x07 , 0x7f , 0x6f ,0x77};
	int locList[] = {0,28,24,20,16,12,8,4,0};
	P2 = locList[loc];
	P0 = numList[num];
	Delay(1);
	P0 = 0;
	
}
//矩阵键盘
unsigned char MatrixKey()
{
	unsigned char KeyNumber=0;
	P1 = 0XFF;
	P1_3=0;
	if(P1_7==0){Delay(20);while(!P1_7)/*松手检测*/;Delay(20);KeyNumber=1;}
	if(P1_6==0){Delay(20);while(!P1_6);Delay(20);KeyNumber=5;}
	if(P1_5==0){Delay(20);while(!P1_5);Delay(20);KeyNumber=9;}
	if(P1_4==0){Delay(20);while(!P1_4);Delay(20);KeyNumber=13;}
	 
	P1_2=0;
	if(P1_7==0){Delay(20);while(!P1_7);Delay(20);KeyNumber=2;}
	if(P1_6==0){Delay(20);while(!P1_6);Delay(20);KeyNumber=6;}
	if(P1_5==0){Delay(20);while(!P1_5);Delay(20);KeyNumber=10;}
	if(P1_4==0){Delay(20);while(!P1_4);Delay(20);KeyNumber=14;}
	
	P1 = 0XFF;
	P1_1=0;
	if(P1_7==0){Delay(20);while(!P1_7);Delay(20);KeyNumber=3;}
	if(P1_6==0){Delay(20);while(!P1_6);Delay(20);KeyNumber=7;}
	if(P1_5==0){Delay(20);while(!P1_5);Delay(20);KeyNumber=11;}
	if(P1_4==0){Delay(20);while(!P1_4);Delay(20);KeyNumber=15;}
	
	P1 = 0XFF;
	P1_0=0;
	if(P1_7==0){Delay(20);while(!P1_7);Delay(20);KeyNumber=4;}
	if(P1_6==0){Delay(20);while(!P1_6);Delay(20);KeyNumber=8;}
	if(P1_5==0){Delay(20);while(!P1_5);Delay(20);KeyNumber=12;}
	if(P1_4==0){Delay(20);while(!P1_4);Delay(20);KeyNumber=16;}
 
	return KeyNumber;
}

//蜂鸣器端口：
sbit Buzzer=P2^5;
/**
  * @brief  蜂鸣器私有延时函数，延时500us
  * @param  无
  * @retval 无
  */
void Buzzer_Delay500us()		//@12.000MHz
{
	unsigned char i;

	_nop_();
	i = 100;
	while (--i);
}
/**
  * @brief  蜂鸣器发声
  * @param  ms 发声的时长，范围：0~32767
  * @retval 无
  */
void Buzzer_Time(unsigned int ms)
{
	unsigned int i;
	for(i=0;i<ms*2;i++)
	{
		Buzzer=!Buzzer;
		Buzzer_Delay500us();
	}
}

void Buzzer_Time_result(unsigned int ms)
{
	unsigned int i;
	for(i=0;i<ms*2;i++)
	{
		Buzzer=!Buzzer;
		{
			unsigned char a;
			_nop_();
			a = 2470;
			while (--a);
		}
	}
}