#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is perfect, otherwise 0 or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	/* main routine */
	if (tree == NULL)
		return (0);
	if (!(tree->left) && !(tree->right))
		return (1);
	if (tree->left && tree->right &&
			binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right) &&
			binary_tree_balance(tree) == 0)
		return (1);
	return (0);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: tree's balance factor, and 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	/* main routine */
	int balance;
	int lheight = 0, rheight = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		lheight = binary_tree_height(tree->left) + 1;
	if (tree->right)
		rheight = binary_tree_height(tree->right) + 1;
	balance = lheight - rheight;
	return (balance);
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
