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
	return n/100;
}
int count10(int n)
{
	return (n-(n/100)*100)/10;
}
int main(void) {
	int x=98;
	int h;
	int d;

	 h=count100(x);
	 d=count10(x);

	 printf("100=%d,10=%d",h,d);

	return EXIT_SUCCESS;
}
