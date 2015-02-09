#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  10000
#define RIGHT_POWER 10500
#define LEFT    1
#define RIGHT   0
#define GO 500

#define LED_LEFT 2
#define LED_RIGHT 1

#define BLACK 500
#define pitch 120
#define VOL 100

void motor(short left, short right) {
	Mtr_Run_lv(-left, right, 0, 0, 0, 0);
}

void stop(void) {
	motor(0,0);
}

void forward(void) {
	LED(LED_LEFT + LED_RIGHT);
	motor(LEFT_POWER, RIGHT_POWER);
	Wait(GO);
	stop();
}

void turn(int dir) {
	if (dir == LEFT) {
		LED(LED_LEFT);
		motor(LEFT_POWER/3,RIGHT_POWER);
	} else if (dir == RIGHT) {
		LED(LED_RIGHT);
		motor(LEFT_POWER,RIGHT_POWER/3);
	}
}

void step(void) {
	forward();
	stop();
}

int is_black(int n) {
	return ADRead(n) > BLACK;
}

int is_white(int n) {
	return ! is_black(n);
}

void sound(void){
	BuzzerSet(pitch,VOL);
	BuzzerStart();
	Wait(200);
	BuzzerStop();
	Wait(100);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	int blackcount=0;
	int i;
	Wait(1000);
	for (;;) {
		if (is_white(LEFT) && is_white(RIGHT)) {
			stop();
			if(2<blackcount && blackcount<8 ){
				i=0;
				while(i<blackcount){
					sound();
					i++;
				}
				stop();
				break;
			}
			else if(blackcount<2){
				i=0;
				while(i<blackcount){
					sound();
					i++;
				}
				blackcount=0;
			}
			else{
				i=0;
				while(i<blackcount){
					sound();
					i++;
				}
				blackcount=0;
			}
			step();
		}
		else if (is_black(LEFT) && is_black(RIGHT)) {
			blackcount += 1;
			step();

		} else if (is_black(LEFT)) {
			turn(LEFT);
		} else if (is_black(RIGHT)) {
			turn(RIGHT);
		} else {
			;
		}
	}
	stop();
	return 0;

}

