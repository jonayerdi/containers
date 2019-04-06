#include "test.h"
#include "Vec.h"

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


