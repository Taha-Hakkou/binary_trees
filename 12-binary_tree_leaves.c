#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in the binary tree
 *		(NULL pointer is not a leaf)
 * @tree: pointer to the root node of the tree to count the leaves
 * Return: number of leaves, and 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree)
	{
		if (!(tree->left) && !(tree->right))
			return (1);
		leaves = binary_tree_leaves(tree->left);
		leaves += binary_tree_leaves(tree->right);
	}
	return (leaves);
}
