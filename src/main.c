#include "succ.h"
#include <stdio.h>
int main (int argc, char *argv[])
{
    int i;
    double n;
    i=atoi(argv[1]);
    n=succ(i);
    printf("%f¥n",n);
}