/*
 ============================================================================
 Name        : function.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int smaller(int x,int y)
{
    if (x < y) {
        return x;
    } else {
        return y;
    }
}


int normal(int x, int y, int z) {
	return (x*x+y*y==z*z ||
			y*y+z*z==x*x ||
			z*z+x*x==y*y);
}



int isprime(int n) {
	int i;
	for(i=2; i<n; i++) {
		if (n%i == 0) {
			return 0;
		}
	}
			return 1;
}


int main(void) {

	int i=2;
	int count=0;

	while (1) {
		if (isprime(i)) {
			count ++;
			if(count==1000) {
				printf("1000th prime is %d\n",i);
				return 0;
			}
		}
		i+=1;
	}
	}







