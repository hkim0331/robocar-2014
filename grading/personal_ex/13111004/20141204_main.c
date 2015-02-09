#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  10000
#define RIGHT_POWER 10000
#define LEFT    1
#define RIGHT   0

#define LED_LEFT 2
#define LED_RIGHT 1

#define MM 20
#define BLACK 500

void motor(short left, short right) {
    Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void) {
    motor(0,0);
}


void forward(int mm) {
    LED(LED_LEFT + LED_RIGHT);
    motor(LEFT_POWER, RIGHT_POWER);
    Wait(MM * mm);
    stop();
}

void turn_left(void){
	motor(0,-RIGHT_POWER);
}

void turn_right(void){
	motor(LEFT_POWER,0);
}


void step(int n) {
    forward(n);
    stop();
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	return 0;
}

