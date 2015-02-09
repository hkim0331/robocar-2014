#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


/*ex1*/
void ex1(void){
	int i;
	LED(3);
	Wait(1000);
	for(i=0; i<10; i++){
		LED((i%2)+1);
		Wait(1000);
	}
}


/*ex2*/
#define SO 120
#define SI 95
#define XX (-1)
void ex2(void){
	int i,j;
	for( ; ; ){
		LED((i%2)+1);
		Wait(1000);
		void play(int pitch){
				if(pitch==SI){
		        BuzzerSet(pitch,50);
				BuzzerStart();
				Wait(500);
				BuzzerStop();
				Wait(250);
			}
			else(pitch==SO);{
		        BuzzerSet(pitch,50);
				BuzzerStart();
				Wait(200);
				BuzzerStop();
				Wait(25);
			}
		}
	    int notes[]={SI,SO};

   	    for (j=0; notes[j]!=XX; j++) {
   	        play(notes[i]);
   	    }

	}
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	void ex2();

	return 0;
}

