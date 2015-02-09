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
	int i = 0;
	for(;;){
		n -= 100;
		if(n >= 0){
			i += 1;
		}else{
			break;
		}
	}
	return i;
}

int count10(int n)
{
	int i = 0;
	int j = n;
	for(;;){
			n -= 10;
			if(n >= 0){
				i += 1;
			}else{
				break;
			}
		}
	i -= count100(j)*10;
	return i;
}


int main(void) {
	int x =563;
	int h;
	int d;

	h = count100(x);
	d = count10(x);   /*FIXME*/

	printf("100 * %d * %d\n",h,d);

	return EXIT_SUCCESS;
}
