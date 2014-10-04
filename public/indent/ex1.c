#include <stdio.h>
#include <stdlib.h>
int run(char *s) {
printf("hello, %s\n",s);
return 0;
}
int main(void) {
int ret;
char name[256];
scanf("%s",name);
ret = run(name);
return 0;}
