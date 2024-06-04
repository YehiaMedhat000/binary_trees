#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if the given
 * binary tree is full or not
 *
 * @tree: The node from to check
 *
 * Return: 1 if `tree` is full, 0 otherwise
 */

/**
 * if tree == NULL -> return (0)
 * else
 *  	if (tree->right && tree->left)
 * 			func(tree->right)
 * 			func(tree->left)
 * 		else if (!tree->left && tree->right)
 * 			return (0)
 * 		else if (!tree->right && tree->left)
 * 			return (0)
 * 		else if (!tree->right && !tree->left)
 * 			return (1)
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int check = 1;

	if (!tree)
		return (0);

	if (tree->left && tree->right)
	{
		check &= binary_tree_is_full(tree->left);
		check &= binary_tree_is_full(tree->right);
	}
	else if (!tree->left && tree->right)
		return (0);
	else if (tree->left && !tree->right)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (check);
}
