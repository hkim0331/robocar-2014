#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void Run(){
	Mtr_Run_lv(10050,-10000,0,0,0,0);
		Wait(1800);
}

void Turn(){
	Mtr_Run_lv(10000,0,0,0,0,0);
		Wait(1000);
}

void Stop(){
	Mtr_Run_lv(0,0,0,0,0,0);
			Wait(800);
}


int main(void){
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	for(i=0;i<4;i++){
		Run();
		Stop();
		Turn();
		Stop();

	}


	return 0;
}

