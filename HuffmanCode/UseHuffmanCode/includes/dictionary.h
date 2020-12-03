/**
 * \file dictionary.h
 * \brief Header of the module which creating the dictionary from the huffman tree.
 * \date November 2020
 * \author Kylian.S, Tommy Lee.A, Joel.G, Jules.R, Oscar.V
 * \version 1.0
 */

#ifndef DICTIONARY
#define DICTIONARY

extern void treeToDic(Node* tree, char* pos, FILE* dico);
extern void mainDico(Node* tree, FILE* dico);

#endif
