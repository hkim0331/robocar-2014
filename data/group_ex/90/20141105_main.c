#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DP 100


#define DO 179
#define RE 160
#define MI 142
#define FA 134
#define SO 120
#define RA 107
#define SI 95

#define XX (-1)

int duration;
int pause;

void step(void)
{
    Mtr_Run_lv(10000,-10000,0,0,0,0);
    Wait(40);
    Mtr_Run_lv(0,0,0,0,0,0);
}

void play(int pitch,int duration,int pause )
{
    BuzzerSet(pitch,25);
    BuzzerStart();
    Wait(duration);
    BuzzerStop();
    Wait(pause);
}

void music(int notes[])
{
    int i;

    for(i=0;notes[i]!=XX;i++){
        play(notes[i],duration,pause);
    }
}

void kaeru(void)
{
    int notes1[]={DO,RE,MI,FA,MI,RE,DO,XX};
    int notes2[]={MI,FA,SO,RA,SO,FA,MI,XX};
    int notes3[]={DO,DO,DO,DO,XX};
    int notes4[]={DO,DO,RE,RE,MI,MI,FA,FA,XX};
    int notes5[]={MI,RE,DO,XX};

    duration =DP*3;
    pause    =DP*2;
    music(notes1);

    Wait(DP);

    duration =DP*3;
    pause    =DP*2;
    music(notes2);

    Wait(DP*3/2);

    duration =DP*4;
    pause    = DP*4;
    music(notes3);


    pause    = DP/2 ;
    Wait(DP);


    duration =DP*3/2;
    pause    =DP;
    music(notes4);

    Wait(DP/2);

    duration =DP*3;
    pause    =DP*2;
    music(notes5);

}

int main(void)
{
    const unsigned short MainCycle = 60;
    Init(MainCycle);

    int i;
    unsigned short left;
    unsigned short right;

    for (i=0;i<10000;i++){

        step();
        Wait(500);
        left = ADRead(1);
        right = ADRead(0);

        if (left > 900 || right > 900){
         break;
        }
        else{
            ;
        }
    }

    kaeru();

    return 0;
}
