#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO   179
#define RE   160
#define MI   142
#define FA   134
#define SO   120
#define RA   107
#define SI   95
#define XX   0

void play(int pitch)
{
	BuzzerSet(pitch, 100);
	BuzzerStart();
	Wait(200);
	BuzzerStop();
	Wait(100);
}

void kaerunouta(void)
{
    int s[]={DO,RE,MI,FA,MI,RE,DO,XX,
    		MI,FA,SO,RA,SO,FA,MI,XX,
    		DO,XX,DO,XX,DO,XX};
    int i;

    for (i=0; s[i]!=XX; i++) {
        play(s[i]);
    }
}


int main(void)
{
	kaerunouta();

	return 0;
}

