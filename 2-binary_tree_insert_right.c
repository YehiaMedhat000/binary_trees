#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts right node
 *
 * @parent: The parent node
 * @value: The value inside the node
 *
 * Return: pointer to the created node
 * NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right = malloc(sizeof(binary_tree_t));
	binary_tree_t *temp;

	if (!right)
		return (NULL);

	if (!parent)
	{
		free(right);
		return (NULL);
	}

	right->n = value;

	if (parent->right)
	{
		temp = parent->right;
		parent->right = right;
		right->parent = parent;
		temp->parent = right;
		right->right = temp;
		right->left = NULL;
	}
	else
	{
		parent->right = right;
		right->parent = parent;
		right->right = NULL;
		right->left = NULL;
	}

	return (right);
}
