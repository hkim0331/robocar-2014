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
#define hDO 90
#define YY 0
#define XX -1
void play(int pitch)
{
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(250);
	BuzzerStop();
	Wait(100);
}
void NN()
{
	BuzzerStop();
	Wait(100);
}
void step()
{
	Mtr_Run_lv(10500, -10600, 0, 0, 0, 0);
	Wait(100);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	Wait(500);
	return 0;
}
void kaeru()
{
	int notes[]={DO,RE,MI,FA,MI,RE,DO,NN,MI,FA,SO,RA,MI,RE,DO,NN,DO,NN,DO,NN,DO,NN,DO,NN};
		int i;
		for(i=0;notes[i]!=XX;i++)
		{
			play(notes[i]);
		}
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
    int i;
    unsigned short left;
    for(; ;)
    {
    	step();
    	left=ADRead(0);
    	if (left>=700)
    	{
    		Mtr_Run_lv(0, 0, 0, 0, 0, 0);
    		kaeru();
    		break;
    	}
    }
}

