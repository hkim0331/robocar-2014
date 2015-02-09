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

int smaller(int x, int y)
{
	if (x<y){
		return x;
	}else{
		return y;
	}
}

int is_prime(int n){
	int i;

	for(i=2; i<n; i++){
		if(n % i==0){
			return 0;
		}
	}
	return 1;
}
int main(void) {
	/*
	int a=3;
	int b=4;
    int c=5;

    if(is_prime(a,b,c)){
    	printf("直角になります\n");
    }else{
    	printf("直角にならない\n");
    }
    */
	int i=2;
	int count=0;

	while(1){
		if(is_prime(i)){
			print("1000th prime is %d\n",i);
			return 0;
		}
	    i+=1;

	}

	return 0;
}
