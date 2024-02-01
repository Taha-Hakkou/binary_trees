#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node
 *		of the 2 given nodes (NULL if not found)
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *ancestor, *tmp;

	if (!first || !second)
		return (NULL);
	ancestor = second;
	while (ancestor)
	{
		tmp = first;
		while (tmp && tmp != ancestor)
			tmp = tmp->parent;
		if (tmp)
			return ((binary_tree_t *)ancestor);
		ancestor = ancestor->parent;
	}
	return (NULL);
}
