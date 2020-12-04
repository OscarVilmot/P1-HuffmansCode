/**
 * \file encoding.h
 * \brief Header of the module encoding the input text with the dictionary.
 * \date November 2020
 * \author Kylian.S, Tommy Lee.A, Joel.G, Jules.R, Oscar.V
 * \version 1.0
 */

#ifndef ENCODING
#define ENCODING

#include <stdio.h>

/**
 * \brief Function to encode the text and put it in the textEncoded's file.
 *        \n Example :
 *         \code{.c}
 *         findTextEncoded("This is a sentence", textEncoded, dictionary);
 *         \endcode
 * \param text the input text.
 * \param textEncoded the output text encoded based on huffman algorithm.
 * \param dictionary the dictionary containing the letter's codes.
*/
extern void findTextEncoded(char* text, FILE* textEncoded, FILE* dictionary);

#endif
