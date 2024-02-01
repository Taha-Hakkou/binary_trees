#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 * Return: pointer to the uncle node,
 *		and NULL if node is NULL or if has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *p;

	if (node == NULL)
		return (NULL);
	p = node->parent;
	if (p && p->parent && p->parent->left && p->parent->right)
	{
		if (p->parent->left == p)
			return (p->parent->right);
		return (p->parent->left);
	}
	return (NULL);
}
