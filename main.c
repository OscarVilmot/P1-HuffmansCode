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
#include <string.h>
#include <time.h>
#include "./IHMHuffmanCode/includes/text2bin.h"
#include "./IHMHuffmanCode/includes/fileActions.h"
#include "./UseHuffmanCode/includes/occurrence.h"
#include "./UseHuffmanCode/includes/huffmanTree.h"
#include "./UseHuffmanCode/includes/encoding.h"
#include "./UseHuffmanCode/includes/dictionary.h"

int main(void) {
	FILE* text = fopen("text.txt", "r");
	FILE* dictionary = fopen("dictionary.txt", "w+");
	FILE* textEncoded = fopen("textEncoded.txt", "r+");
	
    if(text != NULL && dictionary != NULL && textEncoded != NULL){
		
		char* textInBinary = malloc(8 * findSizeText(text) * sizeof(char));
		char* textInString = readTxtFile(text);
		char* textEncodedInBinary = NULL;
		// it will store the size saved by using the huffman algorithm
		double sizeSaved = 0;
		double compressionTime = 0;

		ElementOccurrenceLetter* listOccurrences = NULL;

		Node* huffmanTree = NULL;

		time_t secondsBeforeCompression;
		time_t secondsAfterCompression;

		printf("Compression Start\n");
		time(&secondsBeforeCompression);

		// here we process the huffman algorithm
		findOccurrenceLettersInText(&listOccurrences, textInString);
		huffmanTree = createHuffmanTree(&listOccurrences);
		mainDico(huffmanTree, dictionary);
		findTextEncoded(textInString, textEncoded, dictionary);

		printf("Compression End\n");
		time(&secondsAfterCompression);
		compressionTime = difftime(secondsAfterCompression, secondsBeforeCompression);
		printf("Compression Time : %f sec\n", compressionTime);

		// here we calculate the size saved by the huffman algorithm
		text2bin(textInString, textInBinary);
		textEncodedInBinary = readTxtFile(textEncoded);
		printf("%lu\n", strlen(textEncodedInBinary));
		printf("%lu\n", strlen(textInString));
		// sizeSaved = 100 - ((double) strlen(textEncodedInBinary) / (double) strlen(textInBinary)) * 100;
		fclose(text);
		fclose(dictionary);
		fclose(textEncoded);
		free(textInBinary);
		free(textInString);
		free(textEncodedInBinary);
		textInBinary = NULL;
		textInString = NULL;
		textEncodedInBinary = NULL;
		freeHuffmanTree(&huffmanTree);
	}
	return 0;
}
