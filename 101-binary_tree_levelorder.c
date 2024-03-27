#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node
 *
 * Description: Level-order traversal traverses the tree level by level,
 *               from left to right.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    queue_t *queue = NULL;
    const binary_tree_t *temp;

    if (!tree || !func)
        return;

    queue = queue_create();
    if (!queue)
        return;

    queue_push(queue, (void *)tree);

    while (!queue_is_empty(queue))
    {
        temp = (const binary_tree_t *)queue_front(queue);
        queue_pop(queue);
        func(temp->n);

        if (temp->left)
            queue_push(queue, (void *)(temp->left));
        if (temp->right)
            queue_push(queue, (void *)(temp->right));
    }

    queue_delete(queue);
}
