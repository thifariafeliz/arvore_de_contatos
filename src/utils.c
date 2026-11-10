#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

#include "../include/utils.h"

CTError parse_int(char *input, int *output) {
    errno = 0;
    char *end;
    long int value = strtol(input, &end, 10);

    if (end == input) {

    }
}
