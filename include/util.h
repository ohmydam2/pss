#ifndef UTIL_H
#define UTIL_H

#include "hash.h"

#define METADATA_OUT_FOLDER "metadata/"
#define DATA_OUT_FOLDER "data/"
#define HASH_STRING_SIZE 16


void separateFileNameAndExtension(char const *fileName, char **name, char **extension);
void getDataAndMetadataFileNames(uint64_t hash, char **dataName, char **metadataName);


#endif