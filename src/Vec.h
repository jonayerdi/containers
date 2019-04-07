#ifndef VEC_H
#define VEC_H

#include "Vec_config.h"

typedef struct
{ 
    void *elements;
    Vec_size elementSize;
    Vec_size count;
    Vec_size capacity;
} Vec;

void Vec_Init(Vec *vector, Vec_size elementSize, Vec_size initialCapacity);
void Vec_Clone(Vec *vector, const Vec *source);
void Vec_Destroy(Vec *vector);
void Vec_Push(Vec *vector, const void *element);
void Vec_PushAll(Vec *vector, const void *elements, Vec_size count);
void Vec_Pop(Vec *vector, void *element);
void Vec_Add(Vec *vector, Vec_size index, const void *element);
void Vec_Remove(Vec *vector, Vec_size index);
void Vec_Grow(Vec *vector);
void Vec_Resize(Vec *vector, Vec_size newCapacity);

#define Vec_GetElementPointer(vector, index) ((void *)(((Vec_u8 *)((vector)->elements)) + ((index) * (vector)->elementSize)))
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
    Vec_Memmove(Vec_GetArray(vector, type) + 1, Vec_GetArray(vector, type), ((vector)->count - (index)) * (vector)->elementSize); \
    Vec_GetArray(vector, type)[index] = (element); \
    (vector)->count++; \
}

#endif /* VEC_H */
