#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  10000
#define RIGHT_POWER 11250
#define LEFT    1
#define RIGHT   0

#define LED_LEFT 2
#define LED_RIGHT 1
#define MM 20       // 1mm 進むための時間
#define BLACK 500  // 白黒判断の境界値
#define DURATION 400
#define PAUSE 100
#define VOL 100
#define SO    120
#define XX    0
int blacks=0;

void play(int pitch)
{

	BuzzerSet(pitch, VOL);
	BuzzerStart();
	Wait(DURATION);
	BuzzerStop();
	Wait(PAUSE);
}
void buzzer(int a){
	int i;
	for(i=0; i<=a; i++)
		play(SO);
}


void motor(short left, short right) {
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void) {
	motor(0,0);
}

void forward(int mm) {

	motor(LEFT_POWER, RIGHT_POWER);
	Wait(MM * mm);
	stop();
}

void turn(int dir) {
	if (dir == LEFT) {

		motor(LEFT_POWER/3,RIGHT_POWER);
	} else if (dir == RIGHT) {

		motor(LEFT_POWER,RIGHT_POWER/3);
	}
}

void step(int n) {
	forward(n); // forward nmm

	stop();
}

int is_black(int n) {
	return ADRead(n) > BLACK;
}

int is_white(int n) {
	return ! is_black(n);
}
int length(void){
	for (;;) {
			if (is_white(LEFT) && is_white(RIGHT)) {
				blacks=0;

				step(5);
			}

			else if (is_black(LEFT) && is_black(RIGHT)) {
				for (;;) {
					blacks += 1;
					step(5);
					Wait(100);
					if (is_white(LEFT) && is_white(RIGHT)) {
						stop();
						break;
					}
					else if (is_black(LEFT)) {
						turn(LEFT);
					} else if (is_black(RIGHT)){
						turn(RIGHT);
					}
					else {
						; // 安全のための else
					}
				}
				if(blacks > 17){
					stop();
					buzzer(blacks);
				}
				if(blacks > 7 && blacks < 15){
					break;
				}

				else {
					;
				}


			}

			else if (is_black(LEFT)) {
				blacks=0;
				turn(LEFT);
			} else if (is_black(RIGHT)) {
				blacks=0;
				turn(RIGHT);
			}
			else {
				; // 安全のための else
			}
		}
}

int main(void) {
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait( 1000 );
	length();
	stop();
	buzzer( blacks );
	return 0;
}
