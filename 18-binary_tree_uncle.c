#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: A pointer to the node to find the uncle
 *
 * Return: A pointer to the uncle node, or NULL if node is NULL, the parent
 *         is NULL, or node has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
        return (NULL);

    /* If the parent has no sibling, there is no uncle */
    if (node->parent->parent->left == NULL || node->parent->parent->right == NULL)
        return (NULL);

    /* If the parent is the left child, return the right child (uncle) */
    if (node->parent->parent->left == node->parent)
        return (node->parent->parent->right);

    /* If the parent is the right child, return the left child (uncle) */
    if (node->parent->parent->right == node->parent)
        return (node->parent->parent->left);

    return (NULL); /* Node has no uncle */
}
