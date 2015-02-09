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

int is_prime(int n)
{
	int i;

	for(i=2;i<n; i++){
		if(n% i==0){
			return 0;
		}
	}
	return 1;
}

int main(void) {
	int i=2;
	int count=0;

	while(1){
		if(is_prime(i)){
			count +=1;
			if (count==10){
				printf("10th prime is %d\n",i);
			}
		}
		i+=1;
	}
	return 0;
}
