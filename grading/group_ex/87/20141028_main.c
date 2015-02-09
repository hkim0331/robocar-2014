#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

/*ex1*/
void ex1(void){
Wait(2000);
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(5000);
	Mtr_Run_lv(0,0,0,0,0,0);
}
/*ex2*/
void ex2(void){
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(1800);
	Mtr_Run_lv(0,0,0,0,0,0);
}
/*ex3*/
void ex3(void){
	Mtr_Run_lv(10000,10000,0,0,0,0);
	Wait(1300);
	Mtr_Run_lv(0,0,0,0,0,0);
}

/*ex6*/


void ex6(void){

	int i;
	for(i=1; i<=4; i++){
	Mtr_Run_lv(10000,-10300,0,0,0,0);
	Wait(3000);
	Mtr_Run_lv(0,0,0,0,0,0);

	Mtr_Run_lv(10000,10000,0,0,0,0);
	Wait(700);
	Mtr_Run_lv(0,0,0,0,0,0);
}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	ex6();

	return 0;
}

