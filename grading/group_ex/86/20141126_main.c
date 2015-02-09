#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  10500
#define RIGHT_POWER 10000
#define LEFT  0
#define RIGHT 1
#define BLACK 500
#define LED_LEFT 2
#define LED_RIGHT 1
#define DURATION 120

void motor(short left, short right){
	Mtr_Run_lv(left,-right,0,0,0,0);
}

void stop(void){
	motor(0,0);
}
void Buzzer(void){
	BuzzerSet(179,50);
	BuzzerStart();
	Wait(400);
	BuzzerStop(DURATION);
}
void turn(int dir){
	if(dir == LEFT){
		LED(LED_LEFT);
		motor(LEFT_POWER,RIGHT_POWER/5);
	}else if(dir == RIGHT){
		LED(LED_RIGHT);
		motor(LEFT_POWER/5,RIGHT_POWER);
	}
}
void step(){
	LED(LED_LEFT + LED_RIGHT);
	motor(LEFT_POWER,RIGHT_POWER);
	Wait(DURATION);
	stop();
	Wait(5*DURATION);
}


int black(int n){
	return ADRead(n) > BLACK;
}

int white(int n){
	return ! black(n);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int blacks=0;
	Wait(1000);
	for( ; ;){
		if(black(LEFT) && black(RIGHT)){
					blacks +=1;
					step();
					Buzzer();
					if(blacks > 18 && white(LEFT)){
						step();
						blacks=0;
					}
					else if(blacks >= 4 && blacks <=18  && white(LEFT)){
						break;
					}
					else{
						;
					}
				}

		else if(white(LEFT) && white(RIGHT)){
			step();
		}

		else if(black(LEFT)){
			turn(LEFT);
		}
		else if(black(RIGHT)){
			turn(RIGHT);
		}
		else{
			;
		}
	}
LED(0);
stop();

	return 0;
}

