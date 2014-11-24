#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define FoLEFT   10000
#define FoRIGHT  10000
#define CuLEFT   5000
#define CuRIGHT  5000
#define BLACK    600
#define LEFT     0
#define RIGHT    1

void motor(short left, short right) {
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void Go(void) {
	motor(FoLEFT, FoRIGHT);
	LED(3);
}

void stop(void) {
	motor(0, 0);
	LED(0);
}

void RCurve(void) {
	motor(CuLEFT, 0);
	LED(1);
}

void LCurve(void)  {
	motor(0, CuRIGHT);
	LED(2);
}

int RBlack(void) {
	return ADRead(RIGHT) > BLACK;
}

int LBlack(void) {
	return ADRead(LEFT) > BLACK;
}

void slalom (void) {
	while(1) {

		if(LBlack() && RBlack()) {
			break;
		} else {
			;
		}


		if(LBlack()) {
			RCurve();
		}	else {
			;
		}

		if(RBlack()) {
			LCurve();
		}	else {
			;
		}
		if(!LBlack() && !RBlack()) {
			Go();
		}	else {
			;
		}

	}

	Go();
	Wait(1000);
	stop();

}

int main(void) {
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	slalom();

	return 0;
}


