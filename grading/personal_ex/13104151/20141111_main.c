#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO    179
#define MI    142

void  oto(int a){
	BuzzerSet(a,100);
	BuzzerStart();
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
		LED(i%2+1);
		if(i%2==1){
			oto(DO);
		}else{
			oto(MI);
		}
		Wait(100);
	}
	LED(0);

	return 0;
}

