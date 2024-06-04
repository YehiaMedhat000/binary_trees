#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts number of leaves
 * in a binary tree given the root node
 *
 * @tree: The root node of the tree
 *
 * Return: The number of leaves in the tree
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (!tree)
		return (0);

	if (tree->left)
		leaves += binary_tree_leaves(tree->left);
	if (tree->right)
		leaves += binary_tree_leaves(tree->right);

	if (!tree->left && !tree->right)
		leaves = 1;

	return (leaves);
}
