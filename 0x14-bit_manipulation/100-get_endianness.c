#include "main.h"

/**
 * get_endianness - checks if machine used is either little or a big endian
 * Return: 0 if big and 1 if little
 */
int get_endianness(void)
{
    unsigned int num = 1;
    char *endian = (char *)&num;

    if (*endian != 0)
        return 1; /**little endian*/
    else
        return 0; /**big endian*/
}
