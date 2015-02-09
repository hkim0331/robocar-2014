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

/*int count100(int n){
	if(n>=1000){
	return n/100 - n/1000*10;
	}

	if(n<1000){
	return n/100;
	}

}

int count10(int n) {
	if(n>=100){
	return n/10 - n/100*10;
	}
	if(n<100){
	return n/10 ;
	}
}*/
int countX(int a,int n){
	if(n>=(a*10)){
	return n/a - n/(a*10)*10;
	}
	if(n<(a*10)){
	return n/a ;
	}

}


int main(void)
{
	int x=893;
	int h; //handoreddo
	int d; // desimaru

	/*h = count100(x);
	d = count10(x);*/

	h = countX(100,x);
	d = countX(10,x);

	printf("100 * %d, 10 * %d\n", h,d);
}
