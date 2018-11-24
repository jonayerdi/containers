
#include "test.h"

void **_allocations_list;
size_t _allocations_capacity;
size_t _allocations_count;

static void _add_allocation(void *ptr);
static void _remove_allocation(void *ptr);

static void _add_allocation(void *ptr)
{
	test_assert(_allocations_count + 1 <= _allocations_capacity); //Increase MAX_MEMORY_ALLOCATIONS if needed
	_allocations_list[_allocations_count++] = ptr; //Store allocated memory pointer
}
static void _remove_allocation(void *ptr)
{
	int found = 0;
	for(size_t i = 0 ; i < _allocations_count ; i++)
	{
		if(_allocations_list[i] == ptr)
		{
			ARRAY_SHIFT_LEFT(_allocations_list, i, _allocations_count); //Remove freed element from allocations list
			_allocations_count--;
			found = 1; 
			break;
		}
	}
	test_assert(found);
}

void test_init_allocations(void **buffer, size_t capacity)
{
	_allocations_list = buffer;
	_allocations_capacity = capacity;
	_allocations_count = 0u;
}
size_t test_allocations_count(void)
{
	return _allocations_count;
}

void *test_malloc(const size_t size)
{
	void *ptr = malloc(size);
	_add_allocation(ptr);
	return ptr;
}
void *test_realloc(void *oldptr, const size_t size)
{
	void *newptr = realloc(oldptr, size);
	_remove_allocation(oldptr);
	_add_allocation(newptr);
	return newptr;
}
void test_free(void *ptr)
{
	int found = 0;
	_remove_allocation(ptr);
	free(ptr);
}
