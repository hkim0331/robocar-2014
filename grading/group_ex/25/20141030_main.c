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

#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT   30000
#define RIGHT  30000


#define EDGE 1


#define N 50000

// 1cm 進む時間と1度 回る時間(msec)
// これらの値は実験で求める。ロボカーによって異なる。
#define FW 40


void motor(short left, short right)
{
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
  motor(0, 0);
  Wait(500);

}

void forward(int n)
{
  motor(LEFT, RIGHT);
  Wait(FW * n);
  stop();
}



int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);

  Wait(1000);
  int i;
  unsigned short bw;

  for (i = 0; i < N; i++) {
    forward(EDGE);
     bw = ADRead(0);
    if (bw>500) {
    	  break;
    } else {
    	;
    }
  }
  kaeru();



  return 0;
}
