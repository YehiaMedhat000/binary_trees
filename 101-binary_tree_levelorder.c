#include "binary_trees.h"

/**
 * enqueue - adds a node to the queue
 * @queue: pointer to the queue
 * @node: binary tree node to add
 */

void enqueue(queue_t *queue, binary_tree_t *node)
{
    queue_node_t *new_node = malloc(sizeof(queue_node_t));

    if (new_node == NULL)
        return;

    new_node->node = node;
    new_node->next = NULL;

    if (queue->rear == NULL)
    {
        queue->front = new_node;
        queue->rear = new_node;
    }
    else
    {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

/**
 * dequeue - removes a node from the queue
 * @queue: pointer to the queue
 *
 * Return: pointer to the removed binary tree node
 */

binary_tree_t *dequeue(queue_t *queue)
{
    queue_node_t *temp;
    binary_tree_t *node;

    if (queue->front == NULL)
    {
        return (NULL);
    }
    temp = queue->front;
    node = temp->node;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    return (node);
}

/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Return: Nothing (void)
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    queue_t queue = {NULL, NULL};
    if (tree == NULL || func == NULL)
        return;

    enqueue(&queue, (binary_tree_t *)tree);

    while (queue.front != NULL)
    {
        binary_tree_t *current = dequeue(&queue);
        func(current->n);

        if (current->left != NULL)
            enqueue(&queue, current->left);
        if (current->right != NULL)
            enqueue(&queue, current->right);
    }
}
