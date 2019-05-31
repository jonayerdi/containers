#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h> /* size_t, NULL */
#include <stdint.h> /* uint8_t */
#include <string.h> /* memcpy, memmove */

typedef struct
{ 
    void *elements;
    size_t elementSize;
    size_t count;
    size_t capacity;
} Array;

void Array_Push(Array *array, const void *element);
void Array_PushAll(Array *array, const void *elements, size_t count);
int Array_Pop(Array *array, void *element);
void Array_Add(Array *array, size_t index, const void *element);
void Array_Remove(Array *array, size_t index);

#define Array_GetElementPointer(array, index) ((void *)(((uint8_t *)((array)->elements)) + ((index) * (array)->elementSize)))
#define Array_SetElementPointer(array, index, element) memcpy(Array_GetElementPointer(array, index), element, (array)->elementSize)

#define Array_WithType(array, type) ((type *)((array)->elements))
#define Array_GetElement(array, type, index) Array_WithType(array, type)[index]

#define Array_PushValue(array, type, element) \
{ \
    Array_WithType(array, type)[(array)->count] = (element); \
    (array)->count++; \
}
#define Array_PopValue(array, type) Array_GetElementValue(array, type, --(array)->count)
#define Array_AddValue(array, index, type, element) \
{ \
    memmove(Array_GetElementPointer(array, (index) + 1), Array_GetElementPointer(array, index), ((array)->count - (index)) * (array)->elementSize); \
    Array_WithType(array, type)[index] = (element); \
    (array)->count++; \
}

#endif /* ARRAY_H */
