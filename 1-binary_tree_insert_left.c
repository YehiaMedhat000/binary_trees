#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts left node
 *
 * @parent: The parent node
 * @value: The value inside the node
 *
 * Return: pointer to the created node
 * NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left = malloc(sizeof(binary_tree_t));
	binary_tree_t *temp;

	if (!left || !parent)
		return (NULL);

	left->n = value;

	if (parent->left)
	{
		temp = parent->left;
		parent->left = left;
		left->parent = parent;
		temp->parent = left;
		left->left = temp;
		left->right = NULL;
	}
	else
	{
		parent->left = left;
		left->parent = parent;
		left->left = NULL;
		left->right = NULL;
	}


	return (left);
}
