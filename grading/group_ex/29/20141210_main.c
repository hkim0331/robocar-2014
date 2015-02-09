#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define	RIGHT	10000
#define	LEFT	-10000
#define	GOTIME	2700
#define	RIGHTTIME	1100
#define	LONG	10
#define	MIDDLE	6
#define	STEPTIME	70

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
		Wait(STEPTIME);
		Stop();
		Wait(STEPTIME);
		Note();
	}

}

void exp(void){

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
			Step(1);
			bwright = ADRead(0);//0が右
			bwleft = ADRead(1);//1が左
			if(bwright>500 && bwleft>500){
				count++;
			}else{
				if(count<MIDDLE){
					bwright = 0;
					bwleft = 0;
					count = 0;
				}else{
					break;
				}
			}

		}
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	exp();
	Go();
	Wait(500);
	Stop();

	return 0;
}

