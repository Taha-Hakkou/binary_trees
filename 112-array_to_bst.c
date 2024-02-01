#include "binary_trees.h"

/**
 * array_to_bst - builds a BST from an array
 *		values of array ignored if already present in the BST
 * @array: poiner to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);
	return (root);
}
