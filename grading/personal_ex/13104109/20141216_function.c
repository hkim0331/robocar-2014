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

int is_normal(int x,int y,int z)
{
	return x*x+y*y==z*z ||   //あるいわ:||
			y*y+z*z==x*x ||   //int is_normal()の数値がreturn[]の[]になる関数
			z*z+x*x==y*y ;
}

int is_prime(int n)
{
	int i;
	for(i=2;i<n;i++)
	{
		if(n % i ==0){ //n/2のあまりが0なら
			return 0;	//素数でない
		}
	}
	return 1;
}


int main(void) {

	//int a=6;
	//int b=4;
	//int c=3;

	//if (is_normal(a,b,c)){
		//printf("直角になりますね");
	//}else{
		//printf("直角になりません");
	//}

	//printf("smaller is %d\n",smaller(c,smaller(a,b)));

	int i=2;
	int count =0;

	while(1){
		if(is_prime(i)){
			count +=1;
			if(count==1000){
				printf("1000th prime is %d\n",i);
			}
		}
		i+=1;
	}



	return 0;
}
