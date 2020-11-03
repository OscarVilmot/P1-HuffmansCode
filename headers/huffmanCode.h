/*
 * huffmanCode.h
 *
 *  Created on: 2 nov. 2020
 *      Author: ksauvee
 */

#ifndef HUFFMAN_CODE
#define HUFFMAN_CODE

#include <stdlib.h>

typedef struct OccurrenceLetter{
    char letter;
    int occurrence;
}OccurrenceLetter;

typedef struct ElementOccurrenceLetter{
    OccurrenceLetter* data;
    struct ElementOccurrenceLetter* next;
}ElementOccurrenceLetter;

#endif