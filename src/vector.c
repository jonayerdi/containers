#include "vector.h"

void Vector_Init(Vector *vector, size_t elementSize, size_t initialCapacity)
{
    vector->elementSize = elementSize;
    vector->capacity = initialCapacity;
    vector->count = 0;
    vector->elements = Vector_Malloc(initialCapacity * elementSize);
}

void Vector_Clone(Vector *vector, const Vector *source)
{
    vector->elementSize = source->elementSize;
    vector->capacity = source->count;
    vector->count = source->count;;
    vector->elements = Vector_Malloc(vector->count * vector->elementSize);
    Vector_Memcpy(vector->elements, source->elements, vector->count * vector->elementSize);
}

void Vector_Destroy(Vector *vector)
{
    Vector_Free(vector->elements);
    vector->elementSize = 0;
    vector->capacity = 0;
    vector->count = 0;
}

void Vector_Push(Vector *vector, const void *element)
{
    if(vector->count == vector->capacity)
    {
        Vector_Grow(vector);
    }
    Vector_SetElementPointer(vector, vector->count, element);
    vector->count++;
}

void Vector_Pop(Vector *vector, void *element)
{
    Vector_Memcpy(element, Vector_GetElementPointer(vector, vector->count - 1), vector->elementSize);
    vector->count--;
}

void Vector_Add(Vector *vector, size_t index, const void *element)
{
    if(vector->count == vector->capacity)
    {
        Vector_Grow(vector);
    }
    Vector_Memmove(Vector_GetElementPointer(vector, index + 1), Vector_GetElementPointer(vector, index), (vector->count - index) * vector->elementSize);
    Vector_SetElementPointer(vector, index, element);
    vector->count++;
}

void Vector_Remove(Vector *vector, size_t index)
{
    Vector_Memmove(Vector_GetElementPointer(vector, index), Vector_GetElementPointer(vector, index + 1), (vector->count - index - 1) * vector->elementSize);
    vector->count--;
}

void Vector_Grow(Vector *vector)
{
    size_t newCapacity = (vector->capacity * VECTOR_GROWTH_FACTOR) + 1;
    Vector_Resize(vector, newCapacity);
}

void Vector_Resize(Vector *vector, size_t newCapacity)
{
    vector->elements = Vector_Realloc(vector->elements, newCapacity);
    vector->capacity = newCapacity;
}
