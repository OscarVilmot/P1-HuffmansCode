/**
 * \file filesActions.c
 * \brief Source where all tree-related function take places
 * \date 21 oct. 2020
 * \author Kylian.S, Tommy Lee.A, Joel.G, Jules.R, Oscar.V
 * \version 0.1
 *
 * Compression program using Huffman Algorith, with trees and queues
 *
 */
#include <stdio.h>
#include <stdlib.h>

int findSizeText(FILE* file){
    int size = 0;
    char c = fgetc(file);
    
    while (c != EOF) {
        c = fgetc(file);
        ++size;
    }
    fseek(file, 0, SEEK_SET);

    return size;
}

char* readTxtFile(FILE* fileToRead) {
    char* text = malloc(sizeof(char) * findSizeText(fileToRead));
    fread(text, sizeof(char), findSizeText(fileToRead), fileToRead);

    return text;
}

void writeInTxtFile(char* textToWriteInFile, FILE* fileToWrite) {
    fwrite(textToWriteInFile, sizeof(char), findSizeText(fileToWrite), fileToWrite);
}
