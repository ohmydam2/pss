#ifndef INTERFACE_H
#define INTERFACE_H

#include "command.h"
#include "log.h"


#define USAGE_MESSAGE   \
    "Usage:\n"          \
    "pss add [files]\n" \
    "pss clean\n"


Error checkArguments(int argc, char const **argv, Command *command);

#endif