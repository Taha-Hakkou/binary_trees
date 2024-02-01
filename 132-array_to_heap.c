#include "binary_trees.h"

/**
 * array_to_heap - builds a max binary heap tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node of the created binary heap,
 *		or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root;
	size_t i;

	root = NULL;
	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);
	return (root);
}
