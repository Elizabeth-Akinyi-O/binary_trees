#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Description: If the address stored in tree is NULL, the created
 *              node must become the root node. If the value is already
 *              present in the tree, it must be ignored
 *
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current_node, *new_node;

	if (tree != NULL)
	{
		current_node = *tree;

		if (current_node == NULL)
		{
			new_node = binary_tree_node(current_node, value);
			if (new_node == NULL)
				return (NULL);
			return (*tree = new_node);
		}

		if (value < current_node->n)
		{
			if (current_node->left != NULL)
				return (bst_insert(&current_node->left, value));
			new_node = binary_tree_node(current_node, value);
			if (new_node == NULL)
				return (NULL);
			return (current_node->left = new_node);
		}

		if (value > current_node->n)
		{
			if (current_node->right != NULL)
				return (bst_insert(&current_node->right, value));
			new_node = binary_tree_node(current_node, value);
			if (new_node == NULL)
				return (NULL);
			return (current_node->right = new_node);
		}
	}
	return (NULL);
}
