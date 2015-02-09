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

int count100(int x)
{
	int n=0;

	for(n=0; n<=10; n++)
	{
		if(x<100)
		{
			break;
		}
		else
		{
			x -=100;
			n++;
		}
	}
	return n;
}

int count10(int x)
{
	int n=0;

		for(n=0; n<=10; n++)
		{
			if(x<10)
			{
				break;
			}
			else
			{
				x -=10;
				n++;
			}
		}
		return n;
}

int main(void) {
	int x=980;
	int h;
	int d;

	h=count100(x);
	d=count10(x-100*h);

	printf("100 * %d, 10 * %d\n", h, d);

	return EXIT_SUCCESS;
}

