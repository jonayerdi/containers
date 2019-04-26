#include "test.h"
#include "BST.h"

static int compare_int(const void *left, const void *right) {
	return *((int *)right) - *((int *)left);
}

static void printIntBST(BST *node) {
	if(node->left) {
		printIntBST(node->left);
	}
	printf("%d, ", *((int *)node->value));
	if(node->right) {
		printIntBST(node->right);
	}
}

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
	int values[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
	BST *root = NULL;
	BST_Insert(&root, &values[5], compare_int);
	BST_Insert(&root, &values[1], compare_int);
	BST_Insert(&root, &values[4], compare_int);
	BST_Insert(&root, &values[10], compare_int);
	BST_Insert(&root, &values[12], compare_int);
	BST_Insert(&root, &values[0], compare_int);
	BST_Insert(&root, &values[2], compare_int);
	BST_Insert(&root, &values[7], compare_int);
	BST_Insert(&root, &values[3], compare_int);
	BST_Insert(&root, &values[9], compare_int);
	BST_Insert(&root, &values[6], compare_int);
	BST_Insert(&root, &values[11], compare_int);
	BST_Insert(&root, &values[8], compare_int);
	test_assert(BST_Find(root, &values[0], compare_int) != NULL);
	test_assert(BST_Find(root, &values[1], compare_int) != NULL);
	test_assert(BST_Find(root, &values[2], compare_int) != NULL);
	test_assert(BST_Find(root, &values[3], compare_int) != NULL);
	test_assert(BST_Find(root, &values[4], compare_int) != NULL);
	test_assert(BST_Find(root, &values[5], compare_int) != NULL);
	test_assert(BST_Find(root, &values[6], compare_int) != NULL);
	test_assert(BST_Find(root, &values[7], compare_int) != NULL);
	test_assert(BST_Find(root, &values[8], compare_int) != NULL);
	test_assert(BST_Find(root, &values[9], compare_int) != NULL);
	test_assert(BST_Find(root, &values[10], compare_int) != NULL);
	test_assert(BST_Find(root, &values[11], compare_int) != NULL);
	test_assert(BST_Find(root, &values[12], compare_int) != NULL);
	test_assert(BST_Find(root, &values[13], compare_int) == NULL);
	printIntBST(root);
	BST_Destroy(root);
}

void test2()
{
	
}
