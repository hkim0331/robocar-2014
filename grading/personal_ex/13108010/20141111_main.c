#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void play(int a,int b,int c,int d)
{
    const unsigned short MainCycle = 60;
    Init(MainCycle);
    int i;
    LED(a);
   wait (b);
    for (i=0; i<c; i++) {
        LED((i%2)+1);
        wait(d);
        if (i==0)
        {BuzzerSet(95,100);
        BuzzerStart();
        Wait(d);
        BuzzerStop();}
        else
        {BuzzerSet(120,100);
        BuzzerStart();
        Wait(d);
        BuzzerStop(); }
    LED(0);
    return 0;
}

int main(void)
{
  play (3,1000,20,100)}
