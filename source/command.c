#include "command.h"
#include "error.h"
#include "hash.h"
#include "log.h"
#include "util.h"

#include <stdio.h>
#include <string.h>


Error runAdd(int fileCount, char const *fileNames[]) {
#define TAG "runAdd"
    FILE **inFiles = calloc(fileCount, sizeof(FILE *));
    FILE **dataFiles = calloc(fileCount, sizeof(FILE *));
    FILE **metadataFiles = calloc(fileCount, sizeof(FILE *));
    
    size_t iTop = 0;
    size_t dTop = 0;
    size_t mTop = 0;

    Error returnError = ERROR_OK;

    for (int i = 0; (i < fileCount) && (returnError == ERROR_OK); i++) {
        inFiles[i] = fopen(fileNames[i], "r");
        if (inFiles[i] == NULL) {
            START_ERROR_STACK;
            LOG("Couldn't open file '%s'", fileNames[i]);
            returnError = ERROR_IO;
            break;
        }

        iTop++;

        char *name;
        char *extension;
        separateFileNameAndExtension(fileNames[i], &name, &extension);

        uint64_t hash;
        Error error = hashFile(inFiles[i], &hash);
        if (error != ERROR_OK) {
            START_ERROR_STACK;
            returnError = error;

            free(name);
            free(extension);

            break;
        }

        char *dataName;
        char *metadataName;
        getDataAndMetadataFileNames(hash, &dataName, &metadataName);

        dataFiles[i] = fopen(dataName, "w");
        if (dataFiles[i] == NULL) {
            START_ERROR_STACK;
            LOG("Couldn't open data file for '%s' (should be '%s')", fileNames[i], dataName);
            returnError = ERROR_IO;

            goto str_cleanup;
        }

        dTop++;

        metadataFiles[i] = fopen(metadataName, "w");
        if (metadataFiles[i] == NULL) {
            START_ERROR_STACK;
            LOG("Couldn't open metadata file for '%s' (should be '%s')", fileNames[i], metadataName);
            returnError = ERROR_IO;
            
            goto str_cleanup;
        }

        mTop++;


str_cleanup:
        free(name);
        free(extension);
        free(dataName);
        free(metadataName);
    }

    for (int i = 0; i < iTop; i++)
        fclose(inFiles[i]);
    for (int i = 0; i < dTop; i++)
        fclose(dataFiles[i]); 
    for (int i = 0; i < mTop; i++)
        fclose(metadataFiles[i]);

    BURN(returnError);
    
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