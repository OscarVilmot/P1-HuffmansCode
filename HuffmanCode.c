/**
 * \file HuffmanCode.c
 * \brief The main source where the main function takes place
 * \date 21 oct. 2020
 * \author Kilian.S, TommyLee.A, Joel.G, Jules.R, Oscar.V
 * \version 0.1
 *
 * Compression program using Huffman Algorith, with trees and queues
 *
 */
#include "headers/structures.h"
#include "headers/treesActions.h"

void printTree(Node* a){
	if(a != NULL){
		printf("%d", a->data);
		printTree(a->left);
		printTree(a->right);
	}
}
/**
 * \brief Program entry
 *
 * \return EXIT_SUCCESS - Normal stop from the program
 */
int main(){
	Node * base = createNode(0);
	Node * tree = createNode(4);
	base->left = tree;
	tree->left = createNode(2);
	tree->left->left = createNode(1);
	tree->left->right = createNode(3);
	tree->right = createNode(5);
	printTree(base);
	printf("oui");
	rightRotation(&tree);
	printTree(base);
	return EXIT_SUCCESS;
}

/**
 * 				4
 * 		2				5
 * 	1		3
 *
 *
 * 				2
 * 		1				4
 * 					3		5
 *
 *
 *
 *
 *
 *
 *
 */
