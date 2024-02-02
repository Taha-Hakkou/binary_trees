#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 *		assuming there will be no duplicate values in the array
 *		rotation not allowed, but 2 functions allowed in the file
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (size == 0)
		return (NULL);
	root = binary_tree_node(NULL, array[(size - 1) / 2]);
	root->left = sorted_array_to_avl(array, (size - 1) / 2);
	if (root->left)
		root->left->parent = root;
	else if ((size - 1) / 2 == 0)
		return (NULL);
	root->right = sorted_array_to_avl(&array[(size + 1) / 2], size / 2);
	if (root->right)
		root->right->parent = root;
	else if (size / 2 == 0)
		return (NULL);
	return (root);
}
