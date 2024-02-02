#include "binary_trees.h"

/**
 * binary_tree_is_heap - checks if a binary tree is a valid max binary heap
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a max binary heap, otherwise 0 or if tree is NULL
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	binary_tree_t **nodes;
	int size = 1, i, j;

	if (tree == NULL)
		return (0);
	nodes = malloc(sizeof(binary_tree_t *));
	*nodes = (binary_tree_t *)tree;
	while (1)
	{
		size *= 2;
		nodes = realloc(nodes, size * sizeof(binary_tree_t *));
		for (i = size / 2 - 1; i >= 0; i--)
		{
			if ((nodes[i]->left && nodes[i]->left->n > nodes[i]->n) ||
					(nodes[i]->right && nodes[i]->right->n > nodes[i]->n))
			{
				free(nodes);
				return (0);
			}
			nodes[i * 2 + 1] = nodes[i]->right;
			nodes[i * 2] = nodes[i]->left;
		}
		for (i = 0; i < size && nodes[i]; i++)
			continue;
		if (i < size)
			break;
	}
	for (j = 0; j < size; j++)
		if ((j > i && nodes[j]) ||
				(j < i && (nodes[j]->left || nodes[j]->right)))
		{
			free(nodes);
			return (0);
		}
	free(nodes);
	return (1);
}
