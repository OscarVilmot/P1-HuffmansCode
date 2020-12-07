/**
 * \file fileActions.h
 * \brief Header of the module allowing reading and writing in text files.
 * \date November 2020
 * \author Kylian.S, Tommy Lee.A, Joel.G, Jules.R, Oscar.V
 * \version 1.0
 */

#ifndef FILEACTIONS_H_
#define FILEACTIONS_H_

#include <stdio.h>

/**
 * \brief Function that find the size of the text in a file.
 *        \n Example :
 *         \code{.c}
 *         findSizeText(file);
 *         \endcode
 * \param file the file where there is the text.
 * \return It return the number of caracters in the text.
*/
extern int findSizeText(FILE* file);

/**
 * \brief Function that extract the text from a file.
 *        \n Example :
 *         \code{.c}
 *         readTxtFile(fileToRead);
 *         \endcode
 * \param fileToRead the file where there is the text.
 * \return It return the text, in a string.
*/
extern char* readTxtFile(FILE* fileToRead);

/**
 * \brief Function that put the text in a file.
 *        \n Example :
 *         \code{.c}
 *         writeInTxtFile(textToWriteInFile, fileToWrite);
 *         \endcode
 * \param textToWriteInFile the text to put in the file.
 * \param fileToWrite the file where to put the text.
 * \return VOID.
*/
extern void writeInTxtFile(char* textToWriteInFile, FILE* fileToWrite);


#endif /* FILEACTIONS_H_ */
