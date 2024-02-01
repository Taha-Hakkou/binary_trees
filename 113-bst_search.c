#include "binary_trees.h"

/**
 * bst_t *bst_search - searches for a value in a BST
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the BST
 * Return: pointer to the node containing a value equals to value,
 *		or NULL if tree is NULL or nothing is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	const bst_t *node;

	node = tree;
	while (node && node->n != value)
	{
		if (value < node->n)
			node = node->left;
		else
			node = node->right;
	}
	return ((bst_t *)node);
}
