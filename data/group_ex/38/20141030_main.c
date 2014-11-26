#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT 8200
#define RIGHT 10000

#define x 50
#define y 60
#define N 400

#define length 5

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

#define LEFT_EYE 0
#define RIGHT_EYE 1

#define BLACK_THRES 500

void play(int pitch)
{
    if (pitch==NN) {
        BuzzerStop();
        Wait(DURATION+PAUSE);
    } else {
        BuzzerSet(pitch, VOL);
        BuzzerStart();
        Wait(DURATION);
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

void kaeru(void)
{
    int notes[]={DO,RE,MI,FA,MI,RE,DO,NN,
            MI,FA,SO,RA,SO,FA,MI,NN,
            DO,NN,DO,NN,DO,NN,DO,NN,
            DO,DO,RE,RE,MI,MI,FA,FA,MI,NN,RE,NN,DO,XX};

  music(notes);
}

void motor(short right, short left)
{
  Mtr_Run_lv(right, -left, 0, 0, 0, 0);
}

void go(int a)
{
	motor(RIGHT, LEFT);
	Wait(x*a);
}

void right_turn(int b)
{
	motor(RIGHT, 0);
	Wait(y*b);
}

void left_turn(int b)
{
	motor(0, LEFT);
	Wait(y*b);
}

void stop()
{
	motor(0, 0);
	Wait(200);
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
	return (is_black_left() || is_black_right());
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;

	Wait(1000);

	for(i=0; i<N; i++)
	{
		go(length);
		stop();
		if (is_black()) {
			break;
		}
	}

	kaeru();

	return 0;
}

