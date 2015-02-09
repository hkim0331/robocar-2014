#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT 8000
#define RIGHT 10000

#define y 60

#define short_black 5
#define long_black 9

#define length 1

#define XX    (-1)

#define LEFT_EYE 0
#define RIGHT_EYE 1

#define BLACK_THRES 500

void play()
{
	BuzzerSet(120, 100);
	BuzzerStart();
	Wait(200);
	BuzzerStop();
}

void motor(short right, short left)
{
  Mtr_Run_lv(right, -left, 0, 0, 0, 0);
}

void go(int mm)
{
	motor(RIGHT, LEFT);
	LED(3);
	Wait(mm*150);
}

void stop()
{
	motor(0, 0);
	LED(0);
	Wait(150);
}

void step()
{
	go(length);
	stop();
}

void right_turn(int b)
{
	motor(RIGHT, 0);
	LED(1);
	Wait(y*b);
}

void left_turn(int b)
{
	motor(0, LEFT);
	LED(2);
	Wait(y*b);
}

int is_black_left(void)
{
	return ADRead(LEFT_EYE) > BLACK_THRES;
}

int is_black_right(void)
{
	return ADRead(RIGHT_EYE) > BLACK_THRES;
}

int is_black(void)
{
	return is_black_left() && is_black_right();
}

int is_white_left(void)
{
	return ADRead(LEFT_EYE) < BLACK_THRES;
}

int is_white_right(void)
{
	return ADRead(RIGHT_EYE) < BLACK_THRES;
}

int is_white(void)
{
	return is_white_left() && is_white_right();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i, j=0, blacks=0, record[3];

	Wait(1000);

	for(;;)
	{
		if(is_white()){
			if(blacks != 0){
				record[j] = blacks;
				j+=1;
			}
			if(long_black >= blacks && blacks >= short_black){
				break;
			}
			blacks=0;
			go(length);
		} else if(is_black()) {
			blacks+=1;
			step();
		} else if(is_black_right()){
			left_turn(2);
		} else if(is_black_left()){
			right_turn(2);
		}
	}
	stop();
	for(j=0; j<3; j++){
		for(i=0; i<record[j]; i++){
			play();
			Wait(250);
		}
		Wait(1000);
	}

	return 0;
}
