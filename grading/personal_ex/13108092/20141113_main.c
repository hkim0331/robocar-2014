#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
void Note(int x,int y)
{
	BuzzerSet(x,100);
	BuzzerStart();
	Wait(y);
	BuzzerStop();
}

Buzzerh(int a){
	BuzzerSet(95,100);
	Buzzerstart();
	Wait(1000);
	BuzzerStop();
}

Buzzerg(int a){
	BuzzerSet(120,100);
	Buzzerstart();
	Wait(1000);
	BuzzerStop();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	LED(3);
	Wait(1000);
	int i;
	for(i=0;i<100;i++){
		LED((i%2)+1);
		Wait(1000);


	}
	LED(0);
	return 0;
}

