#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: A pointer to the node to measure the depth
 *
 * Return: The depth of the node, or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;

    /* Traverse up the tree to the root, counting the number of edges */
    while (tree && tree->parent)
    {
        tree = tree->parent;
        depth++;
    }

    return (depth);
}
