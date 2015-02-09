#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define LEFT 10000
#define RIGHT 10000
#define LED_LEFT 2
#define LED_RIGHT 1

#define MM 20       // 1mm 進むための時間
#define BLACK 500   // 白黒判断の境界値

void motor(short left ,short right){

	Mtr_Run_lv(left,-right,0,0,0,0);

}

void stop(void){

	motor(0,0);

}
void forword(void){

	motor(LEFT,RIGHT);
	Wait(500);
	stop();

}

void forword1(int mm){

	   LED(LED_LEFT + LED_RIGHT);
	    motor(LEFT, RIGHT);
	    Wait(MM * mm);
	    stop();
}

void  turnL(void){

	motor(0,RIGHT);
	Wait(500);
	stop();

}

void turnR(void){

	motor(LEFT,0);
	Wait(500);
	stop();

}
void step(int n) {
    forward(n); // forward nmm
    stop();
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	 int i;
	    int n;
	    n = 500;
	    for(i=0;i<10000;i++){
	    	unsigned short Left,Right;
	    	Left = ADRead(0);
	    	Right = ADRead(1);

	    if(Left<n&&Right<n){

	    	forword1(5);

	    }
	    else if(Left>n&&Right<n){

	    	turnL();

	    }
	    else if(Left<n&&Right>n){

	    	turnR();

	    }
	    else if(Left>n&&Right>n){

	    	stop();

	    }
	    else if(Left<=300&&Left>=100&&Right<=300&&Right>=100){

	    	forword();

	    }
	    }
	return 0;
}

