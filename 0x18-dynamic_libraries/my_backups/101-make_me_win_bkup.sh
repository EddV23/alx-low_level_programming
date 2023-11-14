#!/bin/bash


echo -e '
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand(void)
{
	return 6;
}' > /tmp/rand.c
gcc -shared -fPIC -o /tmp/rand.so /tmp/rand.c
LD_PRELOAD=/tmp/rand.so ./gm 9 8 10 24 75 9
