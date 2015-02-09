/*
 ============================================================================
 Name        : hello.c
 Author      : Seiya Masuda
 Version     : 1.0
 Copyright   : All rights reserved.
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void) {
    int i;
    for (i=10; i>0; i--){
	printf("%d\n",i); /* prints !!!Hello World!!! */
	sleep(1);
    }
	puts("どかん！！");
	return EXIT_SUCCESS;
}
