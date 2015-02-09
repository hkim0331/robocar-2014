/*
 ============================================================================
 Name    fukuyama akihiro    : count.c
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
	return (x-count100(x))/10;

}

int main(void) {

	int x=525;
	int h;
	int d;

	h = count100(x);
	d = count10(x-100*h);

	printf("100= %d ,10= %d\n",h,d);

	return EXIT_SUCCESS;
}
