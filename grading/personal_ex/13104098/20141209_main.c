#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_P 10000
#define RIGHT_P 10000
#define LEFT 0
#define RIGHT 1
#define LED_L 2
#define LED_R 1
#define N 20
#define BLACK 500

void motor(short left,short right)
{
Mtr_Run_lv(left,-right,0,0,0,0);
}



void stop(void)
{
motor(0,0);
}

void forward(int n)
{
motor(LEFT,RIGHT);
Wait(N * n);
stop();
}

void turn(int dir) {
    if (dir == LEFT) {
        LED(LED_L);
        motor(LEFT_P/10,RIGHT_P);
    } else if (dir == RIGHT) {
        LED(LED_R);
        motor(LEFT_P,RIGHT_P/10);
    }
}

void step(int n)
{
forward(n);
stop();
}

int is_black(n){
	return ADRead(n) > BLACK;
}
int is_white(n){
	return ! is_black(n);
}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for(;;){
		if(is_white(LEFT) && is_white(RIGHT)){
			step(10);
			Wait(500);
		}else if(is_black(LEFT) && is_black(RIGHT)){
			turn(10);
			Wait(500);
		}else if (is_white(RIGHT)){
			turn(RIGHT);
		}else if(is_white(LEFT)){
			turn(LEFT);
		}
	}


	return 0;
}

