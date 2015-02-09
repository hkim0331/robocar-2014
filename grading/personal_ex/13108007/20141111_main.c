#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void buzzer(n)
{
	BuzzerSet(n,100);
	BuzzerStart();
	Wait(200);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i,n,m;

	LED(3);
	Wait(1000);

	for(i=0;i<10;i++)
	{
		m=n%2+1;

		LED( (m) +1 );
		if(m)
		{
			buzzer(120);
		}
		else
		{
			buzzer(95);
		}
		Wait(200);
	}

	BuzzerStop;
	LED(0);

	return 0;
}

