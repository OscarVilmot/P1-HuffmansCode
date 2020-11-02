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

void printTreePrefixe(Node* a){
	if(a != NULL){
		printf("%d\n", a->data);
		printTreePrefixe(a->left);
		printTreePrefixe(a->right);
	}
}
/**
 * \brief Program entry
 *
 * \return EXIT_SUCCESS - Normal stop from the program
 */
int main(){
	Node * tree = createNode(4);
	tree->left = createNode(8);
	tree->right = createNode(12);
	tree->left->left = createNode(2);
	tree->left->left->left = createNode(1);
	tree->left->left->right = createNode(3);
	tree->left->right = createNode(5);
	printTreePrefixe(tree);
	printf("BARRE\n");
	rightRotation(&(tree->left));
	printTreePrefixe(tree);
	deleteTree(tree);
	return EXIT_SUCCESS;
}
