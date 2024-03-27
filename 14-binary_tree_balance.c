#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree:  pointer to the root node of the tree to measure the height
 *
 * Return: If tree is NULL, return 0, else return height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t a = 0, b = 0;
		/* stores the height of the left and right subtrees respectively */

		a = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		b = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((a > b) ? a : b);
	}
	return (0);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	return (0);
}
