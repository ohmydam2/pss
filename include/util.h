#ifndef UTIL_H
#define UTIL_H

#define METADATA_OUT_FOLDER "metadata/"
#define DATA_OUT_FOLDER "data/"


void separateFileNameAndExtension(char const *fileName, char **name, char **extension);
void getDataAndMetadataFileNames(char const *name, char **dataName, char ** metadataName);


#endif