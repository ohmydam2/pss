#include <stdint.h>

#include "pss.h"



/***** MAIN *****/

int main(int argc, char const **argv) {
#define TAG "main"
    Command command;
    BURN(checkArguments(argc, argv, &command));

    BURN(runCommand(argc, argv, command));

    return ERROR_OK;
#undef TAG
}



/***** ERROR *****/

char const *errorToString(Error send_error) {
    switch (send_error) {
        case (ERROR_OK):
            return "ERROR_OK";
        case (ERROR_INVALID_ARGUMENTS):
            return "ERROR_INVALID_ARGUMENTS";
        case (ERROR_IO):
            return "ERROR_IO";
        default:
            return "INVALID ERROR CODE";
     }
}



/***** HELP *****/

Error checkArguments(int argc, char const **argv, Command *command) {
#define TAG "checkArguments"
    if (argc < 2) goto send_error;

    int isAdd = strcmp(argv[1], "add");
    if (isAdd == 0) {
        if (argc < 3) goto send_error;
        else *command = ADD;
    }

    int isClean = strcmp(argv[1], "clean");
    if (isClean == 0) {
        if (argc > 2) goto send_error;
        else *command = CLEAN;
    }

    if (!isAdd & !isClean) goto send_error;

    return ERROR_OK;

send_error:
    LOG("\n" USAGE_MESSAGE);
    FIRE(ERROR_INVALID_ARGUMENTS);
#undef TAG
}



/***** COMMAND FUNCTIONS *****/

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
    // TODO
    return ERROR_OK;
}

Error runCommand(int argc, char const **argv, Command command) {
#define TAG "runCommand"
    switch (command)
    {
    case ADD:
        BURN(runAdd(argc-2, argv+2));
        break;
    case CLEAN:
        BURN(runClean());
        break;
    default:
        break;
    }

    return ERROR_OK;
#undef TAG
}



/***** HASH *****/

Error hashFile(char const *fileName, uint64_t *hash) {
#define TAG "hashFile"
    FILE *fileHandle = fopen(fileName, "r");
    if (fileHandle == NULL) FIRE(ERROR_IO);

    komihash_stream_t hashStreamContext;
    komihash_stream_init(&hashStreamContext, 0);

    uint8_t block[BLOCK_SIZE];
    do {
        size_t count = fread(block, sizeof(uint8_t), BLOCK_SIZE, fileHandle);
        if (ferror(fileHandle)) {
            fclose(fileHandle);
            FIRE(ERROR_IO);
        }

        komihash_stream_update(&hashStreamContext, block, count * sizeof(uint8_t));
    } while (!feof(fileHandle));

    *hash = komihash_stream_final(&hashStreamContext);

    fclose(fileHandle);
    return ERROR_OK;
#undef TAG
}