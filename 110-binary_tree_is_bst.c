#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a valid BST
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, otherwise 0 or if tree is NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int left = 0, right = 0;
	binary_tree_t *tmp;

	if (tree == NULL)
		return (0);
	if (tree->left)
	{
		tmp = tree->left;
		if (tmp->n < tree->n && binary_tree_is_bst(tmp))
		{
			while (tmp->right)
				tmp = tmp->right;
			if (tmp->n < tree->n)
				left = 1;
		}
	}
	else
		left = 1;
	if (tree->right)
	{
		tmp = tree->right;
		if (tmp->n > tree->n && binary_tree_is_bst(tmp))
		{
			while (tmp->left)
				tmp = tmp->left;
			if (tmp->n > tree->n)
				right = 1;
		}
	}
	else
		right = 1;
	return (left && right);
}
