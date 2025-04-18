#include "hash.h"
#include "log.h"

#include "komihash.h"

#include <stdio.h>


Error hashFile(FILE *fileHandle, uint64_t *hash) {
#define TAG "hashFile"
    komihash_stream_t hashStreamContext;
    komihash_stream_init(&hashStreamContext, 0);

    uint8_t block[BLOCK_SIZE];
    do {
        size_t count = fread(block, sizeof(uint8_t), BLOCK_SIZE, fileHandle);
        if (ferror(fileHandle)) {
            fclose(fileHandle);
            FIRE(ERROR_IO, "Couldn't read file");
        }

        komihash_stream_update(&hashStreamContext, block, count * sizeof(uint8_t));
    } while (!feof(fileHandle));

    *hash = komihash_stream_final(&hashStreamContext);

    return ERROR_OK;
#undef TAG
}