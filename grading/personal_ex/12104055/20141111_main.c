#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO 179
#define RE 160
#define MI 142
#define FA 134
#define SO 120
#define RA 107
#define SI 95
#define hDO 90
#define YASUMI 999
#define XX -1



void play(int pitch,int nagasa)
{
	int saiseinagasa;

	saiseinagasa = nagasa * 300  - 50;


	if(pitch != YASUMI){
		BuzzerSet(pitch, 100);
		BuzzerStart();
		Wait(saiseinagasa);
		}
	else{
		BuzzerStop();
		Wait(saiseinagasa);
		}

	BuzzerStop();
	Wait(50);
}

void sairen(int oto){

	if(oto==1){
		play(MI,2);

		}else{
		play(SO,2);

		}

}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


    LED(3);

    Wait(1000);
    int i;
    for (i=0; i<100; i++) {
        LED((i%2)+1);
    	sairen(i%2);

    	}

    LED(0);

	return 0;
	}

