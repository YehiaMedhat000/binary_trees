#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverses the tree
 * in in_order method
 *
 * @tree: The head node of the tree
 * @func: The function to use over the nodes
 *
 * Return: Nothing (void)
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
