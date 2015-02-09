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



int is_prime(int x){
	int n;
	for(n=2;n<x;n++){
		if(x%n==0){
			return 0;
		}else{
			;
		}
	}
	return 1;
}

int main(void) {
	int x= 1;

	    while (1) {
	        if (is_prime(x)) {
	            printf("%u is prime\n",x);
	        } else {
	            x++;
	        }
	    }
	    return 0;
}
