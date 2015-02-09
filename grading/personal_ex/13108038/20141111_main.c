#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define SO 120
#define SI 95

void play(int pitch){
 BuzzerSet(pitch, 100);
 BuzzerStart();
 Wait(400);
 BuzzerStop();
 Wait(100);
 }


int main(void)
{
    const unsigned short MainCycle = 60;
    Init(MainCycle);

    LED(3);
    int i;
    int notes[]={SO,SI};
    for (i=0; i<100; i++) {
        LED((i%2)+1);
        play(notes[(i%2)+1]);

    }
    LED(0);
    return 0;
}
