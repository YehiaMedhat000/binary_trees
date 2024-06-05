#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling
 * of a node in a binary tree
 *
 * @node: pointer to the node to find the sibling
 *
 * Return: pointer to the sibling node
 * or NULL if there is no sibling
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	if (node->parent->right == node)
		return (node->parent->left);

	return (NULL);
}

/**
 * binary_tree_uncle - Finds the uncle
 * of a given in a binary tree
 *
 * @node: The given node to find uncle for
 *
 * Return: Pointer to the uncle node of `node`
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}
