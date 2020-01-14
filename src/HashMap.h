#ifndef HASH_MAP_H
#define HASH_MAP_H

#include "HashMap_config.h"

#include "Vec.h"

typedef struct
{ 
    Vec bins;
    Vec keys;
    size_t elementSize;
} HashMap;

void HashMap_Init(HashMap *map, size_t keySize, size_t elementSize, size_t initialKeysCapacity, size_t initialBinsCount);
void HashMap_Clone(HashMap *map, const HashMap *source);
void HashMap_Destroy(HashMap *map);
void HashMap_Grow(HashMap *map);
void HashMap_Resize(HashMap *map, size_t newCapacity);
bool HashMap_Insert(HashMap *map, const HashMapKey key, const HashMapValue value, HashMapValue old_value);
bool HashMap_Get(HashMap *map, const HashMapKey key, HashMapValue *value);
bool HashMap_Remove(HashMap *map, const HashMapKey key, HashMapValue old_value);

#endif /* HASH_MAP_H */
