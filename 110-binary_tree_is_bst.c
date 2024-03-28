#include "binary_trees.h"
#include <limits.h>

/**
 * validate_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * @min: minimum value that a node in the subtree rooted at tree can have
 * @max: maximum value that a node in the subtree rooted at tree can have
 *
 * Return: 1 if the tree is a valid BST, otherwise 0
 */
int validate_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree != NULL)
	{
		if (tree->n < min || tree->n > max)
			return (0);
		return (validate_bst(tree->left, min, tree->n - 1) &&
				validate_bst(tree->right, tree->n + 1, max));
	}
	return (1);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Description: function must return 1 if tree is a valid BST, and 0 otherwise
 *
 * Return: If tree is NULL, return 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (validate_bst(tree, INT_MIN, INT_MAX));
}
