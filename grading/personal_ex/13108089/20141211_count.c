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

int count100(int n)
{
	int a;
	a = n/100;
	return a;
}

int count10(int n)
{
	int a;
	a = n/10;
	return a;
}

int main(void) {

	int x=987;
	int h;
	int d;

	h = count100(x);
	d = count10(x-100*h); /*fix me*/

	printf("100 * %d, 10 * %d\n", h,d);
	return EXIT_SUCCESS;
}
