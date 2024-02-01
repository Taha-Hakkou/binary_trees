#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root;

	if (tree == NULL || tree->right == NULL)
		return (tree);
	root = tree->right;
	if (root->left)
		root->left->parent = tree;
	tree->right = root->left;
	root->left = tree;
	root->parent = tree->parent;
	tree->parent = root;
	if (root->parent)
	{
		if (root->parent->left == tree)
			root->parent->left = root;
		else
			root->parent->right = root;
	}
	return (root);
}
