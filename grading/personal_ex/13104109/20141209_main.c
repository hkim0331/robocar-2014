#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  10000
#define RIGHT_POWER 11000
#define LEFT    1
#define RIGHT   0

#define LED_LEFT 2
#define LED_RIGHT 1

#define MM 20       // 1mm 進むための時間
#define Black 910   // 白黒判断の境界値
#define glay  600

void beep(void) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
}

void motor(short Right, short Left) {
    Mtr_Run_lv(Right, -Left, 0, 0, 0, 0);
}

void stop(void) {
    motor(0,0);
}

void go(void){
	motor(RIGHT_POWER, LEFT_POWER);
}

void turnleft(void){
	LED(LED_LEFT);
	motor(RIGHT_POWER,0);
}

void turnright(void){
	LED(LED_RIGHT);
	motor(0,LEFT_POWER);
}

void forward(int mm) {
    LED(LED_LEFT + LED_RIGHT);
    motor(RIGHT_POWER, LEFT_POWER);
    Wait(MM * mm);//1mmの時間＊５
    stop();
}

void step(int n) {
    forward(n); // forward nmm
    beep();
    stop();
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for (; ; ) { // 無限ループ

		unsigned short left, right;
				left = ADRead(LEFT); // ADRead()の値をleftに書き換える
				right = ADRead(RIGHT);
				if((left>Black)&&(right>Black)){
					turnleft();
					Wait(500);
					if((left>Black)&&(right>Black)){
					break;}
				    }else if(left>Black){
				    	turnleft();
                    }else if(right>Black){
					    turnright();
				    }else if((right>glay)&&(left>glay)){
				    	 step(5);
				    }else{
				    	go();
				    }
			     }
	        turnright();
	        Wait(500);
			stop();
	return 0;
}

