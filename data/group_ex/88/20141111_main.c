#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void Go(void){

	Mtr_Run_lv(9000,-9000,0,0,0,0);
	Wait(100);
	Mtr_Run_lv(0,0,0,0,0,0);

}
void leftTurn(void){

	Mtr_Run_lv(10000,0,0,0,0,0);
	Wait(200);
	Mtr_Run_lv(0,0,0,0,0,0);

}
void rightTurn(void){

	Mtr_Run_lv(0,-10000,0,0,0,0);
	Wait(200);
	Mtr_Run_lv(0,0,0,0,0,0);

}
void Stop(void){

	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(500);
}

int main(void){

	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short left;
	unsigned short right;

	for ( ;; ){

		left = ADRead(0);
		right = ADRead(1);


		if( left<300 && right<300 ){

			Go();

		} if ( left>700 && right<300 ){

			leftTurn();

		} if ( (left<300) && (right>700) ){

			rightTurn();

		} if ( (left>700) && (right>700) ){

			break;
		}
	}
	Stop();

	return 0;
}

