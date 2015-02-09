/*
 ============================================================================
 Name        : count.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int count100(int x){

	/*return x/100;*/
	int i;

	for (i=0;i<10;i++){
		if(x<100){
			break;
		}
		else{
			x-=100;
		}

	}

	return i;
}

int count10(int x){

	int y;
	y=(x-(x/100)*100)*10;
	/*return (x-(x/100)*100)/10;*/
	return count100(y);

}

int count1(int x){
	return count100((x-(x/100)*100)*10);
}


int main(void) {
	int x=987;
	int h;
	int t;
	int o;

	h=count100(x);
	t=count10(x);
	o=count1(x);

	printf("100*%d, 10*%d, 1*%d\n",h,r,0);

	return EXIT_SUCCESS;
}
