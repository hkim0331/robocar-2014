#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define DURATION 400
#define PAUSE 100
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
#define LEFT  8000
#define RIGHT 8000
#define LEFT_EYE    0
#define RIGHT_EYE   1

#define MM 20
#define BLACK 500

int duration = DURATION;
int pause    = PAUSE;


void play(int pitch)
{
	if (pitch == NN) {
		BuzzerStop();
		Wait(duration + pause);
	} else {
		BuzzerSet(pitch, VOL);
		BuzzerStart();
		Wait(duration);
		BuzzerStop();
		Wait(pause);
	}
}void music(int notes[])
{
	int i;

	for (i=0; notes[i]!=XX; i++) {
		play(notes[i]);
	}
}

void kaeru(void)
{
	int notes1[]={DO,RE,MI,FA,MI,RE,DO,NN,
			MI,FA,SO,RA,SO,FA,MI,NN,
			DO,NN,DO,NN,DO,NN,DO,NN,XX};
	int notes2[]={DO,DO,RE,RE,MI,MI,FA,FA,XX};
	int notes3[]={MI,RE,DO,XX};

	music(notes1);

	duration = DURATION/2;
	pause    = PAUSE/2;
	music(notes2);

	duration  = DURATION;
	pause     = PAUSE;
	music(notes3);
}

void motor(short left, short right)
{
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void) {
	motor(0,0);
}

int is_black_left(void) {
	return ADRead(LEFT_EYE) > BLACK;
}

int is_black_right(void) {
	return ADRead(RIGHT_EYE) > BLACK;
}
int is_black(void) {
	return (is_black_left() || is_black_right());
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	for(;;){
		if( is_black_left()==0&&is_black_right()==0){
			motor(LEFT,RIGHT);
		}else if(is_black_left()==1&&is_black_right()==0){
			motor(0,RIGHT);
		}else if(is_black_left()==0&&is_black_right()==1){
			motor(LEFT,0);
		}else if(is_black_left()==1&&is_black_right()==1){
			stop();

		}
	}return 0;
}

