#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int average(void){
	int SUM=0;
	int i;
	int a[1025];

	for(i=0;i<1024;i++)
	{
		a[i]=ADRead(0);
	}

	for(i=0;i<1024;i++)
	{
		SUM+=a[i];
	}

	return SUM/1024;

}
void beep(void){
	BuzzerSet(50,100);
	BuzzerStart();
	Wait(50);
	BuzzerStop();
	Wait(300);
}
void color(void){
	int i;
	int n=average();
	for(i=0;i<n;i+=100){
		beep();

	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	color();
	return 0;
}

