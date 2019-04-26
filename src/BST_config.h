#ifndef BST_CONFIG_H
#define BST_CONFIG_H

#include <stddef.h> /* NULL */

#include <stdlib.h> /* malloc, free */
#include <string.h> /* memcpy, memmove */

#define BST_NULL NULL

#define BST_Malloc(size) malloc(size)
#define BST_Free(pointer) free(pointer)
#define BST_Memcpy(destination, source, size) memcpy(destination, source, size)
#define BST_Memmove(destination, source, size) memmove(destination, source, size)

#endif /* BST_CONFIG_H */
