#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 *
 * Return: A pointer to the lowest common ancestor node of the two given nodes,
 *         or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    const binary_tree_t *temp1 = first, *temp2 = second;
    size_t depth1 = 0, depth2 = 0;

    /* Calculate the depth of each node */
    while (temp1)
    {
        temp1 = temp1->parent;
        depth1++;
    }
    while (temp2)
    {
        temp2 = temp2->parent;
        depth2++;
    }

    /* Traverse deeper node up to the same depth */
    temp1 = first;
    temp2 = second;
    while (depth1 > depth2)
    {
        temp1 = temp1->parent;
        depth1--;
    }
    while (depth2 > depth1)
    {
        temp2 = temp2->parent;
        depth2--;
    }

    /* Move both pointers until they meet or find the common ancestor */
    while (temp1 && temp2)
    {
        if (temp1 == temp2)
            return ((binary_tree_t *)temp1);
        temp1 = temp1->parent;
        temp2 = temp2->parent;
    }

    return (NULL); /* No common ancestor found */
}
