#include "log.h"


char const *errorToString(Error error) {
    switch (error) {
        case (ERROR_OK):
            return "ERROR_OK";
        case (ERROR_INVALID_ARGUMENTS):
            return "ERROR_INVALID_ARGUMENTS";
        case (ERROR_IO):
            return "ERROR_IO";
        default:
            return "INVALID ERROR CODE";
     }
}