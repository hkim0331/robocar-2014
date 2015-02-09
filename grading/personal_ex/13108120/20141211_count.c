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

int count(int x, int n){
	return n/x;
}
int main(void) {

	int x=653;
	int h;
	int d;

	h= count(100,x);
	d= count(10,x);

	printf("100*%d,10*%d\n",h,d);

	return EXIT_SUCCESS;
}
