#include "Array.h"

void Array_Push(Array *array, const void *element)
{
    Array_SetElementPointer(array, array->count, element);
    array->count++;
}

void Array_PushAll(Array *array, const void *elements, size_t count) 
{
    memcpy(Array_GetElementPointer(array, array->count), elements, array->elementSize * count);
    array->count += count;
}

int Array_Pop(Array *array, void *element)
{
    if(array->count == 0) {
        return 0;
    }
    memcpy(element, Array_GetElementPointer(array, array->count - 1), array->elementSize);
    array->count--;
    return 1;
}

void Array_Add(Array *array, size_t index, const void *element)
{
    memmove(Array_GetElementPointer(array, index + 1), Array_GetElementPointer(array, index), (array->count - index) * array->elementSize);
    Array_SetElementPointer(array, index, element);
    array->count++;
}

void Array_Remove(Array *array, size_t index)
{
    memmove(Array_GetElementPointer(array, index), Array_GetElementPointer(array, index + 1), (array->count - index - 1) * array->elementSize);
    array->count--;
}
