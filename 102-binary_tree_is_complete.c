#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    int has_null_child = 0;
    const binary_tree_t *temp = NULL;

    if (!tree)
        return (0);

    if (!tree->left && !tree->right)
        return (1);

    if ((!tree->left && tree->right) || (tree->left && !tree->right))
        return (0);

    if (tree->left && tree->right)
    {
        if (binary_tree_is_complete(tree->left) && binary_tree_is_complete(tree->right))
            return (1);
        else
            return (0);
    }

    temp = tree;
    while (temp)
    {
        if (temp->left)
        {
            if (has_null_child)
                return (0);
            temp = temp->left;
        }
        else if (temp->right)
        {
            return (0);
        }
        else
        {
            has_null_child = 1;
            temp = temp->right;
        }
    }

    return (1);
}
