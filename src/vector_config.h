#include <stdint.h> /* uint8_t */
#include <stddef.h> /* size_t */

#include <stdlib.h> /* malloc, realloc, free */
#include <string.h> /* memcpy, memmove */

#define VECTOR_GROWTH_FACTOR ((size_t) 2)

#define Vector_Malloc(size) malloc(size)
#define Vector_Realloc(pointer, size) realloc(pointer, size)
#define Vector_Free(pointer) free(pointer)
#define Vector_Memcpy(destination, source, size) memcpy(destination, source, size)
#define Vector_Memmove(destination, source, size) memmove(destination, source, size)
