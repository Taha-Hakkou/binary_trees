#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as a left-child of another node
 *		if already exists, must take its place &
 *		the old-child must be set as left-child of the new one
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);
	node = malloc(sizeof(binary_tree_t));
	if (node)
	{
		node->n = value;
		node->parent = parent;
		if (parent->left)
		{
			node->left = parent->left;
			node->left->parent = node;
		}
		else
			node->left = NULL;
		parent->left = node;
		node->right = NULL;
	}
	return (node);
}
