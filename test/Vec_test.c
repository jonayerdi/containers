#include "test.h"
#include "Vec.h"

/* Tests */
void test1();
void test2();

int main(void)
{
	test_printf("\n**************************** test1 start ****************************\n");
	test1();
	test_printf("\n*************************** test1 success ***************************\n");
	test_printf("\n**************************** test2 start ****************************\n");
	test2();
	test_printf("\n*************************** test2 success ***************************\n");
	test_assert(test_allocations_count() == 0); /* Check for memory leaks just in case */
	return 0;
}

void test1()
{
	//Init
	Vec vec;
	Vec_Init(&vec, sizeof(int), 5);
	//Add values
	int val1 = 1, val2 = 3;
    Vec_Push(&vec, &val1);
	Vec_PushValue(&vec, int, 2);
	Vec_Push(&vec, &val2);
	Vec_PushValue(&vec, int, 4);
	//Print data
	for(size_t i = 0 ; i < vec.count ; i++)
		printf("%d ", Vec_GetElementValue(&vec, int, i));
	//Destroy
	Vec_Destroy(&vec);
	test_assert(test_allocations_count() == 0); /* Check for memory leaks */
}

void test2()
{
	//Init
	Vec vec;
	Vec_Init(&vec, sizeof(int), 4);
	//Add values
	int val1 = 1, val2 = 3;
	Vec_AddValue(&vec, 0, int, 4);
	Vec_Add(&vec, 0, &val2);
    Vec_AddValue(&vec, 0, int, 2);
	Vec_Add(&vec, 0, &val1);
	Vec_AddValue(&vec, 1, int, 5);
	//Print data
	for(size_t i = 0 ; i < vec.count ; i++)
		printf("%d ", Vec_GetElementValue(&vec, int, i));
	//Destroy
	Vec_Destroy(&vec);
	test_assert(test_allocations_count() == 0); /* Check for memory leaks */
}
