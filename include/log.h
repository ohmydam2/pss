#ifndef LOG_H
#define LOG_H

#include <stdio.h>

#include "error.h"

#define LOG(__TAG,...) printf("%s: ", ((__TAG))); printf(__VA_ARGS__); printf("\n");
#define LOGE(__TAG,__ERROR) fprintf(stderr, "%s: ", ((__TAG))); fprintf(stderr, errorToString(((__ERROR)))); fprintf(stderr, "\n")

#endif
