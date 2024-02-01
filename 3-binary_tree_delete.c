#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 *		if tree is NULL, do nothing
 * @tree: pointer to the root node to the tree to delete
 * Return: Nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree->right)
		binary_tree_delete(tree->right);
	if (tree->left)
		binary_tree_delete(tree->left);
	if (tree)
		free(tree);
}
