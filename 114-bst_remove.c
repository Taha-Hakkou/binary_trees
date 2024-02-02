#include "binary_trees.h"

/**
 * bst_remove - removes a node from a BST
 *		once located, the node must be removed & freed
 *		If the node to be deleted has two children,
 *		must be replaced with its first in-order successor (not predecessor)
 * @root: pointer to the root node of the tree where to remove a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removing value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *successor;

	node = root;
	while (node && node->n != value)
	{
		if (node->n > value)
			node = node->left;
		else
			node = node->right;
	}
	if (node == NULL)
		return (root);
	/* successor */
	successor = NULL;
	if (node->right)
	{
		successor = node->right;
		if (node->left)
			while (successor->left)
				successor = successor->left;
	}
	else if (node->left)
		successor = node->left;
	/* remove node */
	if (successor == NULL)
	{
		free(node);
		return (root);
	}
	/* 1 */
	if (node->right)
	{
		if (successor == node->right)
			node->right->left = node->left;
		else
			successor->parent->left = NULL;
	}
	/* 2 */
	successor->parent = node->parent;
	if (node->left != successor)
		successor->left = node->left;
	if (node->right != successor)
		successor->right = node->right;
	/* 3 */
	if (successor->left && successor->right == NULL)
		successor->left->parent = successor;
	else if (successor->right)
	{
		if (successor->left == NULL)
			successor->right->parent = successor;
		else
		{
			successor->left->parent = successor;
			if (successor->right->left)
				successor->right->parent = successor;
		}
	}
	/* 3 + 4 */
	if (successor->parent)
	{
		if (node == successor->parent->left)
			successor->parent->left = successor;
		else
			successor->parent->right = successor;
	}
	else
		root = successor;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	free(node);
	return (root);
}
