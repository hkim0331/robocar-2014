#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define right 10500
#define left  -10500
#define time  100
#define EDGE 30

void motor(short r,short l){
	Mtr_Run_lv(r,l , 0, 0, 0, 0);
}

void stop(void){
	motor(0,0);
}

void front(int n){
	Wait(0);
	motor(right , left);
	Wait(50);
	stop();
}

void music(void){

	BuzzerSet(150,150);
	 BuzzerStart();
	 Wait(3000);
	 BuzzerStop();
}

int main(void){
	 const unsigned short MainCycle = 60;
	 Init(MainCycle);
	 int i;

	 for(i=0;i<1000;i++){
		front(EDGE);
		Wait(1000);

		if(ADRead(0)>500)
			break;
	 }
		music();
		return 0;
}
