#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: A pointer to the node to insert the right-child in
 * @value: The value to store in the new node
 *
 * Return: A pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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
    new_node->left = NULL; // New node's left child is always NULL upon creation
    new_node->right = parent->right; // New node takes the place of the old right-child

    // If parent already had a right child, update its parent pointer
    if (parent->right != NULL)
    {
        parent->right->parent = new_node;
    }

    // Set the new node as the right child of the parent
    parent->right = new_node;

    return (new_node);
}
