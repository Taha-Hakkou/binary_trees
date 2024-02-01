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
		free(node);
	else if (successor == node->left)
	{
		node->left->parent = node->parent;
		if (node->parent)
		{
			if (node == node->parent->left)
				node->parent->left = node->left;
			else
				node->parent->right = node->right;
		}
	}











	if (node->parent)
	{
		successor->parent = node->parent;
		if (successor)
		{
			if (node->parent->left == node)
				node->parent->left = successor;
			else
				node->parent->right = successor;
		}
	}
	else
	{
		if (successor)
		{

		}
		else
		{
			free(node);
			return (NULL);
		}
	}
}
