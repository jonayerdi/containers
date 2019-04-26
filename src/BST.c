#include "BST.h"

static void BST_RemoveNode(BST *node, BST **parentRef) {
    if(parentRef != BST_NULL) {
        if(node->left == BST_NULL) {
            *parentRef = node->right;
        } else if(node->right == BST_NULL) {
            *parentRef = node->left;
        } else {
            BST *inOrderSuccessor = node->right;
            BST **inOrderSuccessorParentRef = BST_NULL;
            while(inOrderSuccessor->left != BST_NULL) {
                inOrderSuccessorParentRef = &inOrderSuccessor->left;
                inOrderSuccessor = inOrderSuccessor->left;
            }
            if(inOrderSuccessorParentRef != BST_NULL) {
                *inOrderSuccessorParentRef = inOrderSuccessor->right;
                inOrderSuccessor->right = node->right;
            }
            *parentRef = inOrderSuccessor;
        }
    }
    BST_Free(node);
}

void BST_Destroy(BST *node) {
    if(node != BST_NULL) {
        BST_Destroy(node->left);
        BST_Destroy(node->right);
        BST_Free(node);
    }
}

void BST_Insert(BST **root, void *element, int (*compare)(const void *, const void *)) {
    BST *rootValue = *root;
    while(rootValue != BST_NULL) {
        root = compare(rootValue->value, element) > 0 ? &rootValue->right : &rootValue->left;
        rootValue = *root;
    }
    BST *newNode = BST_Malloc(sizeof(BST));
    newNode->left = BST_NULL;
    newNode->right = BST_NULL;
    newNode->value = element;
    *root = newNode;
}

BST *BST_Find(BST *root, void *value, int (*compare)(const void *, const void *)) {
    while(root != BST_NULL) {
        int cmp = compare(root->value, value);
        if(cmp < 0) {
            root = root->left;
        } else if(cmp > 0) {
            root = root->right;
        } else {
            return root;
        }
    }
    return BST_NULL;
}

void *BST_Remove(BST *root, void *value, int (*compare)(const void *, const void *)) {
    BST **parentRef = BST_NULL;
    while(root != BST_NULL) {
        int cmp = compare(root->value, value);
        if(cmp < 0) {
            parentRef = &root->left;
            root = root->left;
        } else if(cmp > 0) {
            parentRef = &root->right;
            root = root->right;
        } else {
            void *result = root->value;
            BST_RemoveNode(root, parentRef);
            return result;
        }
    }
    return BST_NULL;
}
