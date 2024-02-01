#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is complete, otherwise 0 or if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **nodes;
	int size = 1, i, j;
	int perfect = 1;

	if (tree == NULL)
		return (0);
	nodes = malloc(sizeof(binary_tree_t *));
	*nodes = (binary_tree_t *)tree;
	while (perfect)
	{
		size *= 2;
		nodes = realloc(nodes, size * sizeof(binary_tree_t *));
		for (i = size / 2 - 1; i >= 0; --i)
		{
			nodes[i * 2 + 1] = nodes[i]->right;
			nodes[i * 2] = nodes[i]->left;
		}
		for (i = 0; i < size; i++)
			if (nodes[i] == NULL)
				break;
		if (i < size)
			perfect = 0;
	}
	for (j = i + 1; j < size; j++)
		if (nodes[j])
			return (0);
	for (j = 0; j < i; j++)
		if (nodes[j]->left || nodes[j]->right)
			return (0);
	return (1);
}
