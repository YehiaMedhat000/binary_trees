#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses the tree
 * in post_order method
 *
 * @tree: The head node of the tree
 * @func: The function to use over the nodes
 *
 * Return: Nothing (void)
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
