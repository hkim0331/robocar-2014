#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


#define Power 8000
#define Curve 4500

#define DURATION 400
#define PAUSE 100
#define VOL 100

#define DO    179
#define RE    160
#define MI    142
#define FA    134
#define SO    120
#define RA    107
#define SI    95
#define NN    1

#define XX    0



void Motor(short left, short right)
{
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void Forword(int n){
	Motor(Power, Power);
	Wait(n);
}

void Stop(int n){
	Motor(0, 0);
}

void Right(int n){
	Motor(-Curve, Curve);
	Wait(n);
}

void Left(int n){
	Motor(Curve, -Curve);
	Wait(n);
}

void play(int pitch){
	if (pitch == NN){
		BuzzerStop();
		Wait(DURATION + PAUSE);
	} else {
		BuzzerSet(pitch, VOL);
		BuzzerStart();
		Wait(DURATION);
		BuzzerStop();
		Wait(PAUSE);
	}
}

void music(int notes[]){
	int i;

	for(i = 0; notes[i] != XX; i++){
		play(notes[i]);
	}
}

void kaeru(void){
	int s[] = {DO, RE, MI, FA, MI, RE, DO, NN,
			MI, FA, SO, RA, SO, FA, MI, NN,
			DO, NN, DO, NN, DO, NN, DO, NN, XX,
			DO, DO, RE, RE, MI, MI, FA, FA, MI,
			NN, RE, NN, DO, XX};
	music(s);

}


int main (void){

	unsigned int L_Sensor, R_Sensor;


	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(1000);
	while(1){
		L_Sensor = ADRead(0);
		R_Sensor = ADRead(1);
		if(L_Sensor > 500){
			LED(2);
			Left(300);
		}
		if(R_Sensor > 500){
			LED(1);
			Right(300);
		}
		if((L_Sensor <= 500) && (R_Sensor <= 500)){
			LED(0);
			Forword(50);
		}
		if((L_Sensor > 500) && (R_Sensor > 500)){
			break;
		}
	}
	Stop(0);

	LED(0);

	kaeru();

	return 0;
}
