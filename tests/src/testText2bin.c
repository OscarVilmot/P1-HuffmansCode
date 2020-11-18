/**
 * \file text2bin.c
 * \brief Source where all text2bin-related tests take places
 * \date 18 nov. 2020
 * \author Kylian.S, Tommy Lee.A, Joel.G, Jules.R, Oscar.V
 * \version 0.1
 *
 * Compression program using Huffman Algorith, with trees and queues
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../IHMHuffmanCode/includes/text2bin.h"

void testLetterA() {
    char* text = "A";
    char* textinBinary = malloc(8 * sizeof(text));

    text2bin(text, textinBinary);

    if (strcmp(textinBinary, "01000001") == 0) {
        printf("Test 1 : Success");
    } else {
        printf("Test 1 : Failure");
    }
    printf("\n");
}

void testExclamationMark() {
    char* text = "!";
    char* textinBinary = malloc(8 * sizeof(text));

    text2bin(text, textinBinary);

    if (strcmp(textinBinary, "00100001") == 0) {
        printf("Test 2 : Success");
    } else {
        printf("Test 2 : Failure");
    }
    printf("\n");
}

int main() {
    testLetterA();
    testExclamationMark();
    return 0;
}
