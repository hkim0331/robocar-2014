#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT 10000
#define RIGHT 9050
#define go 10
#define N 5
#define FW 50
#define wait 100

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
#define XX    0

void play(int pitch)
{
    BuzzerSet(pitch, VOL);
    BuzzerStart();
    Wait(DURATION);
    BuzzerStop();
    Wait(PAUSE);
}

void kirakira(void)
{
    int notes[]={DO,DO,SO,SO,RA,RA,SO,XX};
    int i;

    for (i=0; notes[i]!=XX; i++) {
        play(notes[i]);
    }
}

void motor(short left, short right)
{
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
  motor(0, 0);
}

void step(int n)
{
  motor(LEFT, RIGHT);
  Wait(FW * n);
  stop();
}




int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);

  unsigned short bw;

  int i;
  for (i = 0; i < N; i++) {
    step(go);
    Wait(wait);
    bw=ADRead(0);
    if (bw>500){
    	kirakira();
    	break;
    }else{
    		;
    	}
    }


  return 0;
}
