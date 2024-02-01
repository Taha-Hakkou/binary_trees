#include "binary_trees.h"

/**
 * avl_insert - inserts a value in an AVL tree
 *		the created node must become the root node if tree is NULL
 *		the resulting tree must be a balanced AVL tree
 * @tree: double pointer to the root node of the tree for inserting value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *tmp;

	if (*tree == NULL)
	{
		*tree = (avl_t *)binary_tree_node(NULL, value);
		return (*tree);
	}
	tmp = *tree;
	while (tmp)
	{
		if (tmp->n == value)
			return (NULL);
		else if (value < tmp->n)
		{
			if (tmp->left == NULL)
			{
				tmp->left = (avl_t *)binary_tree_node(tmp, value);
				tmp = tmp->left;
				break;
			}
			tmp = tmp->left;
		}
		else
		{
			if (tmp->right == NULL)
			{
				tmp->right = (avl_t *)binary_tree_node(tmp, value);
				tmp = tmp->right;
				break;
			}
			tmp = tmp->right;
		}
	}
	avl_balancer(tmp);
	return (tmp);
}

/**
 * avl_balancer - rebalances an AVL tree after insertion
 * @tmp: previously inserted node
 * Return: Nothing
 */
void avl_balancer(avl_t *tmp)
{
	int balance;

	balance = binary_tree_balance(tmp->parent->parent);
	if (balance > 1)
	{
		if (tmp->n > tmp->parent->n)
		{
			binary_tree_rotate_left(tmp->parent);
			binary_tree_rotate_right(tmp->parent);
		}
		else
			binary_tree_rotate_right(tmp->parent->parent);
	}
	else if (balance < -1)
	{
		if (tmp->n < tmp->parent->n)
		{
			binary_tree_rotate_right(tmp->parent);
			binary_tree_rotate_left(tmp->parent);
		}
		else
			binary_tree_rotate_left(tmp->parent->parent);
	}
}
