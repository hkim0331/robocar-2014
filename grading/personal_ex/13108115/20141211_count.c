/*
 ============================================================================
 Name        : count.c
 Author      : Ryo Moriyama
 Version     : 2014-12-11
 Copyright   : All Rights Reserved.
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int count100(int n)
{
	int i

}

int count10(int n)
{
	int i;
	for (i=0;i<9;i++) {
		if (n<100) {
			break;
		} else {
			n -= 100;
		}
	}
}

int main(vold)
{
	int x=779;
	int h;
	int d;

	h = count100(x);
	d = count10(x);

	printf("100 * %d, 10 * %d\n", h, d);
	return EXIT_SUCCESS;
}
