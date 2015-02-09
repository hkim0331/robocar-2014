#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beep(void) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(100);
}

int average(int n){
	int x[n];
	int i;
	int ret =0 ;
    for (i=0;i<n;i++) {}
	x[i] = ADRead(0);
	ret+= x[i];
	Wait(100);

return ret /n;
}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for(;;){

	}
	return 0;
}

