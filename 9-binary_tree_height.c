#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: tree's height, and 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height, rheight;

	if (tree == NULL || !(tree->left || tree->right))
		return (0);
	height = binary_tree_height(tree->left);
	rheight = binary_tree_height(tree->right);
	if (rheight > height)
		height = rheight;
	height++;
	return (height);
}
