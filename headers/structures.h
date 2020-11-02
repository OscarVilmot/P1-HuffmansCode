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

#ifndef HEADERS_STRUCTURES_H_
#define HEADERS_STRUCTURES_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
} Node;

#endif /* HEADERS_STRUCTURES_H_ */
