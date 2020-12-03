/*
 * fileActions.h
 *
 *  Created on: 2 nov. 2020
 *      Author: pasarco
 */

#ifndef FILEACTIONS_H_
#define FILEACTIONS_H_

#include <stdio.h>

int findSizeText(FILE* file);
char* readTxtFile(FILE* fileToRead);
void writeInTxtFile(char* textToWriteInFile, FILE* fileToWrite);


#endif /* FILEACTIONS_H_ */
