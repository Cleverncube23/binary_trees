#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node.
 * @parent: A pointer to the node to insert the left-child in.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the created node, or NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    // Check if parent is NULL
    if (parent == NULL)
    {
        return (NULL);
    }

    // Allocate memory for the new node
    new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
    {
        return (NULL); // Memory allocation failed
    }

    // Initialize the new node
    new_node->n = value;
    new_node->parent = parent;
    new_node->left = parent->left; // New node takes the place of the old left-child
    new_node->right = NULL;

    // If parent already had a left child, update its parent pointer
    if (parent->left != NULL)
    {
        parent->left->parent = new_node;
    }

    // Set the new node as the left child of the parent
    parent->left = new_node;

    return (new_node);
}
