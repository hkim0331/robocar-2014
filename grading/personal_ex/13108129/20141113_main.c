#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define si 95
#define so 120
#define VOL 100

int main(void)
{
    const unsigned short MainCycle = 60;
    Init(MainCycle);

    LED(3);
    Wait(1000);
    int i;
    for (i=0; i<100; i++) {
        LED((i%2)+1);
        if((i%2)+1 == 2){
        BuzzerSet(si, VOL)
        Wait(1000);
    }
    LED(0);
    return 0;
}
