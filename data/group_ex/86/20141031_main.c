#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT 10000
#define RIGHT 10600
void motor(short left, short right)
{
	Mtr_Run_lv(left,-right,0,0,0,0);
}

void ex1(void){
	Wait(2000);
	motor(LEFT,RIGHT);
		Wait(5000);
		motor(0,0);
}
void ex2(void){
	motor(LEFT,RIGHT);
			Wait(5000/9);
	motor(0,0);
			Wait(2000);
    motor(-LEFT,-RIGHT);
			Wait(5000/18);
	motor(0,0);
			Wait(2000);
	motor(LEFT,0);
			Wait(925);
	motor(0,0);
		    Wait(2000);
	motor(0,RIGHT);
		    Wait(3700);
	motor(0,0);
}

void kadai(void){
	Wait(1000);
		int i;
		for(i=0;i<4;i++){
			motor(LEFT,RIGHT);
			Wait(5000/3);
			motor(0,0);

			motor(LEFT,0);
			Wait(830);
			motor(0,0);
		}
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	kadai();

	return 0;
}

