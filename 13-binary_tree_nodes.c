#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the numbers
 * of nodes in a binary tree
 *
 * @tree: The node from which to count
 *
 * Return: The number of nodes
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (!tree)
		return (0);

	/* nodes this node if it has at least one child */
	nodes = (tree->left != NULL || tree->right != NULL) ? 1 : 0;

	/* Recursively nodes nodes in the left and right subtrees */
	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);

	return (nodes);
}
