#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses the tree
 * in pre_order method
 *
 * @tree: The head node of the tree
 * @func: The function to use over the nodes
 *
 * Return: Nothing (void)
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
