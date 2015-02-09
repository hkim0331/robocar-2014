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
#define DO2 90
#define XX -1
#define NN 0



void play(int pitch){

    if(pitch==NN){
        BuzzerStop();
        Wait(500);
    }else{
    BuzzerSet(pitch,100);
    BuzzerStart();
    Wait(400);
    BuzzerStop();
    Wait(100);
    }
}

void kaeru(void){
    int notes[]={DO,RE,MI,FA,MI,RE,DO,NN,MI,FA,SO,RA,SO,FA,MI,XX,DO,NN,DO,NN,DO,DO,DO,RE,RE,MI,MI,FA,FA,MI,RE,DO};

    int i;
            for(i=0;notes[i]!=XX;i++){
                play(notes[i]);
            }
}

int step(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	  Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
	  Wait(100);
	  Mtr_Run_lv( 0, 0, 0, 0, 0, 0);
	  Wait(1000);
	return 0;
}

int owarinogishiki(void){



	 kaeru();






/*	BuzzerSet(120, 100); // ピッチ 120、ボリュームは 100 だ。
	  BuzzerStart();       // ブザー鳴れ。
	  Wait(3000);          // 3秒待つ。
	  BuzzerStop();        // 鳴りやめ。
*/
}

int main(void)
{
	   unsigned short left; // ADRead() の返す型の変数を用意して、

	   Wait(1000);

	   for( ; ; ) {
	        step();
	        Wait(500);
	        left = ADRead(0);    // 代入により受け取る。

	        if(left>600){
	        	break;
	        }
	        else{
	        	;
	        }

	     }

	   owarinogishiki();

	    return 0;
}



