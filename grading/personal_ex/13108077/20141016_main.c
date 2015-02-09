#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define c 179
#define d 160
#define e 149
#define f 134
#define g 120
#define a 107
#define b 95
#define r 1
#define x 0
void play(int a,int b){
	BuzzerSet(a,100);
	BuzzerStart();
	Wait(b);
	BuzzerStop();
	Wait(100);
}
void kirakira(void){
	int s[]={c,d,e,f,e,d,c};
	int i=0;
	while(s[i]!=0){
		play(s[i]);
		i++;
	}
}
int main(void){
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	kirakira();
	return 0;
}
