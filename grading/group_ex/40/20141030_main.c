#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define left 10000
#define right 10000
#define speed 0.013
#define white 10
#define black 500
#define c1 179
#define d1 160
#define e1 142
#define f1 134
#define g1 120
#define a1 107
#define b1 95
#define r 1
#define fine 0
#define n4 600
#define n8 400
#define n16 150
void play(int p,int l){
	if(p!=1){
		BuzzerSet(p,100);
		BuzzerStart();
	}
	Wait(l);
	BuzzerStop();
	Wait(100);
}
void music(void){
	int s[]={c1,d1,e1,f1,e1,d1,c1,r,e1,f1,g1,a1,g1,f1,e1,r,c1,c1,c1,c1,c1,c1,d1,d1,e1,e1,f1,f1,e1,d1,c1,fine};
	int l[]={n8,n8,n8,n8,n8,n8,n8,n8,n8,n8,n8,n8,n8,n8,n8,n8,n4,n4,n4,n4,n16,n16,n16,n16,n16,n16,n16,n16,n8,n8,n8};
	int i=0;
	while(1){
		if(s[i]==fine){
			i=0;
			Wait(1000);
		}
		play(s[i],l[i]);
		if(l[i]==n4){
			Wait(300);
		}
		i++;
	}
}
void foward(float dx,float v){
	if(v>=3.2767){
		v=3.2767;
	}else if(v<=-3.2767){
		v=-3.2767;
	}
	Mtr_Run_lv(right*v,-left*v,0,0,0,0);
	Wait(dx/speed/v);
}
void stop(int t){
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(t);
}
int main(void){
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	unsigned short color;
	while(1){
		foward(0.5,1);
		stop(500);
		color=ADRead(0);
		if(color>black){
			break;
		}
	}
	music();
	return 0;
}
