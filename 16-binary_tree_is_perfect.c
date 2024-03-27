#include "binary_trees.h"

/**
 * node_is_leaf - Checks if a node is a leaf of a binary tree.
 * @node: A pointer to the node to check.
 *
 * Return: If the node is a leaf, 1, otherwise, 0.
 */
unsigned char node_is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * search_leaf - Returns a leaf of a binary tree.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 *
 * Return: A pointer to the first encountered leaf.
 */
const binary_tree_t *search_leaf(const binary_tree_t *tree)
{
	if (node_is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? search_leaf(tree->left) : search_leaf(tree->right));
}

/**
 * recursive_depth - checks the recursive_depth of a given
 *         node in a binary tree.
 * @tree: A pointer to the node to measure the recursive_depth of.
 *
 * Return: The recursive_depth of node.
 */
size_t recursive_depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + recursive_depth(tree->parent) : 0);
}

/**
 * is_binary_tree_perfect - Checks if a binary tree is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @l_node_depth: The recursive_depth of one leaf in the binary tree.
 * @level: Level of current node.
 *
 * Return: If the tree is perfect, 1, otherwise 0.
 */
int is_binary_tree_perfect(const binary_tree_t *tree,
		size_t l_node_depth, size_t level)
{
	if (node_is_leaf(tree))
		return (level == l_node_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_binary_tree_perfect(tree->left, l_node_depth, level + 1) &&
			is_binary_tree_perfect(tree->right, l_node_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_binary_tree_perfect(tree, recursive_depth(search_leaf(tree)), 0));
}
