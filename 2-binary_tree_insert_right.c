#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 *		if already exists, must take its place &
 *		old-node must be set as right-child of new one
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);
	node = malloc(sizeof(binary_tree_t));
	if (node)
	{
		node->n = value;
		node->parent = parent;
		if (parent->right)
		{
			node->right = parent->right;
			node->right->parent = node;
		}
		else
			node->right = NULL;
		parent->right = node;
		node->left = NULL;
	}
	return (node);
}
