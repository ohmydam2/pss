#include "command.h"
#include "interface.h"
#include "log.h"


int main(int argc, char const **argv) {
#define TAG "main"
    Command command;
    BURN(checkArguments(argc, argv, &command));

    BURN(runCommand(argc-2, argv+2, command));

    return ERROR_OK;
#undef TAG
}