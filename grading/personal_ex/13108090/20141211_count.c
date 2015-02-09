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

int count100(int a){
	return a/100;
}

int count10(int a){
	return (a%100)/10;
}


int main(void) {

	int x=241;
	int h;
	int d;

	h = count100(x);
	d = count10(x); /*FIXME */

	printf("100*%d, 10*%d\n",h,d);

	return EXIT_SUCCESS;
}
