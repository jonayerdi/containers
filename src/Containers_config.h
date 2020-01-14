#ifndef CONTAINERS_CONFIG_H
#define CONTAINERS_CONFIG_H

#include <stdbool.h> /* bool */
#include <stdint.h> /* uint8_t */
#include <stddef.h> /* size_t */

#include <stdlib.h> /* malloc, realloc, free */
#include <string.h> /* memcpy, memmove */

#define Containers_Malloc(size) malloc(size)
#define Containers_Realloc(pointer, size) realloc(pointer, size)
#define Containers_Free(pointer) free(pointer)
#define Containers_Memcpy(destination, source, size) memcpy(destination, source, size)
#define Containers_Memmove(destination, source, size) memmove(destination, source, size)

#endif /* CONTAINERS_CONFIG_H */
