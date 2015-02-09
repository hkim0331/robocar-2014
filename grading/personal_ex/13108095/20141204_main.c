
#define time	20 	//微小移動時間

#define Right	10000	//右タイヤモーター
#define Left 	10000	//左タイヤモーター



#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"



void Run(int right, int left){
	Mtr_Run_lv(right, left, 0, 0, 0, 0); //モーターを最大6個載せられるから６つ
	Wait(time);
}

void stop(){
	Run(0,0);
}

void forward(){
	Run(Right,Left);
}

void spinR(){
	Run(-Right,Left);
}

void spinL(){
	Run(Right,-Left);
}

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


int main(void)
{

	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short color0,color1,colorL,colorR;

	int i=1;
	int l;
	int white=0;
	int black=1;
	int blacks=0;




	while(i){

		colorL = ADRead(0); //左
		colorR = ADRead(1);	//右		0が白

		if(ADRead(0)>500){colorL=black;}
		else{colorL=white;}

		if(ADRead(1)>500){colorL=black;}
		else{colorL=white;}



		if(colorL==black && colorR==black){
			forward();
			blacks++;

		}
		else if(colorL==black && colorR==black){
			stop();
			LED(0);
		    break;
		}
		else if(colorL==black){
			spinL();
			l=2;
		}
		else if(colorR==black){
			spinR();
			l=1;
		}

		LED(l); /*0,1,2,3:無、右、左、両方*/

	}

	int n;
	for(n=0;n<=blacks;n++){
		play(120,200,200);
	}

	return 0;
}
