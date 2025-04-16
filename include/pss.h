#ifndef PSS_H
#define PSS_H


#include <stdio.h>
#include <string.h>


/***** LOG *****/

#define LOG(...) printf("%s: ", ((TAG))); printf(__VA_ARGS__); printf("\n");
#define LOGE(__ERROR) fprintf(stderr, "%s: ", ((TAG))); fprintf(stderr, errorToString(((__ERROR)))); fprintf(stderr, "\n")



/***** ERROR *****/

typedef enum Error {
    ERROR_OK = 0,
    ERROR_INVALID_ARGUMENTS = 1
} Error;


#define FIRE(__ERROR) do { Error error = ((__ERROR)); LOGE(error); return error; } while(0)

#define BURN(__ERROR) do { Error error = ((__ERROR)); if (error != ERROR_OK) { LOGE(error); return error; }} while(0)


char const *errorToString(Error error);



/***** HELP *****/

typedef enum Command {
    ADD,
    CLEAN
} Command;


#define USAGE_MESSAGE   \
    "Usage:\n"          \
    "pss add [files]\n" \
    "pss clean\n"


Error checkArguments(int argc, char const **argv, Command *command);


#endif
