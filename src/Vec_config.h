#ifndef VEC_CONFIG_H
#define VEC_CONFIG_H

#include "Containers_config.h"

/* Increase Vec capacity by this factor */
#define VEC_GROWTH_FACTOR ((size_t) 2)

#define Vec_Malloc(size) Containers_Malloc(size)
#define Vec_Realloc(pointer, size) Containers_Realloc(pointer, size)
#define Vec_Free(pointer) Containers_Free(pointer)
#define Vec_Memcpy(destination, source, size) Containers_Memcpy(destination, source, size)
#define Vec_Memmove(destination, source, size) Containers_Memmove(destination, source, size)

#endif /* VEC_CONFIG_H */
