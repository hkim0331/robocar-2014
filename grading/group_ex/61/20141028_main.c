#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

/*5秒間前へ*/
void exp1(){
	Mtr_Run_lv(10000,-10000,0,0,0,0);/*進め(それぞれのモーターに対応)*/
	Wait(5000);              /*秒*/
	Mtr_Run_lv(0,0,0,0,0,0); /*止まれ*/

}

/*2秒後に動く*/
void exp2(){
	Wait(2000);
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(5000);
	Mtr_Run_lv(0,0,0,0,0,0);
}

/*1cm前進*/
void exp3(){
	Mtr_Run_lv(10000,-10000,0,0,0,0);
		Wait(60);
		Mtr_Run_lv(0,0,0,0,0,0);
}

/*10cm前進*/
void exp4(){
	Mtr_Run_lv(10000,-10000,0,0,0,0);
		Wait(550);
		Mtr_Run_lv(0,0,0,0,0,0);
}

/*5cm後退*/
void exp5(){
	Mtr_Run_lv(-10000,10000,0,0,0,0);
		Wait(280);
		Mtr_Run_lv(0,0,0,0,0,0);
}

/*90°右回転*/
void exp6(){
	Mtr_Run_lv(-10000,-10000,0,0,0,0);
		Wait(470);
		Mtr_Run_lv(0,0,0,0,0,0);
}

/*360°左回転*/
void exp7(){
	Mtr_Run_lv(10000,10000,0,0,0,0);
		Wait(1890);
		Mtr_Run_lv(0,0,0,0,0,0);
}

/*30cm善心*/
void exp8(){
	Mtr_Run_lv(10000,-10000,0,0,0,0);
		Wait(1800);
		Mtr_Run_lv(0,0,0,0,0,0);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

    //exp1();
	//exp2();
	//exp3();
	//exp4();
	//exp5();
	//exp6();
	//exp7();

	exp8();
	exp6();
	exp8();
	exp6();
	exp8();
    exp6();
    exp8();
    exp6();


	return 0;
}

