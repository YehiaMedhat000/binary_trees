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
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t queue = {NULL, NULL};
	const binary_tree_t *current;
	int flag = 0;

	if (tree == NULL)
	return 0;

	enqueue(&queue, (binary_tree_t *)tree);

	while (queue.front != NULL)
	{
		current = dequeue(&queue);

		if (current->left)
		{
			if (flag)
			return 0;
			enqueue(&queue, current->left);
		}
		else
			flag = 1;

		if (current->right)
		{
			if (flag)
			return 0;
			enqueue(&queue, current->right);
		}
		else
			flag = 1;
	}
	return 1;
}
