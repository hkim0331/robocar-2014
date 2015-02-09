#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define RIGHT 10000
#define LEFT 10600
#define EDGE 30
#define FW 40

void motor(short left, short right)
{
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
  motor(0, 0);
}

#define DO 179
#define RE 160
#define MI 142
#define FA 134
#define SO 120
#define RA 107
#define SI 95
#define NN 200
#define XX 0

void play(int pitch ,int VOL ,int DURATION ,int PAUSE)
{
	if(pitch == NN){
		BuzzerStop();
		Wait(PAUSE);
		Wait(DURATION);
	}

	if(pitch != NN){
	BuzzerSet(pitch,VOL);
	BuzzerStart();
	Wait(DURATION);
	BuzzerStop();
	Wait(PAUSE);
	}
}

void gerogeero(void)
{
	int N = 400;
	int H = 200;
	int n = 100;
	int h = 50;
	int s[]={DO,RE,MI,FA,MI,RE,DO,NN,
			MI,FA,SO,RA,SO,FA,MI,NN,
			DO,NN,DO,NN,DO,NN,DO,NN,DO,DO,RE,RE,MI,MI,FA,FA,MI,RE,DO,NN,XX};
	int a[]={N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,H,H,H,H,H,H,H,H,N,N,N,N,XX};
	int b[]={n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,h,h,h,h,h,h,h,h,n,n,n,n,XX};

	int i;

	for(i=0; s[i]!=XX; i++){
		play(s[i],100,a[i],b[i]);
	}
}

void kuronisou(void)
{
	  while(1){
		  unsigned short bwright,bwleft;
		  bwright = ADRead(0);
		  bwleft = ADRead(1);

		  if(bwright<500 && bwleft<500){
			  motor(LEFT,RIGHT);
		  }
		  else if(bwright >500 && bwleft>500)
		  {stop();
		  gerogeero();
	  }

		  else if(bwright<500 && bwleft>=500){
		  motor(0,RIGHT);
	  }
		  else if(bwleft<500 && bwright>=500){
		  motor(LEFT,0);
	  }
		 }
}

void step(void)
{

	 Wait(1000);
	  while(1){
	  motor(LEFT,RIGHT);
	  Wait(FW*5);
	  stop();
	  Wait(FW*5);


	  }

}


void tyarenjijima(void)

{	int Bwleft,Bwright ;
	Bwright = ADRead(0);
	Bwleft = ADRead(1);
	int k=0;
	step();
	}



int main(void)
{


 unsigned short MainCycle = 60;
  Init(MainCycle);


while(1)
{

	step();


	}



  return 0;
}
