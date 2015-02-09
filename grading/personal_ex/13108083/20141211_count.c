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

int count100(int);
int count10(int);

int main(void)
{
	int x=722;
	int h, d;

	h=count100(x);
	d=count10(x);   /*FIXME*/

	printf("100 * %d, 10 * %d\n", h, d);
	return EXIT_SUCCESS;
}

int count100(int x)
{
	int count=0;

	while(x>99)
	{
		x -= 100;
		count ++;
	}

	return count;
}

int count10(int x)
{
	int count=0, t;

	t = x - count100(x)*100;

	while(t>9)
	{
		t -= 10;
		count ++;
	}

	return count;
}
