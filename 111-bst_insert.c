#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a binary search tree
 *		if tree is NULL, the created node must become the root
 *		the value is ignored if already exists
 * @tree: double pointer to the root node of the BST to insert the value in
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failue
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp;

	if (*tree == NULL)
	{
		*tree = (bst_t *)binary_tree_node(NULL, value);
		return (*tree);
	}
	tmp = *tree;
	while (tmp)
	{
		if (tmp->n == value)
			return (NULL);
		else if (value < tmp->n)
		{
			if (tmp->left)
				tmp = tmp->left;
			else
			{
				tmp->left = (bst_t *)binary_tree_node(tmp, value);
				tmp = tmp->left;
				break;
			}
		}
		else
		{
			if (tmp->right)
				tmp = tmp->right;
			else
			{
				tmp->right = (bst_t *)binary_tree_node(tmp, value);
				tmp = tmp->right;
				break;
			}
		}
	}
	return (tmp);
}
