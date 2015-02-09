#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void ex1(void){
	/*wait2second*/
Mtr_Run_lv(0,0,0,0,0,0);
	Wait(2000);
Mtr_Run_lv(10000,-10000,0,0,0,0);
Wait(100);
Mtr_Run_lv(0,0,0,0,0,0);}

void ex2(void){
/*10cm forward*/
	Mtr_Run_lv(10000,-10000,0,0,0,0);
		Wait(700);
		Mtr_Run_lv(0,0,0,0,0,0);

}

void ex3(void){
/*5cm back*/
	Mtr_Run_lv(-10000,10000,0,0,0,0);
			Wait(350);
			Mtr_Run_lv(0,0,0,0,0,0);
}
void ex4(void){

	/*arc90*/
	Mtr_Run_lv(10000,0,0,0,0,0);
				Wait(780);
				Mtr_Run_lv(0,0,0,0,0,0);


}
void ex5(void){
	/*arc360*/
	Mtr_Run_lv(10000,0,0,0,0,0);
				Wait(3100);
				Mtr_Run_lv(0,0,0,0,0,0);

}
void ex6(void){
	/*2baisoku10cm*/Mtr_Run_lv(20000,-20000,0,0,0,0);
				Wait(350);
				Mtr_Run_lv(0,0,0,0,0,0);

}
void ex7(void){
	/*hannbunnsokudo10cm*/
	Mtr_Run_lv(5000,-5000,0,0,0,0);
				Wait(1400);
				Mtr_Run_lv(0,0,0,0,0,0);

}
/*30cmrolling*/
void ro(void){
	Mtr_Run_lv(10000,0,0,0,0,0);
		    Wait(800);

}
void go(void){

	Mtr_Run_lv(10000,-10000,0,0,0,0);
		    Wait(2100);

}
void st(void){

	Mtr_Run_lv(0,0,0,0,0,0);
}
int motor(void)
{
	go();
	ro();
	go();
	ro();
	go();
	ro();
	go();
    st();
return 0;
}
int main(){
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	motor();

	return 0;

}

