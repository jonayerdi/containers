#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "vector_config.h"

typedef struct
{ 
    void *elements;
    size_t elementSize;
    size_t count;
    size_t capacity;
} Vector;

void Vector_Init(Vector *vector, size_t elementSize, size_t initialCapacity);
void Vector_Clone(Vector *vector, const Vector *toCopy);
void Vector_Destroy(Vector *vector);
void Vector_Add(Vector *vector, const void *element);
void Vector_AddIndex(Vector *vector, size_t index, const void *element);
void Vector_Remove(Vector *vector, size_t index);
void Vector_Grow(Vector *vector);
void Vector_Resize(Vector *vector, size_t newCapacity);

#define Vector_GetElementPointerNoType(vector, index) ((void *)(((uint8_t *)((vector)->elements)) + ((index) * (vector)->elementSize)))
#define Vector_SetElementNoType(vector, index, element) Vector_Memcpy(Vector_GetElementPointerNoType(vector, index), element, (vector)->elementSize)

#define Vector_GetArray(vector, type) ((type *)((vector)->elements))
#define Vector_GetElementPointer(vector, type, index) (Vector_GetArray(vector, type) + index)
#define Vector_GetElement(vector, type, index) Vector_GetArray(vector, type)[index]

#define Vector_AddValue(vector, type, element) \
{ \
    if((vector)->count == (vector)->capacity) \
    { \
        Vector_Grow(vector); \
    } \
    Vector_GetArray(vector, type)[(vector)->count] = (element); \
    (vector)->count++; \
}
#define Vector_AddValueIndex(vector, index, type, element) \
{ \
    if((vector)->count == (vector)->capacity) \
    { \
        Vector_Grow(vector); \
    } \
    Vector_Memmove(Vector_GetArray(vector, type) + 1, Vector_GetArray(vector, type), ((vector)->count - (index)) * (vector)->elementSize); \
    Vector_GetArray(vector, type)[index] = (element); \
    (vector)->count++; \
}

#define Vector_Foreach(vector, type, index, element) for((index) = 0 ; (index) < (vector)->count, (element) = Vector_GetElement(vector, type, index) ; (index)++)

#endif /* _VECTOR_H_ */
