#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define R_pw 15500
#define L_pw 15000
#define R_eye 1
#define L_eye 0

#define MM 40
#define SS 5
#define BLACK 500


#define DURATION 100
#define PAUSE 50
#define VOL 100

#define DO    179
#define RE    160
#define MI    142
#define FA    134
#define SO    120
#define RA    107
#define SI    95
#define NN    0

#define XX    (-1)



void led_flash(void) //play用
{
	int i;
	for(i=0; i<2; i++){
		LED(3);
		Wait(DURATION/4);
		LED(0);
		Wait(DURATION/4);
	}
}

void play(int pitch)
{
	if (pitch == NN) {
		BuzzerStop();
		led_flash();
		Wait(PAUSE);
	} else {
		BuzzerSet(pitch, VOL);
		BuzzerStart();
		led_flash();
		BuzzerStop();
		Wait(PAUSE);
	}
}

void music(int notes[])
{
	int i;

	for (i=0; notes[i]!=XX; i++) {
		play(notes[i]);
	}
}

void FF(void)
{
	int notes[]={RA,RA,RA,RA,NN,NN,FA,NN,NN,SO,NN,NN,RA,NN,SO,RA,XX};

	music(notes);
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
	return ADRead(R_eye) > BLACK && ADRead(L_eye) > BLACK;
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

