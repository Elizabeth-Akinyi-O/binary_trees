#include "binary_trees.h"

/**
 * recursive_fullness_check - recursively chaecks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: If tree in not full, 0. Otherwise 1
 */
int recursive_fullness_check(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
				(tree->left == NULL && tree->right != NULL) ||
		    recursive_fullness_check(tree->left) == 0 ||
		    recursive_fullness_check(tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (recursive_fullness_check(tree));
}
