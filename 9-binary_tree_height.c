#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height
 * of a binary tree
 *
 * @tree: The node from which to measure
 *
 * Return: The height of the tree
 * from the given node, 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		return (1 + binary_tree_height(tree->left));

	else if (tree->right)
		return (1 + binary_tree_height(tree->right));

	return (height);
}
