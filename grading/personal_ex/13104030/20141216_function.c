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
	if(x<y){
		return x;
	}else{
		return y;
	}
}

int is_nomal(int x,int y,int z){
	return x*x+y*y==z*z||
			y*y+z*z==x*x||
			z*z+x*x==y*y;
}
int is_prime(int n){
	int i;

	for(i=2;i<n;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}

int main(void) {
	/*
	int a=5;
	int b=4;
	int c=3;

	if(is_nomal(a,b,c)){
		printf("直角になります\n");
	}else{
		printf("直角にならない\n");
	}
	return 0;

}
	 */
	int i=2;
	int count=0;

	while(1){
		if(is_prime(i)){
			count +=1;
			if(count==1000){
				printf("1000th prime is %d\n",i);
				return 0;
			}
		}
		i+=1;
	}
}
