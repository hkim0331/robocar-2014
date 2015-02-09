#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void sound(int pitch){

	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(200);
	BuzzerStop();
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;

	for(i=0;i<100;i++){
		LED((i%2)+1);
		Wait(200);
		if((i%2)==0){
		sound(95);
		}
		else{
			sound(120);
		}
	}
	return 0;
}

