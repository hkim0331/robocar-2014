#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
void play(int pitch)
{
	 BuzzerSet(pitch, 50);
		    BuzzerStart();
		    Wait(400);
		    BuzzerStop();
		    Wait(100);
}
int DO(void)
{
	 play(179);
}
int SO(void)
{
	 play(120);
}
int RA(void)
{
	 play(107);



}
int main(void)
{
    const unsigned short MainCycle = 60;
    Init(MainCycle);

   DO();
   DO();
   SO();
   SO();
   RA();
   RA();
   SO();

	return 0;
}

