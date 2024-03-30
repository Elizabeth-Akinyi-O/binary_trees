#include "binary_trees.h"

/**
 * bt_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t bt_height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t left_sub_height = 0, right_sub_height = 0;

		left_sub_height = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		right_sub_height = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((left_sub_height > right_sub_height) ?
				left_sub_height : right_sub_height);
	}
	return (0);
}

/**
 * balance_factor - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int balance_factor(const binary_tree_t *tree)
{
	return (tree != NULL ? bt_height(tree->left) - bt_height(tree->right) : 0);
}

/**
 * recursive_avl_insert - Inserts a value into an AVL tree recursively.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @parent_node: The parent_node node of the current working node.
 * @new_node: A double pointer to store the new node.
 * @val: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *recursive_avl_insert(avl_t **tree, avl_t *parent_node,
		avl_t **new_node, int val)
{
	int bal_factor;

	if (*tree == NULL)
		return (*new_node = binary_tree_node(parent_node, val));

	if ((*tree)->n > val)
	{
		(*tree)->left = recursive_avl_insert(&(*tree)->left, *tree, new_node, val);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < val)
	{
		(*tree)->right = recursive_avl_insert(&(*tree)->right, *tree, new_node, val);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bal_factor = balance_factor(*tree);
	if (bal_factor > 1 && (*tree)->left->n > val)
		*tree = binary_tree_rotate_right(*tree);
	else if (bal_factor < -1 && (*tree)->right->n < val)
		*tree = binary_tree_rotate_left(*tree);
	else if (bal_factor > 1 && (*tree)->left->n < val)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bal_factor < -1 && (*tree)->right->n > val)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree for
 *        inserting the value
 * @value: value to store in the node to be inserted
 *
 * Description: If the address stored in tree is NULL, the created
 *              node must become the root node. The resulting tree
 *	        after insertion, must be a balanced AVL Tree
 *
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	recursive_avl_insert(tree, *tree, &new_node, value);
	return (new_node);
}
