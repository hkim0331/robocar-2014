#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT   10000
#define RIGHT  10000
#define FW 40
#define TN 8
#define EDGE 30

#define DO    179
#define RE    160
#define MI    142
#define FA    134
#define SO    120
#define RA    107
#define SI    95
#define NN    0
#define PI    1
#define DURATION 400
#define PAUSE 100
#define VOL 100

#define XX    (-1)

int duration = DURATION;
int pause    = PAUSE;



void play(int pitch,int plus)
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
}
void music(int notes[],int cat)
{
    int i;

    for (i=0; notes[i]!=XX; i++) {
        play(notes[i],cat);
    }
}


void kaeru(void)
{
    int notes1[]={DO,RE,MI,FA,MI,RE,DO,NN,
            MI,FA,SO,RA,SO,FA,MI,NN,
            DO,NN,DO,NN,DO,NN,DO,NN,XX};
    int notes2[]={DO,DO,RE,RE,MI,MI,FA,FA,XX};
    int notes3[]={MI,RE,DO,XX};

    music(notes1,0);

    duration = DURATION/2;
    pause    = PAUSE/2;
    music(notes2,0);

    duration  = DURATION;
    pause     = PAUSE;
    music(notes3,0);
}






void motor(short left, short right)
{
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}


void stop(void){

	motor(0,0);
	Wait(10);
}




void forward(int n)
{
  Wait(0);
  motor(LEFT, RIGHT);
  Wait(50);
 stop();
}




void right_motor(short right){
	 Wait(0);
	  motor(0, RIGHT);
	  Wait(50);
   stop();

}

void left_motor(short left){
	    Wait(0);
		  motor(LEFT,0);
		  Wait(50);
       stop();

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	int i;

		for(i=0;i<10000;i++){


			forward(EDGE);
			Wait(50);

        if(ADRead(0)>500){
				 left_motor(EDGE);
				 LED(1);
			 }

			 if(ADRead(1)>500){
				 right_motor(EDGE);
				 LED(2);
			 }


			 if((ADRead(1)>500)&&(ADRead(0)>500)){
				 stop();
				 LED(3);
				 for (;;) {

				         kaeru();
				         Wait(3000);


				     }
				 Wait(10000);
			 }



		}





	return 0;
}

