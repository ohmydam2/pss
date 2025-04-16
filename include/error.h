#ifndef ERROR_H
#define ERROR_H

#include "log.h"

typedef enum Error {
    ERROR_OK = 0,
    ERROR_TOO_FEW_ARGUMENTS
} Error;


#define BURN(__TAG,__ERROR) do { Error error = ((__ERROR)); if (error != ERROR_OK) { LOGE(__TAG, error); return error; }} while(0)


char const *errorToString(Error error);

#endif
