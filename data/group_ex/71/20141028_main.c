#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
void ex1(void){
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
		Wait(2000);
		Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
		  Wait(5000);
		  Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}
void ex21(void){
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
			Wait(1000);
			Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
			  Wait(100);
			  Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}
void ex22(void){
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
				Wait(1000);
				Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
				  Wait(1000);
				  Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}
void ex24(void){
	Mtr_Run_lv(10000, 10000, 0, 0, 0, 0);
		Wait(650);
		Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}
void exgp(void){
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
					Wait(1000);
	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
					  Wait(3000);
					  Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	Mtr_Run_lv(10000, 10000, 0, 0, 0, 0);
	Wait(600);
	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
					Wait(3000);
				Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	Mtr_Run_lv(10000, 10000, 0, 0, 0, 0);
						  	Wait(600);
 Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
						    Wait(3000);
						   Mtr_Run_lv(0, 0, 0, 0, 0, 0);
 Mtr_Run_lv(10000, 10000, 0, 0, 0, 0);
						  Wait(600);
Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
						   Wait(3000);
						  Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	//ex1();
    //ex21();
	//exgp();
	exgp();
	return 0;
}

