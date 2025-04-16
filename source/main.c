#include <stdint.h>

#include "log.h"
#include "error.h"
#include "hash.h"
#include "file.h"


#define TAG "MAIN"


int main(int argc, char const **argv) {
    if (argc < 2)
        BURN(TAG, ERROR_TOO_FEW_ARGUMENTS);

    char const *destination;
    BURN(TAG, readConfig(&destination));

    uint64_t hash;
    BURN(TAG, hash_file(argv[1], &hash));

    BURN(TAG, moveFile(argv[1], destination));

    if (argc == 2) {
       BURN(TAG, createDescriptionFile(destination, NULL, 0, NULL);
    } else if (argc == 3) {
       BURN(TAG, createDescriptionFile(destination, argv[2], 0, NULL);
    } else {
       BURN(TAG, createDescriptionFile(destination, argv[2], argc-3, argv+3);
    }

    BURN(TAG, ERROR_OK);
}
