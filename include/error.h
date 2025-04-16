#ifndef ERROR_H
#define ERROR_H

typedef enum Error {
    ERROR_OK = 0
} Error;


#define PROPAGATE(__ERROR) do { Error error = ((__ERROR)); if (error != ERROR_OK) return error; } while (0)


char const *errorToString(Error error);

#endif
