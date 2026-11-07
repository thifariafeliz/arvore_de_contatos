#ifndef COMMON_H
#define COMMON_H

typedef enum CTError {
    CT_ERR_OK = 0,
    CT_ERR_IO,
    CT_ERR_,
    CT_ERR_EMPTY,
    CT_ERR_OVERFLOW,
    CT_ERR_INVALID_ARG,
    CT_ERR_INVALID_INPUT,
    CT_ERR_FAILED_MALLOC,
} CTError;

#endif
