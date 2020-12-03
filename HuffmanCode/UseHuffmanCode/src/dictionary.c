#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../IHMHuffmanCode/includes/fileActions.h"
#include "../includes/huffmanTree.h"

void treeToDic(Node* tree, char* pos, FILE* dico);

void mainDico(Node* tree, FILE* dico){
	char * pos = "";
	treeToDic(tree, pos, dico);
	rewind(dico);
}

void treeToDic(Node* tree, char* pos, FILE* dico){
	if(tree == NULL) return;
	else if(tree->left == NULL && tree->right == NULL){
		char* letter = (char*)malloc(sizeof(char));
		letter[0] = tree->letterAndOccurrence->letter;
		writeInTxtFile(letter, dico);
		writeInTxtFile(":", dico);
		writeInTxtFile(pos, dico);
		writeInTxtFile("\n", dico);
		free(letter);
	}else{
		char* right = (char*)malloc(sizeof(char)*200);
		strcat(strcpy(right, pos), "1");
		treeToDic(tree->right, right, dico);
		free(right);

		char* left = (char*)malloc(sizeof(char)*200);
		strcat(strcpy(left, pos), "0");
		treeToDic(tree->left, left, dico);
		free(left);
	}
}
