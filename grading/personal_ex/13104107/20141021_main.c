#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"





void play(int pitch){
	  BuzzerSet(pitch, 100);
	  BuzzerStart();
	  Wait(400);
	  BuzzerStop();
	  Wait(100);
}


/*以下全部素ソ（茶番）*/

void DO(void){
	  BuzzerSet(179, 100);
	  BuzzerStart();
	  Wait(400);
	  BuzzerStop();
	  Wait(100);
}

void SO(void){  //後で音変えてください
	  BuzzerSet(179, 100);
	  BuzzerStart();
	  Wait(400);
	  BuzzerStop();
	  Wait(100);
}

void Ra(void){
	  BuzzerSet(179, 100);
	  BuzzerStart();
	  Wait(400);
	  BuzzerStop();
	  Wait(100);
}


int main(void) //うんこうんこうんこうんこ
{
	play(179);





	  	  	  	   return 0;



}
