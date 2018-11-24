
#ifndef _TEST_H_
#define _TEST_H_

#include <stdio.h> /* fprintf */
#include <stdlib.h> /* abort, malloc, realloc, free */

/* Output */
#define test_fprintf fprintf
#define test_printf printf
#define test_assert(expression) \
if (!(expression)) \
{ \
	test_fprintf(stderr, "\nAssert failed: %s\nat function %s\nat line %d\n", #expression, __func__, __LINE__); \
	abort(); \
}

/* Memory leak check */
#ifndef TEST_ALLOCATIONS_NO_BUFFER
#ifndef TEST_MAX_MEMORY_ALLOCATIONS
#define TEST_MAX_MEMORY_ALLOCATIONS 1024u
#endif /* TEST_MAX_MEMORY_ALLOCATIONS */
void *_test_allocations_buffer[TEST_MAX_MEMORY_ALLOCATIONS];
#define TEST_INIT_MEMORY() test_init_memory(_test_allocations_buffer, TEST_MAX_MEMORY_ALLOCATIONS)
#endif /* TEST_ALLOCATIONS_NO_BUFFER */

/* Shifts ARRAY to the left, changes values from ARRAY[INDEX] to ARRAY[SIZE-2] */
#define ARRAY_SHIFT_LEFT(ARRAY,INDEX,SIZE) for(size_t _index = (INDEX) ; _index < (SIZE)  - 1 ; _index++) { (ARRAY)[_index] = (ARRAY)[_index + 1]; }

void test_init_allocations(void **buffer, size_t capacity);
size_t test_allocations_count(void);
void *test_malloc(const size_t size);
void *test_realloc(void *oldptr, const size_t size);
void test_free(void *ptr);

#endif /* _TEST_H_ */
