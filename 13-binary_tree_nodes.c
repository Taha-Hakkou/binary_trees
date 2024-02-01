#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with atleast 1 child in a binary tree
 *		(NULL pointer is not a node)
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: number of nodes, and 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree && (tree->left || tree->right))
	{
		nodes = 1;
		nodes += binary_tree_nodes(tree->left);
		nodes += binary_tree_nodes(tree->right);
	}
	return (nodes);
}
