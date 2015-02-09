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
#define PAUSE 100
#define VOL 100
#define DO    179
#define XX    0

void motor(short left, short right) {
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void) {
	motor(0,0);
	Wait(100);
}

void end(void){
	motor(0,0);
}

void forward(int mm) {
	motor(LEFT_POWER, RIGHT_POWER);
	Wait(MM * mm);
	stop();
}

void turn(int dir) {
	if (dir == LEFT_EYE) {
		motor(LEFT_POWER,RIGHT_POWER/3);
	} else if (dir == RIGHT_EYE) {
		motor(LEFT_POWER/3,RIGHT_POWER);
	}
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

void buzzer(int bs){
	int n;

	for(n=0;n<=bs;n++){
		play(DO);
	}
}




int main(void) {
	int blacks=0;
	const unsigned short MainCycle = 60;
	Init(MainCycle);

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
						end();
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

	end();
	return 0;
}






















