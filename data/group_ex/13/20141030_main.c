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
      Wait(500);
	  forward(10000,-10000);
	  Wait(100);
	  Mtr_Run_lv(0,0,0,0,0,0);
	  Wait(50);

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);



    int i;
    unsigned short bw;
    for(i=0; i<N; i++){
      step();
      bw = ADRead(0);
       if (bw>200){
    	  break;

       }

    }
    BuzzerSet(120,100);
    BuzzerStart();
    Wait(3000);
    BuzzerStop();
	return 0;
}

