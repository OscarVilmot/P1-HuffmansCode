/*
 * huffmanCode.h
 *
 *  Created on: 23 nov. 2020
 *      Author: ksauvee, Joel-Alt
 */

#ifndef HUFFMANTREE
#define HUFFMANTREE

#include "occurrence.h"

typedef struct Node {
    OccurrenceLetter* letterAndOccurrence;
    struct Node* right;
    struct Node* left;
}Node;

#endif