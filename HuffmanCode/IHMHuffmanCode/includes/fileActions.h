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

int findSizeText(FILE* file);
char* readTxtFile(FILE* fileToRead);
void writeInTxtFile(char* textToWriteInFile, FILE* fileToWrite);


#endif /* FILEACTIONS_H_ */
