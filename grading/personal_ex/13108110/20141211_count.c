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
 int x;
 x= n/100;
 return x;

}

int count10(int n)
{
	int x;
	x=n/10;
	return x;

}

int main(void) {

	int x = 567;
	int h;
	int d;

	h = count100(x);
	d = count10(x-100*h);  /*FIXME*/

	printf("100 * %d, 10 * %d\n", h, d);

	return EXIT_SUCCESS;
}
