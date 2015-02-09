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
	int i;
	for(i=0;i<10;i++){
		if(n<100){
			break;
		} else {
			n -= 100;
		}
	}
    return i;
}

int count10(int n)
{
	int i;
	for(i=0;i<10;i++){
		if(n<10){
			break;
		} else {
			n -= 10;
		}
	}
    return i;
}

int main(void) {

	int n=893;
	int h;
	int d;

	h = count100(n);
	d = count10(n-100*h);
	printf("100 * %d, 10 * %d\n", h, d);

}
