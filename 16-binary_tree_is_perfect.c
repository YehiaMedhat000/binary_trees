#include "binary_trees.h"

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

/**
 * height - Measures the height
 * of a binary tree
 *
 * @tree: The node from which to measure
 *
 * Return: The height of the tree
 * from the given node, 0 if tree is NULL
 */

size_t height(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		l_height = 1 + height(tree->left);

	if (tree->right)
		r_height = 1 + height(tree->right);

	return (MAX(l_height, r_height));
}

/**
 * balance - Measures the balance
 * factor of a binary tree
 *
 * @tree: The node from which to measure
 *
 * Return: The balance factor of the tree
 */

int balance(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		l_height = 1 + height(tree->left);

	if (tree->right)
		r_height = 1 + height(tree->right);

	return (l_height - r_height);
}

/**
 * check_full - Checks if the given
 * binary tree is full or not
 *
 * @tree: The node from to check
 *
 * Return: 1 if `tree` is full, 0 otherwise
 */

int check_full(const binary_tree_t *tree)
{
	int check = 1;

	if (!tree)
		return (0);

	if (tree->left && tree->right)
	{
		check &= check_full(tree->left);
		check &= check_full(tree->right);
	}
	else if (!tree->left && tree->right)
		return (0);
	else if (tree->left && !tree->right)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (check);
}

/**
 * binary_tree_is_perfect - Checks if
 * a given binary tree is perfect
 *
 * @tree: The root node of the tree
 *
 * Return: 1 if the tree is perfect
 * 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int is_balanced, is_full;

	if (!tree)
		return (0);

	is_balanced = !balance(tree) ? 1 : 0;
	is_full = check_full(tree) ? 1 : 0;

	if (is_full && is_balanced)
		return (1);

	return (0);
}
