#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth
 * of a given node `tree`
 *
 * @tree: The node to measure its depth
 *
 * Return: The depth of the node `tree`
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);

	return (1 + binary_tree_depth(tree->parent));
}
