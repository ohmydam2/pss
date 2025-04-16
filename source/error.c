#include "error.h"

char const *errorToString(Error error) {
    switch (error) {
        case (ERROR_OK):
            return "ERROR_OK";
        case (ERROR_TOO_FEW_ARGUMENTS):
            return "ERROR_TOO_FEW_ARGUMENTS";
        default:
            return "INVALID ERROR CODE";
     }
}
