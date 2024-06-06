#include "binary_trees.h"

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

/**
 * get_height - Measures the get_height
 * of a binary tree
 *
 * @tree: The node from which to measure
 *
 * Return: The get_height of the tree
 * from the given node, 0 if tree is NULL
 */

size_t get_height(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		l_height = 1 + get_height(tree->left);

	if (tree->right)
		r_height = 1 + get_height(tree->right);

	return (MAX(l_height, r_height));
}

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
		l_height = 1 + get_height(tree->left);

	if (tree->right)
		r_height = 1 + get_height(tree->right);

	return (l_height - r_height);
}
