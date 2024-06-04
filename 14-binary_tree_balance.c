#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance
 * factor of a binary tree
 *
 * @tree: The node from which to measure
 *
 * Return: The balance factor of the tree
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		l_height = 1 + binary_tree_height(tree->left);

	if (tree->right)
		r_height = 1 + binary_tree_height(tree->right);

	return (l_height - r_height);
}
