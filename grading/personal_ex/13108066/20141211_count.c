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
	int j=0;


	while(i < 0 ){
	i =	n - 100;
	j += 1;
	}
return j;
}






int main(void) {
	int x =327;
    int h;
    int d=0;

    h = count100(x);


    printf("100 * %d, 10 * %d\n", h,d);
	return EXIT_SUCCESS;
}
