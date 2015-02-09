#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT 8200*1.5
#define RIGHT 10000*1.5

#define X 25
#define Y 60
#define N 4000

#define l 1

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
#define XX  (-1)


#define LEFT_POWER  10000
#define RIGHT_POWER 10000
#define LEFT_EYE    0
#define RIGHT_EYE   1

#define BLACK 500

void play (int pitch){
	if(pitch==NN){
		BuzzerSet(pitch,VOL);
		BuzzerStart();
		Wait(DURATION+PAUSE);
		BuzzerStop();
	}
}
void music(int notes[])
{
	int i;
	for (i=0; notes[i]!=XX; i++){
		play (notes[i]);
	}
}

void kaeru(void)
{
	int notes[]={DO,RE,MI,FA,MI,RE,DO,NN,
MI,FA,SO,RA,SO,FA,MI,NN,
DO,NN,DO,NN,DO,NN,DO,NN,
DO,DO,RE,RE,MI,MI,FA,FA,MI,NN,RE,NN,DO,XX};


}

void motor(short right, short left)
{
	Mtr_Run_lv(right,-left,0,0,0,0);
}

void go(int a){
	motor(RIGHT,LEFT);
	LED(3);
	Wait(X*a);
}

void right_turn(int b){
	motor(RIGHT,0);
	LED(1);
	Wait(Y*b);
}
void left_turn(int b){
	motor(0,LEFT);
	LED(2);
	Wait(Y*b);
}

void stop(void) {
    motor(0,0);
    LED(0);
    Wait(100);
}


int is_black_left(void) {
    return ADRead(LEFT_EYE) > BLACK;
}

int is_black_right(void) {
    return ADRead(RIGHT_EYE) > BLACK;
}

int is_black(void) {
    return (is_black_left() && is_black_right());
}

int main(void) {
    const unsigned short MainCycle = 60;
    Init(MainCycle);

    int i;
    Wait(1000);

    for(i=0; i<N; i++){
    	go(l);
    	if(is_black_left()){
    		left_turn(2);
    	}
    	else if(is_black_left()){
    		right_turn(2);
    	}
    	if(is_black()){
    		break;
    	}
    }
    stop();

    kaeru();

    return 0;
}


