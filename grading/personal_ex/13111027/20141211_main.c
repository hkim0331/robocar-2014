#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int buzzer(int length){
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(length);
	BuzzerStop();
    Wait(100);
}

int color(void){
	int i;
	int a[i];
	int s=0;
	for(i=0; i<10; i++){
      a[i]=ADRead(0);
	  s += a[i];

    }

	return s/10;
}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
    LED(0);
    int i;
    int t = color();
    for(i=0; i<t; i+=100){
    	buzzer(500);
    }
	return 0;
}

