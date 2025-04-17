#include "command.h"
#include "interface.h"
#include "log.h"

#include <string.h>


Error checkArguments(int argc, char const **argv, Command *command) {
#define TAG "checkArguments"
    if (argc < 2)
        FIRE(ERROR_INVALID_ARGUMENTS, "No command was specified" "\n" USAGE_MESSAGE);

    if (strcmp(argv[1], "add") == 0) {
        if (argc < 3)
            FIRE(ERROR_INVALID_ARGUMENTS, "Invalid syntax for 'add'" "\n" USAGE_MESSAGE);
        else {
            *command = COMMAND_ADD;
            return ERROR_OK;
        }
    }

    if (strcmp(argv[1], "clean") == 0) {
        if (argc > 2)
            FIRE(ERROR_INVALID_ARGUMENTS, "Invalid syntax for 'clean'" "\n" USAGE_MESSAGE);
        else {
            *command = COMMAND_CLEAN;
            return ERROR_OK;
        }
    }

    FIRE(ERROR_INVALID_ARGUMENTS, "No command matches '%s'" "\n" USAGE_MESSAGE, argv[1]);
#undef TAG
}