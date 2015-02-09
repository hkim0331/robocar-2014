#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define	RIGHT	10000
#define	LEFT	-10800
#define	GOTIME	2700
#define	RIGHTTIME	1100

void Motor(int right,int left)
{
	Mtr_Run_lv(right,left,0,0,0,0);
}
void Go(void)
{
	Motor(RIGHT,LEFT);
}

void TurnRight(void)
{
	Motor(0,LEFT);
}

void TurnLeft(void)
{
	Motor(RIGHT,0);
}
void Back(void)
{
	Motor(-RIGHT,-LEFT);
}
void Stop(void)
{
	Motor(0,0);
}

void Note(void)
{
	BuzzerSet(107,100);
	BuzzerStart();
	Wait(200);
	BuzzerStop();
}

void Step(unsigned int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		Go();
		Wait(500);
		Stop();
		Wait(500);
	}

}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int bwright,bwleft,count=0;

	while(1){
		bwright = ADRead(0);//0が右
		bwleft = ADRead(1);//1が左


		if(bwright < 500 && bwleft <500){
			Go();
			LED(3);
		}
		else if(bwright>500 && bwleft<500){
			TurnLeft();
			LED(2);
		}
		else if(bwleft>500 && bwright<500){
			TurnRight();
			LED(1);
		}
		else if(bwright>500 && bwleft>500){
			LED(0);
			count++;
			if(count>20){
				Stop();
				count = 0;
			}else if(count>=4){

			}
		}
	}

	return 0;
}

