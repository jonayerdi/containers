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
	Vec_Init(&vec, sizeof(int), 1);
	//Add values
	int val1 = 1, val2 = 3;
    Vec_Push(&vec, &val1);
	Vec_PushValue(&vec, int, 2);
	Vec_Push(&vec, &val2);
	Vec_PushValue(&vec, int, 4);
	//Print data
	for(size_t i = 0 ; i < vec.count ; i++)
		printf("%d ", Vec_GetElementValue(&vec, int, i));
	puts("\n");
	int value;
	while(Vec_Pop(&vec, &value))
		printf("%d ", value);
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
	int val1 = 1, val2 = 2, val3 = 3, val4 = 4, val5 = 5;
	Vec_Add(&vec, 0, &val5);
	Vec_Add(&vec, 0, &val4);
	Vec_Add(&vec, 0, &val3);
	Vec_Add(&vec, 0, &val2);
	Vec_Add(&vec, 0, &val1);
	Vec_AddValue(&vec, 1, int, 7);
	Vec_AddValue(&vec, 1, int, 7);
	Vec_AddValue(&vec, 1, int, 7);
	//Print data
	for(size_t i = 0 ; i < vec.count ; i++)
		printf("%d ", Vec_GetElementValue(&vec, int, i));
	//Destroy
	Vec_Destroy(&vec);
	test_assert(test_allocations_count() == 0); /* Check for memory leaks */
}
