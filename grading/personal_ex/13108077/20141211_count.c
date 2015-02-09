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
	return x/100;
}
int count10(int x){
	return (x%100)/10;
}
int main(void) {
	int x,h,d;

	x=485;
	h=count100(x);
	d=count10(x);

	printf("%d = 100*%d + 10*%d \n",x,h,d);
	return 0;
}
