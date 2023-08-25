echo '#include <stdlib.h>' > winning.c
echo 'int rand(void) { static int i; int arr[6] = {9, 8, 10, 24, 75, 9}; return (arr[i++ % 6]); }' >> winning.c
gcc -shared -fPIC winning.c -o winning.so && export LD_PRELOAD=$PWD/winning.so
