#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * aux_binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height of
 * Return: the height of the tree. If tree is NULL, return 0
 */

int aux_binary_tree_height(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (!tree)
		return (0);
	if (tree->left)
		left_height = 1 + aux_binary_tree_height(tree->left);
	if (tree->right)
		right_height = 1 + aux_binary_tree_height(tree->right);
	return (right_height > left_height ? right_height : left_height);
}

/**
 * isPerfectRec - checks if a binary tree is perfect
 * @root: pointer to the root node of the tree to check
 * @height: gets the height of the tree
 * @level: the level of the actual tree
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0
 */
int isPerfectRec(const binary_tree_t *root, int height, int level)
{
	if (root == NULL)
		return (0);

	if (root->left == NULL && root->right == NULL)
		return (height == level ? 1 : 0);

	if (root->left == NULL || root->right == NULL)
		return (0);

	return (isPerfectRec(root->left, height, level + 1) *
			isPerfectRec(root->right, height, level + 1));
}


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	return (isPerfectRec(tree, aux_binary_tree_height(tree), 0));
}
