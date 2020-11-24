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

int main(void) {
	FILE* text = fopen("text.txt", "r");
	FILE* dictionary = fopen("dictionary.txt", "r");
	FILE* textEncoded = fopen("textEncoded.txt", "r+");
    
	char* textInBinary = malloc(8 * findSizeText(text) * sizeof(char));
	char* textInString = readTxtFile(text);
	char* textEncodedInBinary = NULL;

    // it will store the size saved by using the huffman algorithm
	double sizeSaved = 0;
	
	ElementOccurrenceLetter* listOccurrences = NULL;

	Node* huffmanTree = NULL;

	// here we process the huffman algorithm
	findOccurrenceLettersInText(&listOccurrences, textInString);
	huffmanTree = createHuffmanTree(&listOccurrences);
	findTextEncoded(textInString, textEncoded, dictionary);

    // here we calculate the size saved by the huffman algorithm
    text2bin(textInString, textInBinary);
	textEncodedInBinary = readTxtFile(textEncoded);
	sizeSaved = 100 - ((double) strlen(textEncodedInBinary) / (double) strlen(textInBinary)) * 100;
	printf("We saved %f%% of size !\n", sizeSaved);

    fclose(text);
	fclose(dictionary);
	fclose(textEncoded);
	free(textInBinary);
	textInBinary = NULL;
    freeHuffmanTree(&huffmanTree);
	return 0;
}
