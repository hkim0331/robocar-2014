#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


#define CM       1
#define FW       200
#define BLACK    600
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


void movestep(int cm) {
	motor(LEFT, RIGHT);
	Wait(FW*cm);
	stop();
	Wait(500);
}



void Lengh(void) {
	int i;



	while(1) {
		i = 0;

		if(LBlack() && RBlack()) {
			while(LBlack() && RBlack()) {
				movestep(CM);
				i++;
			}
			if(i>5 || i<15) {
				break;
			}
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



	Go();
	Wait(1000);
	stop();
	}



	int main(void)
	{
		const unsigned short MainCycle = 60;
		Init(MainCycle);

		Lengh();

		return 0;
	}

