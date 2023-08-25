#include <stdlib.h>
int rand(void) { static int i; int arr[6] = {9, 8, 10, 24, 75, 9}; return (arr[i++ % 6]); }
