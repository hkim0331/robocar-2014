/*
 ============================================================================
 Name        : function.c
 Author      : Ryosuke Tsuruda
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int smaller(int x, int y)
{
    if(x<y){
        return x;
    }else{
        return y;
    }
}

int is_normal(int x, int y, int z){
if (x*x+y*y==z*z||y*y+z*z==x*x||z*z+x*x==y*y){
	return 1;
}else{
	return 0;
}
}

//int is_prime(unsigned n){
//	int i=2;
//	for(i=2;i<n;i++){
//		if(n%i==0){
//			return 0;
//		}else{
//			return 1;
//		}
//	}
//}

int is_prime(unsigned int n)
{
    int i;

    for(i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0; //素数じゃない。
        } else {
            ;
        }
    }
    return 1; //素数だ。
}
int main(void) {
	int i=2;
	int count=0;
	while(1){
		if(is_prime(i)){
			count +=1;
			if(count==10)
				printf("1000t h prime is %d/n",i);
		}
	}
	i=+1;
	return 0;
}
