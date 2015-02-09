/*
 ============================================================================
 Name        : function.c
 Author      : gota tuji
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int larger(int x, int y){
	if(x>y){
		return x;
	}else{
		return y;
	}
}
int max(int x, int y, int z){
	return larger(x,larger(y,z));
}
int is_nomal(int x, int y, int z){
	return x*x+y*y==z*z||
			y*y+z*z==x*x||
			z*z+x*x==y*y;
}

int is_prime(unsigned int n){
	int i;

	for(i = 2; i < n; i++){
		if (n%i == 0){
			return 0;
		}else{
			;
		}
	}
	return 1;
}


int main(void) {
	/*
	int a=10;
	int b=20;
	int c=30;

	if(is_nomal(a,b,c)){
		printf("直角\n");
	}else{
		printf("tigau\n");
	}
	return 0;
	*/

	int i=2;
	int count=0;

	while(1){
	if(is_prime(i)){
		count +=1;
		if (count==1000){
			printf("1000t h prime is %d\n",i);
			return 0;
		}
	}
	i +=1;
	}


}
