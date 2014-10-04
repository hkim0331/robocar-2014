#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO    179
#define RE    160
#define MI    142
#define FA    134
#define SO    120
#define RA    107
#define SI    95
#define DO2   90
#define N     0

#define ON    500
#define OFF   100
#define BEET  (ON+OFF)

#define VOL 100

void play(int pitch)
{
    int i;

    if (pitch == N) {
        BuzzerStop();
        LED(0);
        Wait(BEET);
        return;
    }
    BuzzerSet(pitch,VOL);
    BuzzerStart();
    // FIXME: 
    for (i=0; i<10; i++) {
        LED(i % 4);
        Wait(50);
    }
    BuzzerStop();
    LED(0);
    Wait(OFF);
}

void run(void)
{
    int kirakira[] = {DO,DO,SO,SO,RA,RA,SO,N,FA,FA,MI,MI,RE,RE,DO};
    int kaeru[] = {DO,RE,MI,FA,MI,RE,DO,N,
                   MI,FA,SO,RA,SO,FA,MI,N,
                   DO,N,DO,N,DO,N,DO,N,
                   DO,DO,RE,RE,MI,MI,FA,FA,MI,N,RE,N,DO};
    int *music;
    int length;
    int i;

    LED(3);
    Wait(2000);
    if (getSW()) {
        music = kirakira;
        length=sizeof(kirakira)/sizeof(kirakira[0]);
    } else {
        music = kaeru;
        length=sizeof(kaeru)/sizeof(kaeru[0]);
    }

    for (i=0; i<length; i++) {
        play(music[i]);
    }
}

int main(void)
{
    const unsigned short MainCycle = 60;
    Init(MainCycle);

    run();

    return EXIT_SUCCESS;
}

