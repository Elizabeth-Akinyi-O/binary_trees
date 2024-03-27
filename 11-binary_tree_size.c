#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: If tree is NULL, the function must return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t num_nodes = 0; /* stores no of nodes in the tree */

	if (tree)
	{
		num_nodes += 1;
		num_nodes += binary_tree_size(tree->left);
		num_nodes += binary_tree_size(tree->right);
	}
	return (num_nodes);
}
