#include "binary_trees.h"

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

	is_balanced = !binary_tree_balance(tree) ? 1 : 0;
	is_full = binary_tree_is_full(tree) ? 1 : 0;

	if (is_full && is_balanced)
		return (1);

	return (0);
}
