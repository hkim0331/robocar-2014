#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int step(int time){
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(time);
}

int stop(int time){
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(time);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	unsigned short left;

	for(;;){
	step(100);
	stop(500);
	left=ADRead(0);
	if(left>256)break;
}

	BuzzerSet(179,100);
				BuzzerStart();
				Wait(400);
			    BuzzerStop();
			    Wait(400);
			    BuzzerSet(160,100);
				BuzzerStart();
				Wait(400);
				BuzzerStop();
				Wait(400);
				BuzzerSet(142,100);
				BuzzerStart();
				Wait(400);
				BuzzerStop();
				Wait(400);
				BuzzerSet(134,100);
				BuzzerStart();
				Wait(400);
				BuzzerStop();
				Wait(400);
				BuzzerSet(142,100);
				BuzzerStart();
				Wait(400);
				BuzzerStop();
				Wait(400);
				BuzzerSet(160,100);
				BuzzerStart();
				Wait(400);
				BuzzerStop();
				Wait(400);
				BuzzerSet(179,100);
				BuzzerStart();
				Wait(400);
				BuzzerStop();
				Wait(600);
				BuzzerSet(142,100);
				BuzzerStart();
				Wait(400);
				BuzzerStop();
				Wait(400);
				BuzzerSet(134,100);
				BuzzerStart();
				Wait(400);
				BuzzerStop();
				Wait(400);
				BuzzerSet(120,100);
				BuzzerStart();
				Wait(400);
				BuzzerStop();
				Wait(400);
				BuzzerSet(107,100);
				BuzzerStart();
				Wait(400);
				BuzzerStop();
				Wait(400);
				BuzzerSet(120,100);
				BuzzerStart();
				Wait(400);
				BuzzerStop();
				Wait(400);
				BuzzerSet(134,100);
					BuzzerStart();
					Wait(400);
				    BuzzerStop();
				    Wait(400);
					BuzzerSet(142,100);
					BuzzerStart();
					Wait(400);
					BuzzerStop();
					Wait(600);
					BuzzerSet(179,100);
					BuzzerStart();
					Wait(400);
					BuzzerStop();
					Wait(400);
					BuzzerSet(179,100);
					BuzzerStart();
					Wait(400);
					BuzzerStop();
					Wait(400);
					BuzzerSet(179,100);
					BuzzerStart();
					Wait(400);
					BuzzerStop();
					Wait(400);
					BuzzerSet(179,100);
					BuzzerStart();
					Wait(400);
					BuzzerStop();
					Wait(400);
					BuzzerSet(179,100);
					BuzzerStart();
					Wait(400);
					BuzzerStop();
					Wait(400);
					BuzzerSet(179,100);
					BuzzerStart();
					Wait(400);
					BuzzerStop();
					Wait(400);
					BuzzerSet(160,100);
					BuzzerStart();
					Wait(400);
					BuzzerStop();
					Wait(600);
					BuzzerSet(160,100);
							BuzzerStart();
							Wait(400);
							BuzzerStop();
							Wait(400);
							BuzzerSet(142,100);
							BuzzerStart();
							Wait(400);
							BuzzerStop();
							Wait(400);
							BuzzerSet(142,100);
							BuzzerStart();
							Wait(400);
							BuzzerStop();
							Wait(400);
							BuzzerSet(134,100);
							BuzzerStart();
							Wait(400);
							BuzzerStop();
							Wait(400);
							BuzzerSet(134,100);
							BuzzerStart();
							Wait(400);
							BuzzerStop();
							Wait(400);
							BuzzerSet(142,100);
							BuzzerStart();
							Wait(400);
							BuzzerStop();
							Wait(400);
							BuzzerSet(160,100);
							BuzzerStart();
							Wait(400);
							BuzzerStop();
							Wait(600);
							BuzzerSet(179,100);

	return 0;
}


