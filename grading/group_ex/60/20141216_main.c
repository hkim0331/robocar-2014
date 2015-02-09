#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define LEFT_POWER  10000
#define RIGHT_POWER 10500
#define LEFT    1
#define RIGHT   0
#define LED_LEFT 2
#define LED_RIGHT 1
#define MM 20       // 1mm 進むための時間
#define BLACK 700 // 白黒判断の境界値
#define GRAY 310

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

void half_forward(int mm) {
	motor(LEFT_POWER/2, RIGHT_POWER/2);
	Wait(MM * mm);
	stop();
}

void turn(uint8_t dir) {
	if (dir == LEFT) {
		LED(LED_LEFT);
		motor(LEFT_POWER/3,RIGHT_POWER);
	} else if (dir == RIGHT) {
		LED(LED_RIGHT);
		motor(LEFT_POWER,RIGHT_POWER/3);
	}
}
void spin(uint8_t dir){
	if (dir == LEFT) {
		LED(LED_LEFT);
		motor(-LEFT_POWER,RIGHT_POWER);
	} else if (dir == RIGHT) {
		LED(LED_RIGHT);
		motor(LEFT_POWER,-RIGHT_POWER);
	}

}

void CRANK(uint8_t dir) {
	if (dir == LEFT) {
		LED(LED_LEFT);
		motor(-LEFT_POWER/10,RIGHT_POWER);
	} else if (dir == RIGHT) {
		LED(LED_RIGHT);
		motor(LEFT_POWER,-RIGHT_POWER/10);
	}
}
void step(int n) {
	forward(n); // forward nmm
}

void half_step(int n) {
	half_forward(n);
}

void back(int mm) {
	motor(-LEFT_POWER, -RIGHT_POWER);
		Wait(MM * mm);
		stop();
}

int is_black(uint8_t n) {
	return ADRead(n) > BLACK;
}

int is_gray(uint8_t n){
	return ADRead(n) < BLACK && ADRead(n) > GRAY;
}

int is_white(uint8_t n) {
	return ADRead(n) < GRAY;
}

void BLACKBLACK() {
	for(;;){
		LED(3);
		Wait(100);
		LED(0);
		step(5);
		Wait(100);
		if(is_white(LEFT) && is_white(RIGHT)){
			break;
		}else {
			;
		}
	}
}

void GRAY_ZONE(){
	LED(3);
	Wait(100);
	LED(0);
	half_step(5);
	Wait(100);
	if(is_gray(LEFT) && is_white(RIGHT)) {
		turn(RIGHT);
	}else if(is_white(LEFT) && is_gray(RIGHT)) {
		turn(LEFT);
	}
}

void Buzzer(){
	BuzzerSet(179,100);
		BuzzerStart();
		Wait(250);
		BuzzerStop();
}

int blacks=0;

void RUN(){

	Wait(1000);
	for (;;) {
		if (is_white(LEFT) && is_white(RIGHT)) {
			LED(0);
			step(5);
			Wait(100);
		}else if(is_black(LEFT) && is_black(RIGHT)) {
			BLACKBLACK();
			blacks += 1;
		}else if(is_black(LEFT) && is_black(RIGHT) && blacks==4){
			CRANK(RIGHT);
		}else if(is_black(LEFT) && is_black(RIGHT) && blacks==7){
			step(50);
			break;
		}else if(is_black(LEFT) && is_white(RIGHT)){
			Buzzer();
			back(5);
			turn(LEFT);
			//spin(LEFT);
		}else if(is_white(LEFT) && is_black(RIGHT)){
			Buzzer();
			back(5);
			turn(RIGHT);
			//spin(RIGHT);
		}else if(is_gray(LEFT) && is_gray(RIGHT)) {
			GRAY_ZONE();
		}else if((is_gray(LEFT) && is_white(RIGHT)) ||
				(is_white(LEFT) && is_gray(RIGHT))) {
			step(5);
		}else {
			;
		}
	}

	stop();

}

int main(void){
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	RUN();
	return 0;
}

