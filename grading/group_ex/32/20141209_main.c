#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER 10000
#define RIGHT_POWER 10000
#define LEFT_EYE 0
#define RIGHT_EYE 1

#define MM 20
#define BLACK 500

#define DURATION 400
#define PAUSE 150
#define VOL 100
#define SO    120
#define XX    0

void motor(short left, short right) {
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}
void stop(void) {
	motor(0,0);
	Wait(100);
}

void forward(int mm) {
	motor(LEFT_POWER, RIGHT_POWER);
	Wait(MM * mm);
	stop();
}

void turn(int d) {
	if (d == LEFT_EYE) {
		motor(LEFT_POWER,0);
	} else if (d == RIGHT_EYE) {
		motor(0,RIGHT_POWER);
	}
}

void finish(void){
	motor(0,0);
}

void step(int n) {
	forward(n);
	stop();
}

int is_black(int n) {
	return ADRead(n) > BLACK;
}

int is_white(int n) {
	return ! is_black(n);
}

void play(int pitch)
{
	BuzzerSet(pitch, VOL);
	BuzzerStart();
	Wait(DURATION);
	BuzzerStop();
	Wait(PAUSE);
}

void buzzer(int b){
	int n;
	for(n=0;n<=b;n++){
		play(SO);
	}
}
void motor2(void){
	int blacks=0;
	Wait(1000);
	for (;;){
		if (is_white(LEFT_EYE) && is_white(RIGHT_EYE)) {
			step(5);
			Wait(500);

		} else if (is_black(LEFT_EYE) && is_black(RIGHT_EYE)) {
			blacks=0;
			for(;;){

				if (is_black(LEFT_EYE) && is_black(RIGHT_EYE))	{
					blacks+=1;
					step(5);
				}else{
					if(blacks>=10){
						buzzer(blacks);
						break;
					}else if(4<=blacks && blacks<10){
						buzzer(blacks);
						finish();
					}else{
						break;
					}
				}
			}
		}
		else if (is_black(LEFT_EYE)) {
			turn(LEFT_EYE);
		} else if (is_black(RIGHT_EYE)) {
			turn(RIGHT_EYE);
		} else {
			;
		}
	}
	finish();
}
int main(void) {
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	motor2();
	return 0;
}
