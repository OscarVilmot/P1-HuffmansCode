/**
 * \file huffmanTree.h
 * \brief Header of the module creating the huffman tree.
 * \date November 2020
 * \author Kylian.S, Tommy Lee.A, Joel.G, Jules.R, Oscar.V
 * \version 1.0
 */

#ifndef HUFFMANTREE
#define HUFFMANTREE

#include "occurrence.h"

/**
 * \brief Function to create the huffman tree.
 *        \n Example :
 *         \code{.c}
 *         Node* huffmanTree = createHuffmanTree(occurrences);
 *         \endcode
 * \param listOccurrenceLetters the list of occurrences which is transform into the tree.
 * \return the Node's pointer, if the huffmanTree is created.
 * \return \c NULL, if the huffmanTree isn't created.
*/
extern Node* createHuffmanTree(ElementOccurrenceLetter** listOccurrences);

/**
 * \brief Function to free the huffman tree.
 *        \n Example :
 *         \code{.c}
 *         freeHuffmanTree(&huffmanTree);
 *         \endcode
 * \param huffmanTree is the huffmanTree's address which is going to be freed.
*/
extern void freeHuffmanTree(Node** huffmanTree);

#endif