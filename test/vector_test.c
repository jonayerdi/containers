#include "test.h"
#include "vector.h"

/* Tests */
void test1();

int main(void)
{
	test_printf("\n**************************** test1 start ****************************\n");
	test1();
	test_printf("\n*************************** test1 success ***************************\n");
	test_assert(test_allocations_count() == 0); /* Check for memory leaks just in case */
	return 0;
}

void test1()
{
	//Init
	Vector vec;
	Vector_Init(&vec, sizeof(int), 5);
	//Add values
	int val1 = 1, val2 = 3;
    Vector_Add(&vec, &val1);
	Vector_AddValue(&vec, int, 2);
	Vector_Add(&vec, &val2);
	Vector_AddValue(&vec, int, 4);
	//Print data
	for(size_t i = 0 ; i < vec.count ; i++)
		printf("%d ", Vector_GetElement(&vec, int, i));
	//Destroy
	Vector_Destroy(&vec);
	
	test_assert(test_allocations_count() == 0); /* Check for memory leaks */
}


