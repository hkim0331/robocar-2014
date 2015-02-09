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
int smoller(int x,int y)
{
	if(x<y){
		return x;
	}else{
		return y;
	}
}
int normal(int x,int y,int z){
	return x*x+y*y==z*z ||
			x*x + z*z == y*y ||
			z*z + y*y == x*x;

}
int is_prime(int n){
	int i;
	for(i=2;i<2;i++){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
	}
int main(void) {
	//int a=10;
		//int b=20;
		//int c= 30;
  // if(is normal(a,b,c)){
	  // printf("直角になります\n");
   }//else{
	   //printf("直角になりません\n");
   }
		//printf("smaller is %d\n",smaller(a,b)); /* prints !!!Hello World!!! */
	//return 0;
int i=2;
int count=0;
while(1){
	if(is_prime(1)){
		count i=1;
		if(count==1000){
			printf("1000th prime is %d\n".i)

		}
	}

}
