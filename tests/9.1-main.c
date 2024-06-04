#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t height;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_insert_right(root, 0);
    binary_tree_insert_right(root, 1);
    binary_tree_insert_right(root, 2);
    binary_tree_insert_right(root, 3);
    binary_tree_insert_right(root, 4);
    binary_tree_insert_right(root, 5);
    binary_tree_insert_right(root, 6);
    binary_tree_insert_right(root, 7);
    binary_tree_insert_right(root, 8);
    binary_tree_insert_right(root, 9);
    binary_tree_insert_right(root, 10);
    binary_tree_insert_right(root, 11);
    binary_tree_insert_left(root, 5);
    binary_tree_insert_left(root, 6);
    binary_tree_insert_left(root, 7);
    binary_tree_insert_left(root, 8);
    binary_tree_insert_left(root, 9);
    binary_tree_print(root);

    height = binary_tree_height(root);
    printf("Height from %d: %lu\n", root->n, height);
    height = binary_tree_height(root->right);
    printf("Height from %d: %lu\n", root->right->n, height);
    height = binary_tree_height(root->left->right);
    return (0);
}
