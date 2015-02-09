#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

/*車輪にかける力。ロボカーNO.13*/
#define Left    8000
#define Right   8000

/*黒と判断する境界*/
#define Blackborder 500

/*ADReadの左と右*/
#define Read_left 0
#define Read_right 1

/*1cm進むのにかかる時間*/
#define Forward 48.3

/*継続時間*/
#define WAIT 500

void motor(short left, short right)
{
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
	motor(0, 0);
	Wait(WAIT);
}

int Readcolor_L(void)
{
	return ADRead(Read_left) > Blackborder;
}

int Readcolor_R(void)
{
	return ADRead(Read_right) > Blackborder;
}

int Readcolor(void)
{
	return (Readcolor_L() || Readcolor_R());

}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	LED(3);
	Wait(1000);
	for (;;) {

		if( Readcolor_L()==0 && Readcolor_R()==1){
			motor(0,Right);
			LED(1);
		}else if(Readcolor_L()==1 && Readcolor_R()==0){
			motor(Left,0);
			LED(2);
		}else if(Readcolor_L()==0 && Readcolor_R()==0){
			motor(Left,Right);
			LED(3);
		}else if( Readcolor_L()==1 && Readcolor_R()==1){
			stop();
			LED(0);

		}
		stop();
	}



	return 0;
}


