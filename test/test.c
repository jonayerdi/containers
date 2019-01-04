#include "test.h"

/* Shifts ARRAY to the left, changes values from ARRAY[INDEX] to ARRAY[SIZE-2] */
#define ARRAY_SHIFT_LEFT(ARRAY,INDEX,SIZE) for(size_t _index = (INDEX) ; _index < (SIZE)  - 1 ; _index++) { (ARRAY)[_index] = (ARRAY)[_index + 1]; }

static void **_allocations_list[TEST_MAX_MEMORY_ALLOCATIONS];
static size_t _allocations_count;

static void _add_allocation(void *ptr);
static void _remove_allocation(void *ptr);

static void _add_allocation(void *ptr)
{
	test_assert(_allocations_count + 1 <= TEST_MAX_MEMORY_ALLOCATIONS); // Increase MAX_MEMORY_ALLOCATIONS if needed
	_allocations_list[_allocations_count++] = ptr; // Store allocated memory pointer
}
static void _remove_allocation(void *ptr)
{
	int found = 0;
	for(size_t i = 0 ; i < _allocations_count ; i++)
	{
		if(_allocations_list[i] == ptr)
		{
			ARRAY_SHIFT_LEFT(_allocations_list, i, _allocations_count); // Remove freed element from allocations list
			_allocations_count--;
			found = 1; 
			break;
		}
	}
	test_assert(found);
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
	_remove_allocation(ptr);
	free(ptr);
}
