/**
 * \file text2bin.h
 * \brief Header of the module converting the text in binary.
 * \date November 2020
 * \author Kylian.S, Tommy Lee.A, Joel.G, Jules.R, Oscar.V
 * \version 1.0
 */

#ifndef HEADERS_TEXT2BIN_H_
#define HEADERS_TEXT2BIN_H_

/**
 * \brief Function that transform a text into a binary.
 *        \n Example :
 *         \code{.c}
 *         text2bin(plainText, binaryText);
 *         \endcode
 * \param the plain text to tranform into a binary.
 * \param the binary calculated from the initial text.
 * \param VOID.
*/
extern void text2bin(char* text, char* textInBinary);

#endif /* HEADERS_TEXT2BIN_H_ */
