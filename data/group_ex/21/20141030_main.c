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

#define NN    1

#define XX    0

void play(int pitch)
{
if (pitch == NN){
	BuzzerStop();
	Wait(DURATION + PAUSE);
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
	int s[]={DO,RE,MI,FA,MI,RE,DO,NN,
			MI,FA,SO,RA,SO,FA,MI,NN,
			DO,NN,DO,NN,DO,NN,DO,NN,
			DO,DO,RE,RE,MI,MI,FA,FA,MI,RE,DO,NN};
	int i;

	for (i=0; s[i]!=XX; i++){
		play(s[i]);
	}
}




#define LEFT   10000
#define RIGHT  10000

#define N 500

#define FW 100


void motor(short left, short right)
{
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
  motor(0, 0);
  Wait(1000);
}

void step(void)
{
  motor(LEFT, RIGHT);
  Wait(FW);

}

void look(void)
{
	unsigned short c;
    c= ADRead(0);
  if(c>700){kirakira();}

}


int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);

  Wait(1000);
  int i;

  for (i = 0; i < N; i++) {
    step();
    stop();

   look();

  }






  return 0;
}
