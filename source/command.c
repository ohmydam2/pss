#include "command.h"

#include "error.h"
#include "hash.h"
#include "log.h"


Error runAdd(int fileCount, char const **fileNames) {
#define TAG "runAdd"
    // TODO
    for (int i = 0; i < fileCount; i++) {
        uint64_t hash;
        BURN(hashFile(fileNames[i], &hash));
        LOG("Hash of file %i is: %llx", i+1, hash);
    }
    
    return ERROR_OK;
#undef TAG
}
    
Error runClean(void) {
#define TAG "runClean"
    LOG("TODO");
    return ERROR_OK;
#undef TAG
}

Error runCommand(int argc, char const **argv, Command command) {
#define TAG "runCommand"
    switch (command)
    {
        case COMMAND_ADD:
            BURN(runAdd(argc, argv));
            break;
        case COMMAND_CLEAN:
            BURN(runClean());
            break;
        default:
            break;
    }

    return ERROR_OK;
#undef TAG
}