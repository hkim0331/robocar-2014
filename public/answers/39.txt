#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

/*車輪にかける力。ロボカーNO.13*/
#define Left    8000
#define Right   8000

/*繰り返し回数*/
#define N 100

/*1cm進むのにかかる時間*/
#define Forward 48.3

/*ステップで進む距離*/
#define STEP 0.5

/*継続時間*/
#define WAIT 500

/*黒と判断する境界*/
#define Blackborder 500

/*ADReadの左と右*/
#define Read_left 0
#define Read_right 1

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
#define NN    1

#define DO1    179
#define RE1    160
#define MI1    142
#define FA1    134
#define XX    0

void play(int pitch)
{
	if (pitch == NN){
		BuzzerStop();
		Wait(DURATION + PAUSE);
	}else if(pitch == DO1 || RE1 || MI1 || FA1){

		BuzzerSet(pitch, VOL);
		BuzzerStart();
		Wait(DURATION/2);
		BuzzerStop();
		Wait(PAUSE);
	}else{
		BuzzerSet(pitch, VOL);
		BuzzerStart();
		Wait(DURATION);
		BuzzerStop();
		Wait(PAUSE);
	}
}



void kirakira(void)
{
	int s[]={DO,DO,SO,SO,RA,RA,SO,XX};
	int i;

	for(i=0; s[i]!=XX; i++)
	{
		play(s[i]);
	}
}

void gerogero(void)
{
	int s[]={DO,RE,MI,FA,MI,RE,DO,NN,
			MI,FA,SO,RA,SO,FA,MI,NN,
			DO,NN,DO,NN,DO,NN,DO,NN,
			DO,DO,RE,RE,MI,MI,FA,FA,MI,NN,RE,NN,DO,XX};
	int i;

	for(i=0; s[i]!=XX; i++)
	{
		play(s[i]);
	}
}

void motor(short left, short right)
{
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
	motor(0, 0);
	Wait(WAIT);
}

void forward(double n)
{
	motor(Left, Right);
	Wait(WAIT/2);
	stop();
}

int Readcolor_L(void)
{
	return ADRead(Read_left) > Blackborder;
}

int Readcolor_R(void)
{
	return ADRead(Read_right) > Blackborder;
}

int Readcolor(void)
{
	return (Readcolor_L() || Readcolor_R());

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	LED(3);
	Wait(1000);
	for (;;) {

		if( Readcolor_L()==0 && Readcolor_R()==1){
			motor(0,Right);
			LED(1);
		}else if(Readcolor_L()==1 && Readcolor_R()==0){
			motor(Left,0);
			LED(2);
		}else if(Readcolor_L()==0 && Readcolor_R()==0){
			motor(Left,Right);
			LED(3);
		}else if( Readcolor_L()==1 && Readcolor_R()==1){
			stop();
			LED(0);
			gerogero();
		}


	}

	return 0;
}

