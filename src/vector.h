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
void Vector_Clone(Vector *vector, const Vector *source);
void Vector_Destroy(Vector *vector);
void Vector_Push(Vector *vector, const void *element);
void Vector_Pop(Vector *vector, void *element);
void Vector_Add(Vector *vector, size_t index, const void *element);
void Vector_Remove(Vector *vector, size_t index);
void Vector_Grow(Vector *vector);
void Vector_Resize(Vector *vector, size_t newCapacity);

#define Vector_GetElementPointer(vector, index) ((void *)(((uint8_t *)((vector)->elements)) + ((index) * (vector)->elementSize)))
#define Vector_SetElementPointer(vector, index, element) Vector_Memcpy(Vector_GetElementPointer(vector, index), element, (vector)->elementSize)

#define Vector_GetArray(vector, type) ((type *)((vector)->elements))
#define Vector_GetElementValue(vector, type, index) Vector_GetArray(vector, type)[index]
#define Vector_SetElementValue(vector, type, index, element) (Vector_GetArray(vector, type)[index] = (element))

#define Vector_PushValue(vector, type, element) \
{ \
    if((vector)->count == (vector)->capacity) \
    { \
        Vector_Grow(vector); \
    } \
    Vector_GetArray(vector, type)[(vector)->count] = (element); \
    (vector)->count++; \
}
#define Vector_PopValue(vector, type) Vector_GetElementValue(vector, type, --(vector)->count)
#define Vector_AddValue(vector, index, type, element) \
{ \
    if((vector)->count == (vector)->capacity) \
    { \
        Vector_Grow(vector); \
    } \
    Vector_Memmove(Vector_GetArray(vector, type) + 1, Vector_GetArray(vector, type), ((vector)->count - (index)) * (vector)->elementSize); \
    Vector_GetArray(vector, type)[index] = (element); \
    (vector)->count++; \
}

#endif /* _VECTOR_H_ */
