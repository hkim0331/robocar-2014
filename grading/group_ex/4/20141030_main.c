#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT 10000
#define RIGHT 10000
#define ZE 200
#define N 10000
#define EDGE 1
#define ST 300
#define STOP 1


void motor(short left, short right)
{
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(int m)
{
	motor(0,0);
	Wait(ST * m);
}

void forward(int n)
{
	motor(LEFT, RIGHT);
	Wait(ZE * n);
	stop(0);
}

void step(void)
{
	forward(EDGE);
	stop(STOP);
}

void buzzer(int bb)
{
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(bb);
	BuzzerStop();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Wait(1000);
	int i;

	unsigned short bw;

	for(i = 0; i < N; i++){
		step();
		stop(STOP);
		bw=ADRead(0);
		if(bw > 100) {
			break;
		}else {
			;
		}
	}

	buzzer(500);

	return 0;
}






