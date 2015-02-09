#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO 179
#define RE 160
#define MI 142
#define FA 134
#define SO 120
#define RA 107
#define SI 95
#define DO2 90
#define XX (-1)
#define MU 0

void play1(int pitch)

{

	if(pitch == MU)

	{

		BuzzerStop();
		Wait(400);

	}

	else

	{

		BuzzerSet(pitch, 100);
        BuzzerStart();
        Wait(400);
        BuzzerStop();
        Wait(100);
	}

}

void play2(int bitch)

{

	BuzzerSet(bitch, 100);
    BuzzerStart();
    Wait(800);
    BuzzerStop();
    Wait(100);

}

void play3(int kitch)

{

	BuzzerSet(kitch, 100);
    BuzzerStart();
    Wait(125);
    BuzzerStop();
    Wait(100);

}

void play4(int titch)

{

    if(titch == MU)

    {

    	BuzzerStop();
        Wait(400);

    }

    else

    {

    	BuzzerSet(titch, 100);
        BuzzerStart();
        Wait(400);
        BuzzerStop();
        Wait(100);

    }

}



int kaeru()

{

int i;

int onkai1[]={DO,RE,MI,FA,MI,RE,DO,MU,MI,FA,SO,RA,SO,FA,MI,MU,XX};

int onkai2[]={DO,DO,DO,DO,XX};

int onkai3[]={DO,DO,RE,RE,MI,MI,FA,FA,XX};

int onkai4[]={MI,RE,DO,MU,XX};

for(i=0;onkai1[i]!=XX;i++)

    {

	    play1(onkai1[i]);

    }

for(i=0;onkai2[i]!=XX;i++)

    {

	    play2(onkai2[i]);

    }

for(i=0;onkai3[i]!=XX;i++)

    {

	play3(onkai3[i]);

    }

for(i=0;onkai4[i]!=XX;i++)

    {

	play4(onkai4[i]);

    }

}



int step(){

	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(100);
	Mtr_Run_lv(0,0,0,0,0,0);

}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short left;
    int i=0;
	for( ; ; ) {
		step();
		Wait(400);
		left=ADRead(0);
	if(800<left){break;

	} else {;}

	}

    kaeru();

	return 0;
}


