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
	const binary_tree_t **nodes;
	size_t height, i, j, before = 0, after = 1, tmp;

	height = binary_tree_height(tree);
	nodes = malloc(sizeof(binary_tree_t *));
	*nodes = tree;
	for (i = 0; i < height; i++)
	{
		tmp = after;
		for (j = before; j < after; j++)
		{
			if (nodes[j]->left)
			{
				tmp++;
				nodes = realloc(nodes, tmp * sizeof(binary_tree_t *));
				nodes[tmp - 1] = nodes[j]->left;
			}
			if (nodes[j]->right)
			{
				tmp++;
				nodes = realloc(nodes, tmp * sizeof(binary_tree_t *));
				nodes[tmp - 1] = nodes[j]->right;
			}
		}
		before = after;
		after = tmp;
	}
	for (i = 0; i < after; i++)
		func(nodes[i]->n);
	free(nodes);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: tree's height, and 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height, rheight;

	if (tree == NULL || !(tree->left || tree->right))
		return (0);
	height = binary_tree_height(tree->left);
	rheight = binary_tree_height(tree->right);
	if (rheight > height)
		height = rheight;
	height++;
	return (height);
}
