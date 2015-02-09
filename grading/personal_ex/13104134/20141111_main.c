#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define DO 174
#define MI 142

void oto (int pitch){
	BuzzerSet(pitch,100);
		BuzzerStart();
		Wait(500);
		BuzzerStop();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	    LED(3);
	    Wait(1000);
	    int i;
	    for (i=0; i<10; i++) {
	        LED((i%2)+1);
	        Wait(100);
	        if(i%2==1){
	        	oto(DO);
	        }else{
	        	oto(MI);
	        }
	    }
	    LED(0);

	return 0;
}

