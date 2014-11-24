#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

//モーター
# define LEFT  10000
# define RIGHT 10000

//回転
# define FW 120
# define N 5000

void motor(short left, short right)
{
	Mtr_Run_lv(left, -right,0,0,0,0);
}

void stop(void)
{
	motor(0,0);
}

void forward(int n)
{
	motor(LEFT, RIGHT);
	Wait(FW * n);
	stop();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	unsigned short bw;

	for(i=0;i<N;i++)
	{

		Wait(500);
		bw = ADRead(0);
		if(bw >500){
			break;
		}
		else(bw < 500)
		;
		forward(1);
		}
	stop();

	return 0;
}

