#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define RIGHT 10000
#define LEFT 10600
#define EDGE 30
#define FW 40
#define RMT 800
#define LMT 800
void motor(short left, short right)
{
  Mtr_Run_lv(right, -left, 0, 0, 0, 0);
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
	  Wait(FW*3);
	  stop();
	  Wait(FW*3);


	  }

}


void tyarenjijima(void)

{	int bwleft,bwright ;
	int i;
	int m=0;
	int n=1;
	while(n==1){
	step();
	bwright = ADRead(0);
	bwleft = ADRead(1);
	if((bwright>500)&&(bwleft>500))
	{

		m++;
			}
	if((m>0)&&(bwright<500)&&(bwleft<500))
	{
		for(i=0;i<m;i++)
		{
			play(DO,100,100,100);
			}

		if(m>3 && m<6){
		n=24;
		}
		if(m<3 && m>6){
		m=0;
		}
		}

	}
}

/*void iroyomitoruyo(void){
	int i,a[5],sum=0;
	for(i=0;i<5;i++){
		Wait(100);
		a[i] = ADRead(0);
		sum +=a[i]
	}

	}*/

void mae(int time){
	motor(LEFT,RIGHT);
	Wait(time);
	stop();
}

void migi(int time){
	motor(LEFT,0);
	Wait(RMT);
	stop();
	motor(LEFT,RIGHT);
	Wait(time);
	stop();

}
void hidari(int time){
	motor(0,RIGHT);
	Wait(LMT);
	stop();
	motor(LEFT,RIGHT);
	Wait(time);
	stop();
}
void usiro(int time){
	motor(LEFT,0);
	Wait(LMT*2);
	stop();
	motor(LEFT,RIGHT);
	Wait(time);
	stop();
	}

void susumuzo(char houkou[],int houkoujikan[]){

	int i;
	for(i=0;i<5;i++){
	if(houkou[i]=='F'){mae(houkoujikan[i]);};
	if(houkou[i]=='R'){migi(houkoujikan[i]);};
	if(houkou[i]=='L'){hidari(houkoujikan[i]);};
	if(houkou[i]=='B'){usiro(houkoujikan[i]);};

}
}

int main(void)
{


 unsigned short MainCycle = 60;
  Init(MainCycle);

char houkou[5] = {'F','R','L','B','L'};
int houkoujikan[5] = {1000,1000,1000,1000,1000};

susumuzo(houkou,houkoujikan);




  return 0;
}
