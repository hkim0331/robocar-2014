#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  5000
#define RIGHT_POWER -5000

#define MM 40
#define BLACK 500

void motor(short left, short right) {
	Mtr_Run_lv(left, -right, 0,0,0,0);
}

void stop(void) {
	motor(0,0);
}

void forward(int mm) {
	motor(LEFT_POWER, RIGHT_POWER);
	Wait(MM * mm);
	stop;
}

void step(int n) {
	forward(n);
	stop();
}


int is_black(uint8_t n) {
	ADRead(n) > BLACK;
}

int is_white(uint8_t n) {
	ADRead(n) < BLACK;
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
Wait(2000);
for (;;) {
	if (is_white(1) && is_white(0)) {
		step(5);
		Wait(500);
	} else if (is_black(1) && is_black(0)) {
		int blacks;
		blacks += 1;
		step(5);
		if (blacks >= 4) {
			stop();
			break;
		} else if (blacks < 4){
			step(5);
			Wait(500);
		}

	}  else if (is_black(1)) {
	motor(LEFT_POWER/3,RIGHT_POWER);
	} else if (is_black(0)) {
    motor(LEFT_POWER,RIGHT_POWER/3);
	}

	return 0;
}

