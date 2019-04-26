#ifndef BST_H
#define BST_H

#include "BST_config.h"

typedef struct _BST
{
    struct _BST *left;
    struct _BST *right;
    void *value;
} BST;

void BST_Destroy(BST *root);
void BST_Insert(BST **root, void *element, int (*compare)(const void *, const void *));
BST *BST_Find(BST *root, void *value, int (*compare)(const void *, const void *));
void *BST_Remove(BST *root, void *value, int (*compare)(const void *, const void *));

#endif /* BST_H */
