#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define R_pw 	15500
#define L_pw 	15000
#define R_eye 	1
#define L_eye	0

#define MM		40
#define SS		5
#define BLACK	500

#define WW    	1440 //全音符 whole note
#define PAUSE	20
#define VOL 	100

#define DO    	179
#define RE    	160
#define MI    	142
#define FA    	134
#define SO    	120
#define RA    	107
#define SI    	95
#define NN    	0

#define XX    	(-1)



void led_flash(int time)
{
	LED(3);
	Wait(time-50);
	LED(0);
	Wait(50);
}
/*
void led_flash(int time) //play用
{
	int i;
	for(i=0; i<time/60; i++){
		LED(3);
		Wait(40);
		LED(0);
		Wait(20);
	}
}
*/
void play(int pitch, int time)
{
	if (pitch == NN) {
		led_flash(time);
		Wait(PAUSE);
	} else {
		BuzzerSet(pitch, VOL);
		BuzzerStart();
		led_flash(time);
		BuzzerStop();
		Wait(PAUSE);
	}
}


void music(int notes_P[], int notes_T[])
{
	int i;

	for (i=0; notes_P[i]!=XX; i++) {
		play(notes_P[i], notes_T[i]);
	}
}

void FF(void)
{
	int notes_P[] = {RA,RA,RA,RA,FA,SO,RA,NN,SO,RA,XX};
	int notes_T[] = {WW/12,WW/12,WW/12,WW/4,WW/4,WW/4,WW/8,WW/16,WW/16,WW*3/4};

	music(notes_P, notes_T);
}




void sw_on(void)
{
	for(;;){
		if (getSW() == 1){
			break;
		}
	}
}

void sw_off(void)
{
	for(;;){
		if (getSW() != 1){
			return;
		}
	}
}

void sw_on_off(int n)
{
	sw_on();
	sw_off();
	Wait(n*1000);
}

void run(int right, int left, int time)
{
	Mtr_Run_lv(right, -left, 0, 0, 0, 0);
	Wait(time);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void led_run(int right, int left, int time, int n)
{
	int i;
	Mtr_Run_lv(right, -left, 0, 0, 0, 0);
	for(i=0; i<n; i++){
		LED(i%2+1);
		Wait(time/n); //Waitの引数は17以上
		LED(0);
	}
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void step(void)
{
	run(R_pw, L_pw, MM);
}

void led_step(void)
{
	led_run(R_pw, L_pw, MM, 2);
}

void stop(void)
{
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void turn(int deg)
{
	if (deg > 0){
		run(-R_pw / 5, L_pw, SS * deg);
	} else {
		run(R_pw, -L_pw / 5, SS * -deg);
	}
}

void led_turn(int deg)
{
	if (deg > 0){
		led_run(-R_pw / 5, L_pw, SS * deg, 2);
	} else {
		led_run(R_pw, -L_pw / 5, SS * -deg, 2);
	}
}

void finish(int deg)
{
	run(R_pw, -L_pw, SS * deg / 2);
}

int right_black(void){
	return ADRead(R_eye) > BLACK;
}

int left_black(void){
	return ADRead(L_eye) > BLACK;
}

int both_black(void){
	return right_black() && left_black();
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for(;;){
		sw_on_off(1);
		for(;;){
			if (both_black()){
				break;
			} else if (right_black()){
				led_turn(7);
			} else if (left_black()){
				led_turn(-7);
			} else {
				led_step();
			}
		}
		stop();
		Wait(500);
		finish(720);
		FF();
	}

	return 0;
}

