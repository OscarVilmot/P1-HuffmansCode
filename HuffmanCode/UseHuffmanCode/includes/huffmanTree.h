/**
 * \file huffmanTree.h
 * \brief Header of the module which create the huffman tree.
 * \date November 2020
 * \author Kylian.S, Tommy Lee.A, Joel.G, Jules.R, Oscar.V
 * \version 1.0
 */

#ifndef HUFFMANTREE
#define HUFFMANTREE

#include "occurrence.h"

typedef struct Node {
    OccurrenceLetter* letterAndOccurrence;
    struct Node* right;
    struct Node* left;
}Node;

extern Node* createHuffmanTree(ElementOccurrenceLetter** listOccurrences);
extern void freeHuffmanTree(Node** huffmanTree);

#endif