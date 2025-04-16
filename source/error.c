#include "error.h"

char const *errorToString(Error error) {
    switch (error) {
        case (ERROR_OK):
            return "ERROR_OK";
        default:
            return "INVALID ERROR CODE";
     }
}
