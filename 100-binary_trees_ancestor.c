#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Description: function must return a pointer to the lowest common
 *              ancestor node of the two given nodes
 *
 * Return: NULL If no common ancestor is found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *parent1, *parent2;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	parent1 = first->parent;
	parent2 = second->parent;
	if (first == parent2 || !parent1 || (!parent1->parent && parent2))
		return (binary_trees_ancestor(first, parent2));
	else if (parent1 == second || !parent2 || (!parent2->parent && parent1))
		return (binary_trees_ancestor(second, parent1));

	return (binary_trees_ancestor(parent1, parent2));
}
