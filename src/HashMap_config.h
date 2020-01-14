#ifndef HASH_MAP_CONFIG_H
#define HASH_MAP_CONFIG_H

#include "Containers_config.h"

#include "CRC32.h"

/* Hasher */
typedef uint32_t HashType;
#define HashMap_Hash(data, size) CRC32_Compute(data, size)

typedef void *HashMapKey;
typedef void *HashMapValue;

/* Increase HashMap capacity when HashMap.keys.count / HashMap.bins.count > HASH_MAP_GROWTH_THRESHOLD */
#define HASH_MAP_GROWTH_THRESHOLD ((size_t) 2)
/* Increase HashMap.bins.capacity by this factor */
#define HASH_MAP_GROWTH_FACTOR ((size_t) 8)

#define HashMap_Malloc(size) Containers_Malloc(size)
#define HashMap_Realloc(pointer, size) Containers_Realloc(pointer, size)
#define HashMap_Free(pointer) Containers_Free(pointer)
#define HashMap_Memcpy(destination, source, size) Containers_Memcpy(destination, source, size)
#define HashMap_Memmove(destination, source, size) Containers_Memmove(destination, source, size)

#endif /* HASH_MAP_CONFIG_H */
