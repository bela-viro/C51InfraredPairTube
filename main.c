#include <REGX52.H>
#include <INTRINS.H>
#include "function.h"
#include "Timer0.h"
#define s_loc 1
#define g_loc 2

unsigned char KeyNum;
unsigned char i;
unsigned long T0Count;
unsigned int s,g,cnt;
void main(){
	Timer0Init();
	while(1){
		if(!P1_0){
			while(!P1_0) Buzzer_Time(100);
			g++;
			if(g==10){
				s++;
				g=0;
			}else if(s==9 && g==9){
				s = 0;
				g = 0;
			}
			Delay(50);
		}
		if(!P3_1){
			while(!P3_1);
			s = 0;
			g = 0;
		}
	}
}
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=5)
	{
		Nixie(s_loc,s);Nixie(g_loc,g);
		T0Count=0;
	}
}
