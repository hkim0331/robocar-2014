#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


# define  SO  120
# define  SI  95

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	ex1();
	return 0;
}


int ex1(void)
{


	    LED(3);
	    Wait(1000);
	    int i;
	    for (i=0; i<100; i++) {
	        LED((i%2)+1);
	    }

	    if(i%2)

	    {
	    			BuzzerSet(120,100);
	    			BuzzerStart();
	    			Wait(500);
	    			BuzzerStop();
	    			Wait(500);
	    }

	    else
	    {
			BuzzerSet(95,100);
			BuzzerStart();
			Wait(500);
			BuzzerStop();
			Wait(500);
	    }


	    return 0;

}

int ex2(void)
{


}

