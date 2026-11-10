#include <stdio.h>
#include <stdlib.h>
#include "../include/stringo.h"

#define STRINGO_INIT_SIZE 16
#define STRINGO_GROWTH_FACTOR 2

struct Stringo {
    char *data;
    size_t length;
    size_t capacity;
};

char *stringo_data(Stringo *stringo) {
    return stringo == NULL ? NULL : stringo->data == NULL ? NULL : stringo->data;
}

size_t stringo_length(Stringo *stringo) {
    return stringo == NULL ? 0 : stringo->length;
}

size_t stringo_capacity(Stringo *stringo) {
    return stringo == NULL ? 0 : stringo->capacity;
}

void stringo_destroy(Stringo *stringo) {
    if (stringo == NULL) {
        return;
    }

    if (stringo->data != NULL) {
        free(stringo->data);
        stringo->data = NULL;
        stringo->length = 0;
        stringo->capacity = 0;
    }

    free(stringo);
    stringo = NULL;
    return;
}

Stringo *stringo_new(void) {
    Stringo *new_stringo = malloc(sizeof(*new_stringo));
    if (new_stringo == NULL) {
        return NULL;
    }

    new_stringo->length = 0;
    new_stringo->data = malloc(STRINGO_INIT_SIZE);
    if (new_stringo->data == NULL) {
        free(new_stringo);
        return NULL;
    }

    new_stringo->capacity = STRINGO_INIT_SIZE;

    return new_stringo;
}

CTError stringo_get_input(Stringo *input) {
    if (input == NULL || stringo_data(input)) {
        return CT_ERR_INVALID_ARG;
    }

    int c = 0;

    for ( ; ; ) {
        c = getchar();

        if (c == EOF) {
            if (stringo_length(input) == 0) {
                return CT_ERR_IO;
            }
            break;
        }

        if (c == '\n') {
            break;
        }

        if (stringo_length(input) + 1 >= stringo_capacity(input)) {
            size_t new_capacity = stringo_capacity(input) * STRINGO_GROWTH_FACTOR;
            char *temp = realloc(stringo_data(input), new_capacity);
            if (temp == NULL) {
                return CT_ERR_FAILED_MALLOC;
            }

            input->capacity = new_capacity;
            input->data = temp;
        }

        input->data[input->length++] = (char) c;
    }

    input->data[input->length] = '\0';

    return CT_ERR_OK;
}
