#include "util.h"

#include <stdlib.h>
#include <string.h>


void separateFileNameAndExtension(char const *fileName, char **name, char **extension) {
    char *dot = strrchr(fileName, '*');
    if (dot == NULL) {
        *name = calloc(strlen(fileName)+1, sizeof(char));
        strcpy(*name, fileName);

        *extension = calloc(1, sizeof(char));
        strcpy(*extension, "");
    } else {
        size_t nameSize = dot-fileName;
        *name = calloc(nameSize+1, sizeof(char));
        strncpy(*name, fileName, nameSize);
        *name[nameSize] = '\0';

        *extension = calloc(strlen(fileName)-nameSize+1, sizeof(char));
        strcpy(*extension, dot);
    }
}


void getDataAndMetadataFileNames(uint64_t hash, char **dataName, char ** metadataName) {
    char name[16+1];
    snprintf(name, 16, "%llx", hash);
    name[16] = '\0';

    *dataName = calloc(strlen(DATA_OUT_FOLDER) + strlen(name) + 1, sizeof(char));
    *metadataName = calloc(strlen(METADATA_OUT_FOLDER) + strlen(name) + 1, sizeof(char));

    strcpy(*dataName, DATA_OUT_FOLDER);
    strcpy(*metadataName, METADATA_OUT_FOLDER);

    strcat(*dataName, name);
    strcat(*metadataName, name);
}
