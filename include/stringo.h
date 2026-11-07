#ifndef STRINGO_H
#define STRINGO_H

#include <stddef.h>

#include "common.h"

typedef struct Stringo Stringo;

Stringo *stringo_new(void);
char *stringo_data(Stringo *stringo);
void stringo_destroy(Stringo *stringo);
size_t stringo_length(Stringo *stringo);
size_t stringo_capacity(Stringo *stringo);
CTError stringo_get_input(Stringo *input);

#endif
