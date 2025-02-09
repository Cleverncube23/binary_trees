#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height
 *
 * Return: The height of the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    /* Recursively calculate the height of the left subtree */
    left_height = binary_tree_height(tree->left);

    /* Recursively calculate the height of the right subtree */
    right_height = binary_tree_height(tree->right);

    /* Return the maximum of the left and right subtree heights, plus 1 for the root */
    return (1 + (left_height > right_height ? left_height : right_height));
}
