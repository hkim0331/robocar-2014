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


int count(int keta, int x)
{
	int i;


}

int count100(int x)
{
	return x/100;
}

int count10(int x)
{
	x %= 100;
	return x/10;
}

int main(void) {

	int x;
	int h, d;

	printf("xを入力");
	scanf("%d", &x);

	h = count100(x);
	d = count10(x);

	printf("100 * %d, 10 * %d\n", h, d);

	return EXIT_SUCCESS;
}
