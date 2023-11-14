#!/bin/bash

echo -e '#include <stdio.h>\n#include <stdlib.h>\n#include <time.h>\n\nint rand(void) { return 6; }\n' > /tmp/rand.c
gcc -shared -fPIC -o /tmp/rand.so /tmp/rand.c
LD_PRELOAD=/tmp/rand.so ./gm 9 8 10 24 75 9
