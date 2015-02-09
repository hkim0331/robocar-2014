#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"








int ex1(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	Wait(1000);
	int i;

	for (i=0;i<100 ;i++ ) {
		LED((i%2)+1);
		Wait(100);
		if(i%2){
			BuzzerSet(95,100);
			BuzzerStart();
			Wait(50);
			BuzzerStop();
			Wait(50);}

		else{
			BuzzerSet(120,100);
			BuzzerStart();
			Wait(50);
			BuzzerStop();
			Wait(50);
		}

	}
	LED(0);
return 0;
}

int ex2(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	 for(; ; ) {
	       step();
	        Wait(500);
	        unsigned short left;
	        left = ADRead(0);
	 }
return 0;
}


int main(void){


	ex1();

return 0;
}
