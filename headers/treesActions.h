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

#ifndef HEADERS_TREESACTIONS_H_
#define HEADERS_TREESACTIONS_H_

int max(int a, int b);

Node* createNode(int value);
void deleteTree(Node* tree);

int heightTree(Node* tree);
int balFactorTree(Node* tree);

void rightRotation(Node** tree);
void leftRotation(Node** tree);

#endif /* HEADERS_TREESACTIONS_H_ */
