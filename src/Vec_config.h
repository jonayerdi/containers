#ifndef VEC_CONFIG_H
#define VEC_CONFIG_H

#include <stdint.h> /* uint8_t */
#include <stddef.h> /* size_t */

#include <stdlib.h> /* malloc, realloc, free */
#include <string.h> /* memcpy, memmove */

typedef uint8_t Vec_u8;
typedef size_t Vec_size;

#define VEC_GROWTH_FACTOR ((Vec_size) 2)

#define Vec_Malloc(size) malloc(size)
#define Vec_Realloc(pointer, size) realloc(pointer, size)
#define Vec_Free(pointer) free(pointer)
#define Vec_Memcpy(destination, source, size) memcpy(destination, source, size)
#define Vec_Memmove(destination, source, size) memmove(destination, source, size)

#endif /* VEC_CONFIG_H */
