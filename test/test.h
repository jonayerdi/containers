
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
#ifndef TEST_MAX_MEMORY_ALLOCATIONS
#define TEST_MAX_MEMORY_ALLOCATIONS 1024u
#endif /* TEST_MAX_MEMORY_ALLOCATIONS */

size_t test_allocations_count(void);
void *test_malloc(const size_t size);
void *test_realloc(void *oldptr, const size_t size);
void test_free(void *ptr);

#endif /* _TEST_H_ */
