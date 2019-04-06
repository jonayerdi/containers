#include "Vec.h"

void Vec_Init(Vec *vector, size_t elementSize, size_t initialCapacity)
{
    vector->elementSize = elementSize;
    vector->capacity = initialCapacity;
    vector->count = 0;
    vector->elements = Vec_Malloc(initialCapacity * elementSize);
}

void Vec_Clone(Vec *vector, const Vec *source)
{
    vector->elementSize = source->elementSize;
    vector->capacity = source->count;
    vector->count = source->count;;
    vector->elements = Vec_Malloc(vector->count * vector->elementSize);
    Vec_Memcpy(vector->elements, source->elements, vector->count * vector->elementSize);
}

void Vec_Destroy(Vec *vector)
{
    Vec_Free(vector->elements);
    vector->elementSize = 0;
    vector->capacity = 0;
    vector->count = 0;
}

void Vec_Push(Vec *vector, const void *element)
{
    if(vector->count == vector->capacity)
    {
        Vec_Grow(vector);
    }
    Vec_SetElementPointer(vector, vector->count, element);
    vector->count++;
}

void Vec_PushAll(Vec *vector, const void *elements, size_t count) 
{
    size_t newCount = vector->count + count;
    while(newCount >= vector->capacity)
    {
        Vec_Grow(vector);
    }
    Vec_Memcpy(Vec_GetElementPointer(vector, vector->count), elements, vector->elementSize * count);
    vector->count = newCount;
}

void Vec_Pop(Vec *vector, void *element)
{
    Vec_Memcpy(element, Vec_GetElementPointer(vector, vector->count - 1), vector->elementSize);
    vector->count--;
}

void Vec_Add(Vec *vector, size_t index, const void *element)
{
    if(vector->count == vector->capacity)
    {
        Vec_Grow(vector);
    }
    Vec_Memmove(Vec_GetElementPointer(vector, index + 1), Vec_GetElementPointer(vector, index), (vector->count - index) * vector->elementSize);
    Vec_SetElementPointer(vector, index, element);
    vector->count++;
}

void Vec_Remove(Vec *vector, size_t index)
{
    Vec_Memmove(Vec_GetElementPointer(vector, index), Vec_GetElementPointer(vector, index + 1), (vector->count - index - 1) * vector->elementSize);
    vector->count--;
}

void Vec_Grow(Vec *vector)
{
    size_t newCapacity = (vector->capacity * VECTOR_GROWTH_FACTOR) + 1;
    Vec_Resize(vector, newCapacity);
}

void Vec_Resize(Vec *vector, size_t newCapacity)
{
    vector->elements = Vec_Realloc(vector->elements, newCapacity);
    vector->capacity = newCapacity;
}
