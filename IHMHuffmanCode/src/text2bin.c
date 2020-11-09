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
#include "../includes/text2bin.h"

char* char2bin(char letter) {
    int letterToDec = (int)letter;
    char* decToBin = malloc(sizeof(char));
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

    return decToBin;
}

char* text2bin(char* a) {
	char b = a[0];
	char* y = malloc(8 * sizeof(char));
	char* c = malloc(8 * sizeof(a));
	int i = 0;
	while (b != '\0'){
		y = char2bin(b);
		for (int j = 0; j < 8; j++) {
			c[8 * i + j] = y[j];
		}
		i++;
		b = a[i];
	}
	return c;
}
