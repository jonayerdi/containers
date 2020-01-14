#ifndef VEC_H
#define VEC_H

#include "Vec_config.h"

typedef struct
{ 
    void *elements;
    size_t elementSize;
    size_t count;
    size_t capacity;
} Vec;

void Vec_Init(Vec *vector, size_t elementSize, size_t initialCapacity);
void Vec_Clone(Vec *vector, const Vec *source);
void Vec_Destroy(Vec *vector);
void Vec_Grow(Vec *vector);
void Vec_Resize(Vec *vector, size_t newCapacity);
void Vec_Push(Vec *vector, const void *element);
void Vec_PushAll(Vec *vector, const void *elements, size_t count);
int Vec_Pop(Vec *vector, void *element);
void Vec_Add(Vec *vector, size_t index, const void *element);
void Vec_Remove(Vec *vector, size_t index);

#define Vec_GetElementPointer(vector, index) ((void *)(((uint8_t *)((vector)->elements)) + ((index) * (vector)->elementSize)))
#define Vec_SetElementPointer(vector, index, element) Vec_Memcpy(Vec_GetElementPointer(vector, index), element, (vector)->elementSize)

#define Vec_GetArray(vector, type) ((type *)((vector)->elements))
#define Vec_GetElementValue(vector, type, index) Vec_GetArray(vector, type)[index]
#define Vec_SetElementValue(vector, type, index, element) (Vec_GetArray(vector, type)[index] = (element))

#define Vec_PushValue(vector, type, element) \
{ \
    if((vector)->count == (vector)->capacity) \
    { \
        Vec_Grow(vector); \
    } \
    Vec_GetArray(vector, type)[(vector)->count] = (element); \
    (vector)->count++; \
}
#define Vec_PopValue(vector, type) Vec_GetElementValue(vector, type, --(vector)->count)
#define Vec_AddValue(vector, index, type, element) \
{ \
    if((vector)->count == (vector)->capacity) \
    { \
        Vec_Grow(vector); \
    } \
    Vec_Memmove(Vec_GetElementPointer(vector, (index) + 1), Vec_GetElementPointer(vector, index), ((vector)->count - (index)) * (vector)->elementSize); \
    Vec_GetArray(vector, type)[index] = (element); \
    (vector)->count++; \
}

#endif /* VEC_H */
