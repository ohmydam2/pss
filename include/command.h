#ifndef COMMAND_H
#define COMMAND_H

#include "log.h"


typedef enum Command {
    COMMAND_ADD,
    COMMAND_CHECK, // TODO
    COMMAND_CLEAN,
    COMMAND_OPEN   // TODO
} Command;


Error runAdd(int fileCount, char const **fileNames);
Error runClean(void);

Error runCommand(int argc, char const **argv, Command command);

#endif