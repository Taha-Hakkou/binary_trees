#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: node's depth, and 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	const binary_tree_t *tmp;

	if (tree)
		for (tmp = tree; tmp->parent; tmp = tmp->parent)
			depth++;
	return (depth);
}
