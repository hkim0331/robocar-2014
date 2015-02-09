#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT 10000
#define RIGHT -10000
#define N 500

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



    int i;
    unsigned short br;
    unsigned short bl;
    for(i=0; i<N; i++){

      br = ADRead(0); //left
      bl = ADRead(1);  //right


      if(bl<200 && br<200){
   	  step();

      }
       if (bl>200 && br<200){
    	   LED(1);
    	   Wait(100);
    	   LED(0);
    	  right();
       }
       if(br>200 && bl<200){
    	  LED(2);
    	  Wait(100);
    	  LED(0);
    	  left();

       }

       else if(br>200 && bl>200){
    	 forward(0,0);
    	 break;
       }


    }

  buzzer();
	return 0;
}
