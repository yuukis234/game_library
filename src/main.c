#include "succ.h"
#include <stdio.h>
int main (int argc, char *argv[])
{
    int i;
    i=atoi(argv[1]);
    i=succ(i);
    printf("%d¥n",i);
}