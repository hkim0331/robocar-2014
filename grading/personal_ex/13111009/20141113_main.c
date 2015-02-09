#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
    const unsigned short MainCycle = 60;
    Init(MainCycle);

    BuzzerSet(120,100);
    	BuzzerStart();
    	Wait(300000);
    	BuzzerStop();


    LED(3);
    Wait(1000);
    int i;
    for (i=0; i<100; i++) {
        LED((i%2)+1);
        Wait(500);
    if(i==1){
    	BuzzerSet(120,100);
    		BuzzerStart();
    		Wait(3000);
    		BuzzerStop();}
    else{
    	BuzzerSet(95,100);
    		BuzzerStart();
    		Wait(3000);
    		BuzzerStop();

    }


    }
    LED(0);
    return 0;
}
