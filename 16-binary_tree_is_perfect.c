#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0,
	right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height) ? (left_height + 1) : (right_height + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise, or if tree is NULL
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t height = binary_tree_height(tree);

	return (is_perfect_recursive(tree, height, 0));
}

/**
 * is_perfect_recursive - Recursively checks if a binary tree is perfect
 * @tree: Pointer to the current node being checked
 * @height: Height of the tree
 * @level: Current level of the node
 *
 * Return: 1 if the tree is perfect, 0 otherwise
*/

int is_perfect_recursive(const binary_tree_t *tree, size_t height, size_t level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (level == height);

	if (tree->left && tree->right)
		return (is_perfect_recursive(tree->left, height, level + 1) &&
		is_perfect_recursive(tree->right, height, level + 1));

	return (0);
}
