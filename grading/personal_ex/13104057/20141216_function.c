/*
 ============================================================================
 Name        : function.c
 Author      : Kuroda Yukiya
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int smaller(int x, int y)
{
	if (x<y) {
		return x;
	} else {
		return y;
	}
}

int is_prime(unsigned int n) {
	int i;

	for (i=2; i<n; i++) {
		if (n % i ==0){
			return 0;
		}
	}
	return 1;
}
int main(void) {

	int i=2;
	int count=0;

	while (1) {
		if (is_prime(i)) {
			count +=1;
			if (count==1000) {
				printf("1000th prime is %d\n",i);
				return 0;
			}
		}
	i+=1;
	}
	return 0;
	}
