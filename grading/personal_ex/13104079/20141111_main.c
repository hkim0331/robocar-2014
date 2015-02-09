#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define MI 142
#define DO 179

void play (int pitch){
	BuzzerSet(pitch, 100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
	Wait(100);

}
void m (void){
	int notes[]={MI};
		int i;
		for (i=0; notes[i]=XX; i++)
		{
			play(notes[i]);
		}
}
void d (void){
	int notes[]={DO};
	int a;
	for (a=0;notes[a]=xx; a++){
		play(notes[a]);
	}
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	LED(3);
	Wait(1000);
	int i;
	for(i=0;1<100;i++){
		LED(i%2+1);
		if((i%2) < 2){
			m();
		}else{
			d();
		}

		Wait(100);
	}
	LED(0);
	return 0;
}

