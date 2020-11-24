/**
 * \file HuffmanCode.c
 * \brief The main source where the main function takes place
 * \date 21 oct. 2020
 * \author Kylian.S, Tommy Lee.A, Joel.G, Jules.R, Oscar.V
 * \version 0.1
 *
 * Compression program using Huffman Algorith, with trees and queues
 *
 */

/**
 * \brief Program entry
 *
 * \return EXIT_SUCCESS - Normal stop from the program
 */

#include <stdio.h>
#include <stdlib.h>
#include "./IHMHuffmanCode/includes/text2bin.h"
#include "./IHMHuffmanCode/includes/fileActions.h"
#include "./UseHuffmanCode/includes/occurrence.h"
#include "./UseHuffmanCode/includes/huffmanTree.h"
#include "./UseHuffmanCode/includes/encoding.h"

int main() {
	FILE* text = fopen("text.txt", "r");
	FILE* dictionary = fopen("dictionary.txt", "r");
	FILE* textEncoded = fopen("textEncoded.txt", "w");
    
	char* textInBinary = malloc(8 * findSizeText(text) * sizeof(char));
	char* textInString = readTxtFile(text);
	
	ElementOccurrenceLetter* listOccurrences = NULL;

	Node* huffmanTree = NULL;
	text2bin(textInString, textInBinary);
	findOccurrenceLettersInText(&listOccurrences, textInString);
	huffmanTree = createHuffmanTree(&listOccurrences);
	findTextEncoded(textInString, textEncoded, dictionary);

    fclose(text);
	fclose(dictionary);
	fclose(textEncoded);
	free(textInBinary);
	textInBinary = NULL;
    freeHuffmanTree(&huffmanTree);
	return EXIT_SUCCESS;
}
