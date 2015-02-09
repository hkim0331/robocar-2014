#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT 10000	//左回転数
#define RIGHT 10000	//右回転数
#define T 150		//1cm進む秒数(ms)

void motor(short left, short right)
{
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(double t)
{
  motor(0, 0);
  Wait(t);
}

void runstraight(double l)
{
	motor(LEFT, RIGHT);
	Wait(l*T);
}

void buzzer(void){
	BuzzerSet(120, 100);
	BuzzerStart();
	Wait(3000);
	BuzzerStop();
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i, color;

	for(i=0; i<500; i++){
		runstraight(0.5);		//1度に進みたい距離(cm)
		stop(500);		//止まりたい秒数(ms)
		color = ADRead(1);
		if(color > 980){
			i = 60;
		}
	}

	buzzer();

	return 0;
}

