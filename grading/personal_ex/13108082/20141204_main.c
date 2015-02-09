#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define t1 150 //1cm進むのにかかる時間
#define t2 580//90度回転するのにかかる時間
#define censerleft 810 //センサー左の明るさの認識の値
#define censerright 990 //センサー右の明るさの認識の値
#define ledoff 0 //ライト消灯
#define ledleft 1　// 左のライト
#define ledright 2 //右のライト
#define ledboth 3 //両方のライト
#define n //止まった回数

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
		int bracks=0;
		if((ADRead(0) < censerleft)&&(ADRead(1) <censerright ))
		{
			LED(ledboth);
			go();
			LED(ledoff);
		}

		else if((ADRead(0) > censerleft)&&(ADRead(1) < censerright))
		{
			LED(ledleft);
			turnleft();
			LED(0);
		}

		else if((ADRead(0) < censerleft)&&(ADRead(1) > censerright))
		{
			LED(ledright);
			turnright();
			LED(0);
		}

		else if((ADRead(0) > censerleft)&&(ADRead(1) > censerright))
		{
			LED(ledboth);
			go();
			LED(ledoff);
			bracks+=1;
				if(blacks>=n)
				{
					break;
				}
		}

	}

	stop();

	Buzzer();

	return 0;
}

