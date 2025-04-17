#include "hash.h"
#include "log.h"

#include "komihash.h"

#include <stdio.h>


Error hashFile(char const *fileName, uint64_t *hash) {
#define TAG "hashFile"
    FILE *fileHandle = fopen(fileName, "r");
    if (fileHandle == NULL)
        FIRE(ERROR_IO, "Couldn't open file '%s'", fileName);

    komihash_stream_t hashStreamContext;
    komihash_stream_init(&hashStreamContext, 0);

    uint8_t block[BLOCK_SIZE];
    do {
        size_t count = fread(block, sizeof(uint8_t), BLOCK_SIZE, fileHandle);
        if (ferror(fileHandle)) {
            fclose(fileHandle);
            FIRE(ERROR_IO, "Error while reading file '%s'", fileName);
        }

        komihash_stream_update(&hashStreamContext, block, count * sizeof(uint8_t));
    } while (!feof(fileHandle));

    *hash = komihash_stream_final(&hashStreamContext);

    fclose(fileHandle);
    return ERROR_OK;
#undef TAG
}