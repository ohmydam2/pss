#ifndef PSS_H
#define PSS_H


#include <stdio.h>
#include <string.h>

#include "komihash.h"



/***** LOG *****/

#define LOG(...) printf("%s: ", ((TAG))); printf(__VA_ARGS__); printf("\n");
#define LOGE(__ERROR) fprintf(stderr, "%s: ", ((TAG))); fprintf(stderr, errorToString(((__ERROR)))); fprintf(stderr, "\n")



/***** ERROR *****/

typedef enum Error {
    ERROR_OK = 0,
    ERROR_INVALID_ARGUMENTS = 1,
    ERROR_IO = 2
} Error;


#define FIRE(__ERROR) do { Error error = ((__ERROR)); LOGE(error); return error; } while (0)
#define BURN(__ERROR) do { Error error = ((__ERROR)); if (error != ERROR_OK) { LOGE(error); return error; }} while (0)


char const *errorToString(Error error);



/***** HELP *****/

typedef enum Command {
    ADD,
    CHECK, // TODO
    CLEAN,
    OPEN   // TODO
} Command;


#define USAGE_MESSAGE   \
    "Usage:\n"          \
    "pss add [files]\n" \
    "pss check\n"       \
    "pss clean\n"       \


Error checkArguments(int argc, char const **argv, Command *command);



/***** COMMAND FUNCTIONS *****/

Error runAdd(int fileCount, char const **fileNames);
Error runClean(void);

Error runCommand(int argc, char const **argv, Command command);



/***** HASH *****/

#define BLOCK_SIZE 1024


Error hashFile(char const *fileName, uint64_t *hash); 

#endif
