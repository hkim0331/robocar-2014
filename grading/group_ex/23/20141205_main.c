#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define powerL 10000
#define powerR 10000
#define LEFT 0
#define RIGHT 1
#define cm 50
#define angle 65

int blacks=0;

void motor(int motorL, int motorR)
{
	Mtr_Run_lv(motorL, -motorR, 0, 0, 0, 0);
}

void go()
{
	motor(powerR, powerL);
}

void stop()
{
	motor(0, 0);
}

void turnR()
{
	motor(0, powerR);
	Wait(angle);
	stop();
}

void turnL()
{
	motor(powerL, 0);
	Wait(angle);
	stop();
}


void step()
{
		go();
		Wait(cm);
		stop();
		Wait(200);
}

void forward()
{
	for(;;)
	{
		if((ADRead(LEFT)<500) && (ADRead(RIGHT)<500))
		{
			if(blacks>0)
			{
				stop();
				break;
			}
			else
			{
				step();
			}
		}
		else if((ADRead(LEFT)>500) && (ADRead(RIGHT)>500))
		{
			stop();
			Wait(500);
			step();
			blacks+=1;
		}
		else if((ADRead(LEFT)<500) && (ADRead(RIGHT)>500))
		{
			turnR();
		}
		else if((ADRead(LEFT)>500) && (ADRead(RIGHT)<500))
		{
			turnL();
		}
		else{;}
	}
}

void buzzer(int n)
{
	int i;

	for(i=1; i<=n; i++)
	{
		BuzzerSet(179, 100);
		BuzzerStart();
		Wait(200);
		BuzzerStop();
		Wait(100);
	}
}

void length(int n)
{
	int i;

	for(i=0; i<n; i++)
		{
			forward();
			buzzer(blacks);
			blacks = 0;
		}
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	length(3);

	return 0;
}

