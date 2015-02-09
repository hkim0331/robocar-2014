#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

	int main(void)
	{
	    const unsigned short MainCycle = 60;
	    Init(MainCycle);

	    LED(0);
	    Wait(1000);
	    int i;

	    for (i=0; i<100; i++) {
	        LED((i%2)+1);
	        Wait(200);
	    }

	    int si,so,oto;

	    si=95;
	    so=120;

	    if(i=0){oto=si} else{oto=so}

	    for(i=0; i<100; i++){
	    	BuzzerSet(oto, 100);
	    	BuzzerStart();
	    	Wait(200);
	    	BuzzerStop();
	    }

	    LED(0);
	    return 0;
	}
