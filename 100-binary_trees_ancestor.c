#include "binary_trees.h"

/**
 * depth - Measures the depth
 * of a given node `tree`
 *
 * @tree: The node to measure its depth
 *
 * Return: The depth of the node `tree`
 */

size_t depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);

	return (1 + depth(tree->parent));
}

/**
 * binary_trees_ancestor - Finds common ancestor
 * of two given nodes
 *
 * @first: The first child node
 * @second: The second child node
 *
 * Return: Pointer to the common ancestor
 * NULL if not found
 */

binary_tree_t
*binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	if (depth(first) > depth(second))
	{
		if (second == first->parent)
			return ((binary_tree_t *)second);

		while (second->parent != first->parent)
			first = first->parent;

		return ((binary_tree_t *)second);
	}

	else
	{
		if (first == second->parent)
			return ((binary_tree_t *)first);

		while (second->parent != first->parent)
			second = second->parent;

		return ((binary_tree_t *)first);
	}
	return (NULL);
}
