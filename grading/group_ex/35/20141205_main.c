#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define  CM        200
#define  FW        0.5
#define  BLACK     600
#define FoLEFT     5000
#define FoRIGHT    5000
#define StepLEFT   10000
#define StepRIGHT  10000
#define CuLEFT     5000
#define CuRIGHT    5000
#define BLACK      600
#define LEFT       0
#define RIGHT      1
#define SI         95
#define VOL        100
#define LONG       18
#define SHORT      5


void motor(short left, short right) {
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void Go(void) {
	motor(FoLEFT, FoRIGHT);
}

void stop(void) {
	motor(0, 0);
}

void RCurve(void) {
	motor(CuLEFT, 0);
}

void LCurve(void)  {
	motor(0, CuRIGHT);
}

int RBlack(void) {
	return ADRead(RIGHT) > BLACK;
}

int LBlack(void) {
	return ADRead(LEFT) > BLACK;
}

void movestep(double cm) {
	motor(StepLEFT, StepRIGHT);
	Wait(FW*cm);
	stop();
	Wait(500);
}

void buzzer (void) {
	BuzzerSet(SI, VOL);
	BuzzerStart();
	LED(3);
	Wait(500);
	BuzzerStop();
	LED(0);
	Wait(200);
}

void buzzer_x_cm (int num_of_step) {
	int i;
	for(i=0; i<num_of_step/2; i++) {
		buzzer();
	}
}

void MeasureLength(void) {
	int i = 0;
	int j;
	int length[10] = {};

	while(1) {

		if(LBlack() && RBlack()) {
			while(LBlack() && RBlack()) {
				movestep(CM);
				length[i]++;
			}
			if (length[i]>SHORT && length[i]<LONG) {
				i++;
				break;
			}
			i++;
		}  else {
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
	stop();

	for(j=0; j<i; j++) {
		buzzer_x_cm(length[j]);
		Wait(1000);
	}
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	MeasureLength();

	return 0;
}

