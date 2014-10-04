void forward(void)
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
}

void turn_left(void)
{
	Mtr_Run_lv(20000,0,0,0,0,0);
}

void turn_right(void)
{
	Mtr_Run_lv(0,-20000,0,0,0,0);
}

void stop(void)
{
	Mtr_Run_lv(0,0,0,0,0,0);
}

void run(void)
{
	int left;
	int right;
	
	for(;;){
		left=ADRead(0);
		right=ADRead(1);
		if (left>512) {
			turn_left();Wait(1000);
		} else if (right>512) {
			turn_right();Wait(1000);
		} else {
			stop();
		}
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	run();
	return 0;
}
