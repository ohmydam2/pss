#ifndef HASH_H
#define HASH_H

#include "log.h"

#include <stdint.h>


#define BLOCK_SIZE 1024


Error hashFile(char const *fileName, uint64_t *hash); 

#endif