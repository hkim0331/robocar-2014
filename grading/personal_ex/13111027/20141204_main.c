#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT 10000
#define RIGHT -10000
#define N 500
#define L 0
#define R 1
#define ORANGE 1
#define GREEN 2
#define LONG 20
#define MID  4
#define SHORT  1

void forward(short left, short right){

    Mtr_Run_lv(left,right,0,0,0,0);

}

void step(void){
	  Wait(20);
	  forward(8000,-8000);
	  Wait(10);

}

void left(void){
	  forward(8000,-100);
	  Wait(25);

}

void right(void){
	  forward(100,-8000);
	  Wait(25);

}

void stop(void){
	  forward(0,0);

}



void buzzer(void){
    BuzzerSet(120, 100);
    BuzzerStart();
    Wait(3000);
    BuzzerStop();


}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


    int blacks=0;
    int i;
    unsigned short br;
    unsigned short bl;
    for(i=0; i<N; i++){

      br = ADRead(L); //left
      bl = ADRead(R);  //right


      if(bl<200 && br<200){
   	     step();
   	     LED(ORANGE);
   	     LED(GREEN);


      }
       if (bl>200 && br<200){
    	   LED(ORANGE);
    	   Wait(100);
    	   LED(0);
    	  right();
       }
       if(br>200 && bl<200){
    	  LED(GREEN);
    	  Wait(100);
    	  LED(0);
    	  left();

       }

       else if(br>200 && bl>200){
    	   blacks += 1;
    	   step();

    	   if(blacks>LONG){
    		   step();
    	   }
    	   else if(blacks>=MID){
    		   stop();
    		   break;
    	   }
    	   else if(blacks=SHORT){
    		   step();
    	   }
       }


    }

  buzzer();
	return 0;
}
