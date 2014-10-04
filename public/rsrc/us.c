#include <stdio.h>

int main(void)
{
    int s=-1;
    unsigned int u=s;

    if (s>0) {
        puts("s is positive");
    }
    if (u>0) {
        puts("u is positive");
    }
    return 0;
}
