
#ifndef _MAP_H_
#define _MAP_H_

#include <stdint.h> /* uint8_t, uint32_t */
#include <stddef.h> /* size_t */
#include <stdlib.h> /* [malloc], [realloc], [free] */
#include <string.h> /* [memcpy], [memmove] */

typedef struct
{ 
    
} Map;

void Map_Init(Map *map, size_t keySize, size_t valueSize, size_t bucketSize);
void Map_Clone(Map *map, const Map *toCopy);
void Map_Destroy(Map *map);
void Map_Add(Map *map, const void *key, const void *value);
void Map_Remove(Map *map, const void *key);
int Map_Get(Map *map, const void *key, void *value);

#endif /* _MAP_H_ */
