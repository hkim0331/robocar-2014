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
#define XX    0



void play(int pitch,int t,int w){

	if(pitch==0){
		Wait(t+w);
	}
	else{
	 BuzzerSet(pitch,100);
	 BuzzerStart();
	 Wait(t);
	 BuzzerStop();
	 Wait(w);
	}

}

void kirakira(){

	play(DO,900,100);
	play(DO,900,100);
	play(SO,900,100);
	play(SO,900,100);
	play(RA,900,100);
	play(RA,900,100);
	play(SO,1800,200);

	play(FA,900,100);
	play(FA,900,100);
	play(MI,900,100);
	play(MI,900,100);
	play(RE,900,100);
	play(RE,900,100);
	play(DO,1800,200);

	play(120,900,100); /*ソ*/
	play(120,900,100); /*ソ*/
	play(134,900,100); /*ファ*/
	play(134,900,100); /*ファ*/
	play(142,900,100); /*ミ*/
	play(142,900,100); /*ミ*/
	play(160,1800,200); /*レ*/

	play(120,900,100); /*ソ*/
	play(120,900,100); /*ソ*/
	play(134,900,100); /*ファ*/
	play(134,900,100); /*ファ*/
	play(142,900,100); /*ミ*/
	play(142,900,100); /*ミ*/
	play(160,1800,200); /*レ*/

	play(179,900,100); /*ド*/
	play(179,900,100); /*ド*/
	play(120,900,100); /*ソ*/
	play(120,900,100); /*ソ*/
	play(107,900,100); /*ラ*/
	play(107,900,100); /*ラ*/
	play(120,1800,200); /*ソ*/

	play(134,900,100); /*ファ*/
	play(134,900,100); /*ファ*/
	play(142,900,100); /*ミ*/
	play(142,900,100); /*ミ*/
	play(160,900,100); /*レ*/
	play(160,900,100); /*レ*/
	play(179,1800,200); /*ド*/

}

void doremi(){

	play(DO,400,100);
	play(RE,400,100);
	play(MI,400,100);
	play(FA,400,100);
	play(MI,400,100);
	play(RE,400,100);
	play(DO,400,100);
	play(XX,400,100);

	play(MI,400,100);
	play(FA,400,100);
	play(SO,400,100);
	play(RA,400,100);
	play(SO,400,100);
	play(FA,400,100);
	play(MI,400,100);
	play(XX,400,100);

	play(DO,400,100);
	play(XX,400,100);
	play(DO,400,100);
	play(XX,400,100);
	play(DO,400,100);
	play(XX,400,100);
	play(DO,400,100);
	play(XX,400,100);

	play(DO,200,50);
	play(DO,200,50);
	play(RE,200,50);
	play(RE,200,50);
	play(MI,200,50);
	play(MI,200,50);
	play(FA,200,50);
	play(FA,200,50);
	play(MI,400,100);
	play(RE,400,100);
	play(DO,400,100);
	play(XX,400,100);




}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	while(1){

	 doremi();

	/*kirakira();*/
    }
	return 0;
}

