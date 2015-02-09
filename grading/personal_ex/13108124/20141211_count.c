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

int count(int n, int m)
{
	return n/m;

}



int main(void) {

	int x = 236;
	int h;
	int d;

	h = count(x, 100);
	d = count(x-100*h, 10);  /*FIXME*/

	printf("100 * %d, 10 * %d\n", h, d);


	return EXIT_SUCCESS;
}
