#ifndef HASH_H
#define HASH_H

#include "log.h"

#include <stdio.h>
#include <stdint.h>


#define BLOCK_SIZE 1024


Error hashFile(FILE *fileHandle, uint64_t *hash); 

#endif