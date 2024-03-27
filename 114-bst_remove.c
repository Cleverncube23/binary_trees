#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree
 * @value: Value to be removed from the tree
 *
 * Return: Pointer to the new root node of the tree after removing the value,
 *         or NULL on failure or if `value` is not present in the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else
    {
        if (root->left == NULL)
        {
            bst_t *right_child = root->right;
            free(root);
            return right_child;
        }
        else if (root->right == NULL)
        {
            bst_t *left_child = root->left;
            free(root);
            return left_child;
        }

        bst_t *min_right_subtree = root->right;
        while (min_right_subtree->left != NULL)
            min_right_subtree = min_right_subtree->left;

        root->n = min_right_subtree->n;
        root->right = bst_remove(root->right, min_right_subtree->n);
    }

    return root;
}

