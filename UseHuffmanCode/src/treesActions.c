/**
 * \file treesActions.c
 * \brief Source where all tree-related function take places
 * \date 21 oct. 2020
 * \author Kylian.S, Tommy Lee.A, Joel.G, Jules.R, Oscar.V
 * \version 0.1
 *
 * Compression program using Huffman Algorith, with trees and queues
 *
 */

#include "../includes/treesActions.h"

/**
 * \brief Maximum between 2 integers
 *	Compare both of the integer in parameter
 * \return int
 */

int max(int a, int b){
	return (a>b)? a : b;
}

/**
 * \brief Create a Node
 *	Create a Node with the value in the parameters
 * \return Node* Return the node created
 */

Node* createNode(int value){
	Node* tree = (Node*)malloc(sizeof(Node)); /*Allocate some space for the node*/
	tree->left = NULL;
	tree->right = NULL; /*Make both branch point to nothing*/
	tree->data = value; /*Make the node value equal the parameter value*/
	return tree; /*We return the tree*/
}

/**
 * \brief Delete a tree
 *	Delete the tree recursively
 * \return void
 */

void deleteTree(Node* tree){
	if(tree!=NULL){/*If the node exist*/
		deleteTree(tree->right);
		deleteTree(tree->left);/*Free both of the branches*/
		free(tree); /*Free the tree*/
	}
}

/**
 * \brief Calculate the height of a node recursively
 *	Calculate the height recursively
 * \return int return the height from the node
 */
int heightTree(Node* tree){
	if(tree == NULL) return 0; /*If the tree doesn't exist we return a 0*/
	else return 1 + max(heightTree(tree->left), heightTree(tree->right)); /*Else
 it return the maximum between both branch + 1, the actual node*/
}

/**
 * \brief Calculate the balancing factor of the node
 *	It subtract the height of the right branch from the left one
 * \return int return the balancing factor from the node
 */
int balFactorTree(Node* tree){
	if(tree != NULL){/*If the tree exist*/
		return  (heightTree(tree->left) - heightTree(tree->right)); /*Return
 the difference between both of the branches*/
	}
	return 0;
}

/**
 * \brief Rotate right side the sub-tree in parameter
 *	Simply rotate the subtree to the right.
 * \return void
 */
void rightRotation(Node** tree){
	if(*tree != NULL && (*tree)->right != NULL && (*tree)->left != NULL){
		Node* pivot = (*tree)->left;
		(*tree)->left = pivot->right;
		pivot->right = (*tree);
		*tree = pivot;
	}
}

/**
 * \brief Rotate left side the sub-tree in parameter
 *	Simply rotate the subtree to the left.
 * \return void
 */
void leftRotation(Node** tree){
	if(*tree != NULL && (*tree)->right != NULL && (*tree)->left != NULL){
		Node* pivot = (*tree)->right;
		(*tree)->right = pivot->left;
		pivot->left = (*tree);
		*tree = pivot;
	}
}
