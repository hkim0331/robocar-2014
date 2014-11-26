#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define t1 150 //1cm進むのにかかる時間
#define l0 810 //センサー左の明るさの認識の値
#define l1 990 //センサー右の明るさの認識の値
#define t2 580//90度回転するのにかかる時間

void motor(short right,short left)
{

	Mtr_Run_lv(right,left, 0, 0, 0, 0);
}

void stop(void)
{
	motor(0, 0);
}

void go(void)
{
	motor(10500, -10000);
	Wait(t1/10);
}

void turnleft(void)
{
	motor(10500, 0);
	Wait(t2/90);
}

void turnright(void)
{
	motor(0, -10000);
	Wait(t2/90);
}

void Buzzer(void)
{
	BuzzerSet(120, 100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	while(1)
	{

		if((ADRead(0) < l0)&&(ADRead(1) < l1))
		{
			LED(3);
			go();
			LED(0);
		}

		else if((ADRead(0) > l0)&&(ADRead(1) < l1))
		{
			LED(1);
			turnleft();
			LED(0);
		}

		else if((ADRead(0) < l0)&&(ADRead(1) > l1))
		{
			LED(2);
			turnright();
			LED(0);
		}

		else if((ADRead(0) > l0)&&(ADRead(1) > l1))
		{
			break ;
		}

	}

	stop();

	Buzzer();

	return 0;
}

