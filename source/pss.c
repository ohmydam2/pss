#include <stdint.h>

#include "pss.h"



/***** MAIN *****/

int main(int argc, char const **argv) {
#define TAG "main"
    Command command;
    BURN(checkArguments(argc, argv, &command));

    FIRE(ERROR_OK);
#undef TAG
}



/***** ERROR *****/

char const *errorToString(Error error) {
    switch (error) {
        case (ERROR_OK):
            return "ERROR_OK";
        case (ERROR_INVALID_ARGUMENTS):
            return "ERROR_INVALID_ARGUMENTS";
        default:
            return "INVALID ERROR CODE";
     }
}



/***** HELP *****/

Error checkArguments(int argc, char const **argv, Command *command) {
#define TAG "checkArguments"
    if (argc < 2) goto sos;

    int isAdd = strcmp(argv[1], "add");
    int isClean = strcmp(argv[1], "clean");

    if (isAdd == 0) {
        if (argc < 3) goto sos;
        else *command = ADD;
    }
    else if (isClean == 0) {
        if (argc > 2) goto sos;
        else *command = CLEAN;
    } else goto sos;

    FIRE(ERROR_OK);

sos:
    LOG("\n" USAGE_MESSAGE);
    FIRE(ERROR_INVALID_ARGUMENTS);
#undef TAG
}

