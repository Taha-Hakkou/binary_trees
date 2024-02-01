#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree
 *		using level-order traversal
 *		if tree or func is NULL, do nothing
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 *		The value in the node must be passed as a parameter to this function
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **nodes;
	int size = 1, i;
	int empty = 0;

	if (tree == NULL || func == NULL)
		return;
	nodes = malloc(sizeof(binary_tree_t *));
	*nodes = (binary_tree_t *)tree;
	func(tree->n);
	while (!empty)
	{
		size *= 2;
		nodes = realloc(nodes, size * sizeof(binary_tree_t *));
		for (i = size / 2 - 1; i >= 0; --i)
		{
			if (nodes[i])
			{
				nodes[i * 2 + 1] = nodes[i]->right;
				nodes[i * 2] = nodes[i]->left;
			}
			else
				nodes[i * 2 + 1] = nodes[i * 2] = NULL;
		}
		empty = 1;
		for (i = 0; i < size; i++)
			if (nodes[i])
			{
				func(nodes[i]->n);
				empty = 0;
			}
	}
	free(nodes);
}
