#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define	c	179
#define	d	160
#define	e	142
#define	f	134
#define	g	120
#define	a	107
#define	b	95
#define	cc	90

#define	xx	0

#define	sn	1


int nf = 600; //4分音符
int ne = 300; //8分音符
int nst = 150;

void Note(int x,int y)
{
	BuzzerSet(x,100);
	BuzzerStart();
	Wait(y);
	BuzzerStop();
}

void Frog(void){
	int frogpitch[] = {c,d,e,f,e,d,c,sn,e,f,g,a,g,f,e,sn,c,sn,c,sn,c,sn,c,sn,xx};
	int frogtone[] = {ne,ne,ne,ne,ne,ne,ne,sn,ne,ne,ne,ne,ne,ne,ne,sn,nf,sn,nf,sn,nf,sn,nf,sn,xx};
	int frogpitchh[] = {c,sn,c,sn,d,sn,d,sn,e,sn,e,sn,f,sn,f,sn,e,d,c,xx};
	int frogtoneh[] = {nst,sn,nst,sn,nst,sn,nst,sn,nst,sn,nst,sn,nst,sn,nst,sn,ne,ne,nf,xx};

	int i;

	for(i=0;i!=xx;i++){
		if(frogpitch[i] == 1){
			Wait(100);
		} else {
		Note(frogpitch[i],frogtone[i]);
		}
	}

	for(i=0;i!=xx;i++){
		if()
	}



}

void Kirakira(void)
{
	Note(c,nf);
	Note
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Frog();


	return 0;
}

