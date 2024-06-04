#include "binary_trees.h"

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

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
	size_t l_height = 0, r_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		l_height = 1 + binary_tree_height(tree->left);

	if (tree->right)
		r_height = 1 + binary_tree_height(tree->right);

	return (MAX(l_height, r_height));
}
