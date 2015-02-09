/*
 ============================================================================
 Name        : hello.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int i;
	char name[256];

	scanf("%s", name);
	if (strcmp(name, "bill") == 0) {
		for (i = 0; i < 10; i++)
			puts("gold");
	} else {
		for	(i=0; i<10; i++) {
			puts("love");
		}
	}
	puts("okiro!");
	for (i=0; i<10; i++) {
		printf("ohayou,%s,aishiteruyo\n",name);
	}
	puts("okitaka?");

	return EXIT_SUCCESS;
}
