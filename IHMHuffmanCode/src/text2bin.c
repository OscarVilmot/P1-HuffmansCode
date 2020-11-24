/**
 * \file text2bin.c
 * \brief Source where all tree-related function take places
 * \date 21 oct. 2020
 * \author Kylian.S, Tommy Lee.A, Joel.G, Jules.R, Oscar.V
 * \version 0.1
 *
 * Compression program using Huffman Algorith, with trees and queues
 *
 */
#include <string.h>

static void char2bin(char letter, char decToBin[9]) {
    int letterToDec = (int) letter;
    int i = 7;

    // we convert the letter to binary
    while (letterToDec != 0) {
        decToBin[i] = (char) letterToDec % 2 + 48;
        letterToDec /= 2;
        --i;
    }

    // then we add the zeros
    while (i >= 0) {
        decToBin[i] = '0';
        --i;
    }
}

void text2bin(char* text, char* textInBinary) {
	int i = 0;
    char characterInBinary[9];

	while (text[i] != '\0') {
		char2bin(text[i], characterInBinary);
		strcat(textInBinary, &characterInBinary);
        ++i;
	}
}
