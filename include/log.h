#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdlib.h>


typedef enum Error {
    ERROR_OK = EXIT_SUCCESS,
    ERROR_INVALID_ARGUMENTS,
    ERROR_IO
} Error;


#define LOG(...)                 \
    do {                         \
        printf("%s: ", ((TAG))); \
        printf(__VA_ARGS__);     \
        printf("\n");            \
    } while (0)

#define LOGE(__ERROR)                                \
    do {                                             \
        fprintf(stderr, "%s: ", ((TAG)));            \
        fprintf(stderr, errorToString(((__ERROR)))); \
        fprintf(stderr, "\n");                       \
    } while (0)

#define START_ERROR_STACK printf("***** ERROR STACK *****\n")

#define FIRE(__ERROR, ...)           \
    do {                             \
        Error __error = ((__ERROR)); \
        START_ERROR_STACK;           \
        LOG(__VA_ARGS__);            \
        LOGE(__error);               \
        return __error;              \
    } while (0)

#define BURN(__ERROR)                \
    do {                             \
        Error __error = ((__ERROR)); \
        if (__error != ERROR_OK) {   \
            LOGE(__error);           \
            return __error;          \
        }                            \
    } while (0)


char const *errorToString(Error error);

#endif
