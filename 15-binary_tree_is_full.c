#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: A pointer to the root node of the tree
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    /* Base case: An empty tree is full */
    if (tree == NULL)
        return (1);

    /* If the node is a leaf, it is full by definition */
    if (tree->left == NULL && tree->right == NULL)
        return (1);

    /* If the node has two children, check if both subtrees are full */
    if (tree->left && tree->right)
        return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

    /* If the node has only one child, the tree is not full */
    return (0);
}
