/*
 * huffmanTree.h
 *
 *  Created on: 23 nov. 2020
 *      Author: ksauvee, Joel-Alt
 */

#ifndef HUFFMANTREE
#define HUFFMANTREE

#include "occurrence.h"

extern Node* createHuffmanTree(ElementOccurrenceLetter** listOccurrences);
extern void freeHuffmanTree(Node** huffmanTree);

#endif